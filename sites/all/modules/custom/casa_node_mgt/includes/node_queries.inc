<?php
/**
 * @file
 * Summary for the file...
 */

/**
 * CONTENTS

  get_referencing_nodes()
  get_identifications_refing_observation()
  get_identifications_by_user()
  get_comm_id_refing_identification()

  get_observations_with_localities()

  query_nodes_by_user()
  get_nodes_by_user()
  count_nodes_by_user()

  get_observation_referencing_pic()
  get_observations_referencing_collection()
  get_observations_referencing_taxon()

  count_referencings()

  get_collection_locations()
  get_tids_of_vocab()
 */


// namespace Drupal\casa_node_management\node_queries;

/**
 * Gets the nids of all nodes that reference the specified node.
 */
function get_one_entity($type = 'node', $bundle) {

  // Get first node of this type to use, using EntityFieldQuery
  $query = new EntityFieldQuery();
  $query
   ->entityCondition('entity_type', $type)
   ->entityCondition('bundle', $bundle)
   ->range(0, 1) // Fetch just one
   ->addMetaData('account', user_load(1)); // Run the query as user 1.
  ;

  $result = $query->execute();
  // dpm($result, '$result');

  // If there a result, take only the first one.
  $response = isset($result[$type]) ? reset($result[$type]) : [];
  return $response;
}



/**
 * Gets the nids of all nodes that reference the specified node.
 */
function get_referencing_nodes($type = NULL,
  $field1, $column1, $nid1,
  $field2 = NULL, $column2 = NULL, $nid2 = NULL) {

  // Get first node of this type to use, using EntityFieldQuery
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->fieldCondition($field1, $column1, $nid1, '=')
    // ->fieldOrderBy('field_date_taken', 'value', 'ASC')
   ->range(0, 5000) // Return up to 5000 results; more will slow down the system
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;

  if ($type) {
    $query->entityCondition('bundle', $type);
  }

  if ($field2) {
    $query->fieldCondition($field2, $column2, $nid2, '=');
  }

  $result = $query->execute();

  $response = isset($result['node']) ? $result['node'] : [];
  return $response;

}





/**
 * A specialised EntityFieldQuery function.
 * Gets the identifications or community identifications that reference the
 * observation specified by the provided nid.
 *
 * @param $type
 *   String. The content type to get. Either 'identification' (default) or 
 *   'identification_community' or NULL for both.
 * @param $nid
 *   The nid of the observation that the identifications must reference.
 * @param $tid
 *   Optional. The tid of the taxon that the identifications must also reference.
 * @param $uid
 *   Optional. The UID of the user that created the identification.
 */
function get_identifications_refing_observation($type = NULL, $nid, $tid = NULL, $uid = NULL) {
  // dpm($nid, 'in get_identifications_refing_observation(), $nid');

  // if ($type != 'identification' && $type != 'identification_community') {
  //   throw new InvalidArgumentException("Param \$type not valid.", 1);
  // }

  if (! is_valid_eid($nid)) {
    throw new InvalidArgumentException("Parameter $nid, " . $nid . ", needs to be a valid NID.", 1);
  }

  $field1 = 'field_observation';
  $column1 = 'target_id';

  // Get first node of this type to use, using EntityFieldQuery
  $query = new EntityFieldQuery();
  $query
   ->entityCondition('entity_type', 'node')
   ->fieldCondition($field1, $column1, $nid, '=')
   ->range(0, 100) // Return up to 100 results (there should never be that many).
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;

  // Additional filters

  if ($uid) {
    $query->propertyCondition('uid', $uid);
  }

  if ($type) {
    $query->entityCondition('bundle', $type);
  }
  else {
    $query->entityCondition('bundle', array('identification', 'identification_community'), 'IN');
  }

  if ($tid) {
    $field2 = 'field_identified_species';
    $column2 = 'tid';

    $query->fieldCondition($field2, $column2, $tid, '=');
  }

  // Sorting

  if ($type === 'identification') {
    $query->fieldOrderBy('field_certainty', 'value', 'DESC');
  }
  else if ($type === 'identification_community') {
    $query->fieldOrderBy('field_reliability', 'value', 'DESC');
  }

  // Execute and return

  $result = $query->execute();

  $response = isset($result['node']) ? $result['node'] : [];
  return $response;
}



function get_identifications_by_user($uid, $limit) {
  $query = new EntityFieldQuery();
  $query
   ->entityCondition('entity_type', 'node')
   ->entityCondition('bundle', 'identification')
   ->propertyCondition('uid', $uid)
   ->propertyOrderBy('created', 'DESC') // Most recent first
   ->range(0, $limit)
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;
  $result = $query->execute();

  $response = isset($result['node']) ? $result['node'] : [];
  return $response;
}



function get_first_identifications_of_taxon($tid, $limit = 1) {
  $query = new EntityFieldQuery();
  $query
   ->entityCondition('entity_type', 'node')
   ->entityCondition('bundle', 'identification')
   ->fieldCondition('field_identified_species', 'tid', $tid, '=')
   // ->propertyCondition('uid', $uid)
   ->propertyOrderBy('created', 'ASC') // Most recent first
   ->range(0, $limit)
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;
  $result = $query->execute();


  $response = isset($result['node']) ? $result['node'] : [];
  return $response;
}





