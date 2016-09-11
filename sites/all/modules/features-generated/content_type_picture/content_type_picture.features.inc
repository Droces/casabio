<?php
/**
 * @file
 * content_type_picture.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_picture_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_picture_node_info() {
  $items = array(
    'picture' => array(
      'name' => t('Picture'),
      'base' => 'node_content',
      'description' => t('An image of an organism or natural feature including landscapes, habitats and geology. There can be one or more pictures of each subject/organism, and these pictures could be taken in one or more locations.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
