<?php
/**
 * @file
 * Description…
 */



// =======================================================================================
/**
 * Implements hook_services_resources().
 */
function _other_node_resources_definition() {
  $other_node_resources_file = array(
    'type' => 'inc',
    'module' => 'casa_services',
    'name' => 'resources/other_node_resources',
  );

  // module_load_include('inc', 'casa_services', 'resources/resources_arguments');

  // --------------------------------------------------------------------------
  //                                                   Arguments

  // Arguments that can be re-used within the resource definitions.
  $node_operation_args = array(
    'nid' => array(
      'name' => 'nid',
      'optional' => FALSE,
      'source' => array('path' => 0),
      'type' => 'int',
      'description' => 'The nid of the node to get',
    ),
    'node' => array(
      'name' => 'node',
      'optional' => FALSE,
      'source' => 'data',
      'description' => 'The node data to create',
      'type' => 'array',
    ),
    'page' => array(
      'name' => 'page',
      'optional' => TRUE,
      'type' => 'int',
      'description' => 'The zero-based index of the page to get, defaults to 0.',
      'default value' => 0,
      'source' => array('param' => 'page'),
    ),
    'fields' => array(
      'name' => 'fields',
      'optional' => TRUE,
      'type' => 'string',
      'description' => 'The fields to get.',
      'default value' => '*',
      'source' => array('param' => 'fields'),
    ),
    'parameters' => array(
      'name' => 'parameters',
      'optional' => TRUE,
      'type' => 'array',
      'description' => 'Parameters array',
      'default value' => array(),
      'source' => array('param' => 'parameters'),
    ),
    'pagesize' => array(
      'name' => 'pagesize',
      'optional' => TRUE,
      'type' => 'int',
      'description' => 'Number of records to get per page.',
      'default value' => variable_get('services_node_index_page_size', 20),
      'source' => array('param' => 'pagesize'),
    ),
    'options' => array(
      'name' => 'options',
      'optional' => TRUE,
      'type' => 'array',
      'description' => 'Additional query options.',
      'default value' => array(
        'orderby' => array(
          'sticky' => 'DESC',
          'created' => 'DESC'
        )
      ),
      'source' => array('param' => 'options'),
    ),
  );



  $other_node_resources = array(

    // ========================================================================
    //                                                   Collections
    'collections' => array(
      'operations' => array(

        // --------------------------------------------- GET
        'retrieve' => array(
          'file' => $other_node_resources_file,
          'callback' => '_collections_resource_retrieve',
          'args' => array(
            $node_operation_args['nid'],
          ),
          'access callback' => '_node_resource_access',
          'access arguments' => array('view'),
          'access arguments append' => TRUE,
        ),

        // --------------------------------------------- List
        'index' => array(
          'file' => $other_node_resources_file,
          'callback' => '_collections_resource_index',
          'args' => array(
            $node_operation_args['page'],
            $node_operation_args['fields'],
            $node_operation_args['parameters'],
            $node_operation_args['pagesize'],
            $node_operation_args['options'],
          ),
          'access arguments' => array('access content'),
        ),

      ),
      'relationships' => array(
        'observations' => array(
          'help' => "View a list of a collection's observations",
          'file' => $other_node_resources_file,
          'callback' => '_collections_resource_observations',
          'access callback' => '_node_resource_access',
          'access arguments' => array('view'),
          'access arguments append' => TRUE,
          'args' => array(
            array(
              'name' => 'nid',
              'optional' => FALSE,
              'source' => array('path' => 0),
              'type' => 'int',
              'description' => "The nid of the collection whose observations you'd like a list of",
            ),
          ),
        ),
      ),
    ),


    // ========================================================================
    //                                                   Identifications
    'identifications' => array(
      'operations' => array(

        // --------------------------------------------- GET
        'retrieve' => array(
          'file' => $other_node_resources_file,
          'callback' => '_identifications_resource_retrieve',
          'args' => array(
            $node_operation_args['nid'],
          ),
          'access callback' => '_node_resource_access',
          'access arguments' => array('view'),
          'access arguments append' => TRUE,
        ),

        // --------------------------------------------- POST
        'create' => array(
          'file' => $other_node_resources_file,
          'callback' => '_identifications_resource_create',
          'args' => array(
            $node_operation_args['node'],
          ),
          'access callback' => '_node_resource_access',
          'access arguments' => array('create'),
          'access arguments append' => TRUE,
        ),

      ),
    ),
  );

  return $other_node_resources;
}





/**
 * Checks that param $nid is the nid of a collection; if it is, then calls _node_resource_retrieve().
 *
 * @see _node_resource_retrieve()
 */
function _collections_resource_retrieve($nid) {

  $node = node_load($nid);

  // If the node isn't an observation
  if($node->type != 'collection') {
    services_error("Node " . $nid . " is not a collection.", 406); // 406: Not Acceptable
    return FALSE;
  }

  module_load_include('inc', 'services', 'resources/node_resource');
  $node = _node_resource_retrieve($nid);

  return $node;
}



