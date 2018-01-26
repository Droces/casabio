<?php
/**
 * @file
 * taxonomy_achievements.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function taxonomy_achievements_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_score_required'.
  $field_bases['field_score_required'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_score_required',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'decimal_separator' => '.',
      'precision' => 10,
      'scale' => 2,
    ),
    'translatable' => 0,
    'type' => 'number_decimal',
  );

  return $field_bases;
}
