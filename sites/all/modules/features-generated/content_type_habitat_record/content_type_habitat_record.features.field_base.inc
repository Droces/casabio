<?php
/**
 * @file
 * content_type_habitat_record.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function content_type_habitat_record_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_aspect'.
  $field_bases['field_aspect'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_aspect',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'E' => 'East',
        'ENE' => 'East-northeast',
        'ESE' => 'East-southeast',
        'N' => 'North',
        'NE' => 'Northeast',
        'NNE' => 'North-northeast',
        'NNW' => 'North-northwest',
        'NW' => 'Northwest',
        'S' => 'South',
        'SE' => 'Southeast',
        'SSE' => 'South-southeast',
        'SSW' => 'South-southwest',
        'SW' => 'Southwest',
        'W' => 'West',
        'WNW' => 'West-northwest',
        'WSW' => 'West-southwest',
        'neutral' => 'Neutral',
        'unknown' => 'Unknown',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_slope'.
  $field_bases['field_slope'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_slope',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'gentle' => 'Gentle',
        'moderate' => 'Moderate',
        'steep' => 'Steep',
        'vertical' => 'Vertical',
        'variable' => 'Variable',
        'flat' => 'Flat',
        'unknown' => 'Unknown',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
