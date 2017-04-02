<?php
/**
 * @file
 * featured_openlayers.default_openlayers_components.inc
 */

/**
 * Implements hook_default_openlayers_components().
 */
function featured_openlayers_default_openlayers_components() {
  $export = array();

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'browse_observations_zoom_to_data';
  $ol_component->name = 'Browse observations  Zoom to data';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:ZoomToSource';
  $ol_component->options = array(
    'source' => 'views_geojson_browse_observations_map_feed_1',
    'zoom' => 'auto',
    'max_zoom' => '17',
    'process_once' => 0,
    'enableAnimations' => 1,
    'animations' => array(
      'pan' => '500',
      'zoom' => '500',
    ),
  );
  $export['browse_observations_zoom_to_data'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'browse_pictures_zoom_to_data';
  $ol_component->name = 'Browse pictures Zoom to data';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:ZoomToSource';
  $ol_component->options = array(
    'source' => 'views_geojson_pictures_map_feed_1',
    'zoom' => 'auto',
    'max_zoom' => 17,
    'process_once' => 0,
    'enableAnimations' => 1,
    'animations' => array(
      'pan' => 500,
      'zoom' => 500,
    ),
  );
  $export['browse_pictures_zoom_to_data'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'component_geofield_widget_area_path';
  $ol_component->name = 'Geofield: Widget component: area or path';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:GeofieldWidget';
  $ol_component->options = array(
    'featureLimit' => 0,
    'showInputField' => 0,
    'inputFieldName' => 'geom',
    'dataProjection' => 'EPSG:4326',
    'editStyle' => 'geofield_edit',
    'editLayer' => 'openlayers_geofield_layer_widget',
    'editControl' => 'control_geofield_toolbar_area__path',
    'dataType' => array(
      'GeoJSON' => 'GeoJSON',
      'KML' => 0,
      'GPX' => 0,
      'WKT' => 0,
    ),
  );
  $export['component_geofield_widget_area_path'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'geofield_single_point';
  $ol_component->name = 'Geofield for a single point';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Geofield';
  $ol_component->options = array(
    'dataType' => array(
      'GeoJSON' => 'GeoJSON',
      'KML' => 0,
      'GPX' => 0,
      'WKT' => 0,
    ),
    'actionFeature' => array(
      'draw' => 'draw',
      'modify' => 'modify',
    ),
    'typeOfFeature' => array(
      'Point' => 'Point',
      'LineString' => 0,
      'Polygon' => 0,
    ),
    'featureLimit' => '1',
    'showInputField' => 0,
    'inputFieldName' => 'geom',
    'initialData' => '',
    'dataProjection' => 'EPSG:4326',
  );
  $export['geofield_single_point'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'geofield_widget_component_single_point';
  $ol_component->name = 'Geofield widget component: single point';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:GeofieldWidget';
  $ol_component->options = array(
    'featureLimit' => 0,
    'showInputField' => 0,
    'inputFieldName' => 'geom',
    'dataProjection' => 'EPSG:4326',
    'editStyle' => 'geofield_edit',
    'editLayer' => 'openlayers_geofield_layer_widget',
    'editControl' => 'geofield_toolbar_single_point',
    'dataType' => array(
      'GeoJSON' => 'GeoJSON',
      'KML' => 0,
      'GPX' => 0,
      'WKT' => 0,
    ),
  );
  $export['geofield_widget_component_single_point'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'zoom_user_latest_collection';
  $ol_component->name = 'Zoom to User\'s Latest Collection';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:ZoomToSource';
  $ol_component->options = array(
    'source' => 'user_latest_collection',
    'zoom' => 'auto',
    'max_zoom' => 17,
    'process_once' => 0,
    'enableAnimations' => 1,
    'animations' => array(
      'pan' => 500,
      'zoom' => 500,
    ),
  );
  $export['zoom_user_latest_collection'] = $ol_component;

  return $export;
}
