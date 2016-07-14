<?php
/**
 * @file
 * content_type_interaction.features.inc
 */

/**
 * Implements hook_node_info().
 */
function content_type_interaction_node_info() {
  $items = array(
    'interaction' => array(
      'name' => t('Interaction'),
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
