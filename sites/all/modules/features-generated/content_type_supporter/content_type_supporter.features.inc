<?php
/**
 * @file
 * content_type_supporter.features.inc
 */

/**
 * Implements hook_node_info().
 */
function content_type_supporter_node_info() {
  $items = array(
    'supporter' => array(
      'name' => t('Supporter'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
