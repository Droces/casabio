<?php
/**
 * @file
 * content_type_collection.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_collection_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_collection_node_info() {
  $items = array(
    'collection' => array(
      'name' => t('Collection'),
      'base' => 'node_content',
      'description' => t('A group of pictures. Simply helps the contributor see his / her pictures together.'),
      'has_title' => '1',
      'title_label' => t('Title of collection'),
      'help' => t('Create a collection of pictures by uploading the photographs of your observations. On the following pages, you\'ll be able to add information about the pictures and your observations.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