/**
 * A specialised EntityFieldQuery function.
 * Gets the community identification that references an identification.
 *
 * @param $type
 *   The content type to get. Either 'identification' (default) or 'identification_community'.
 * @param $nid
 *   The nid of the observation that the identifications must reference.
 * @param $tid
 *   Optional. The tid of the taxon that the identifications must also reference.
 */
function get_comm_id_refing_identification($nid) {

  // Get first node of this type to use, using EntityFieldQuery
  $query = new EntityFieldQuery();
  $query
   ->entityCondition('entity_type', 'node')
   ->entityCondition('bundle', 'identification_community')
   ->fieldCondition('field_identifications', 'target_id', $nid, '=')
   ->range(0, 1) // Return up to 100 results (there should never be that many).
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;

  $result = $query->execute();

  $response = isset($result['node']) ? reset($result['node']) : []; // Return first (and only) resulting node.
  return $response;
}



/**
 * A specialised EntityFieldQuery function.
 * Gets the observations...
 */
function get_observations_with_localities($range_max) {

  $field = 'field_locality';
  $column = 'tid';

  $query = new EntityFieldQuery();
  $query
   ->entityCondition('entity_type', 'node')
   ->entityCondition('bundle', 'observation')
   ->fieldCondition('field_locality', 'tid', 'NULL', 'IS NOT NULL')
   ->range(0, $range_max)
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;
  $result = $query->execute();

  $response = isset($result['node']) ? $result['node'] : [];
  return $response;
}




/**
 * Builds a query of nodes created by a user.
 *
 * @param $uid
 * @param $type
 *   (optional) The content type that the nodes must be
 * @param $collection_nid
 *   (optional) Collection that the node must be part of.
 * @param $range_max
 *   (optional) Maximum number of observations to fetch.
 * @param string[] $required_fields
 *   (optional) Names of fields that must have a value. Cannot be used for reference fields.
 * @param [][] $field_filters
 *   Array of field filters to apply to the query, in format [[$field_name, $column, $value], ...]
 */
function query_nodes_by_user($uid, $type = NULL, $collection_nid = NULL,
  $range_max = 1000, $required_fields = [], $field_filters = []) {

  if (! is_valid_eid($uid)) {
    throw new InvalidArgumentException("Parameter $uid, " . $uid . ", needs to be a valid UID.", 1);
  }
  if ($collection_nid && ! is_valid_eid($collection_nid)) {
    throw new InvalidArgumentException("Parameter $collection_nid, " . $collection_nid . ", needs to be a valid NID.", 1);
  }

  $query = new EntityFieldQuery();
  $query
   ->propertyCondition('uid', $uid)
   ->entityCondition('entity_type', 'node')
   ->range(0, $range_max)
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;

  if ($type) {
    $query->entityCondition('bundle', $type);
  }

  if ($collection_nid) {
    $query->fieldCondition('field_collection', 'target_id', $collection_nid, '=');
  }

  if ($required_fields) {
    foreach ($required_fields as $field_name) {
      $query->fieldCondition($field_name, 'value', 'NULL', 'IS NOT NULL');
    }
  }

  if ($field_filters) {
    foreach ($field_filters as $key => $filter) {
      $query->fieldCondition($filter[0], $filter[1], $filter[2], '=');
    }
  }

  return $query;
}

/**
 * A specialised EntityFieldQuery function.
 * Gets the observations owned by specified user.
 *
 * @param $uid
 * @param $collection_nid
 *   (optional) Collection that the observation must be part of.
 * @param $range_max
 *   (optional) Maximum number of observations to fetch.
 * @param string[] $required_fields
 *   (optional) Names of fields that must have a value. Cannot be used for reference fields.
 * @param [][] $field_filters
 *   Array of field filters to apply to the query, in format [[$field_name, $column, $value], ...]
 */
function get_nodes_by_user($uid, $type, $collection_nid = NULL, $range_max = 1000, $required_fields = [], $field_filters = []) {
  
  $query = query_nodes_by_user($uid, $type, $collection_nid, $range_max, $required_fields, $field_filters);

  $result = $query->execute();

  $response = isset($result['node']) ? $result['node'] : [];
  return $response;
}

/**
 * A specialised EntityFieldQuery function.
 * Gets the observations owned by specified user.
 *
 * @param $uid
 * @param $collection_nid
 */
function count_nodes_by_user($uid, $type, $collection_nid = NULL) {
  
  $query = query_nodes_by_user($uid, $type, $collection_nid, 1000000);

  $count = $query->count()->execute();
  return $count;
}




/**
 * A specialised EntityFieldQuery function.
 * Gets observations that reference the picture specified by the provided nid.
 */
