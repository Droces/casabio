<?php
/**
 * @file
 * Casa Habitat Management code, which provides functions that manage habitats.
 */



/**
 * The hook_block_info is done in the .module file.
 * The hook_block_view is also done in the .module file.
 */



// =============================================================================
/**
 * Description
 */
function habitat_form_block_view() {

  $content = "";

  $entity_type = 'node';
  $entity_bundle_key =  'type';
  $bundle = 'habitat_record';

  $node = entity_create($entity_type, array(
    $entity_bundle_key => $bundle,
  ));

  module_load_include('inc', 'node', 'node.pages');
  $content = drupal_get_form($bundle . '_node_form', $node, 'contribute');

  return $content;
}
