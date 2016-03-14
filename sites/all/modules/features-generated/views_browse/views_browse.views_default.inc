<?php
/**
 * @file
 * views_browse.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_browse_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'browse_collections_table';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Browse Collections Table';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Browse Collections Table';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'name' => 'name',
    'created' => 'created',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['ui_name'] = 'Author';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Contributor';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Contributed date';
  $handler->display->display_options['fields']['created']['date_format'] = 'raw time ago';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'collection' => 'collection',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'browse/collections/table';
  $export['browse_collections_table'] = $view;

  $view = new view();
  $view->name = 'browse_observations_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Browse Observations List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Browse Observations';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'inline';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No observations found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['ui_name'] = 'Author';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  /* Field: Content: Pictures in observation */
  $handler->display->display_options['fields']['field_pictures_observation']['id'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['table'] = 'field_data_field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['field'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['label'] = 'Picture';
  $handler->display->display_options['fields']['field_pictures_observation']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_pictures_observation']['settings'] = array(
    'view_mode' => 'thumbnail',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_pictures_observation']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_pictures_observation']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Contributed date';
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Identifications */
  $handler->display->display_options['fields']['field_identifications']['id'] = 'field_identifications';
  $handler->display->display_options['fields']['field_identifications']['table'] = 'field_data_field_identifications';
  $handler->display->display_options['fields']['field_identifications']['field'] = 'field_identifications';
  $handler->display->display_options['fields']['field_identifications']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_identifications']['settings'] = array(
    'view_mode' => 'text',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_identifications']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_identifications']['separator'] = '';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'observation' => 'observation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Location (field_location:geom) */
  $handler->display->display_options['filters']['field_location_geom']['id'] = 'field_location_geom';
  $handler->display->display_options['filters']['field_location_geom']['table'] = 'field_data_field_location';
  $handler->display->display_options['filters']['field_location_geom']['field'] = 'field_location_geom';
  $handler->display->display_options['filters']['field_location_geom']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_location_geom']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title contains';
  $handler->display->display_options['filters']['title']['expose']['description'] = 'Words that the title must contain; eg. “indigenous”';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>';
  $handler->display->display_options['filters']['created']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Date contributed';
  $handler->display->display_options['filters']['created']['expose']['description'] = 'An offset from today’s date; eg. “-2 weeks”';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'date_created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Locality (field_locality) */
  $handler->display->display_options['filters']['field_locality_tid']['id'] = 'field_locality_tid';
  $handler->display->display_options['filters']['field_locality_tid']['table'] = 'field_data_field_locality';
  $handler->display->display_options['filters']['field_locality_tid']['field'] = 'field_locality_tid';
  $handler->display->display_options['filters']['field_locality_tid']['value'] = '';
  $handler->display->display_options['filters']['field_locality_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_locality_tid']['expose']['operator_id'] = 'field_locality_tid_op';
  $handler->display->display_options['filters']['field_locality_tid']['expose']['label'] = 'Locality';
  $handler->display->display_options['filters']['field_locality_tid']['expose']['description'] = 'A known geographic area; eg. “Western Cape”';
  $handler->display->display_options['filters']['field_locality_tid']['expose']['operator'] = 'field_locality_tid_op';
  $handler->display->display_options['filters']['field_locality_tid']['expose']['identifier'] = 'locality';
  $handler->display->display_options['filters']['field_locality_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_locality_tid']['vocabulary'] = 'locality';
  /* Filter criterion: Content: Species (field_identified_species) */
  $handler->display->display_options['filters']['field_identified_species_tid']['id'] = 'field_identified_species_tid';
  $handler->display->display_options['filters']['field_identified_species_tid']['table'] = 'field_data_field_identified_species';
  $handler->display->display_options['filters']['field_identified_species_tid']['field'] = 'field_identified_species_tid';
  $handler->display->display_options['filters']['field_identified_species_tid']['relationship'] = 'field_identifications_target_id';
  $handler->display->display_options['filters']['field_identified_species_tid']['value'] = '';
  $handler->display->display_options['filters']['field_identified_species_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['operator_id'] = 'field_identified_species_tid_op';
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['label'] = 'Species identified';
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['description'] = 'The scientific or common name';
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['operator'] = 'field_identified_species_tid_op';
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['identifier'] = 'identified_species';
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_identified_species_tid']['vocabulary'] = 'taxa';
  /* Filter criterion: Content: Identifications (field_identifications) */
  $handler->display->display_options['filters']['field_identifications_target_id']['id'] = 'field_identifications_target_id';
  $handler->display->display_options['filters']['field_identifications_target_id']['table'] = 'field_data_field_identifications';
  $handler->display->display_options['filters']['field_identifications_target_id']['field'] = 'field_identifications_target_id';
  $handler->display->display_options['filters']['field_identifications_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_identifications_target_id']['expose']['operator_id'] = 'field_identifications_target_id_op';
  $handler->display->display_options['filters']['field_identifications_target_id']['expose']['label'] = 'Identifications (field_identifications)';
  $handler->display->display_options['filters']['field_identifications_target_id']['expose']['operator'] = 'field_identifications_target_id_op';
  $handler->display->display_options['filters']['field_identifications_target_id']['expose']['identifier'] = 'field_identifications_target_id';
  $handler->display->display_options['filters']['field_identifications_target_id']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_identifications_target_id']['group_info']['label'] = 'Is identified';
  $handler->display->display_options['filters']['field_identifications_target_id']['group_info']['identifier'] = 'has_identifications';
  $handler->display->display_options['filters']['field_identifications_target_id']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Identified',
      'operator' => 'not empty',
      'value' => array(
        'value' => '.',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'No identifications',
      'operator' => 'empty',
      'value' => array(
        'value' => '.',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author’s username';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'author';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'browse/observations/list';
  $export['browse_observations_list'] = $view;

  $view = new view();
  $view->name = 'browse_observations_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Browse Observations Map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Browse Observations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3000';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['data_source'] = 'field_location';
  $handler->display->display_options['style_options']['name_field'] = 'title';
  $handler->display->display_options['style_options']['description_field'] = 'body';
  $handler->display->display_options['style_options']['map'] = 'OSM Mapnik';
  $handler->display->display_options['style_options']['height'] = '500';
  $handler->display->display_options['style_options']['hide_empty'] = 1;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '-1';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '0';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['icon']['iconUrl'] = 'http://localhost/Current/CasaBio/sites/default/files/12x12-circle-green.png';
  $handler->display->display_options['style_options']['icon']['iconSize']['x'] = '6';
  $handler->display->display_options['style_options']['icon']['iconSize']['y'] = '6';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No observations found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Identifications */
  $handler->display->display_options['relationships']['field_identifications_target_id']['id'] = 'field_identifications_target_id';
  $handler->display->display_options['relationships']['field_identifications_target_id']['table'] = 'field_data_field_identifications';
  $handler->display->display_options['relationships']['field_identifications_target_id']['field'] = 'field_identifications_target_id';
  $handler->display->display_options['relationships']['field_identifications_target_id']['ui_name'] = 'Identifications';
  $handler->display->display_options['relationships']['field_identifications_target_id']['label'] = 'Identifications';
  /* Relationship: Identified species */
  $handler->display->display_options['relationships']['field_identified_species_tid']['id'] = 'field_identified_species_tid';
  $handler->display->display_options['relationships']['field_identified_species_tid']['table'] = 'field_data_field_identified_species';
  $handler->display->display_options['relationships']['field_identified_species_tid']['field'] = 'field_identified_species_tid';
  $handler->display->display_options['relationships']['field_identified_species_tid']['relationship'] = 'field_identifications_target_id';
  $handler->display->display_options['relationships']['field_identified_species_tid']['ui_name'] = 'Identified species';
  $handler->display->display_options['relationships']['field_identified_species_tid']['label'] = 'Identified species';
  /* Relationship: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['ui_name'] = 'Author';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_location']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  /* Field: Content: Pictures in observation */
  $handler->display->display_options['fields']['field_pictures_observation']['id'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['table'] = 'field_data_field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['field'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['label'] = 'Pictures';
  $handler->display->display_options['fields']['field_pictures_observation']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_pictures_observation']['settings'] = array(
    'view_mode' => 'thumbnail',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_pictures_observation']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_pictures_observation']['delta_offset'] = '0';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location_1']['id'] = 'field_location_1';
  $handler->display->display_options['fields']['field_location_1']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location_1']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location_1']['label'] = 'Latitude';
  $handler->display->display_options['fields']['field_location_1']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_location_1']['type'] = 'geofield_lat';
  $handler->display->display_options['fields']['field_location_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location_2']['id'] = 'field_location_2';
  $handler->display->display_options['fields']['field_location_2']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location_2']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location_2']['label'] = 'Longitude';
  $handler->display->display_options['fields']['field_location_2']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_location_2']['type'] = 'geofield_lon';
  $handler->display->display_options['fields']['field_location_2']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'observation' => 'observation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Location (field_location:geom) */
  $handler->display->display_options['filters']['field_location_geom']['id'] = 'field_location_geom';
  $handler->display->display_options['filters']['field_location_geom']['table'] = 'field_data_field_location';
  $handler->display->display_options['filters']['field_location_geom']['field'] = 'field_location_geom';
  $handler->display->display_options['filters']['field_location_geom']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_location_geom']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title contains';
  $handler->display->display_options['filters']['title']['expose']['description'] = 'Words that the title must contain; eg. “indigenous”';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>';
  $handler->display->display_options['filters']['created']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Date contributed';
  $handler->display->display_options['filters']['created']['expose']['description'] = 'An offset from today’s date; eg. “-2 weeks”';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'date_created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Locality (field_locality) */
  $handler->display->display_options['filters']['field_locality_tid']['id'] = 'field_locality_tid';
  $handler->display->display_options['filters']['field_locality_tid']['table'] = 'field_data_field_locality';
  $handler->display->display_options['filters']['field_locality_tid']['field'] = 'field_locality_tid';
  $handler->display->display_options['filters']['field_locality_tid']['value'] = '';
  $handler->display->display_options['filters']['field_locality_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_locality_tid']['expose']['operator_id'] = 'field_locality_tid_op';
  $handler->display->display_options['filters']['field_locality_tid']['expose']['label'] = 'Locality';
  $handler->display->display_options['filters']['field_locality_tid']['expose']['description'] = 'A known geographic area; eg. “Western Cape”';
  $handler->display->display_options['filters']['field_locality_tid']['expose']['operator'] = 'field_locality_tid_op';
  $handler->display->display_options['filters']['field_locality_tid']['expose']['identifier'] = 'locality';
  $handler->display->display_options['filters']['field_locality_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_locality_tid']['vocabulary'] = 'locality';
  /* Filter criterion: Content: Species (field_identified_species) */
  $handler->display->display_options['filters']['field_identified_species_tid']['id'] = 'field_identified_species_tid';
  $handler->display->display_options['filters']['field_identified_species_tid']['table'] = 'field_data_field_identified_species';
  $handler->display->display_options['filters']['field_identified_species_tid']['field'] = 'field_identified_species_tid';
  $handler->display->display_options['filters']['field_identified_species_tid']['relationship'] = 'field_identifications_target_id';
  $handler->display->display_options['filters']['field_identified_species_tid']['value'] = '';
  $handler->display->display_options['filters']['field_identified_species_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['operator_id'] = 'field_identified_species_tid_op';
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['label'] = 'Species identified';
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['description'] = 'The scientific or common name';
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['operator'] = 'field_identified_species_tid_op';
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['identifier'] = 'identified_species';
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_identified_species_tid']['vocabulary'] = 'taxa';
  /* Filter criterion: Content: Identifications (field_identifications) */
  $handler->display->display_options['filters']['field_identifications_target_id']['id'] = 'field_identifications_target_id';
  $handler->display->display_options['filters']['field_identifications_target_id']['table'] = 'field_data_field_identifications';
  $handler->display->display_options['filters']['field_identifications_target_id']['field'] = 'field_identifications_target_id';
  $handler->display->display_options['filters']['field_identifications_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_identifications_target_id']['expose']['operator_id'] = 'field_identifications_target_id_op';
  $handler->display->display_options['filters']['field_identifications_target_id']['expose']['label'] = 'Identifications (field_identifications)';
  $handler->display->display_options['filters']['field_identifications_target_id']['expose']['operator'] = 'field_identifications_target_id_op';
  $handler->display->display_options['filters']['field_identifications_target_id']['expose']['identifier'] = 'field_identifications_target_id';
  $handler->display->display_options['filters']['field_identifications_target_id']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_identifications_target_id']['group_info']['label'] = 'Is identified';
  $handler->display->display_options['filters']['field_identifications_target_id']['group_info']['identifier'] = 'has_identifications';
  $handler->display->display_options['filters']['field_identifications_target_id']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Identified',
      'operator' => 'not empty',
      'value' => array(
        'value' => '.',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'No identifications',
      'operator' => 'empty',
      'value' => array(
        'value' => '.',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author’s username';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'author';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'browse/observations/map';
  $export['browse_observations_map'] = $view;

  $view = new view();
  $view->name = 'browse_observations_table';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Browse Observations Table';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Browse Observations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_pictures_observation' => 'field_pictures_observation',
    'title' => 'title',
    'name' => 'name',
    'created' => 'created',
    'field_identifications' => 'field_identifications',
    'edit_node' => 'edit_node',
    'view_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pictures_observation' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_identifications' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No observations found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['ui_name'] = 'Author';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Pictures in observation */
  $handler->display->display_options['fields']['field_pictures_observation']['id'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['table'] = 'field_data_field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['field'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['label'] = 'Pictures';
  $handler->display->display_options['fields']['field_pictures_observation']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_pictures_observation']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_pictures_observation']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_pictures_observation']['settings'] = array(
    'view_mode' => 'thumbnail',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_pictures_observation']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_pictures_observation']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_pictures_observation']['separator'] = ' ';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['empty'] = '<em class="subtle">untitled</em>';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Contributor';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Contributed date';
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Identifications */
  $handler->display->display_options['fields']['field_identifications']['id'] = 'field_identifications';
  $handler->display->display_options['fields']['field_identifications']['table'] = 'field_data_field_identifications';
  $handler->display->display_options['fields']['field_identifications']['field'] = 'field_identifications';
  $handler->display->display_options['fields']['field_identifications']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_identifications']['settings'] = array(
    'view_mode' => 'text',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_identifications']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_identifications']['separator'] = '';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'observation' => 'observation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>';
  $handler->display->display_options['filters']['created']['value']['value'] = '-2 weeks';
  $handler->display->display_options['filters']['created']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Date contributed';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['created']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['created']['group_info']['label'] = 'Submitted when';
  $handler->display->display_options['filters']['created']['group_info']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'in the past day',
      'operator' => '>',
      'value' => array(
        'type' => 'offset',
        'value' => '-1 day',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'in the last week',
      'operator' => '>',
      'value' => array(
        'type' => 'offset',
        'value' => '-7 weeks',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => 'in the last month',
      'operator' => '>',
      'value' => array(
        'type' => 'offset',
        'value' => '-1 month',
        'min' => '',
        'max' => '',
      ),
    ),
    4 => array(
      'title' => 'in the past year',
      'operator' => '>',
      'value' => array(
        'type' => 'offset',
        'value' => '-1 year',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Content: Identifications (field_identifications) */
  $handler->display->display_options['filters']['field_identifications_target_id']['id'] = 'field_identifications_target_id';
  $handler->display->display_options['filters']['field_identifications_target_id']['table'] = 'field_data_field_identifications';
  $handler->display->display_options['filters']['field_identifications_target_id']['field'] = 'field_identifications_target_id';
  $handler->display->display_options['filters']['field_identifications_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_identifications_target_id']['expose']['operator_id'] = 'field_identifications_target_id_op';
  $handler->display->display_options['filters']['field_identifications_target_id']['expose']['label'] = 'Identifications (field_identifications)';
  $handler->display->display_options['filters']['field_identifications_target_id']['expose']['operator'] = 'field_identifications_target_id_op';
  $handler->display->display_options['filters']['field_identifications_target_id']['expose']['identifier'] = 'field_identifications_target_id';
  $handler->display->display_options['filters']['field_identifications_target_id']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_identifications_target_id']['group_info']['label'] = 'Identifications';
  $handler->display->display_options['filters']['field_identifications_target_id']['group_info']['identifier'] = 'field_identifications_target_id';
  $handler->display->display_options['filters']['field_identifications_target_id']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Has identifications',
      'operator' => 'not empty',
      'value' => array(
        'value' => '.',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Doesn’t have identifications',
      'operator' => 'empty',
      'value' => array(
        'value' => '.',
        'min' => '',
        'max' => '',
      ),
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'browse/observations/table';
  $export['browse_observations_table'] = $view;

  $view = new view();
  $view->name = 'clone_of_browse_observations_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Clone of Browse Observations Map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Browse Pictures';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_location' => 'field_location',
    'field_pictures_observation' => 'field_pictures_observation',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pictures_observation' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No observations found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Identifications */
  $handler->display->display_options['relationships']['field_identifications_target_id']['id'] = 'field_identifications_target_id';
  $handler->display->display_options['relationships']['field_identifications_target_id']['table'] = 'field_data_field_identifications';
  $handler->display->display_options['relationships']['field_identifications_target_id']['field'] = 'field_identifications_target_id';
  $handler->display->display_options['relationships']['field_identifications_target_id']['ui_name'] = 'Identifications';
  $handler->display->display_options['relationships']['field_identifications_target_id']['label'] = 'Identifications';
  /* Relationship: Identified species */
  $handler->display->display_options['relationships']['field_identified_species_tid']['id'] = 'field_identified_species_tid';
  $handler->display->display_options['relationships']['field_identified_species_tid']['table'] = 'field_data_field_identified_species';
  $handler->display->display_options['relationships']['field_identified_species_tid']['field'] = 'field_identified_species_tid';
  $handler->display->display_options['relationships']['field_identified_species_tid']['relationship'] = 'field_identifications_target_id';
  $handler->display->display_options['relationships']['field_identified_species_tid']['ui_name'] = 'Identified species';
  $handler->display->display_options['relationships']['field_identified_species_tid']['label'] = 'Identified species';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_location']['type'] = 'geofield_geojson';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Pictures in observation */
  $handler->display->display_options['fields']['field_pictures_observation']['id'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['table'] = 'field_data_field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['field'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['label'] = 'Pictures';
  $handler->display->display_options['fields']['field_pictures_observation']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_pictures_observation']['settings'] = array(
    'view_mode' => 'thumbnail',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_pictures_observation']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_pictures_observation']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'observation' => 'observation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Location (field_location:geom) */
  $handler->display->display_options['filters']['field_location_geom']['id'] = 'field_location_geom';
  $handler->display->display_options['filters']['field_location_geom']['table'] = 'field_data_field_location';
  $handler->display->display_options['filters']['field_location_geom']['field'] = 'field_location_geom';
  $handler->display->display_options['filters']['field_location_geom']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_location_geom']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title contains';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>';
  $handler->display->display_options['filters']['created']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Date contributed';
  $handler->display->display_options['filters']['created']['expose']['description'] = 'An offset from the current date, such as "-2 weeks"';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_geojson_feed';
  $handler->display->display_options['style_options']['data_source']['value'] = 'geofield';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_location';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'title';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'title';
  $handler->display->display_options['style_options']['data_source']['description_field'] = 'field_pictures_observation';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'browse/observations/feed.geojson';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['data_source'] = 'field_location';
  $handler->display->display_options['style_options']['name_field'] = 'title';
  $handler->display->display_options['style_options']['map'] = 'OSM Mapnik';
  $handler->display->display_options['style_options']['hide_empty'] = 1;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '-1';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '0';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['clone_of_browse_observations_map'] = $view;

  $view = new view();
  $view->name = 'pictures_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Browse Pictures Map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Pictures Map';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_location' => 'field_location',
    'field_image' => 'field_image',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_location']['type'] = 'geofield_map_map';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'geofield_map_width' => '100%',
    'geofield_map_height' => '300px',
    'geofield_map_center' => array(
      'lat' => '',
      'lon' => '',
      'geocode' => 'Find my location',
    ),
    'geofield_map_zoom' => '8',
    'geofield_map_min_zoom' => '0',
    'geofield_map_max_zoom' => '0',
    'geofield_map_controltype' => 'default',
    'geofield_map_mtc' => 'standard',
    'geofield_map_pancontrol' => 1,
    'geofield_map_maptype' => 'map',
    'geofield_map_baselayers_map' => 1,
    'geofield_map_baselayers_satellite' => 1,
    'geofield_map_baselayers_hybrid' => 1,
    'geofield_map_baselayers_physical' => 0,
    'geofield_map_scale' => 0,
    'geofield_map_overview' => 0,
    'geofield_map_overview_opened' => 0,
    'geofield_map_scrollwheel' => 0,
    'geofield_map_draggable' => 0,
    'geofield_map_streetview_show' => 0,
  );
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Tooltip';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[title]
[field_image]';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'picture' => 'picture',
  );
  /* Filter criterion: Content: Location (field_location:geom) */
  $handler->display->display_options['filters']['field_location_geom']['id'] = 'field_location_geom';
  $handler->display->display_options['filters']['field_location_geom']['table'] = 'field_data_field_location';
  $handler->display->display_options['filters']['field_location_geom']['field'] = 'field_location_geom';
  $handler->display->display_options['filters']['field_location_geom']['operator'] = '!=';
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>';
  $handler->display->display_options['filters']['created']['value']['value'] = '-2 weeks';
  $handler->display->display_options['filters']['created']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Date contributed';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title contains';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_geojson_feed';
  $handler->display->display_options['style_options']['data_source']['value'] = 'geofield';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_location';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'title';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'title';
  $handler->display->display_options['style_options']['data_source']['description_field'] = 'field_image';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'browse/pictures/feed.geojson';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['pictures_map'] = $view;

  return $export;
}
