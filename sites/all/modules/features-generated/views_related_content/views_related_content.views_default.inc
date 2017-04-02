<?php
/**
 * @file
 * views_related_content.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_related_content_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'collection_report';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Collection Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Collection Report';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No observations found';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry; no observations were found for this collection.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Collection */
  $handler->display->display_options['relationships']['field_collection_target_id']['id'] = 'field_collection_target_id';
  $handler->display->display_options['relationships']['field_collection_target_id']['table'] = 'field_data_field_collection';
  $handler->display->display_options['relationships']['field_collection_target_id']['field'] = 'field_collection_target_id';
  $handler->display->display_options['relationships']['field_collection_target_id']['ui_name'] = 'Collection';
  $handler->display->display_options['relationships']['field_collection_target_id']['label'] = 'Collection';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_main_image_target_id']['id'] = 'field_main_image_target_id';
  $handler->display->display_options['relationships']['field_main_image_target_id']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['relationships']['field_main_image_target_id']['field'] = 'field_main_image_target_id';
  $handler->display->display_options['relationships']['field_main_image_target_id']['ui_name'] = 'Main image';
  $handler->display->display_options['relationships']['field_main_image_target_id']['label'] = 'Main image';
  /* Relationship: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['ui_name'] = 'Author';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_main_image_target_id';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date observed */
  $handler->display->display_options['fields']['field_date_observed']['id'] = 'field_date_observed';
  $handler->display->display_options['fields']['field_date_observed']['table'] = 'field_data_field_date_observed';
  $handler->display->display_options['fields']['field_date_observed']['field'] = 'field_date_observed';
  $handler->display->display_options['fields']['field_date_observed']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Identifications */
  $handler->display->display_options['fields']['field_identifications']['id'] = 'field_identifications';
  $handler->display->display_options['fields']['field_identifications']['table'] = 'field_data_field_identifications';
  $handler->display->display_options['fields']['field_identifications']['field'] = 'field_identifications';
  $handler->display->display_options['fields']['field_identifications']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_identifications']['settings'] = array(
    'view_mode' => 'text',
    'links' => 1,
  );
  $handler->display->display_options['fields']['field_identifications']['delta_offset'] = '0';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_location']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
    'format' => 'degrees_minutes_seconds',
    'labels' => 0,
  );
  /* Field: Content: Locality */
  $handler->display->display_options['fields']['field_locality']['id'] = 'field_locality';
  $handler->display->display_options['fields']['field_locality']['table'] = 'field_data_field_locality';
  $handler->display->display_options['fields']['field_locality']['field'] = 'field_locality';
  $handler->display->display_options['fields']['field_locality']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_locality']['delta_offset'] = '0';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid, hidden';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: User: Collector code */
  $handler->display->display_options['fields']['field_collector_code']['id'] = 'field_collector_code';
  $handler->display->display_options['fields']['field_collector_code']['table'] = 'field_data_field_collector_code';
  $handler->display->display_options['fields']['field_collector_code']['field'] = 'field_collector_code';
  $handler->display->display_options['fields']['field_collector_code']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_collector_code']['label'] = 'Specimen code';
  $handler->display->display_options['fields']['field_collector_code']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_collector_code']['alter']['text'] = '[field_collector_code]-[nid]';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_collection_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'collection-report/%';
  $export['collection_report'] = $view;

  $view = new view();
  $view->name = 'identifications_of_observation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Identifications of observation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Identifications of observation';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'non-list fanned';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No content';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No identifications yet.';
  $handler->display->display_options['empty']['area']['format'] = 'raw_html';
  /* Relationship: Observation */
  $handler->display->display_options['relationships']['field_observation_target_id']['id'] = 'field_observation_target_id';
  $handler->display->display_options['relationships']['field_observation_target_id']['table'] = 'field_data_field_observation';
  $handler->display->display_options['relationships']['field_observation_target_id']['field'] = 'field_observation_target_id';
  $handler->display->display_options['relationships']['field_observation_target_id']['ui_name'] = 'Observation';
  $handler->display->display_options['relationships']['field_observation_target_id']['label'] = 'Observation';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Field: Reliability (field_reliability) */
  $handler->display->display_options['sorts']['field_reliability_value']['id'] = 'field_reliability_value';
  $handler->display->display_options['sorts']['field_reliability_value']['table'] = 'field_data_field_reliability';
  $handler->display->display_options['sorts']['field_reliability_value']['field'] = 'field_reliability_value';
  $handler->display->display_options['sorts']['field_reliability_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_observation_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'identification_community' => 'identification_community',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['identifications_of_observation'] = $view;

  $view = new view();
  $view->name = 'image_of_taxon_reference_widget';
  $view->description = 'This is a basic view ready to use with entity reference view widget. Feel free to edit it or create another.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Image of Taxon Reference Widget';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['total_pages'] = '2';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = '8';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No pictures';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No pictures in observation.';
  $handler->display->display_options['empty']['area']['format'] = 'raw_html';
  /* Relationship: Observation */
  $handler->display->display_options['relationships']['reverse_field_pictures_observation_node']['id'] = 'reverse_field_pictures_observation_node';
  $handler->display->display_options['relationships']['reverse_field_pictures_observation_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_pictures_observation_node']['field'] = 'reverse_field_pictures_observation_node';
  $handler->display->display_options['relationships']['reverse_field_pictures_observation_node']['ui_name'] = 'Observation';
  $handler->display->display_options['relationships']['reverse_field_pictures_observation_node']['label'] = 'Observation';
  /* Relationship: Identifications */
  $handler->display->display_options['relationships']['field_identifications_target_id']['id'] = 'field_identifications_target_id';
  $handler->display->display_options['relationships']['field_identifications_target_id']['table'] = 'field_data_field_identifications';
  $handler->display->display_options['relationships']['field_identifications_target_id']['field'] = 'field_identifications_target_id';
  $handler->display->display_options['relationships']['field_identifications_target_id']['relationship'] = 'reverse_field_pictures_observation_node';
  $handler->display->display_options['relationships']['field_identifications_target_id']['ui_name'] = 'Identifications';
  $handler->display->display_options['relationships']['field_identifications_target_id']['label'] = 'Identifications';
  /* Relationship: Identified species */
  $handler->display->display_options['relationships']['field_identified_species_tid']['id'] = 'field_identified_species_tid';
  $handler->display->display_options['relationships']['field_identified_species_tid']['table'] = 'field_data_field_identified_species';
  $handler->display->display_options['relationships']['field_identified_species_tid']['field'] = 'field_identified_species_tid';
  $handler->display->display_options['relationships']['field_identified_species_tid']['relationship'] = 'field_identifications_target_id';
  $handler->display->display_options['relationships']['field_identified_species_tid']['ui_name'] = 'Identified species';
  $handler->display->display_options['relationships']['field_identified_species_tid']['label'] = 'Identified species';
  /* Field: Entity Reference View Widget Checkbox: Content */
  $handler->display->display_options['fields']['entityreference_view_widget']['id'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['table'] = 'node';
  $handler->display->display_options['fields']['entityreference_view_widget']['field'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['label'] = '';
  $handler->display->display_options['fields']['entityreference_view_widget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['entityreference_view_widget']['ervw']['force_single'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_identified_species_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
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

  /* Display: Entity Reference View Widget */
  $handler = $view->new_display('entityreference_view_widget', 'Entity Reference View Widget', 'entityreference_view_widget_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'entityreference_view_widget' => 'entityreference_view_widget',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'entityreference_view_widget' => array(
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
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'entityreference_view_widget' => 'entityreference_view_widget',
    'field_image' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['image_of_taxon_reference_widget'] = $view;

  $view = new view();
  $view->name = 'interactions_of_observation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Interactions of observation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Identifications of observation';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'non-list fanned';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No content';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No identifications yet.';
  $handler->display->display_options['empty']['area']['format'] = 'raw_html';
  /* Relationship: Observation */
  $handler->display->display_options['relationships']['field_observation_target_id']['id'] = 'field_observation_target_id';
  $handler->display->display_options['relationships']['field_observation_target_id']['table'] = 'field_data_field_observation';
  $handler->display->display_options['relationships']['field_observation_target_id']['field'] = 'field_observation_target_id';
  $handler->display->display_options['relationships']['field_observation_target_id']['ui_name'] = 'Observation';
  $handler->display->display_options['relationships']['field_observation_target_id']['label'] = 'Observation';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Field: Reliability (field_reliability) */
  $handler->display->display_options['sorts']['field_reliability_value']['id'] = 'field_reliability_value';
  $handler->display->display_options['sorts']['field_reliability_value']['table'] = 'field_data_field_reliability';
  $handler->display->display_options['sorts']['field_reliability_value']['field'] = 'field_reliability_value';
  $handler->display->display_options['sorts']['field_reliability_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_observation_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'interaction' => 'interaction',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['interactions_of_observation'] = $view;

  $view = new view();
  $view->name = 'taxon_identifications_locations_template';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Taxon identifications locations template';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Taxon identifications locations template';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Community identification */
  $handler->display->display_options['relationships']['reverse_field_observation_node']['id'] = 'reverse_field_observation_node';
  $handler->display->display_options['relationships']['reverse_field_observation_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_observation_node']['field'] = 'reverse_field_observation_node';
  $handler->display->display_options['relationships']['reverse_field_observation_node']['ui_name'] = 'Community identification';
  $handler->display->display_options['relationships']['reverse_field_observation_node']['label'] = 'Community identification';
  /* Relationship: Species */
  $handler->display->display_options['relationships']['field_identified_species_tid']['id'] = 'field_identified_species_tid';
  $handler->display->display_options['relationships']['field_identified_species_tid']['table'] = 'field_data_field_identified_species';
  $handler->display->display_options['relationships']['field_identified_species_tid']['field'] = 'field_identified_species_tid';
  $handler->display->display_options['relationships']['field_identified_species_tid']['relationship'] = 'reverse_field_observation_node';
  $handler->display->display_options['relationships']['field_identified_species_tid']['ui_name'] = 'Species';
  $handler->display->display_options['relationships']['field_identified_species_tid']['label'] = 'Species';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_location']['type'] = 'geofield_geojson';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_identified_species_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = ' 96540';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_observation_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'identification_community' => 'identification_community',
  );
  /* Filter criterion: Content: Location (field_location:geom) */
  $handler->display->display_options['filters']['field_location_geom']['id'] = 'field_location_geom';
  $handler->display->display_options['filters']['field_location_geom']['table'] = 'field_data_field_location';
  $handler->display->display_options['filters']['field_location_geom']['field'] = 'field_location_geom';
  $handler->display->display_options['filters']['field_location_geom']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'view-template/taxon-identifications-locations';
  $export['taxon_identifications_locations_template'] = $view;

  return $export;
}
