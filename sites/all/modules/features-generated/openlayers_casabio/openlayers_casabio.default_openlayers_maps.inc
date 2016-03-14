<?php
/**
 * @file
 * openlayers_casabio.default_openlayers_maps.inc
 */

/**
 * Implements hook_default_openlayers_maps().
 */
function openlayers_casabio_default_openlayers_maps() {
  $export = array();

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'browse_pictures';
  $ol_map->name = 'Browse pictures';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '450px',
    'provideBlock' => 1,
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
    'renderer' => 'canvas',
    'layers' => array(
      0 => 'openlayers_layer_tile_mapquest_osm',
      1 => 'browse_observations_map',
    ),
    'controls' => array(
      0 => 'openlayers_control_fullscreen',
      1 => 'openlayers_control_zoom',
      2 => 'openlayers_control_zoomslider',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_dragpan',
    ),
    'styles' => array(
      0 => 'openlayers_style_default',
    ),
    'sources' => array(
      0 => 'openlayers_source_mapquest_osm',
    ),
    'components' => array(),
  );
  $export['browse_pictures'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'contribute_mo_collection_geofield_widget';
  $ol_map->name = 'Contribute MO: Collection Geofield widget';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '450px',
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
      'minZoom' => 2,
      'maxZoom' => 19,
    ),
    'layers' => array(
      0 => 'openlayers_geofield_layer_widget',
      1 => 'googlemaps_hybrid_layer',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_pinchzoom',
    ),
    'components' => array(
      0 => 'component_geofield_widget_area_path',
    ),
    'sources' => array(
      0 => 'openlayers_source_mapquest_osm',
    ),
    'controls' => array(
      0 => 'openlayers_control_fullscreen',
      1 => 'openlayers_control_zoom',
      2 => 'openlayers_control_zoomslider',
      3 => 'control_geofield_toolbar_area__path',
    ),
    'styles' => array(
      0 => 'openlayers_style_default',
    ),
    'renderer' => 'canvas',
    'provideBlockLayerSwitcher' => 0,
  );
  $export['contribute_mo_collection_geofield_widget'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'contribute_mo_observation_geofield_widget';
  $ol_map->name = 'Contribute MO: Observation geofield widget';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '450px',
    'provideBlock' => 0,
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => 0,
      'zoom' => 2,
      'minZoom' => 2,
      'maxZoom' => 19,
    ),
    'renderer' => 'canvas',
    'layers' => array(
      0 => 'geofield_field_formatter_layer',
      1 => 'googlemaps_hybrid_layer',
    ),
    'controls' => array(
      0 => 'geofield_toolbar_single_point',
      1 => 'openlayers_control_fullscreen',
      2 => 'openlayers_control_zoom',
      3 => 'openlayers_control_zoomslider',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_pinchzoom',
    ),
    'components' => array(
      0 => 'geofield_widget_component_single_point',
    ),
  );
  $export['contribute_mo_observation_geofield_widget'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'geofield_field_widget_single_point';
  $ol_map->name = 'Geofield field widget for a single point';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 0,
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
      0 => 'geofield_field_formatter_layer',
      1 => 'google_maps_satellite',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_dragpan',
      1 => 'openlayers_interaction_doubleclickzoom',
    ),
    'components' => array(
      0 => 'openlayers_geofield_component_geofield_formatter',
      1 => 'openlayers_geofield_component_zoom_to_source',
    ),
    'sources' => array(
      0 => 'openlayers_source_mapquest_osm',
    ),
    'renderer' => 'canvas',
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_zoomslider',
    ),
    'styles' => array(
      0 => 'openlayers_style_default',
    ),
  );
  $export['geofield_field_widget_single_point'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'map_browse_observations';
  $ol_map->name = 'Browse observations';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '450px',
    'provideBlock' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
      'minZoom' => '0',
      'maxZoom' => '0',
      'limit_extent' => 0,
      'extent' => '-266.484375, -57.326521225217085, 29664904.929363765, 7827151.696402048',
    ),
    'renderer' => 'canvas',
    'layers' => array(
      0 => 'openlayers_layer_tile_mapquest_osm',
      1 => 'browse_observations_map',
    ),
    'controls' => array(
      0 => 'openlayers_control_fullscreen',
      1 => 'openlayers_control_scaleline',
      2 => 'openlayers_control_zoom',
      3 => 'openlayers_control_zoomslider',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_dragpan',
      1 => 'openlayers_interaction_pinchzoom',
    ),
    'styles' => array(
      0 => 'openlayers_style_default',
    ),
    'sources' => array(
      0 => 'openlayers_source_mapquest_osm',
    ),
    'components' => array(
      0 => 'browse_observations_zoom_to_data',
    ),
    'provideBlockLayerSwitcher' => 0,
  );
  $export['map_browse_observations'] = $ol_map;

  return $export;
}
