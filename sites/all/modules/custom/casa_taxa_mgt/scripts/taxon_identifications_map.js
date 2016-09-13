/**
 * @file
 * A JavaScript file for…
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

var page_is_setup = false;

// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.taxon_identifications_map = {
  attach: function(context, settings) {
    // console.log('taxon_identifications_map');

    if (! page_is_setup) {

      set_up_maps(context);

      page_is_setup = true;
    }
  }
};



/**
 * Converts map containers that contain location data into OpenLayers maps.
 */
function set_up_maps(context) {

  $('[data-transform="to-map"]', context).each(function(index, el) {

    var map_container = $(this);
    var map_id = $(this).attr('id');
    // console.log('map_id: ', map_id);

    map_container.removeClass('hidden');

    // Create the layers.

    var tile_layer = new ol.layer.Tile({
      // source: new ol.source.MapQuest({layer: 'sat'})
      source: new ol.source.OSM({})
    });

    var vector_source = new ol.source.Vector();
    var vector_layer = new ol.layer.Vector({
      source: vector_source
    });

    // Add location features

    var projection = tile_layer.getSource().getProjection();
    var features = create_features_from_geojson(map_container.html(), projection);
    // console.log('features: ', features);
    map_container.html('');

    $.each(features, function(index, feature) {
      vector_source.addFeature(feature);
    });

    // Create the OpenLayers map.
    var map = new ol.Map({
      target: map_id,

      layers: [tile_layer, vector_layer],

      view: new ol.View({
        center: ol.proj.fromLonLat([0, 0]),
        zoom: 4
      })
    });

    // Zoom to and center on vector layer.
    map.getView().fit(vector_layer.getSource().getExtent(), map.getSize());

  });
}

function isOdd(num) { return num % 2;}



/**
 * @param crs
 *   The coordinate reference system that the new features should have.
 */
function create_features_from_geojson(json, crs) {
  var features_data = $.parseJSON(json).features;
  var features = [];

  $.each(features_data, function(index, feature_data) {
    // console.log('index: ', index);
    // console.log('feature_data: ', feature_data);

    var feature = create_feature_from_geometry(feature_data.geometry, crs);

    // Transform the feature's projection.
    feature.getGeometry().transform(
      new ol.proj.Projection({code: "EPSG:4326"}), // source: EPSG:4326 (WGS84 geographic coordinates)
      crs // destination: EPSG:3857 (Web or Spherical Mercator, as used for example by Bing Maps or OpenStreetMap)
    );

    // Style it according to it's geometry type.

    // Point
    if (feature.getGeometry().getType() == 'Point') {
      var style = new ol.style.Style({
        // Small red dot
        image: new ol.style.Circle({
          radius: 3,
          fill: new ol.style.Fill({color: 'red'}),
        })
      });
    }
    // Polygon (representing a QDS)
    else if (feature.getGeometry().getType() == 'Polygon') {
      // Set the feature's style (based on its count).
      var count = parseInt(feature_data.properties.count);
      var colour = get_qds_count_colour(count);
      var style = create_qds_style(colour);
      feature.setStyle(style);
    }

    features.push(feature);
  });

  return features;
}



/**
 * @param geometry
 *   A GeoJSON geometry object.
 */
function create_feature_from_geometry(geometry) {
  var feature_geometry;

  // Point
  if (geometry.type == 'Point') {
    var feature_geometry = new ol.geom.Point([
      parseFloat(geometry.coordinates[0]),
      parseFloat(geometry.coordinates[1])
    ]);
  }
  // Polygon (representing a QDS)
  else if (geometry.type == 'Polygon') {
    var feature_geometry = new ol.geom.Polygon([[
      [parseFloat(geometry.coordinates[0][0][0]),
       parseFloat(geometry.coordinates[0][0][1])],
      [parseFloat(geometry.coordinates[0][1][0]),
       parseFloat(geometry.coordinates[0][1][1])],
      [parseFloat(geometry.coordinates[0][2][0]),
       parseFloat(geometry.coordinates[0][2][1])],
      [parseFloat(geometry.coordinates[0][3][0]),
       parseFloat(geometry.coordinates[0][3][1])]
    ]]);
    // console.log('polygon: ', polygon);
  }

  var feature = new ol.Feature({
    geometry: feature_geometry
  });

  // console.log('feature: ', feature);
  return feature;
}



function get_qds_count_colour(count) {
  var colour = 'black';

  // Validation.
  // if (typeof count !==

  var categories = {
    1: {
      'min': 0, 'max': 1,
      'colour': [255, 234, 000, 1] // yellow
    },
    2: {
      'min': 1, 'max': 4,
      'colour': [255, 120, 000, 1] // orange
    },
    3: {
      'min': 4, 'max': 10,
      'colour': [255, 000, 000, 1] // red
    },
    4: {
      'min': 10, 'max': 16,
      'colour': [255, 000, 180, 1] // pink
    },
    5: {
      'min': 16, 'max': 100,
      'colour': [195, 000, 255, 1] // purple
    },
  };

  $.each(categories, function(index, category) {
    if(count > category.min && count <= category.max) {
      colour = category.colour; // yellow
    }
  });

  return colour;
}



function create_qds_style(colour) {
  var stroke = new ol.style.Stroke({
    color: colour,
    width: 1
  });
  colour[3] = 0.6;
  var fill = new ol.style.Fill({
    color: colour
  });
  var style = new ol.style.Style({
    fill: fill,
    stroke: stroke
  });

  return style;
}


})(jQuery, Drupal, this, this.document);
