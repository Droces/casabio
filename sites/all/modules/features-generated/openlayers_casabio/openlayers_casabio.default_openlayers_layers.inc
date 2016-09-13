<?php
/**
 * @file
 * openlayers_casabio.default_openlayers_layers.inc
 */

/**
 * Implements hook_default_openlayers_layers().
 */
function openlayers_casabio_default_openlayers_layers() {
  $export = array();

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'browse_observations_map';
  $ol_layer->name = 'Browse observations map';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'views_geojson_browse_observations_map_feed_1',
    'visible' => 1,
    'style' => 'openlayers_style_default',
  );
  $export['browse_observations_map'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'browse_pictures_map';
  $ol_layer->name = 'Browse pictures map';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'views_geojson_pictures_map_feed_1',
    'visible' => 1,
    'style' => 'openlayers_style_default',
  );
  $export['browse_pictures_map'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'geofield_field_formatter_layer';
  $ol_layer->name = 'Geofield Field Formatter Layer';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'openlayers_geofield_source_vector',
    'style' => 'geofield_display',
    'visible' => 1,
  );
  $export['geofield_field_formatter_layer'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'google_maps_satellite';
  $ol_layer->name = 'Google maps: terrain';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Tile';
  $ol_layer->options = array(
    'source' => 'google_hybrid',
    'visible' => 1,
    'style' => 'openlayers_style_default',
    'opacity' => 1,
  );
  $export['google_maps_satellite'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'googlemaps_hybrid_layer';
  $ol_layer->name = 'Google Maps: hybrid';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_googlemaps',
    'visible' => 1,
    'style' => 'openlayers_style_default',
    'zoomOffset' => 0,
    'wrapDateLine' => 0,
  );
  $export['googlemaps_hybrid_layer'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_geofield_layer_openstreetmap';
  $ol_layer->name = 'Geofield OpenStreetMap';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_geofield_source_openstreetmap',
    'style' => 'openlayers_style_default',
  );
  $export['openlayers_geofield_layer_openstreetmap'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'user_latest_collection';
  $ol_layer->name = 'User\'s latest collection';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'user_latest_collection',
    'visible' => 1,
    'style' => 'openlayers_style_default',
    'zoomActivity' => '',
  );
  $export['user_latest_collection'] = $ol_layer;

  return $export;
}
