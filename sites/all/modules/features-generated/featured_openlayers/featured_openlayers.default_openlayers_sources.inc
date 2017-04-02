<?php
/**
 * @file
 * featured_openlayers.default_openlayers_sources.inc
 */

/**
 * Implements hook_default_openlayers_sources().
 */
function featured_openlayers_default_openlayers_sources() {
  $export = array();

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'google_maps_hybrid';
  $ol_source->name = 'Google Maps: Hybrid';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:GoogleMaps';
  $ol_source->options = array(
    'key' => 'AIzaSyDtaw9SIRHNX_JQsAuhycdwcCuBpenTZOk',
    'mapTypeId' => 'HYBRID',
    'sensor' => 0,
  );
  $export['google_maps_hybrid'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_views_source_collection_observations_map_block_1';
  $ol_source->name = 'Openlayers views source: collection_observations_map:block_1';
  $ol_source->description = 'Source for <a href="/Current/CasaBio/admin/structure/views/view/collection_observations_map/edit/block_1">this</a> views map';
  $ol_source->factory_service = 'openlayers.Source:Views';
  $ol_source->options = array(
    'view' => 'collection_observations_map:block_1',
  );
  $export['openlayers_views_source_collection_observations_map_block_1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'views_geojson_collection_location_data_feed_1';
  $ol_source->name = 'Views GeoJSON: Collection location';
  $ol_source->description = 'This source is automatically generated. See View collection_location_data at display feed_1';
  $ol_source->factory_service = 'openlayers.Source:GeoJSON';
  $ol_source->options = array(
    'url' => 'http://localhost/drupal/CasaBio/contribute/collection/location-data',
  );
  $export['views_geojson_collection_location_data_feed_1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'views_geojson_location_user_latest_collection_feed_1';
  $ol_source->name = 'Views GeoJSON: Location of user’s latest collection';
  $ol_source->description = 'This source is automatically generated. See View location_user_latest_collection at display feed_1';
  $ol_source->factory_service = 'openlayers.Source:GeoJSON';
  $ol_source->options = array(
    'url' => 'map-sources/user-latest-collection',
    'useBBOX' => 0,
    'paramForwarding' => 1,
    'reloadOnZoomChange' => 0,
    'reloadOnExtentChange' => 0,
    'geojson_data' => '',
    'devMode' => 0,
  );
  $export['views_geojson_location_user_latest_collection_feed_1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'views_geojson_pictures_map_feed_1';
  $ol_source->name = 'Views GeoJSON: Browse pictures map';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:GeoJSON';
  $ol_source->options = array(
    'url' => 'browse/pictures/feed.geojson',
    'useBBOX' => 0,
    'paramForwarding' => 1,
    'reloadOnZoomChange' => 0,
    'reloadOnExtentChange' => 0,
    'geojson_data' => '',
    'devMode' => 0,
  );
  $export['views_geojson_pictures_map_feed_1'] = $ol_source;

  return $export;
}