function get_observations_referencing_pic($pic_nid) {
  // dpm($pic_nid, '$pic_nid');

  $field = 'field_pictures_observation';
  $column = 'target_id';

  $query = new EntityFieldQuery();
  $query
   ->entityCondition('entity_type', 'node')
   ->entityCondition('bundle', 'observation')
   ->fieldCondition($field, $column, $pic_nid, '=')
   ->range(0, 100) // Return at most 100 results
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;
  $result = $query->execute();
  // dpm($result, '$result');

  $response = isset($result['node']) ? $result['node'] : [];
  return $response;
}




/**
 * A specialised EntityFieldQuery function.
 * Gets the observation (there should be only one) that references the picture
 * specified by the provided nid.
 */
function get_observation_referencing_pic($pic_nid) {
  $observation = get_observations_referencing_pic($pic_nid);

  $observation = $observation ? reset($observation) : [];
  return $observation;
}




/**
 * A specialised EntityFieldQuery function.
 * Gets the observations that reference a collection
 * specified by the provided nid.
 */
function get_observations_referencing_collection($collection_nid, $settings = [], $offset = 0, $max_results = 2000) {

  $field = 'field_collection';
  $column = 'target_id';

  $query = new EntityFieldQuery();
  $query
   ->entityCondition('entity_type', 'node')
   ->entityCondition('bundle', 'observation')
   ->fieldCondition($field, $column, $collection_nid, '=')
   ->range($offset, $max_results) // Return up to 2000 results
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;

  if (isset($settings['is_count'])) {
    $query->count();
    $result = $query->execute();
    return $result;
  }

  $result = $query->execute();

  $response = isset($result['node']) ? $result['node'] : [];
  return $response;
}




/**
 * Fetches observations that reference a taxon.
 * 
 * @return
 *   A list of node ids.
 */
function get_observations_referencing_taxon($tid) {
  
  if (! is_valid_eid($tid)) {
    throw new InvalidArgumentException("Parameter $tid, " . $tid . ", needs to be a valid TID.", 1);
  }

  // dpm($tid, '$tid');
  $observations = views_get_view_result('observations_of_taxon', 'default', $tid);
  // dpm($observations, '$observations');
  
  // Convert the node representations to just their nids
  foreach ($observations as $key => $observation_rep) {
    $observations[$key] = $observation_rep->nid;
  }
  return $observations;
}




/**
 * A specialised EntityFieldQuery function.
 * Gets the observations that reference a collection
 * specified by the provided nid.
 */
function get_nodes_referencing_collection($collection_nid, $type = NULL, 
  $settings = [], $offset = 0, $max_results = 2000) {

  $field = 'field_collection';
  $column = 'target_id';

  $query = new EntityFieldQuery();
  $query
   ->entityCondition('entity_type', 'node')
   ->fieldCondition($field, $column, $collection_nid, '=')
   ->range($offset, $max_results) // Return up to 2000 results
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;

  if (isset($settings['is_count'])) {
    $query->count();
    $result = $query->execute();
    return $result;
  }

  if (isset($type)) {
    $query->entityCondition('bundle', $type);
  }

  $result = $query->execute();

  $response = isset($result['node']) ? $result['node'] : [];
  return $response;
}




/**
 * Counts number of entities referencing a particular node.
 *
 * @param $field
 *   Machine name of field used as reference.
 * @param $nid
 *   Nid of the node that the entities must reference
 * @param $bundle
 *   (optional) Bundle of entities that should be counted.
 */
function count_referencings($field, $nid, $bundle = NULL) {

  if (gettype($field) !== 'string') {
    throw new InvalidArgumentException("Parameter $field, " . $field . ", needs to be a string.", 1);
  }
  if (! is_valid_eid($nid)) {
    throw new InvalidArgumentException("Parameter $nid, " . $nid . ", needs to be a valid NID.", 1);
  }

  // $field = 'field_collection';
  $column = 'target_id';

  $query = new EntityFieldQuery();
  $query
   ->entityCondition('entity_type', 'node')
   ->fieldCondition($field, $column, $nid, '=')
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;

  if ($bundle) {
    $query->entityCondition('bundle', $bundle);
  }

  $count = $query->count()->execute();
  return $count;
}




/**
 * Gets the locations of all observations within a collection.
 *
 * @param $results_limit
 *   (optional) The maximum number of results to fetch. Defaults to 1000.
 *
 * @return
 *   An array of longitudes and latitudes.
 */
function get_collection_locations($nid, $results_limit = 1000) {
  if (! is_valid_eid($nid)) {
    throw new InvalidArgumentException("Parameter $nid, " . $nid . ", needs to be a valid NID.", 1);
  }

  $view_name = 'data_collection_observations_locations';
  $display_id = 'feed';
  $geoJSON = views_embed_view($view_name, $display_id, $nid);
  // dpm($geoJSON, '$geoJSON');

  return json_decode($geoJSON);
}



function get_tids_of_vocab($vocabulary) {
  $query = new EntityFieldQuery();
  $result = $query
    ->entityCondition('entity_type', 'taxonomy_term')
    ->propertyCondition('vid', (int) $vocabulary, '=')
    ->execute();

  $response = isset($result['taxonomy_term']) ? $result['taxonomy_term'] : [];
  return $response;
}