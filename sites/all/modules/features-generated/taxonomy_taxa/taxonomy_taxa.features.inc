<?php
/**
 * @file
 * taxonomy_taxa.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function taxonomy_taxa_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
