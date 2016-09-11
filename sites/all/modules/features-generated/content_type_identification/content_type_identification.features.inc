<?php
/**
 * @file
 * content_type_identification.features.inc
 */

/**
 * Implements hook_node_info().
 */
function content_type_identification_node_info() {
  $items = array(
    'identification' => array(
      'name' => t('Identification'),
      'base' => 'node_content',
      'description' => t('Contributor’s guess of the species that an observation might be.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
