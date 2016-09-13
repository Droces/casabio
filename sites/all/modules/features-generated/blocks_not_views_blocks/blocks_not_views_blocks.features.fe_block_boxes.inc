<?php
/**
 * @file
 * blocks_not_views_blocks.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function blocks_not_views_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Maintainer contribution options';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'maintainer_contribution_options';
  $fe_block_boxes->body = '<p><a href="taxa/lookup-multiple">Add multiple taxa</a></p>';

  $export['maintainer_contribution_options'] = $fe_block_boxes;

  return $export;
}
