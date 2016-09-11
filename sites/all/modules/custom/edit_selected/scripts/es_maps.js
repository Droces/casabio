/**
 * @file
 * A JavaScript file for…
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

// var page_is_setup = false;


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.es_maps = {
  attach: function(context, settings) {
    // console.log('es_maps');

    // if (! page_is_setup) {

    //   page_is_setup = true;
    // }

  }/*,
  weight: 10*/
};


Drupal.es_maps = {

  set_field_value: function(value) {
    console.log('Called: Drupal.es_maps.set_field_value()');

    // // The Geofield map widget

    // if (field_widget == 'geofield-wkt') {
    //   // console.log('field_widget: ', field_widget);
    //   // console.log('values:', values);

    //   map_layer_selected_location = Drupal.casa_map_mgt.create_vector_layer();
    //   Drupal.casa_map_mgt.add_layer(map_layer_selected_location);

    //   var feature_data = {geom: values, geo_type: 'point'};
    //   // var feature_data = {geom: 'POINT (0 0)'};
    //   // console.log('feature_data: ', feature_data);

    //   feature = Drupal.casa_map_mgt.create_feature_from_JSON(feature_data);
    //   // console.log('feature coords: ', feature.getGeometry().getCoordinates());

    //   var colour_semi_blue = [0, 0, 255, 0.4];
    //   var style = Drupal.casa_map_mgt.create_style('point', 5, colour_semi_blue, 'blue');
    //   feature.setStyle(style);

    //   // Add the collection location as a layer to the map
    //   map_layer_selected_location.getSource().addFeature(feature);
    //   // Drupal.casa_map_mgt.add_feature_to_vector_layer(feature);

    //   // Drupal.casa_map_mgt.center_map();
    // }



    // The custom openlayers map

    // var map_instances = Drupal.openlayers.instances;

    // $.each(map_instances, function(map_id, map_instance) {
    //   var map = map_instance.map;
    //   // console.log('map:', map);

    //   var layers = map.getLayers();
    //   // console.log('layers:', layers);
    //   var observation_location_layer = null;
    //   var location = parse_location(value);

    //   // Manage the layers

    //   layers.forEach(function(layer, index, array) {
    //     // console.log('layer:', layer);

    //     // layer.mn is the layer’s ID
    //     if (layer.mn == 'geofield_field_formatter_layer' || layer.mn == 'openlayers_geofield_layer_widget') {
    //       // Hide these layers because of a bug preventing altering the point features.
    //       layer.setVisible(false);
    //       // This is ideal; shows bug in console.
    //       // var point = layer.getSource().getFeatures()[0].getGeometry();
    //       // point.setCoordinates(location);
    //     }
    //     if (layer.mn == 'observation_location') {
    //       observation_location_layer = layer;
    //     }
    //   });

    //   var point;

    //   // If the layer hasn't yet been created, create it.

    //   if (observation_location_layer == null) {
    //     point = new ol.geom.Point(location);
    //     map.addLayer(create_layer(point));
    //   }
    //   else {
    //     point = observation_location_layer.getSource().getFeatures()[0].getGeometry();
    //     // console.log('point:', point);
    //     point.setCoordinates(location);
    //   }

    //   // Transform the point (from WGS84 geographic coordinates to Spherical Mercator).
    //   var current_projection = new ol.proj.Projection({code: "EPSG:4326"});
    //   var new_projection = new ol.proj.Projection({code: "EPSG:3857"});
    //   point.transform(current_projection, new_projection);

    // });
  }
}



})(jQuery, Drupal, this, this.document);
