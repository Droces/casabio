<?php
/**
 * @file
 * content_type_community_identification.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function content_type_community_identification_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_reliability'.
  $field_bases['field_reliability'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_reliability',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'decimal_separator' => '.',
      'precision' => 10,
      'scale' => 7,
    ),
    'translatable' => 0,
    'type' => 'number_decimal',
  );

  return $field_bases;
}
