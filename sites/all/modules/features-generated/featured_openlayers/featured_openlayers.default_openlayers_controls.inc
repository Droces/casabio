<?php
/**
 * @file
 * featured_openlayers.default_openlayers_controls.inc
 */

/**
 * Implements hook_default_openlayers_controls().
 */
function featured_openlayers_default_openlayers_controls() {
  $export = array();

  $ol_control = new stdClass();
  $ol_control->disabled = FALSE; /* Edit this to true to make a default ol_control disabled initially */
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'control_geofield_toolbar_area__path';
  $ol_control->name = 'Geofield toolbar: area or path';
  $ol_control->description = '';
  $ol_control->factory_service = 'openlayers.Control:Geofield';
  $ol_control->options = array(
    'draw' => array(
      'Point' => 'Point',
      'LineString' => 'LineString',
      'Polygon' => 'Polygon',
      'MultiPoint' => 0,
      'MultiLineString' => 0,
      'MultiPolygon' => 0,
      'Triangle' => 0,
      'Square' => 0,
      'Circle' => 0,
      'Box' => 0,
    ),
    'actions' => array(
      'Edit' => 'Edit',
      'Move' => 'Move',
      'Clear' => 0,
    ),
    'options' => array(
      'Snap' => 0,
    ),
  );
  $export['control_geofield_toolbar_area__path'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->disabled = FALSE; /* Edit this to true to make a default ol_control disabled initially */
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'geofield_toolbar_single_point';
  $ol_control->name = 'Geofield toolbar: single point';
  $ol_control->description = '';
  $ol_control->factory_service = 'openlayers.Control:Geofield';
  $ol_control->options = array(
    'draw' => array(
      'Point' => 'Point',
      'MultiPoint' => 0,
      'LineString' => 0,
      'MultiLineString' => 0,
      'Polygon' => 0,
      'MultiPolygon' => 0,
      'Triangle' => 0,
      'Square' => 0,
      'Circle' => 0,
      'Box' => 0,
    ),
    'actions' => array(
      'Edit' => 'Edit',
      'Move' => 'Move',
      'Clear' => 0,
    ),
    'options' => array(
      'Snap' => 0,
    ),
  );
  $export['geofield_toolbar_single_point'] = $ol_control;

  return $export;
}
