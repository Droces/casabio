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
 * Drupal.casa_map_mgt
 *  .get_map()
 *  .get_ol_maps()
 *  .create_feature_from_JSON()
 *  .create_vector_layer()
 *  .add_feature_to_vector_layer()
 *  .add_layer()
 *  .get_feature_from_settings()
 *  .make_widget_map()
 *    .remove_interaction()
 *  .center_map()
 *  .create_style()
 *
 * add_collection_to_map()
 * add_draw_interaction()
 *
 * create_feature_geometry()
 * fix_layer_ordering()
 * transform_geometry_to_4326()
 * transform_geometry_from_4326()
 * get_style()
 */


var page_is_setup = false;

var map;
var map_tile_layer;
var map_vector_layer;
var draw_source;

// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.casa_map_mgt = {
  attach: function(context, settings) {

    if (! page_is_setup) {

      // Convert location fields with a textarea into a map

      var map_field = $('.form-field-name-field-location .form-type-textarea', context);
      // console.log('map_field.length: ', map_field.length);
      if (map_field.length > 0) {
        map = Drupal.casa_map_mgt.make_widget_map(settings);
      }


      // Listener: When a tab is clicked, updateSize of any maps within it.
      $('.horizontal-tab-button a', context).on('click', function( event, ui ) {
        // console.log("heard: horizontal-tab-button clicked");

        if (typeof(Drupal.openlayers) !== 'undefined') {
          map = Drupal.casa_map_mgt.get_ol_maps(settings);
          // console.log('map: ', map);
          map.updateSize();
        }
      });

      page_is_setup = true;
    }

  },
  weight: 2
};


