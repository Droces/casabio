<?php
/**
 * @file
 * featured_openlayers.default_openlayers_maps.inc
 */

/**
 * Implements hook_default_openlayers_maps().
 */
function featured_openlayers_default_openlayers_maps() {
  $export = array();

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'map_widget_single_point';
  $ol_map->name = 'Widget map: Single point';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '400px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => 0,
      'zoom' => 2,
      'minZoom' => 0,
      'maxZoom' => 0,
    ),
    'layers' => array(
      0 => 'openlayers_geofield_layer_widget',
      1 => 'google_maps_hybrid',
    ),
    'controls' => array(
      0 => 'openlayers_geofield_control_geofield',
      1 => 'openlayers_control_zoom',
      2 => 'openlayers_control_fullscreen',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_dragpan',
    ),
    'components' => array(
      0 => 'openlayers_geofield_component_geofield_widget',
      1 => 'openlayers_geofield_component_zoom_to_source',
    ),
    'renderer' => 'canvas',
  );
  $export['map_widget_single_point'] = $ol_map;

  return $export;
}
