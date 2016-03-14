<?php
/**
 * @file
 * openlayers_casabio.default_openlayers_sources.inc
 */

/**
 * Implements hook_default_openlayers_sources().
 */
function openlayers_casabio_default_openlayers_sources() {
  $export = array();

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'google_hybrid';
  $ol_source->name = 'Google Maps: Hybrid';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:GoogleMaps';
  $ol_source->options = array(
    'mapTypeId' => 'HYBRID',
    'sensor' => 0,
  );
  $export['google_hybrid'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'googlemaps_hybrid';
  $ol_source->name = 'Google Maps: hybrid';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:GoogleMaps';
  $ol_source->options = array(
    'key' => '',
    'client' => '',
    'channel' => '',
    'mapTypeId' => 'HYBRID',
    'sensor' => 0,
  );
  $export['googlemaps_hybrid'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_googlemaps';
  $ol_source->name = 'Openlayers examples: Google Maps';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:GoogleMaps';
  $ol_source->options = array(
    'key' => '',
    'client' => '',
    'channel' => '',
    'mapTypeId' => 'HYBRID',
    'sensor' => 0,
  );
  $export['openlayers_examples_source_googlemaps'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'test_openstreetmap';
  $ol_source->name = 'Test OpenStreetMap';
  $ol_source->description = 'Source OpenStreetMap description';
  $ol_source->factory_service = 'openlayers.Source:OSM';
  $ol_source->options = array();
  $export['test_openstreetmap'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'user_latest_collection';
  $ol_source->name = 'User\'s latest collection';
  $ol_source->description = '';
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
  $export['user_latest_collection'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'views_geojson_browse_observations_map_feed_1';
  $ol_source->name = 'Views GeoJSON: Browse observations map';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:GeoJSON';
  $ol_source->options = array(
    'url' => 'browse/observations/feed.geojson',
    'useBBOX' => 0,
    'paramForwarding' => 1,
    'reloadOnZoomChange' => 0,
    'reloadOnExtentChange' => 0,
    'geojson_data' => '',
    'devMode' => 0,
  );
  $export['views_geojson_browse_observations_map_feed_1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'views_geojson_clone_of_browse_observations_map_feed_1';
  $ol_source->name = 'Views GeoJSON source: clone_of_browse_observations_map_feed_1';
  $ol_source->description = 'This source is automatically generated. See View clone_of_browse_observations_map at display feed_1';
  $ol_source->factory_service = 'openlayers.Source:GeoJSON';
  $ol_source->options = array(
    'url' => 'http://localhost/Current/CasaBio/browse/observations/feed.geojson',
  );
  $export['views_geojson_clone_of_browse_observations_map_feed_1'] = $ol_source;

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
