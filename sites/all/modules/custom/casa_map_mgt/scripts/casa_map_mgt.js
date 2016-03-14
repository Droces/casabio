/**
 * @file
 *   
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.casa_map_mgt = {
  attach: function(context, settings) {

  },
  weight: 2
};


Drupal.casa_map_mgt = {



  /*
   * Create a vector layer from JSON data and add it to a provided map.
   * 
   * @param map
   *   OpenLayers map object
   * @param feature_location
   *   Feature's location data in geofield JSON format
   */
  create_vector_layer: function(feature_location) {
    // console.log('map: ', map);
    // console.log('feature_location: ', feature_location);

    var tile_layer = new ol.layer.Tile({
      // source: new ol.source.MapQuest({layer: 'sat'})
      source: new ol.source.OSM({})
    });

    var vector_source = new ol.source.Vector();
    var vector_layer = new ol.layer.Vector({
      source: vector_source
    });

    // Convert "LINESTRING (20.41…)" to "20.41…"
    var indexStart = feature_location.geom.indexOf('(') + 1;
    var indexEnd = feature_location.geom.indexOf(')');
    var coordinates_string = feature_location.geom.substring(indexStart, indexEnd);
    // console.log('coordinates_string: ', coordinates_string);

    var featureGeometry = create_feature_geometry(coordinates_string, feature_location.geo_type);

    // Transform this to match the projection of the map tile layer that will be used
    featureGeometry.transform(
      new ol.proj.Projection({code: "EPSG:4326"}), // source: EPSG:4326 (WGS84 geographic coordinates)
      tile_layer.getSource().getProjection() // destination: EPSG:3857 (Web or Spherical Mercator, as used for example by Bing Maps or OpenStreetMap)
    );
    // console.log('featureGeometry coords after transform: ', featureGeometry.getCoordinates());

    var feature = new ol.Feature({
      geometry: featureGeometry,
      name: 'My ___'
    });


    // var style = create_style(feature_location.geo_type); 
    // feature.setStyle(style);

    vector_source.addFeature(feature);

    return vector_layer;
  }

};



function create_feature_geometry(coordinates_string, geo_type) {

  var featureGeometry;

  if (geo_type = 'linestring') {
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

  return featureGeometry;
}



function create_style(geo_type) {

  // if (geo_type = 'linestring') {}
  // else if (geo_type = 'point') {}

  // Small red dot
  var style = new ol.style.Style({
    image: new ol.style.Circle({
      radius: 3,
      fill: new ol.style.Fill({color: 'red'}),
      // stroke: new ol.style.Stroke({color: '#bada55', width: 1})
    })
  });

  return style;
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



})(jQuery, Drupal, this, this.document);