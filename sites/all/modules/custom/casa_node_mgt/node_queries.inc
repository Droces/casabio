<?php
/**
 * @file
 * Summary for the file...
 */

/**
 * CONTENTS

  get_referencing_nodes
  get_identifications_refing_observation
  get_identifications_by_user
  get_comm_id_refing_identification
  get_observations_with_localities
  get_observation_referencing_pic
  get_observations_referencing_collection
  get_referencings_count
 */


// namespace Drupal\casa_node_management\node_queries;

/**
 * Gets the nids of all nodes that reference the specified node.
 */
function get_referencing_nodes($type = NULL,
  $field1, $column1, $nid1,
  $field2 = NULL, $column2 = NULL, $nid2 = NULL) {

  // Get first node of this type to use, using EntityFieldQuery
  $query = new EntityFieldQuery();
  $query -> entityCondition('entity_type', 'node')
    ->fieldCondition($field1, $column1, $nid1, '=')
    // ->fieldOrderBy('field_date_taken', 'value', 'ASC')
    -> range(0, 5000) // Return up to 5000 results; more will slow down the system
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;

  if ($type) {
    $query -> entityCondition('bundle', $type);
  }

  if ($field2) {
    $query -> fieldCondition($field2, $column2, $nid2, '=');
  }

  $result = $query -> execute();

  if (isset($result['node'])) {
    return $result['node'];
  }
  else {
    return [];
  }

}





/**
 * A specialised EntityFieldQuery function.
 * Gets the identifications or community identifications that reference the
 * observation specified by the provided nid.
 *
 * @param $type
 *   The content type to get. Either 'identification' (default) or 'identification_community'.
 * @param $nid
 *   The nid of the observation that the identifications must reference.
 * @param $tid
 *   Optional. The tid of the taxon that the identifications must also reference.
 * @param $uid
 *   Optional. The UID of the user that created the identification.
 */
function get_identifications_refing_observation($type = 'identification', $nid, $tid = NULL, $uid = NULL) {

  if ($type != 'identification' && $type != 'identification_community') {
    throw new InvalidArgumentException("Param \$type not valid.", 1);
  }
  if (!(int) $nid > 0) {
    throw new InvalidArgumentException("Param \$nid not valid.", 1);
  }

  $field1 = 'field_observation';
  $column1 = 'target_id';

  // Get first node of this type to use, using EntityFieldQuery
  $query = new EntityFieldQuery();
  $query
    -> entityCondition('entity_type', 'node')
    -> entityCondition('bundle', $type)
    -> fieldCondition($field1, $column1, $nid, '=')
    -> range(0, 100) // Return up to 100 results (there should never be that many).
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;

  if ($type == 'identification') {
    $query -> fieldOrderBy('field_certainty', 'value', 'DESC');
  }
  else {
    $query -> fieldOrderBy('field_reliability', 'value', 'DESC');
  }

  if ($tid) {
    $field2 = 'field_identified_species';
    $column2 = 'tid';

    $query -> fieldCondition($field2, $column2, $tid, '=');
  }

  if ($uid) {
    $query -> propertyCondition('uid', $uid);
  }

  $result = $query -> execute();

  if (isset($result['node'])) {
    return $result['node'];
  }
  else {
    return [];
  }
}



function get_identifications_by_user($uid, $limit) {
  $field = 'field_pictures_observation';
  $column = 'target_id';

  $query = new EntityFieldQuery();
  $query
    -> entityCondition('entity_type', 'node')
    -> entityCondition('bundle', 'identification')
    -> propertyCondition('uid', $uid)
    -> propertyOrderBy('created', 'DESC') // Most recent first
    -> range(0, $limit)
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;
  $result = $query -> execute();

  if (isset($result['node'])) {
    return $result['node'];
  }
  else {
    return [];
  }
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
    -> entityCondition('entity_type', 'node')
    -> entityCondition('bundle', 'identification_community')
    -> fieldCondition('field_identifications', 'target_id', $nid, '=')
    -> range(0, 1) // Return up to 100 results (there should never be that many).
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;

  $result = $query -> execute();

  if (isset($result['node'])) {
    return reset($result['node']); // Return first (and only) resulting node.
  }
  else {
    return [];
  }
}



/**
 * A specialised EntityFieldQuery function.
 * Gets the observation (there should be only one) that references the picture
 * specified by the provided nid.
 */
function get_observations_with_localities($range_max) {

  $field = 'field_locality';
  $column = 'tid';

  $query = new EntityFieldQuery();
  $query
    -> entityCondition('entity_type', 'node')
    -> entityCondition('bundle', 'observation')
    -> fieldCondition('field_locality', 'tid', 'NULL', 'IS NOT NULL')
    -> range(0, $range_max)
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;
  $result = $query -> execute();

  if (isset($result['node'])) {
    return $result['node'];
  }
  else {
    return [];
  }
}




/**
 * A specialised EntityFieldQuery function.
 * Gets the observation (there should be only one) that references the picture
 * specified by the provided nid.
 */
function get_observation_referencing_pic($pic_nid) {

  $field = 'field_pictures_observation';
  $column = 'target_id';

  $query = new EntityFieldQuery();
  $query
    -> entityCondition('entity_type', 'node')
    -> entityCondition('bundle', 'observation')
    -> fieldCondition($field, $column, $pic_nid, '=')
    -> range(0, 1) // Return 1 result
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;
  $result = $query -> execute();

  if (isset($result['node'])) {
    return reset($result['node']); // Return first (and only) resulting node.
  }
  else {
    return [];
  }
}




/**
 * A specialised EntityFieldQuery function.
 * Gets the observation (there should be only one) that references the picture
 * specified by the provided nid.
 */
function get_observations_referencing_collection($collection_nid) {

  $field = 'field_collection';
  $column = 'target_id';

  $query = new EntityFieldQuery();
  $query
    -> entityCondition('entity_type', 'node')
    -> entityCondition('bundle', 'observation')
    -> fieldCondition($field, $column, $collection_nid, '=')
    -> range(0, 2000) // Return up to 2000 results
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;
  $result = $query -> execute();

  if (isset($result['node'])) {
    return $result['node']; // Return first (and only) resulting node.
  }
  else {
    return [];
  }
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
function get_referencings_count($field, $nid, $bundle = NULL) {

  // $field = 'field_collection';
  $column = 'target_id';

  $query = new EntityFieldQuery();
  $query
    -> entityCondition('entity_type', 'node')
    -> fieldCondition($field, $column, $nid, '=')
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;

  if ($bundle) {
    $query -> entityCondition('bundle', $bundle);
  }

  $count = $query->count()->execute();
  return $count;
}
