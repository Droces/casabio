<?php
/**
 * @file
 * views_contribute.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_contribute_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'contribute_mo_habitats';
  $view->description = '';
  $view->tag = 'contribute';
  $view->base_table = 'node';
  $view->human_name = 'Contribute: Habitats';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'non-list cols';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Learn more.';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Learn <a href="/help/habitat-records">about this step</a>.';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['label'] = 'Heading: Habitats recorded';
  $handler->display->display_options['header']['area_1']['content'] = '<h2>Habitats recorded</h2>';
  $handler->display->display_options['header']['area_1']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No habitats recorded.';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You haven\'t recorded any habitats yet.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
    'habitat_record' => 'habitat_record',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'contribute/habitats';
  $export['contribute_mo_habitats'] = $view;

  $view = new view();
  $view->name = 'contribute_observations_info';
  $view->description = '';
  $view->tag = 'contribute';
  $view->base_table = 'node';
  $view->human_name = 'Contribute: Observations Info';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contribute Observations Info';
  $handler->display->display_options['css_class'] = 'selectables';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'selectable node-observation displayed-as-node';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'content';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No observations to edit';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no observations for you to edit…';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Pictures in observation */
  $handler->display->display_options['fields']['field_pictures_observation_1']['id'] = 'field_pictures_observation_1';
  $handler->display->display_options['fields']['field_pictures_observation_1']['table'] = 'field_data_field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation_1']['field'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation_1']['label'] = '';
  $handler->display->display_options['fields']['field_pictures_observation_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pictures_observation_1']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_pictures_observation_1']['settings'] = array(
    'view_mode' => 'small',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_pictures_observation_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_pictures_observation_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_pictures_observation_1']['separator'] = '';
  /* Field: Content: Pictures in observation */
  $handler->display->display_options['fields']['field_pictures_observation']['id'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['table'] = 'field_data_field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['field'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['label'] = '';
  $handler->display->display_options['fields']['field_pictures_observation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pictures_observation']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_pictures_observation']['settings'] = array(
    'view_mode' => 'thumbnail',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_pictures_observation']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_pictures_observation']['delta_offset'] = '1';
  $handler->display->display_options['fields']['field_pictures_observation']['separator'] = '';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_type'] = 'div';
  $handler->display->display_options['fields']['nid']['element_class'] = 'property-nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Expand';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Pictures in observation */
  $handler->display->display_options['fields']['field_pictures_observation_2']['id'] = 'field_pictures_observation_2';
  $handler->display->display_options['fields']['field_pictures_observation_2']['table'] = 'field_data_field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation_2']['field'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pictures_observation_2']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_pictures_observation_2']['settings'] = array(
    'view_mode' => 'medium',
    'links' => 0,
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  $handler->display->display_options['fields']['field_pictures_observation_2']['delta_offset'] = '0';
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'nothing';
  $handler->display->display_options['fields']['colorbox']['popup'] = '[field_pictures_observation_2]';
  $handler->display->display_options['fields']['colorbox']['gid'] = 1;
  $handler->display->display_options['fields']['colorbox']['width'] = '800px';
  $handler->display->display_options['fields']['colorbox']['height'] = '600px';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="selectable-target"></div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Content: Pictures in observation */
  $handler->display->display_options['fields']['field_pictures_observation_3']['id'] = 'field_pictures_observation_3';
  $handler->display->display_options['fields']['field_pictures_observation_3']['table'] = 'field_data_field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation_3']['field'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation_3']['label'] = '';
  $handler->display->display_options['fields']['field_pictures_observation_3']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pictures_observation_3']['alter']['text'] = 'link';
  $handler->display->display_options['fields']['field_pictures_observation_3']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_pictures_observation_3']['alter']['path'] = 'sites/default/files/styles/very_large_cropped/public/[field_pictures_observation_3]';
  $handler->display->display_options['fields']['field_pictures_observation_3']['alter']['rel'] = '[nid]';
  $handler->display->display_options['fields']['field_pictures_observation_3']['alter']['link_class'] = 'colorbox';
  $handler->display->display_options['fields']['field_pictures_observation_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pictures_observation_3']['settings'] = array(
    'link' => 0,
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  $handler->display->display_options['fields']['field_pictures_observation_3']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_pictures_observation_3']['separator'] = '';
  /* Contextual filter: Content: Collection (field_collection) */
  $handler->display->display_options['arguments']['field_collection_target_id']['id'] = 'field_collection_target_id';
  $handler->display->display_options['arguments']['field_collection_target_id']['table'] = 'field_data_field_collection';
  $handler->display->display_options['arguments']['field_collection_target_id']['field'] = 'field_collection_target_id';
  $handler->display->display_options['arguments']['field_collection_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_collection_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_collection_target_id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_collection_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_collection_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_collection_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_collection_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_collection_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_collection_target_id']['validate_options']['types'] = array(
    'collection' => 'collection',
  );
  $handler->display->display_options['arguments']['field_collection_target_id']['validate_options']['access'] = TRUE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['contribute_observations_info'] = $view;

  $view = new view();
  $view->name = 'contribute_pictures_info';
  $view->description = '';
  $view->tag = 'contribute';
  $view->base_table = 'node';
  $view->human_name = 'Contribute: Pictures info';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'selectables groupables';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '80';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'node node-picture size-medium selectable';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'content';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No pictures to edit';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no pictures for you to edit…';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: image */
  $handler->display->display_options['relationships']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['relationships']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['relationships']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['relationships']['field_image_fid']['ui_name'] = 'image';
  $handler->display->display_options['relationships']['field_image_fid']['label'] = 'image';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium_square',
    'image_link' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_class'] = 'property-nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="selectable-target"></div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Expand';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'very_large',
    'image_link' => 'file',
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  $handler->display->display_options['fields']['field_image_1']['field_api_classes'] = TRUE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'nothing_1';
  $handler->display->display_options['fields']['colorbox']['popup'] = '[field_image_1]';
  $handler->display->display_options['fields']['colorbox']['gid'] = 1;
  $handler->display->display_options['fields']['colorbox']['width'] = '800px';
  $handler->display->display_options['fields']['colorbox']['height'] = '600px';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['relationship'] = 'field_image_fid';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['filename']['alter']['text'] = 'lightbox';
  $handler->display->display_options['fields']['filename']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['filename']['alter']['path'] = 'sites/default/files/styles/very_large_cropped/public/[filename]';
  $handler->display->display_options['fields']['filename']['alter']['rel'] = '[nid]';
  $handler->display->display_options['fields']['filename']['alter']['link_class'] = 'colorbox';
  $handler->display->display_options['fields']['filename']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['filename']['link_to_file'] = FALSE;
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Contextual filter: Content: Collection (field_collection) */
  $handler->display->display_options['arguments']['field_collection_target_id']['id'] = 'field_collection_target_id';
  $handler->display->display_options['arguments']['field_collection_target_id']['table'] = 'field_data_field_collection';
  $handler->display->display_options['arguments']['field_collection_target_id']['field'] = 'field_collection_target_id';
  $handler->display->display_options['arguments']['field_collection_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_collection_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_collection_target_id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_collection_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_collection_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_collection_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_collection_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_collection_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_collection_target_id']['validate_options']['types'] = array(
    'collection' => 'collection',
  );
  $handler->display->display_options['arguments']['field_collection_target_id']['validate_options']['access'] = TRUE;
  $handler->display->display_options['arguments']['field_collection_target_id']['validate']['fail'] = 'empty';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'picture' => 'picture',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['contribute_pictures_info'] = $view;

  $view = new view();
  $view->name = 'group_pictures';
  $view->description = '';
  $view->tag = 'contribute';
  $view->base_table = 'node';
  $view->human_name = 'Contribute: Group pictures';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'selectables groupables';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1000';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'node node-picture size-medium selectable groupable';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'content';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No pictures to group';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There aren\'t any pictures to group…';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Author of picture */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['ui_name'] = 'Author of picture';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author of picture';
  /* Relationship: Observation */
  $handler->display->display_options['relationships']['reverse_field_pictures_observation_node']['id'] = 'reverse_field_pictures_observation_node';
  $handler->display->display_options['relationships']['reverse_field_pictures_observation_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_pictures_observation_node']['field'] = 'reverse_field_pictures_observation_node';
  $handler->display->display_options['relationships']['reverse_field_pictures_observation_node']['ui_name'] = 'Observation';
  $handler->display->display_options['relationships']['reverse_field_pictures_observation_node']['label'] = 'Observation';
  /* Relationship: Collection */
  $handler->display->display_options['relationships']['field_collection_target_id']['id'] = 'field_collection_target_id';
  $handler->display->display_options['relationships']['field_collection_target_id']['table'] = 'field_data_field_collection';
  $handler->display->display_options['relationships']['field_collection_target_id']['field'] = 'field_collection_target_id';
  $handler->display->display_options['relationships']['field_collection_target_id']['ui_name'] = 'Collection';
  $handler->display->display_options['relationships']['field_collection_target_id']['label'] = 'Collection';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'field image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium_square',
    'image_link' => '',
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_wrapper_class'] = 'property-nid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'reverse_field_pictures_observation_node';
  $handler->display->display_options['fields']['nid_1']['label'] = 'Observation';
  $handler->display->display_options['fields']['nid_1']['element_wrapper_class'] = 'field nid-observation';
  $handler->display->display_options['fields']['nid_1']['hide_empty'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Expand';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['label'] = 'Image, very large';
  $handler->display->display_options['fields']['field_image_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'very_large_cropped',
    'image_link' => '',
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'nothing';
  $handler->display->display_options['fields']['colorbox']['popup'] = '[field_image_1]';
  $handler->display->display_options['fields']['colorbox']['gid'] = 1;
  $handler->display->display_options['fields']['colorbox']['width'] = '800px';
  $handler->display->display_options['fields']['colorbox']['height'] = '600px';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="selectable-target"></div>
<span class="field-data"></span>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Date taken */
  $handler->display->display_options['fields']['field_date_taken']['id'] = 'field_date_taken';
  $handler->display->display_options['fields']['field_date_taken']['table'] = 'field_data_field_date_taken';
  $handler->display->display_options['fields']['field_date_taken']['field'] = 'field_date_taken';
  $handler->display->display_options['fields']['field_date_taken']['settings'] = array(
    'format_type' => 'unix_timestamp',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Sort criterion: Content: Date taken (field_date_taken) */
  $handler->display->display_options['sorts']['field_date_taken_value']['id'] = 'field_date_taken_value';
  $handler->display->display_options['sorts']['field_date_taken_value']['table'] = 'field_data_field_date_taken';
  $handler->display->display_options['sorts']['field_date_taken_value']['field'] = 'field_date_taken_value';
  $handler->display->display_options['sorts']['field_date_taken_value']['expose']['label'] = 'Date taken';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_collection_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['value'] = '1';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'picture' => 'picture',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'contribute/multiple-observations/group';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Group';
  $handler->display->display_options['menu']['description'] = 'Group pictures into observations';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-contribute-stages';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['group_pictures'] = $view;

  $view = new view();
  $view->name = 'observations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Contribute MO: Picture info';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'selectables groupables';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '80';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'node node-picture size-medium selectable';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'content';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No pictures to edit';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no pictures for you to edit…';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Subject */
  $handler->display->display_options['relationships']['field_subject_tid']['id'] = 'field_subject_tid';
  $handler->display->display_options['relationships']['field_subject_tid']['table'] = 'field_data_field_subject';
  $handler->display->display_options['relationships']['field_subject_tid']['field'] = 'field_subject_tid';
  $handler->display->display_options['relationships']['field_subject_tid']['ui_name'] = 'Subject';
  $handler->display->display_options['relationships']['field_subject_tid']['label'] = 'Subject';
  /* Relationship: Tags */
  $handler->display->display_options['relationships']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['relationships']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid']['ui_name'] = 'Tags';
  $handler->display->display_options['relationships']['field_tags_tid']['label'] = 'Tags';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium_square',
    'image_link' => '',
  );
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Date taken */
  $handler->display->display_options['fields']['field_date_taken']['id'] = 'field_date_taken';
  $handler->display->display_options['fields']['field_date_taken']['table'] = 'field_data_field_date_taken';
  $handler->display->display_options['fields']['field_date_taken']['field'] = 'field_date_taken';
  $handler->display->display_options['fields']['field_date_taken']['label'] = '';
  $handler->display->display_options['fields']['field_date_taken']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_taken']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_date_taken']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Content: Species */
  $handler->display->display_options['fields']['field_identified_species']['id'] = 'field_identified_species';
  $handler->display->display_options['fields']['field_identified_species']['table'] = 'field_data_field_identified_species';
  $handler->display->display_options['fields']['field_identified_species']['field'] = 'field_identified_species';
  $handler->display->display_options['fields']['field_identified_species']['label'] = '';
  $handler->display->display_options['fields']['field_identified_species']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_identified_species']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_identified_species']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Beauty */
  $handler->display->display_options['fields']['field_beauty']['id'] = 'field_beauty';
  $handler->display->display_options['fields']['field_beauty']['table'] = 'field_data_field_beauty';
  $handler->display->display_options['fields']['field_beauty']['field'] = 'field_beauty';
  $handler->display->display_options['fields']['field_beauty']['label'] = '';
  $handler->display->display_options['fields']['field_beauty']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_beauty']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_beauty']['type'] = 'list_key';
  /* Field: Content: Usefulness */
  $handler->display->display_options['fields']['field_usefulness']['id'] = 'field_usefulness';
  $handler->display->display_options['fields']['field_usefulness']['table'] = 'field_data_field_usefulness';
  $handler->display->display_options['fields']['field_usefulness']['field'] = 'field_usefulness';
  $handler->display->display_options['fields']['field_usefulness']['label'] = '';
  $handler->display->display_options['fields']['field_usefulness']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_usefulness']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_usefulness']['type'] = 'list_key';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Tags */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['relationship'] = 'field_tags_tid';
  $handler->display->display_options['fields']['tid_1']['ui_name'] = 'Tags';
  $handler->display->display_options['fields']['tid_1']['label'] = '';
  $handler->display->display_options['fields']['tid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid_1']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['tid_1']['element_wrapper_class'] = 'views-field views-field-field-tags';
  $handler->display->display_options['fields']['tid_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['tid_1']['empty_zero'] = TRUE;
  /* Field: term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'field_subject_tid';
  $handler->display->display_options['fields']['tid']['ui_name'] = 'term ID';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['tid']['element_wrapper_class'] = 'views-field views-field-field-subject';
  $handler->display->display_options['fields']['tid']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['tid']['empty_zero'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<header><h3>[title_1]</h3></header>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Activity */
  $handler->display->display_options['fields']['field_interaction_activity']['id'] = 'field_interaction_activity';
  $handler->display->display_options['fields']['field_interaction_activity']['table'] = 'field_data_field_interaction_activity';
  $handler->display->display_options['fields']['field_interaction_activity']['field'] = 'field_interaction_activity';
  $handler->display->display_options['fields']['field_interaction_activity']['label'] = '';
  $handler->display->display_options['fields']['field_interaction_activity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_interaction_activity']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_interaction_activity']['type'] = 'list_key';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_interaction_subject']['id'] = 'field_interaction_subject';
  $handler->display->display_options['fields']['field_interaction_subject']['table'] = 'field_data_field_interaction_subject';
  $handler->display->display_options['fields']['field_interaction_subject']['field'] = 'field_interaction_subject';
  $handler->display->display_options['fields']['field_interaction_subject']['label'] = '';
  $handler->display->display_options['fields']['field_interaction_subject']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_interaction_subject']['hide_empty'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Fields completed progress';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="progress"></div>';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'progress-container';
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Contextual filter: Content: Collection (field_collection) */
  $handler->display->display_options['arguments']['field_collection_target_id']['id'] = 'field_collection_target_id';
  $handler->display->display_options['arguments']['field_collection_target_id']['table'] = 'field_data_field_collection';
  $handler->display->display_options['arguments']['field_collection_target_id']['field'] = 'field_collection_target_id';
  $handler->display->display_options['arguments']['field_collection_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_collection_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_collection_target_id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_collection_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_collection_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_collection_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_collection_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_collection_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_collection_target_id']['validate_options']['types'] = array(
    'collection' => 'collection',
  );
  $handler->display->display_options['arguments']['field_collection_target_id']['validate_options']['access'] = TRUE;
  $handler->display->display_options['arguments']['field_collection_target_id']['validate']['fail'] = 'empty';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'picture' => 'picture',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['observations'] = $view;

  $view = new view();
  $view->name = 'tag';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Contribute MO: Observation Info';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contribute Observations Info';
  $handler->display->display_options['css_class'] = 'selectables';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'selectable node-observation displayed-as-node';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'content';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No observations to edit';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no observations for you to edit…';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Pictures in observation */
  $handler->display->display_options['fields']['field_pictures_observation_1']['id'] = 'field_pictures_observation_1';
  $handler->display->display_options['fields']['field_pictures_observation_1']['table'] = 'field_data_field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation_1']['field'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation_1']['label'] = '';
  $handler->display->display_options['fields']['field_pictures_observation_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pictures_observation_1']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_pictures_observation_1']['settings'] = array(
    'view_mode' => 'small',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_pictures_observation_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_pictures_observation_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_pictures_observation_1']['separator'] = '';
  /* Field: Content: Pictures in observation */
  $handler->display->display_options['fields']['field_pictures_observation']['id'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['table'] = 'field_data_field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['field'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['label'] = '';
  $handler->display->display_options['fields']['field_pictures_observation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pictures_observation']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_pictures_observation']['settings'] = array(
    'view_mode' => 'thumbnail',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_pictures_observation']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_pictures_observation']['delta_offset'] = '1';
  $handler->display->display_options['fields']['field_pictures_observation']['separator'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Collection */
  $handler->display->display_options['fields']['field_collection']['id'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['table'] = 'field_data_field_collection';
  $handler->display->display_options['fields']['field_collection']['field'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['label'] = '';
  $handler->display->display_options['fields']['field_collection']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_collection']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_collection']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_collection']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Count */
  $handler->display->display_options['fields']['field_count']['id'] = 'field_count';
  $handler->display->display_options['fields']['field_count']['table'] = 'field_data_field_count';
  $handler->display->display_options['fields']['field_count']['field'] = 'field_count';
  $handler->display->display_options['fields']['field_count']['label'] = '';
  $handler->display->display_options['fields']['field_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_count']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_count']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Name of observer */
  $handler->display->display_options['fields']['field_observer_name']['id'] = 'field_observer_name';
  $handler->display->display_options['fields']['field_observer_name']['table'] = 'field_data_field_observer_name';
  $handler->display->display_options['fields']['field_observer_name']['field'] = 'field_observer_name';
  $handler->display->display_options['fields']['field_observer_name']['label'] = '';
  $handler->display->display_options['fields']['field_observer_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_observer_name']['hide_empty'] = TRUE;
  /* Field: Content: Date observed */
  $handler->display->display_options['fields']['field_date_observed']['id'] = 'field_date_observed';
  $handler->display->display_options['fields']['field_date_observed']['table'] = 'field_data_field_date_observed';
  $handler->display->display_options['fields']['field_date_observed']['field'] = 'field_date_observed';
  $handler->display->display_options['fields']['field_date_observed']['label'] = '';
  $handler->display->display_options['fields']['field_date_observed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_observed']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_date_observed']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '100',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_location']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'centroid',
    'format' => 'decimal_degrees',
    'labels' => 0,
  );
  /* Field: Content: Locality */
  $handler->display->display_options['fields']['field_locality']['id'] = 'field_locality';
  $handler->display->display_options['fields']['field_locality']['table'] = 'field_data_field_locality';
  $handler->display->display_options['fields']['field_locality']['field'] = 'field_locality';
  $handler->display->display_options['fields']['field_locality']['label'] = '';
  $handler->display->display_options['fields']['field_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_locality']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_locality']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_locality']['delta_offset'] = '0';
  /* Field: Content: Habitat */
  $handler->display->display_options['fields']['field_habitat']['id'] = 'field_habitat';
  $handler->display->display_options['fields']['field_habitat']['table'] = 'field_data_field_habitat';
  $handler->display->display_options['fields']['field_habitat']['field'] = 'field_habitat';
  $handler->display->display_options['fields']['field_habitat']['label'] = '';
  $handler->display->display_options['fields']['field_habitat']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_habitat']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_habitat']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_habitat']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_habitat']['delta_limit'] = '5';
  $handler->display->display_options['fields']['field_habitat']['delta_offset'] = '0';
  /* Field: Content: Species */
  $handler->display->display_options['fields']['field_identified_species']['id'] = 'field_identified_species';
  $handler->display->display_options['fields']['field_identified_species']['table'] = 'field_data_field_identified_species';
  $handler->display->display_options['fields']['field_identified_species']['field'] = 'field_identified_species';
  $handler->display->display_options['fields']['field_identified_species']['label'] = '';
  $handler->display->display_options['fields']['field_identified_species']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_identified_species']['hide_empty'] = TRUE;
  /* Field: Content: Specimen ID */
  $handler->display->display_options['fields']['field_specimen_id']['id'] = 'field_specimen_id';
  $handler->display->display_options['fields']['field_specimen_id']['table'] = 'field_data_field_specimen_id';
  $handler->display->display_options['fields']['field_specimen_id']['field'] = 'field_specimen_id';
  $handler->display->display_options['fields']['field_specimen_id']['label'] = '';
  $handler->display->display_options['fields']['field_specimen_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_specimen_id']['hide_empty'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<header>
<h3>[title]</h3>
<div class="field"><label>Species: </label><span class=\'value\'>[field_identified_species]</span></div>
<div class="field"><label>Habitat: </label><span class=\'value\'>[field_habitat]</span></div>
<div class="field"><label>Locality: </label><span class=\'value\'>[field_locality]</span></div>
<div class="field"><label>Location: </label><span class=\'value\'>[field_location]</span></div>
<div class="field"><label>Nid: </label><span class=\'value\'>[nid]</span></div>
<div class="field">[edit_node], [delete_node]</div>
</header>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_mls_probability']['id'] = 'field_mls_probability';
  $handler->display->display_options['fields']['field_mls_probability']['table'] = 'field_data_field_mls_probability';
  $handler->display->display_options['fields']['field_mls_probability']['field'] = 'field_mls_probability';
  $handler->display->display_options['fields']['field_mls_probability']['label'] = 'MLS probability';
  $handler->display->display_options['fields']['field_mls_probability']['exclude'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_most_likely_species']['id'] = 'field_most_likely_species';
  $handler->display->display_options['fields']['field_most_likely_species']['table'] = 'field_data_field_most_likely_species';
  $handler->display->display_options['fields']['field_most_likely_species']['field'] = 'field_most_likely_species';
  $handler->display->display_options['fields']['field_most_likely_species']['label'] = 'Most likely species';
  $handler->display->display_options['fields']['field_most_likely_species']['exclude'] = TRUE;
  /* Contextual filter: Content: Collection (field_collection) */
  $handler->display->display_options['arguments']['field_collection_target_id']['id'] = 'field_collection_target_id';
  $handler->display->display_options['arguments']['field_collection_target_id']['table'] = 'field_data_field_collection';
  $handler->display->display_options['arguments']['field_collection_target_id']['field'] = 'field_collection_target_id';
  $handler->display->display_options['arguments']['field_collection_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_collection_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_collection_target_id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_collection_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_collection_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_collection_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_collection_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_collection_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_collection_target_id']['validate_options']['types'] = array(
    'collection' => 'collection',
  );
  $handler->display->display_options['arguments']['field_collection_target_id']['validate_options']['access'] = TRUE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['tag'] = $view;

  return $export;
}
