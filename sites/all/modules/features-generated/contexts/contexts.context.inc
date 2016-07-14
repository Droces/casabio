<?php
/**
 * @file
 * contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'section_browse';
  $context->description = 'All pages within the Browse section of CasaBio';
  $context->tag = 'site section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'browse/*' => 'browse/*',
        'node/*' => 'node/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:node/11',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages within the Browse section of CasaBio');
  t('site section');
  $export['section_browse'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'section_contribute_mo';
  $context->description = 'All pages within the Contribute MO section of CasaBio';
  $context->tag = 'site section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'contribute/upload' => 'contribute/upload',
        'contribute/multiple-observations/*' => 'contribute/multiple-observations/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'menu-contribute:contribute/upload',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages within the Contribute MO section of CasaBio');
  t('site section');
  $export['section_contribute_mo'] = $context;

  return $export;
}