/**
 * Sets param $parameters['type'] = 'collection'; then calls _node_resource_index().
 *
 * @see _node_resource_index()
 */
function _collections_resource_index($page, $fields, $parameters, $page_size, $options = array()) {

  $parameters['type'] = 'collection';

  module_load_include('inc', 'services', 'resources/node_resource');
  $list = _node_resource_index($page, $fields, $parameters, $page_size, $options = array());
  // dpm($list, 'list');

  drupal_add_http_header('results-count', count($list));

  return $list;
}



/**
 * Sets param $parameters['type'] = 'collection'; then calls _node_resource_index().
 *
 * @see _node_resource_index()
 */
function _collections_resource_observations($nid) {
  // dpm("Called: _collections_resource_observations");
  $type = 'observation';
  $field1 = 'field_collection';
  $column1 = 'target_id';
  $nid1 = $nid;

  $output = array();

  $observations = get_referencing_nodes($type, $field1, $column1, $nid1);
  // dpm($observations, 'observations');

  // Replace each observation 'representation' with the real observation object
  foreach ($observations as $key => $observation) {
    $observations[$key] = node_load($key);
  }
  // dpm($observations, 'observations');

  // Include referencing entities
  foreach ($observations as $key => $observation) {

    // Identifications

    $ids = get_identifications_refing_observation('identification', $key);
    foreach ($ids as $nid => $identification_summary) {
      $observations[$key] -> identifications[$nid] = create_id_representation($nid);
    }
    // $observations[$key]->identifications = $ids;

    // Community identifications

    $comm_ids = get_identifications_refing_observation('identification_community', $key);
    // $observations[$key]->community_identifications = $comm_ids;

    foreach ($comm_ids as $nid => $comm_id_summary) {
      $observations[$key] -> community_identifications[$nid] = create_comm_id_representation($nid);
    }
  }


  foreach ($observations as $nid => $observation) {
    // ---------------------------------- Copied from Services' _node_resource_retrieve()
    if ($observation) {
      $uri = entity_uri('node', $observation);
      $observations[$nid]->path = url($uri['path'], array('absolute' => TRUE));
      // Unset uri as it has complete entity and this
      // cause never ending recursion in rendering.
      unset($observations[$nid]->uri);
    }
    //Lets check field_permissions
    $observations[$nid] = services_field_permissions_clean('view', 'node', $observations[$nid]);
    // return $observation;
    // ----------------------------------
  }

  drupal_add_http_header('results-count', count($observations));

  // dpm($observations, 'observations');
  return $observations;
}

/**
 * Format an identification as {'species': $species, 'certainty': $certainty}
 */
function create_id_representation($nid) {

  $identification_raw = node_load($nid);
  $identification = entity_metadata_wrapper('node', $identification_raw);

  $certainty_field_info = field_info_field('field_certainty');
  // dpm($certainty_field_info, '$certainty_field_info');
  $certainty = $certainty_field_info['settings']['allowed_values'][
    $identification->field_certainty->value()];
  // dpm($certainty, '$certainty');

  $species = $identification->field_identified_species->value()->name;
  // dpm($species, '$species');

  return array(
    'species' => $species,
    'certainty' => $certainty
  );
}

/**
 * Format a community identification as {'species': $species, 'reliability': $reliability}
 */
function create_comm_id_representation($nid) {

  $identification_raw = node_load($nid);
  $comm_id = entity_metadata_wrapper('node', $identification_raw);

  $reliability = $comm_id->field_reliability->value();
  // dpm($reliability, '$reliability');

  $species = $comm_id->field_identified_species->value()->name;
  // dpm($species, '$species');

  return array(
    'species' => $species,
    'certainty' => $reliability
  );
}





/**
 * Checks that param $nid is the nid of a collection; if it is, then calls _node_resource_retrieve().
 *
 * @see _node_resource_retrieve()
 */
function _identifications_resource_retrieve($nid) {

  $node = node_load($nid);

  // If the node isn't an observation
  if($node->type != 'identification') {
    services_error("Node " . $nid . " is not an identification.", 406); // 406: Not Acceptable
    return FALSE;
  }

  module_load_include('inc', 'services', 'resources/node_resource');
  $node = _node_resource_retrieve($nid);

  return $node;
}



/**
 * Checks that param $node is an observation; if it is, then calls _node_resource_create().
 *
 * @see _node_resource_create()
 */
function _identifications_resource_create($node) {
  // dpm($node, 'node');

  // If the node isn't an observation
  if($node['type'] != 'identification') {
    services_error("Can only create identifications.", 406); // 406: Not Acceptable
    return FALSE;
  }

  module_load_include('inc', 'services', 'resources/node_resource');
  $node = _node_resource_create($node);

  return $node;
}
