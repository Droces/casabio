<?php
/**
 * @file
 * content_type_community_identification.features.inc
 */

/**
 * Implements hook_node_info().
 */
function content_type_community_identification_node_info() {
  $items = array(
    'identification_community' => array(
      'name' => t('Community identification'),
      'base' => 'node_content',
      'description' => t('The species that an observation might be based on individual identifications of it.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
