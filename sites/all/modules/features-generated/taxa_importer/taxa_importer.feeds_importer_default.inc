<?php
/**
 * @file
 * taxa_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function taxa_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'taxa_taxonomy_terms_';
  $feeds_importer->config = array(
    'name' => 'Taxa (taxonomy terms)',
    'description' => 'Create taxa (such as species) from an uploaded CSV file.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => 'TAB',
        'no_headers' => 0,
        'encoding' => 'UTF-8',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'name',
            'target' => 'name',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'parent',
            'target' => 'parent',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'rank',
            'target' => 'field_taxon_rank',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'common names',
            'target' => 'field_common_names',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'description',
            'target' => 'description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'etymology',
            'target' => 'field_etymology',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'vulnerability',
            'target' => 'field_vulnerability',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'scientific name',
            'target' => 'field_scientific_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'localities',
            'target' => 'field_localities',
            'term_search' => '1',
            'autocreate' => 0,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'taxa',
        'update_non_existent' => 'skip',
        'insert_new' => 1,
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['taxa_taxonomy_terms_'] = $feeds_importer;

  return $export;
}
