<?php
/**
 * @file
 * featured_openlayers.default_openlayers_layers.inc
 */

/**
 * Implements hook_default_openlayers_layers().
 */
function featured_openlayers_default_openlayers_layers() {
  $export = array();

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'google_maps_hybrid';
  $ol_layer->name = 'Google Maps: Hybrid';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Tile';
  $ol_layer->options = array(
    'source' => 'google_maps_hybrid',
    'visible' => 1,
    'style' => 'openlayers_style_default',
    'opacity' => 1,
  );
  $export['google_maps_hybrid'] = $ol_layer;

  return $export;
}
