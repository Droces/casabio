<?php
/**
 * @file
 * content_type_habitat_record.features.inc
 */

/**
 * Implements hook_node_info().
 */
function content_type_habitat_record_node_info() {
  $items = array(
    'habitat_record' => array(
      'name' => t('Habitat record'),
      'base' => 'node_content',
      'description' => t('A location at which a habitat was seen and recorded.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
