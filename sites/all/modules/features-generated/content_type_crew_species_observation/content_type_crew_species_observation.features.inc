<?php
/**
 * @file
 * content_type_crew_species_observation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_crew_species_observation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_crew_species_observation_node_info() {
  $items = array(
    'crew_species_observation' => array(
      'name' => t('CREW species observation'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
