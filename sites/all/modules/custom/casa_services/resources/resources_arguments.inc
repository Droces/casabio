<?php

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