<?php
/**
 * @file
 * text_format_raw_html.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function text_format_raw_html_filter_default_formats() {
  $formats = array();

  // Exported format: Raw HTML.
  $formats['raw_html'] = array(
    'format' => 'raw_html',
    'name' => 'Raw HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'filters' => array(
      'media_filter' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => 50,
        'status' => 1,
        'settings' => array(
          'local_paths' => '',
          'protocol_style' => 'full',
        ),
      ),
    ),
  );

  return $formats;
}
