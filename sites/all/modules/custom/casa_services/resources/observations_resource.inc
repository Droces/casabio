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
      'targeted_actions' => array(
        'add_interaction' => array(
          'help' => "Add an interaction of an observation",
          'file' => $observations_resource_file,
          'callback' => '_observations_resource_add_interaction',
          'access callback' => '_node_resource_access',
          'access arguments' => array('view'),
          'access arguments append' => TRUE,
          'args' => array(
            $node_operation_args['nid'],
            $node_operation_args['node'],
          ),
        ),
      ),
    ),
  );

  return $observation_resource;
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

  // node_payload_normaliser($node);
  // return $node;

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
 * How the _node_resource_update() function works:
 *   1. Creates a 'new node values' object from submitted values
 *   2. Loads the existing node from the nid parameter
 *   3. Loads the existing node's edit form
 *   4. Creates a form_state array and inserts the 'new node values'
 *   5. Submits the new form_state array with the existing node
 *
 * @param mixed $nid
 *   Either an int nid of a single node to be updated, or a string of nids concatenated by '|' (eg. '45|46') of mutiple nodes to be updated using the same values provided in $node.
 *
 * @see _node_resource_update()
 */
function _observations_resource_update($nid, $node) {
  // dpm($node, '$node');
  // dpm($nid, '$nid');

  // if (! is_valid_eid($nid)) {
  //   throw new InvalidArgumentException("Parameter $nid, " . $nid . ", needs to be a valid NID.", 1);
  // }
  // If the node isn't an observation
  if ($node['type'] != 'observation') {
    services_error("Can only update observations.", 406); // 406: Not Acceptable
    return FALSE;
  }

  $nids = explode('|', $nid);
  // dpm($nids, 'nids');

  module_load_include('inc', 'services', 'resources/node_resource');

  if (count($nids) == 1) {
    if (! is_valid_eid($nid)) {
      throw new Exception("Parameter $nid, " . $nid . ", needs to be a valid NID.", 1);
    }
    return _node_resource_update($nid, $node);
  }
  else {
    $nodes = [];
    foreach ($nids as $nid) {
      if (! is_valid_eid($nid)) {
        throw new Exception("Parameter $nid, " . $nid . ", needs to contain valid NIDs.", 1);
      }
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

  if(!$comm_ids) {
    return NULL;
  }

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


/**
 * @param $params
 *   an array
 */
function _observations_resource_add_interaction($nid, $params) {

  if (! is_valid_eid($nid)) {
    throw new InvalidArgumentException("Parameter $nid, " . $nid . ", needs to be a valid NID.", 1);
  }
  try {
    $interaction = observation_add_interaction($nid, $params);
    return $interaction;
  }
  catch (Exception $e) {
    services_error($e->getMessage(), 406); // 406: Not Acceptable
    return NULL;
  }
}


/**
 * Converts a simple service payload of node info into a normalised array representing the node.
 */
function node_payload_normaliser($payload) {
  $node_array = array();
  $language = 'und';

  foreach ($payload as $field_name => $value) {
    // dpm($value);

    $info = field_info_field($field_name);

    if ($info) {
      // dpm($info, $field_name . ' $info');

      $columns = array_keys($info['columns']);

      switch ($info['type']) {
        case 'geofield':

          // @todo Make this support more types.
          $geometry_type = 'POINT';

          $node_array[$field_name] =
            array($language => array(0 => array($columns[0] =>
              $geometry_type . ' (' . implode(' ', $value) . ')')));

          break;
        case 'entityreference':

          $title = '';
          $collection = node_load($value);
          // dpm($collection, '$collection');
          if ($collection) {
            $title = $collection->title;
          }

          $node_array[$field_name] =
            array($language => array(0 => array($columns[0] =>
              $title . ' (' . $value . ')')));

          break;

        default:
          $node_array[$field_name] =
            array($language => array(0 => array($columns[0] => $value)));
          break;
      }
    }
    // If this is not a field, but a property (eg. title, nid, etc.)
    else {
      $node_array[$field_name] = $value;
    }
  }

  // dpm($node_array, '$node_array');
  return $node_array;
}
