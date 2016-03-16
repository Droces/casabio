/**
 * @file
 * A JavaScript file for…
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.contribute_maps = {
  attach: function(context, settings) {
    // console.log('Called: Drupal.behaviors.contribute_maps');
    // console.log('context: ', context);
    // console.log('settings: ', settings);

    var vector_layer;
    var map;

    add_listeners(context, settings);

  },
  weight: 11
};



/**
 * Adds event listeners to page elements.
 */
function add_listeners(context, settings) {

  // $(document, context).on('edit-selected.edit-form_dialog-opened', function() {});

  $( window ).load(function() {
    // console.log('window has loaded');

    // On Upload page, in the map, set path ('linestring') as default edit mode.
    $('.page-contribute-upload .openlayers-map-container button.ol-geofield-linestring').trigger('click');

    // Update the map size
    // map = get_map(settings);
    // map.updateSize();
  });


  // Map setup has been completed
  $(document, context).on('openlayers.build_stop', function() {

    // If this is one of the 'Edit selected' pages
    if (typeof settings.edit_selected != 'undefined') {

      // Get the collection's location as a vector layer
      feature_location = get_feature_location(settings);
      vector_layer = Drupal.casa_map_mgt.create_vector_layer(feature_location);
      // console.log('vector_layer: ', vector_layer);

      // Add the collection location as a layer to the map
      map = get_map(settings);
      map.addLayer(vector_layer);
    }
  });

  // Dialogs

  // When a dialog is opened.
  $( ".ui-dialog[role='dialog']", context ).on( "dialogopen", function( event, ui ) {
    // console.log("heard: dialogopen");

    map = get_map(settings);
    map.updateSize();

    if (typeof vector_layer != 'undefined') {
      zoom_map_to_extent(map, vector_layer.getSource().getExtent());
    }
  });

  $('.horizontal-tab-button a').on('click', function( event, ui ) {
    // console.log("heard: horizontal-tab-button clicked");

    map = get_map(settings);
    map.updateSize();

    if (typeof vector_layer != 'undefined') {
      zoom_map_to_extent(map, vector_layer.getSource().getExtent());
    }
  });
}



function get_feature_location(settings) {
  // Fetch the current collection's location data.
  var feature_location_string = settings.edit_selected.collection_location;
  // Convert the location data into JSON.
  var feature_location = $.parseJSON(feature_location_string);
  return feature_location;
}



function get_map(settings) {

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
}



function zoom_map_to_extent(map, extent) {
  // console.log('Called: zoom_map_to_extent');
  // console.log('map size: ', map.getSize());
  map.getView().fit(extent, map.getSize());
}



})(jQuery, Drupal, this, this.document);
