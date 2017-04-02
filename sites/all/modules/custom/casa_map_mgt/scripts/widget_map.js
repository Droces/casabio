/**
 * @file
 *
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {



/**
 * CONTENTS
 *
 * - variable declarations -
 *
 * Drupal.behaviors.casa_map_mgt
 *  .attach()
 *
 * Drupal.map_widget_maker
 *   .make_widget_map()
 *
 * add_draw_interaction()
 * get_style()
 * draw_source_manage_change()
 * fix_layer_ordering()
 * add_collection_location()
 */


var page_is_setup = false;

// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.map_widget_maker = {
  attach: function(context, settings) {
    // console.log('context: ', context);
    // console.log('settings: ', settings);

    if (! page_is_setup) {
      // console.log('Page being set up...');

      Drupal.casa_map_mgt.setup_map(settings);

      page_is_setup = true;
    }

  },
  weight: 2
};



Drupal.map_widget_maker = {

  /*
   * Creates an OpenLayers 3 map, with a draw point interaction, and the collection's location.
   */
  make_widget_map: function(settings) {
    // console.log('make_widget_map()');

    // =========================================================================
    // Create map with tile layer

    $('.form-field-name-field-location').append('<div id="map" class="map"></div>');

    // Create the map object.
    var map = new ol.Map({ });

    // Set the map's target HTML element.
    map.setTarget('map');

    // var projection = ol.proj.get('EPSG:4326');
    // var projection = ol.proj.get('EPSG:3857');

    // Set the map's view.
    // [lon, lat], or [x, y]
    var view = new ol.View({
      center: [0, 0],
      zoom: 2,
      // projection: projection
    })
    map.setView(view);

    // Add a tile layer.
    var map_tile_layer = Drupal.casa_map_mgt.make_map_tile_layer('Bing');
    map.addLayer(map_tile_layer);
    Drupal.casa_map_mgt.set_map_tile_layer(map_tile_layer);

    // Set the zoom level.
    map.getView().setZoom(2);

    // Remove interactions: MouseWheelZoom
    var interactions = map.getInteractions();
    interactions.forEach(function(interaction, index, array) {
      var is_mouseWheelZoom = interaction instanceof ol.interaction.MouseWheelZoom;

      if (is_mouseWheelZoom) {
        map.removeInteraction(interaction);
      }
    });

    var draw_interaction = add_draw_interaction(map);

    // Used to determine if the field has a value yet.
    var has_location = false;

    // Manage click / draw
    map.on('click', function (event) {
      // console.log('event: draw_source, on change: ', event);
      draw_source_manage_change(has_location);
    });

    // add_collection_location(settings);

    // console.log('map: ', map);
    return map;
  }


}


/**
 * Called by Drupal.casa_map_mgt.make_widget_map()
 */
function add_draw_interaction(map) {

  var draw_collection = new ol.Collection();
  draw_source = new ol.source.Vector();

  var style = get_style('draw');

  var draw_vector_layer = new ol.layer.Vector({
    source: draw_source,
    style: style
  });

  map.addLayer(draw_vector_layer);

  var draw = new ol.interaction.Draw({
    features: draw_collection,
    source: draw_source,
    type: 'Point'
  });
  map.addInteraction(draw);

  return draw;
}



function get_style(type) {
  var default_style = new ol.style.Style({});

  var draw_style = new ol.style.Style({
    fill: new ol.style.Fill({
      color: 'rgba(255, 255, 255, 0.2)'
    }),
    stroke: new ol.style.Stroke({
      color: '#ffcc33',
      width: 2
    }),
    image: new ol.style.Circle({
      radius: 7,
      fill: new ol.style.Fill({
        color: '#ffcc33'
      })
    })
  });

  switch (type) {
    case 'draw':
      return draw_style;
      break;

    default:
      return default_style;
      break;
  }
}




function draw_source_manage_change(has_location) {

  var last_feature;
  var features = draw_source.getFeatures();
  // console.log('features: ', features);

  if (!has_location || features.length > 1) {
    has_location = true;

    // // Remove all but the last (most recently-added) feature
    last_feature = features[features.length - 1];
    draw_source.clear();
    draw_source.addFeature(last_feature);

    // Get coordinates
    var features = draw_source.getFeatures();

    // Call the transform function on the features.
    // features.forEach(transform_geometry);

    var point = features[0];

    // Transform to get correct coordinates (in degrees)
    Drupal.casa_map_mgt.transform_geometry_to_4326(point, Drupal.casa_map_mgt.get_map_tile_layer());
    var coords = point.getGeometry().getCoordinates();
    // console.log('coords: ', coords);

    // transform back to display corrently on the map
    Drupal.casa_map_mgt.transform_geometry_from_4326(point, Drupal.casa_map_mgt.get_map_tile_layer());

    // // Set field value type
    // var input = $('[name="field_location[und][0][dataType]"]');
    // input.val('wkt');
    // This isn't used (it gets overridden).

    // Set field value
    var input = $('[name="field_location[und][0][geom]"]');
    input.val(coords.join(', '));
    Drupal.edit_selected.trigger_manage_field_change( input );
  }
}



function fix_layer_ordering(map) {
  var map_layers = map.getLayers();

  for (var i = 0; i < map_layers.getLength(); i++) {
    // console.log('layer, ZIndex: ' + i + ': ' + map_layers.item(i).getZIndex());

    if (map_layers.item(i) instanceof ol.layer.Vector) {}
    if (map_layers.item(i) instanceof ol.layer.Tile) {
      map_layers.item(i).setZIndex(-1);
    }
  };
}



function add_collection_location(settings) {

  // =========================================================================
  // Add collection's location as a vector layer

  // If this is one of the 'Edit selected' pages
  if (typeof settings.edit_selected != 'undefined') {

    // Get the collection's location as a vector layer
    feature_data = Drupal.casa_map_mgt.get_feature_from_settings(settings);
    // console.log('feature_data: ', feature_data);

    if (typeof feature_data != 'undefined') {
      if (feature_data != null && feature_data['geom'] != 'GEOMETRYCOLLECTION EMPTY') {
        add_collection_to_map(feature_data);
      }
    }

  }
}



})(jQuery, Drupal, this, this.document);
