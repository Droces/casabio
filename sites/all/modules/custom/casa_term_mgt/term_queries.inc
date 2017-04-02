<?php
/**
 * @file
 *   Casa Taxa Management Module
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


function get_taxa($results_limit = 1000) {
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', 'taxa')
    // ->propertyCondition('status', NODE_PUBLISHED)
    // ->propertyCondition('name', $sc_name, 'like')
    ->range(0, $results_limit);

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
 */
function get_taxa_with_name($name, $match_type) {
  // dpm($match_type, '$match_type');

  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', 'taxa')
    // ->propertyCondition('status', NODE_PUBLISHED)
    ->range(0, 50);

  switch($match_type) {
    case 'is':
      $query->propertyCondition('name', $name, '=');
      break;

    case 'contains':
    default:
      // dpm('switch contains');
      $query->propertyCondition('name', '%' . $name . '%', 'LIKE');
      break;
  }

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
