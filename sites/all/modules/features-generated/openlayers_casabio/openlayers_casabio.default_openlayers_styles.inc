<?php
/**
 * @file
 * openlayers_casabio.default_openlayers_styles.inc
 */

/**
 * Implements hook_default_openlayers_styles().
 */
function openlayers_casabio_default_openlayers_styles() {
  $export = array();

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default ol_style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'geofield_display';
  $ol_style->name = 'Geofield display';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Circle';
  $ol_style->options = array(
    'default' => array(
      'image' => array(
        'radius' => 5,
        'fill' => array(
          'color' => '51,153,204,0.4',
        ),
        'stroke' => array(
          'color' => '51,153,204,1',
          'width' => 1.25,
          'lineDash' => '0,0',
        ),
      ),
      'stroke' => array(
        'color' => '51,153,204,1',
        'width' => 1.25,
        'lineDash' => '0,0',
      ),
      'fill' => array(
        'color' => '51,153,204,0.4',
      ),
    ),
  );
  $export['geofield_display'] = $ol_style;

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default ol_style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'geofield_edit';
  $ol_style->name = 'Geofield edit';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Circle';
  $ol_style->options = array(
    'default' => array(
      'image' => array(
        'radius' => 5,
        'fill' => array(
          'color' => '100, 100, 100, 0.90',
        ),
        'stroke' => array(
          'color' => '0, 0, 0, 1',
          'width' => 1,
          'lineDash' => '0,0',
        ),
      ),
      'stroke' => array(
        'color' => '0, 0, 0, 1',
        'width' => 2,
        'lineDash' => '2,4',
      ),
      'fill' => array(
        'color' => '100, 100, 100, 0.60',
      ),
    ),
  );
  $export['geofield_edit'] = $ol_style;

  return $export;
}