Drupal.casa_map_mgt = {


  get_map: function(settings) {
    // Has custom map
    if (typeof(map) !== 'undefined') {
      return map;
    }
    // Has has OL module map
    else if (typeof(Drupal.openlayers) !== 'undefined') {
      return get_ol_maps(settings);
    }
  },



  /*
   * Gets all maps created by the OpenLayers module;
   * Assumes there's only 1 map on the page...
   * @todo change this (and calling functions) to support multiple
   */
  get_ol_maps: function(settings) {

    if (typeof(Drupal.openlayers) === 'undefined') {
      throw 'Drupal.openlayers is not defined' + ', in Drupal.casa_map_mgt.refresh_maps()';
    }

    var map;
    var map_instances = Drupal.openlayers.instances;
    // console.log('map_instances: ', map_instances);

    $.each(map_instances, function(map_id, map_instance) {
      map = map_instance.map;
    });

    return map;
  },



  /*
   * Create a vector layer from JSON data.
   *
   * @param map
   *   OpenLayers map object
   * @param feature_data
   *   Feature's location data in geofield JSON format
   */
  create_feature_from_JSON: function(feature_data) {
    // console.log('feature_data: ', feature_data);

    // var map_tile_layer = new ol.layer.Tile({
    //   // source: new ol.source.MapQuest({layer: 'sat'})
    //   source: new ol.source.OSM({})
    // });

    // Convert "LINESTRING (20.41…)" to "20.41…"
    var indexStart = feature_data.geom.indexOf('(') + 1;
    var indexEnd = feature_data.geom.indexOf(')');
    var coordinates_string = feature_data.geom.substring(indexStart, indexEnd);
    // console.log('coordinates_string: ', coordinates_string);


    var featureGeometry = create_feature_geometry(coordinates_string, feature_data.geo_type);
    // console.log('featureGeometry: ', featureGeometry);

    var projection = map_tile_layer.getSource().getProjection();
    // console.log('projection: ', projection);

    // Transform this to match the projection of the map tile layer that will be used
    featureGeometry.transform(
      new ol.proj.Projection({code: "EPSG:4326"}), // source: EPSG:4326 (WGS84 geographic coordinates)
      projection // destination: EPSG:3857 (Web or Spherical Mercator, as used for example by Bing Maps or OpenStreetMap)
    );
    // console.log('featureGeometry coords after transform: ', featureGeometry.getCoordinates());


    var feature = new ol.Feature({
      geometry: featureGeometry,
      name: 'My ___'
    });

    return feature;
  },



  /*
   * Create a vector layer from JSON data.
   */
  create_point_feature_from_lon_lat: function(lon, lat) {

    var geometry = new ol.geom.Point(
      [lon, lat]
    );
    // console.log('geometry coords: ', geometry.getCoordinates());

    var projection = map_tile_layer.getSource().getProjection();
    // console.log('projection: ', projection);

    // Transform from coordinates (EPSG:4326) to metres (EPSG:3857)

    // Transform this to match the projection of the map tile layer that will be used
    geometry.transform(
      new ol.proj.Projection({code: "EPSG:4326"}), // source: EPSG:4326 (WGS84 geographic coordinates)
      projection // destination: EPSG:3857 (Web or Spherical Mercator, as used for example by Bing Maps or OpenStreetMap)
    );
    // console.log('geometry coords after transform: ', geometry.getCoordinates());


    var feature = new ol.Feature({
      geometry: geometry,
      name: 'My point'
    });

    return feature;
  },



  create_vector_layer: function() {
    return new ol.layer.Vector({
      source: new ol.source.Vector()
    });
  },



  add_feature_to_vector_layer: function(feature) {
    // console.log('features: ', map_vector_layer.getSource().getFeatures());
    map_vector_layer.getSource().addFeature(feature);
    // console.log('features: ', map_vector_layer.getSource().getFeatures());
  },



  add_layer: function(layer) {
    map.addLayer(layer);
  },





  get_feature_from_settings: function(settings) {
    // Fetch the current collection's location data.
    var feature_location_string = settings.edit_selected.collection_location;
    // Convert the location data into JSON.
    var feature_location = $.parseJSON(feature_location_string);
    return feature_location;
  },





  /*
   * Creates an OpenLayers 3 map, with a draw point interaction, and the collection's location.
   */
  make_widget_map: function(settings) {


    // =========================================================================
    // Create map with tile layer

    $('.form-field-name-field-location').append('<div id="map" class="map"></div>');

    // Create the map object.
    map = new ol.Map({ });

    // Set the map's target HTML element.
    map.setTarget('map');

    // Set the map's view.
    // [lon, lat], or [x, y]
    var view = new ol.View({
      center: [0, 0],
      zoom: 1
    })
    map.setView(view);

    // Add a tile layer (MapQuest OSM).
    // map_tile_layer = new ol.layer.Tile({
    //   source: new ol.source.MapQuest({layer: 'osm'})
    // })

    // BingMaps types -------------
    // Aerial             Aerial
    // AerialWithLabels   Aerial with labels
    // Road               Road
    // collinsBart        Collins Basrt
    // ordnanceSurvey     Ordnance Survey

    // Add a tile layer (Bing AerialWithLabels).
    map_tile_layer = new ol.layer.Tile({
      source: new ol.source.BingMaps({
        imagerySet: 'AerialWithLabels',
        key: 'Alv8UVrw4GpMxdqDyfVK8js_wa56fdUPFhZF7eUPSTiPVsry3kdyIQcr-U5upHIN'
      })
    });
    // console.log('map_tile_layer: ', map_tile_layer);

    // var projection = ol.proj.get('EPSG:3857');

    map.addLayer(map_tile_layer);

    // Set the zoom level.
    map.getView().setZoom(2);

    // Remove an interaction.

    var interactions = map.getInteractions();

    function remove_interaction(interaction, index, array) {
      var is_mouseWheelZoom = interaction instanceof ol.interaction.MouseWheelZoom;

      if (is_mouseWheelZoom) {
        map.removeInteraction(interaction);
      }
    }

    interactions.forEach(remove_interaction);


    // =========================================================================
    // Add draw interaction

    add_draw_interaction();



    // =========================================================================
    // Add draw event management

    // Used to determine if the field has a value yet.
    var has_location = false;

    // draw.on('drawend', function (event) {
    //   // console.log('event: draw, on drawend: ', event);
    // });

    draw_source.on('change', function (event) {
      // console.log('event: draw_source, on change: ', event);

      var last_feature;
      var features = draw_source.getFeatures();
      // console.log('features: ', features);

      if (!has_location || features.length > 1) {
        has_location = true;

        // Remove all but the last (most recently-added) feature
        last_feature = features[features.length - 1];
        draw_source.clear();
        draw_source.addFeature(last_feature);

        // Get coordinates
        var features = draw_source.getFeatures();

        // Call the transform function on the features.
        // features.forEach(transform_geometry);

        var point = features[0];

        // Transform to get correct coordinates (in degrees)
        Drupal.casa_map_mgt.transform_geometry_to_4326(point, map_tile_layer);
        var coords = point.getGeometry().getCoordinates();
        // console.log('coords: ', coords);

        // transform back to display corrently on the map
        Drupal.casa_map_mgt.transform_geometry_from_4326(point, map_tile_layer);

        // // Set field value type
        // var input = $('[name="field_location[und][0][dataType]"]');
        // input.val('wkt');
        // This isn't used (it gets overridden).

        // Set field value
        var input = $('[name="field_location[und][0][geom]"]');
        input.val(coords.join(', '));
        Drupal.edit_selected.trigger_manage_field_change( input );
      }

    });


   // add_collection_location(settings);

    return map;
  },


  center_map: function(layer) {
    // console.log('layer: ', layer);
    var maxZoom = 19; // Max for Bing AerialWithLabels tile layer

    if (typeof layer !== 'undefined') {
      // Zoom map to the layer's extent
      var extent = layer.getSource().getExtent();
      map.getView().fit(extent, map.getSize(), {
        maxZoom: maxZoom
      });
    }
    else {
      // Zoom map to the own map_vector_layer's extent
      var extent = map_vector_layer.getSource().getExtent();
      map.getView().fit(extent, map.getSize(), {
        maxZoom: maxZoom
      });
    }
  },



  create_style: function(geo_type, radius, fill_colour, stroke_colour) {

    // if (geo_type = 'linestring') {}
    // else if (geo_type = 'point') {}

    if (typeof radius == undefined) {
      radius = 3;
    }

    if (typeof fill_colour == undefined) {
      fill_colour = 'white';
    }

    if (typeof stroke_colour == undefined) {
      stroke_colour = '#bada55';
    }

    // Circle
    var style = new ol.style.Style({
      image: new ol.style.Circle({
        radius: radius,
        fill: new ol.style.Fill({color: fill_colour}),
        stroke: new ol.style.Stroke({color: stroke_colour, width: 1})
      })
    });

    return style;
  },



  // Write the tranform function.
  transform_geometry_to_4326: function(feature, layer) {

    if (typeof layer == 'undefined') {
      layer = map_tile_layer;
    }

    var current_projection = layer.getSource().getProjection();
    // console.log('new_projection: ', new_projection);
    var new_projection = new ol.proj.Projection({code: "EPSG:4326"});

    feature.getGeometry().transform(current_projection, new_projection);
  },



  // Write the tranform function.
  transform_geometry_from_4326: function(feature, layer) {

    if (typeof layer == 'undefined') {
      layer = map_tile_layer;
    }

    var current_projection = new ol.proj.Projection({code: "EPSG:4326"});
    var new_projection = layer.getSource().getProjection();
    // console.log('new_projection: ', new_projection);

    feature.getGeometry().transform(current_projection, new_projection);
  }

};


