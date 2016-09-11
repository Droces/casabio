<?php
/**
 * @file
 * Description…
 */



// =======================================================================================
/**
 * Implements hook_services_resources().
 */
function _taxa_resource_definition() {
  $taxa_resource_file = array(
    'type' => 'inc',
    'module' => 'casa_services',
    'name' => 'resources/taxa_resource',
  );

  module_load_include('inc', 'casa_services', 'resources/resources_arguments');
  // dpm($test, 'test');

  // Arguments that can be re-used within the resource definitions.
  $args = array(
  	'tid' => array(
      'name' => 'tid',
      'optional' => FALSE,
      'source' => array('path' => 0),
      'type' => 'int',
      'description' => 'The tid of the taxonomy term to get / update / delete.',
    ),
    'page' => array(
      'name' => 'page',
      'optional' => TRUE,
      'type' => 'int',
      'description' => 'The zero-based index of the page to get, defaults to 0.',
      'default value' => 0,
      'source' => array('param' => 'page'),
    ),
    'term' => array(
	    'name' => 'term',
      'optional' => FALSE,
      'source' => 'data',
      'description' => 'The taxonomy term object to create / update',
      'type' => 'array',
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
      'description' => 'Parameters',
      'default value' => array(),
      'source' => array('param' => 'parameters'),
    ),
    'pagesize' => array(
      'name' => 'pagesize',
      'optional' => TRUE,
      'type' => 'int',
      'description' => 'Number of records to get per page.',
      'default value' => variable_get('services_taxonomy_term_index_page_size', 20),
      'source' => array('param' => 'pagesize'),
    ),
    'options' => array(
      'name' => 'options',
      'optional' => TRUE,
      'type' => 'array',
      'description' => 'Additional query options.',
      'default value' => array(
        'orderby' => array(
          'vid' => 'DESC',
          'weight' => 'DESC',
          'name' => 'DESC'
        )
      ),
      'source' => array('param' => 'options'),
    ),
  );

  module_load_include('inc', 'services', 'resources/taxonomy_resource');

  $taxa_resources = array(
    'taxa' => array(
      'operations' => array(

        // --------------------------------------------- GET
        'retrieve' => array(
          'help' => 'Retrieve a taxon',
	        'file' => $taxa_resource_file,
          'callback' => '_taxa_resource_retrieve',
          'args' => array(
            $args['tid'],
          ),
          'access callback' => '_taxon_resource_access',
          'access arguments' => array('access content'),
        ),
      ),
      'create' => array(
        'help' => 'Create a term',
        'file' => $taxa_resource_file,
        'callback' => '_taxa_resource_create',
        'args' => array(
          $args['term'],
        ),
        'access callback' => '_taxonomy_resource_create_access',
        'access arguments append' => TRUE,
      ),
      'update' => array(
        'help' => 'Update a term',
        'file' => $taxa_resource_file,
        'callback' => '_taxon_resource_update',
        'args' => array(
          $args['tid'],
          $args['term'],
        ),
        'access callback' => '_taxonomy_resource_update_access',
        'access arguments append' => TRUE,
      ),
      'delete' => array(
        'help' => 'Delete the term',
        'file' => $taxa_resource_file,
        'callback' => '_taxa_resource_delete',
        'args' => array(
          $args['tid'],
        ),
        'access callback' => '_taxonomy_resource_delete_access',
        'access arguments append' => TRUE,
      ),
      'index' => array(
        'help' => 'List all terms. Limited to 5000 results.',
        'file' => $taxa_resource_file,
        'callback' => '_taxa_resource_index',
        'args' => array(
          $args['page'],
          $args['fields'],
          $args['parameters'],
          $args['pagesize'],
          $args['options'],
        ),
        'access arguments' => array('access content'),
      ),
    ),
  );

  return $taxa_resources;
}





/**
 * Checks that param $tid is the tid of a taxon; if it is, then calls _taxonomy_term_resource_retrieve().
 *
 * @see _taxonomy_term_resource_retrieve()
 */
function _taxa_resource_retrieve($tid) {
  $term = taxonomy_term_load($tid);

  if($term->vocabulary_machine_name != 'taxa') {
    services_error("Term " . $tid . " is not an taxon", 406); // 406: Not Acceptable
    return FALSE;
  }

  module_load_include('inc', 'services', 'resources/taxonomy_resource');
  $term = _taxonomy_term_resource_retrieve($tid);
  return $term;
}



/**
 * Checks that param $term is a taxon; if it is, then calls _taxonomy_term_resource_create().
 *
 * @see _taxonomy_term_resource_create()
 */
function _taxa_resource_create($term) {
  // dpm($term, 'term');

  // If the node isn't an observation
  if($term['vid'] != '2') {
    services_error("Can only create taxa.", 406); // 406: Not Acceptable
    return FALSE;
  }

  module_load_include('inc', 'services', 'resources/taxonomy_resource');
  $term = _taxonomy_term_resource_create($term);

  return $term;
}



/**
 * Checks that param $term is a taxon; if it is, then calls _taxonomy_term_resource_update().
 *
 * @see 
 */
function _taxa_resource_update($tid, $term) {

  // If the node isn't an observation
  if($term['vid'] != '2') {
    services_error("Can only update taxa.", 406); // 406: Not Acceptable
    return FALSE;
  }

  module_load_include('inc', 'services', 'resources/taxonomy_resource');
  $term = _taxonomy_term_resource_update($tid, $term);

  return $term;
}



/**
 * Checks that param $tid is the tid of a taxon; if it is, then calls _taxonomy_term_resource_delete().
 *
 * @see _taxonomy_term_resource_delete()
 */
function _taxa_resource_delete($tid) {
  $term = taxonomy_term_load($tid);

  if($term->vocabulary_machine_name != 'taxa') {
    services_error("Term " . $tid . " is not an taxon", 406); // 406: Not Acceptable
    return FALSE;
  }

  module_load_include('inc', 'services', 'resources/taxonomy_resource');
  $term = _taxonomy_term_resource_delete($tid);
  return $term;
}



/**
 * Sets param $parameters['vid'] = '2'; then calls _node_resource_index().
 * 
 * @see _node_resource_index()
 **/
function _taxa_resource_index($page, $fields, $parameters, $page_size, $options = array()) {

  module_load_include('inc', 'services', 'resources/taxonomy_resource');

  $taxonomy_select = db_select('taxonomy_term_data', 't');
  $taxonomy_select->addTag('term_access');
  $taxonomy_select->join('taxonomy_term_hierarchy', 'tth', 't.tid = tth.tid');
  $taxonomy_select->fields('tth');

  $page_size = $page_size > 5000 ? 5000 : $page_size; // Limit to 5000 results

  $parameters['vid'] = '2'; // Taxa vocabulary
  
  services_resource_build_index_query($taxonomy_select, $page, $fields, $parameters, $page_size, 'taxonomy_term', $options);

  $results = services_resource_execute_index_query($taxonomy_select);

  $list = services_resource_build_index_list($results, 'taxonomy_term', 'tid');

  drupal_add_http_header('results-count', count($list));

  return $list;
}