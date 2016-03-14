<?php
/**
 * @file
 * content_type_observation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_observation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_observation_node_info() {
  $items = array(
    'observation' => array(
      'name' => t('Observation'),
      'base' => 'node_content',
      'description' => t('A sighting of a species at a specific location. One or more pictures of the species can be part of one observation. The observation will be in a locality, though it may be within multiple overlapping (or contained) localities. The observation will also be within one or more habitats.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
