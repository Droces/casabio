<?php
/**
 * @file
 * Functions that perform queries to find taxonomy terms.
 */

/**
 * CONTENTS

  is_taxon_in_casabio()
  get_taxa()
  get_taxa_with_name()
  get_taxon_locations()
 */


function is_taxon_in_casabio($sc_name) {
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', 'taxa')
    // ->propertyCondition('status', NODE_PUBLISHED)
    ->propertyCondition('name', $sc_name, 'like')
    ->range(0, 1);

  $result = $query->execute();
  // dpm($result, '$result');

  return (empty($result) === FALSE);
}


/**
 * @param int $results_limit
 *   (optional) Maximum number of results that should be fetched. If NULL, there will be no maximum.
 * @param string[] $required_fields
 *   (optional) Names of fields that must have a value. Cannot be used for reference fields.
 */
function get_taxa($results_limit = 1000, $required_fields = []) {
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', 'taxa')
    // ->propertyCondition('status', NODE_PUBLISHED)
    // ->propertyCondition('name', $sc_name, 'like')
  ;

  if ($results_limit) {
    $query->range(0, $results_limit);
  }

  if ($required_fields) {
    foreach ($required_fields as $field_name) {
      // $query->fieldCondition('field_taxon_rank', 'value', $rank, '=');
      $query->fieldCondition($field_name, 'value', 'NULL', 'IS NOT NULL');
    }
  }

  $result = $query->execute();
  // dpm($result, '$result');

  if (! isset($result['taxonomy_term'])) {
    return NULL;
  }
  return $result['taxonomy_term'];
}


/**
 * Finds taxa that have a name containing the text specified.
 *
 * @param string $match_type
 *   Either 'is' or 'contains'.
 * @param string[] $required_empty_fields
 *   (optional) Names of fields that must not have a value. Cannot be used for reference fields.
 */
function get_taxa_with_name($name, $match_type, $rank = NULL, $results_limit = 1000, $required_empty_fields = []) {
  // dpm($name, '$name');
  // dpm($match_type, '$match_type');
  // dpm($rank, '$rank');

  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', 'taxa')
    // ->propertyCondition('status', NODE_PUBLISHED)
  ;

  switch($match_type) {
    case 'is':
      $query->propertyCondition('name', $name, 'LIKE');
      break;

    case 'contains':
    default:
      // dpm('switch contains');
      $query->propertyCondition('name', '%' . $name . '%', 'LIKE');
      break;
  }

  if ($results_limit) {
    $query->range(0, $results_limit);
  }

  if ($rank) {
    $query->fieldCondition('field_taxon_rank', 'value', $rank, '=');
  }

  if ($required_empty_fields) {
    foreach ($required_empty_fields as $field_name) {
      // $query->fieldCondition('field_taxon_rank', 'value', $rank, '=');
      $query->fieldCondition($field_name, 'value', 'IS NULL');
    }
  }

  $result = $query->execute();

  if (! isset($result['taxonomy_term'])) {
    return [];
  }
  // dpm($result, '$result');
  return $result['taxonomy_term'];
}


/**
 * Finds taxa that have a name containing the text specified.
 *
 * @param string $match_type
 *   Either 'is' or 'contains'.
 */
function get_taxa_with_sci_name($sci_name, $match_type, $results_limit = 1000) {
  // dpm($name, '$name');
  // dpm($match_type, '$match_type');
  // dpm($rank, '$rank');

  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', 'taxa')
    ->fieldCondition('field_scientific_name', 'value', $sci_name, '=')
    // ->propertyCondition('status', NODE_PUBLISHED)
  ;

  if ($results_limit) {
    $query->range(0, $results_limit);
  }

  $result = $query->execute();

  if (! isset($result['taxonomy_term'])) {
    return [];
  }
  // dpm($result, '$result');
  return $result['taxonomy_term'];
}



/**
 * Finds taxa that are missing a value of a given field.
 *
 * @param string $match_type
 *   Either 'is' or 'contains'.
 */
function get_taxa_missing_field_info($field_name, $field_value_label, $results_limit = 100) {
  // dpm($match_type, '$match_type');

  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', 'taxa')
    // ->propertyCondition('status', NODE_PUBLISHED)
    ->range(0, $results_limit)
    ->addTag('condition_field_value_null')
    ->addTag('random')
    ->addMetaData('field_name', $field_name)
    ->addMetaData('field_value_label', $field_value_label)
  ;

  $result = $query->execute();
  // dpm($result, '$result');

  if (! isset($result['taxonomy_term'])) {
    return [];
  }
  return $result['taxonomy_term'];
}




/**
 * Gets taxa that don't have any pictures (not including main picture)
 */
function get_taxa_without_pictures($results_limit = 1000) {
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', 'taxa')
    // ->fieldCondition('field_pictures', 'target_id', 'NULL', '=')
    ->addTag('has_no_pictures')
    ->addTag('random')
    ->range(0, $results_limit);

  $result = $query->execute();
  // dpm($result, '$result');

  if (! isset($result['taxonomy_term'])) {
    return NULL;
  }
  return $result['taxonomy_term'];
}




/**
 * Gets the locations of all identifications of a taxon.
 *
 * @param $results_limit
 *   The maximum number of results to fetch
 *
 * @return
 *   An array of longitudes and latitudes.
 */
function get_taxon_locations($tid, $results_limit) {

  $view_name = 'data_taxon_observations_locations';
  $display_id = 'feed';
  $geoJSON = views_embed_view($view_name, $display_id, $tid);
  // dpm($geoJSON, '$geoJSON');

  return json_decode($geoJSON);
}


/**
 * @param int $results_limit
 *   (optional) Maximum number of results that should be fetched. If NULL, there will be no maximum.
 */
function get_taxa_without_history($results_limit = 10) {
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', 'taxa')
    ->addTag('condition_field_value_null')
    ->addMetaData('field_name', 'field_history')
    ->addMetaData('field_value_label', 'value')
  ;

  if (isset($results_limit)) {
    $query->range(0, $results_limit);
  }

  $result = $query->execute();
  // dpm($result, '$result');

  if (! isset($result['taxonomy_term'])) {
    return NULL;
  }
  return $result['taxonomy_term'];
}


/**
 * @param int $results_limit
 *   (optional) Maximum number of results that should be fetched. If NULL, there will be no maximum.
 */
function get_taxa_without_sc_name($results_limit = 10) {
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', 'taxa')
    ->addTag('condition_field_value_null')
    ->addMetaData('field_name', 'field_scientific_name')
    ->addMetaData('field_value_label', 'value')
  ;

  if (isset($results_limit)) {
    $query->range(0, $results_limit);
  }

  $query->fieldCondition('field_history', 'value', ['Updated scientific name'], 'NOT IN');

  $result = $query->execute();
  // dpm($result, '$result');

  if (! isset($result['taxonomy_term'])) {
    return NULL;
  }
  return $result['taxonomy_term'];
}