/**
 * Called by Drupal.casa_map_mgt.make_widget_map()
 */
function add_collection_to_map() {
  map_vector_layer = new ol.layer.Vector({
    source: new ol.source.Vector()
  });
  // console.log('vector_layer: ', vector_layer);

  var feature = Drupal.casa_map_mgt.create_feature_from_JSON(feature_data);

  // var style = create_style(feature_data.geo_type);
  // feature.setStyle(style);

  Drupal.casa_map_mgt.add_feature_to_vector_layer(feature);

  // Add the collection location as a layer to the map
  map.addLayer(map_vector_layer);

  Drupal.casa_map_mgt.center_map();
}


/**
 * Called by Drupal.casa_map_mgt.make_widget_map()
 */
function add_draw_interaction() {

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
}


function create_feature_geometry(coordinates_string, geo_type) {
  // console.log('geo_type: ', geo_type);

  var featureGeometry;

  if (geo_type == 'linestring') {
    // console.log('is linestring');

    var path_points_strings = coordinates_string.split(', ');
    // console.log('path_points_strings: ', path_points_strings);

    var path_points = [];

    $.each(path_points_strings, function(index, val) {
      // console.log('point vals: ', val);
      var vals = val.split(' ');
      path_points.push([parseFloat(vals[0]),parseFloat(vals[1])]);
    });
    // console.log('path_points: ', path_points);

    featureGeometry = new ol.geom.LineString(path_points);
  }

  if (geo_type == 'point') {
    var coords = coordinates_string.split(' ');
    featureGeometry = new ol.geom.Point([parseFloat(coords[0]), parseFloat(coords[1])]);
  }

  return featureGeometry;
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
