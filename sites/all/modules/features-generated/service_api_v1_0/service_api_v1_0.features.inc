<?php
/**
 * @file
 * service_api_v1_0.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function service_api_v1_0_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}
