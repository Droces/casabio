<?php
/**
 * @file
 * Description…
 */



// =======================================================================================
/**
 * Implements hook_services_resources().
 */
function _observations_resource_definition() {
  $observations_resource_file = array(
    'type' => 'inc',
    'module' => 'casa_services',
    'name' => 'resources/observations_resource',
  );

  // module_load_include('inc', 'casa_services', 'resources/resources_arguments');

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



  $observation_resource = array(
    'observations' => array(
      'operations' => array(

        // --------------------------------------------- GET
        'retrieve' => array(
          'file' => $observations_resource_file,
          'callback' => '_observations_resource_retrieve',
          'args' => array(
            $node_operation_args['nid'],
          ),
          'access callback' => '_node_resource_access',
          'access arguments' => array('view'),
          'access arguments append' => TRUE,
        ),

        // --------------------------------------------- POST
        'create' => array(
          'file' => $observations_resource_file,
          'callback' => '_observations_resource_create',
          'args' => array(
            $node_operation_args['node'],
          ),
          'access callback' => '_node_resource_access',
          'access arguments' => array('create'),
          'access arguments append' => TRUE,
        ),

        // --------------------------------------------- PUT
        'update' => array(
          'file' => $observations_resource_file,
          'callback' => '_observations_resource_update',
          'args' => array(
            $node_operation_args['nid'],
            $node_operation_args['node'],
          ),
          'access callback' => '_casa_node_resource_access',
          'access arguments' => array('update'),
          'access arguments append' => TRUE,
        ),

        // --------------------------------------------- DELETE
        'delete' => array(
          'file' => $observations_resource_file,
          'callback' => '_observations_resource_delete',
          'args' => array(
            $node_operation_args['nid'],
          ),
          'access callback' => '_node_resource_access',
          'access arguments' => array('delete'),
          'access arguments append' => TRUE,
        ),

        // --------------------------------------------- List
        'index' => array(
          'file' => $observations_resource_file,
          'callback' => '_observations_resource_index',
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
        // --------------------------------------------- See its Community identifications
        'community_identifications' => array(
          'help' => "View a list of an observation's community identifications",
          'file' => $observations_resource_file,
          'callback' => '_observations_resource_community_identifications',
          'access callback' => '_node_resource_access',
          'access arguments' => array('view'),
          'access arguments append' => TRUE,
          'args' => array(
            array(
              'name' => 'nid',
              'optional' => FALSE,
              'source' => array('path' => 0),
              'type' => 'int',
              'description' => "The nid of the observation whose community identifications you'd like a list of",
            ),
          ),
        ),
      ),
    ),
  );

  return $observation_resource;
}



/**
 * @return boolean
 *   TRUE if the user is permitted access, FALSE otherwise.
 */
function _casa_node_resource_access($op = 'view', $args = array()) {
  // dpm($op, 'op');
  // dpm($args, 'args');

  if ($op == 'update') {
    $nids = explode('|', $args[0]);
    // dpm($nids, 'nids');
    if (count($nids) == 1) {
      return _node_resource_access($op, $args);
    }
    else {
      // // Adds backwards compatability with regression fixed in #1083242
      // if (isset($args[0])) {
      //   $args[0] = _services_access_value($args[0], 'node');
      // }

      // // Make sure we have an object or this all fails, some servers can
      // // mess up the types.
      // if (is_array($args[0])) {
      //   $args[0] = (object) $args[0];
      // }
      // elseif (!is_array($args[0]) && !is_object($args[0])) { //This is to determine if it is just a string happens on node/%NID
      //   $args[0] = (object) array('nid' => $args[0]);
      // }

      // if ($op != 'create' && !empty($args)) {
      //   $node = node_load($args[0]->nid);
      // }
      // elseif ($op == 'create') {
      //   if (isset($args[0]->type)) {
      //     $node = $args[0]->type;
      //     return node_access($op, $node);
      //   }
      //   else {
      //     return services_error(t('Node type is required'), 406);
      //   }
      // }
      // if (isset($node->nid) && $node->nid) {
      //   return node_access($op, $node);
      // }
      // else {
      //   return services_error(t('Node @nid could not be found', array('@nid' => $args[0]->nid)), 404);
      // }
      return TRUE;
    }
  }
  else {
    return _node_resource_access($op, $args);
  }
}



/**
 * Checks that param $nid is the nid of an observation; if it is, then calls _node_resource_retrieve().
 *
 * @see _node_resource_retrieve()
 */
function _observations_resource_retrieve($nid) {

  $node = node_load($nid);

  // If the node isn't an observation
  if($node->type != 'observation') {
    services_error("Node " . $nid . " is not an observation.", 406); // 406: Not Acceptable
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
function _observations_resource_create($node) {
  // dpm($node, 'node');

  // If the node isn't an observation
  if($node['type'] != 'observation') {
    services_error("Can only create observations.", 406); // 406: Not Acceptable
    return FALSE;
  }

  module_load_include('inc', 'services', 'resources/node_resource');
  $node = _node_resource_create($node);

  return $node;
}



/**
 * Checks that param $node is an observation; if it is, then calls _node_resource_update().
 * 
 * @param mixed $nid
 *   Either an int nid of a single node to be updated, or a string of nids concatenated by '|' (eg. '45|46') of mutiple nodes to be updated using the same values provided in $node.
 *
 * @see _node_resource_update()
 */
function _observations_resource_update($nid, $node) {

  // If the node isn't an observation
  if ($node['type'] != 'observation') {
    services_error("Can only update observations.", 406); // 406: Not Acceptable
    return FALSE;
  }

  $nids = explode('|', $nid);
  // dpm($nids, 'nids');

  module_load_include('inc', 'services', 'resources/node_resource');

  if (count($nids) == 1) {
    return _node_resource_update($nid, $node);
  }
  else {
    $nodes = [];
    foreach ($nids as $nid) {
      $nodes[] = _node_resource_update($nid, $node);
    }
    return $nodes;
  }
}



/**
 * Delete a node given its nid.
 *
 * @param int $nid
 *   Node ID of the node we're deleting.
 * @return bool
 *   Always returns true.
 */
function _observations_resource_delete($nid) {

  $node = node_load($nid);

  // If the node isn't an observation
  if($node->type != 'observation') {
    services_error("Node " . $nid . " is not an observation.", 406); // 406: Not Acceptable
    return FALSE;
  }

  module_load_include('inc', 'services', 'resources/node_resource');
  $result = _node_resource_delete($nid);

  return $result;
}



/**
 * Sets param $parameters['type'] = 'observation'; then calls _node_resource_index().
 *
 * @see _node_resource_index()
 */
function _observations_resource_index($page, $fields, $parameters, $page_size, $options = array()) {

  $parameters['type'] = 'observation';

  module_load_include('inc', 'services', 'resources/node_resource');
  $list = _node_resource_index($page, $fields, $parameters, $page_size, $options = array());

  drupal_add_http_header('results-count', count($list));

  return $list;
}


function _observations_resource_community_identifications($nid) {
  // dpm("Called: _observations_resource_community_identifications");
  $type = 'identification_community';
  $field1 = 'field_observation';
  $column1 = 'target_id';
  $nid1 = $nid;

  $output = array();

  $comm_ids = get_referencing_nodes($type, $field1, $column1, $nid1);
  // dpm($comm_ids, 'comm_ids');
  foreach ($comm_ids as $nid => $comm_id) {
    // ---------------------------------- Copied from Services' _node_resource_retrieve()
    // Simply changes 'uri' to a 'path', and checks permissions
    if ($comm_id) {
      $uri = entity_uri('node', $comm_id);
      $comm_ids[$nid]->path = url($uri['path'], array('absolute' => TRUE));
      // Unset uri as it has complete entity and this
      // cause never ending recursion in rendering.
      unset($comm_ids[$nid]->uri);
    }
    //Lets check field_permissions
    $comm_ids[$nid] = services_field_permissions_clean('view', 'node', $comm_ids[$nid]);
    // return $comm_id;
    // ----------------------------------
  }

  drupal_add_http_header('results-count', count($comm_ids));

  // dpm($comm_ids, 'comm_ids');
  return $comm_ids;
}