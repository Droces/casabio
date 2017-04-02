<?php
/**
 * @file
 * views_content_administration.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_content_administration_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'admin_observations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Administration: Observations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Administer: Observations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'nid' => 'nid',
    'field_pictures_observation' => 'field_pictures_observation',
    'title' => 'title',
    'name' => 'name',
    'field_location' => 'field_location',
    'created' => 'created',
    'field_date_observed' => 'field_date_observed',
    'changed' => 'changed',
    'title_1' => 'title_1',
    'edit_node' => 'edit_node',
    'delete_node' => 'edit_node',
    'view_node' => 'edit_node',
    'field_collection' => 'field_collection',
    'delta' => 'delta',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
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
    'field_location' => array(
      'sortable' => 0,
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
    'field_date_observed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_collection' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delta' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result_1']['id'] = 'result_1';
  $handler->display->display_options['footer']['result_1']['table'] = 'views';
  $handler->display->display_options['footer']['result_1']['field'] = 'result';
  /* Relationship: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['ui_name'] = 'Author';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  /* Relationship: Collection */
  $handler->display->display_options['relationships']['field_collection_target_id']['id'] = 'field_collection_target_id';
  $handler->display->display_options['relationships']['field_collection_target_id']['table'] = 'field_data_field_collection';
  $handler->display->display_options['relationships']['field_collection_target_id']['field'] = 'field_collection_target_id';
  $handler->display->display_options['relationships']['field_collection_target_id']['ui_name'] = 'Collection';
  $handler->display->display_options['relationships']['field_collection_target_id']['label'] = 'Collection';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
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
  /* Field: Content: Pictures in observation */
  $handler->display->display_options['fields']['field_pictures_observation']['id'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['table'] = 'field_data_field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['field'] = 'field_pictures_observation';
  $handler->display->display_options['fields']['field_pictures_observation']['label'] = 'Main picture';
  $handler->display->display_options['fields']['field_pictures_observation']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_pictures_observation']['settings'] = array(
    'view_mode' => 'inline',
    'links' => 0,
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
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
  $handler->display->display_options['fields']['name']['label'] = 'Contributor';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Collection */
  $handler->display->display_options['fields']['field_collection']['id'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['table'] = 'field_data_field_collection';
  $handler->display->display_options['fields']['field_collection']['field'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['settings'] = array(
    'link' => 0,
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Field: Content: Identifications (field_identifications:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_identifications';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['label'] = 'Identifications';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date contributed';
  $handler->display->display_options['fields']['created']['date_format'] = 'raw time ago';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
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
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_collection_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '<h3>Collection: [title_1]</h3>';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['empty'] = '<h3>No collection</h3>';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['text'] = 'view';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'field_collection_target_id';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created_1']['id'] = 'created_1';
  $handler->display->display_options['sorts']['created_1']['table'] = 'node';
  $handler->display->display_options['sorts']['created_1']['field'] = 'created';
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
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_collection_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Collection';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Updated date */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = '>=';
  $handler->display->display_options['filters']['changed']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['changed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['changed']['expose']['operator_id'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['label'] = 'Updated date';
  $handler->display->display_options['filters']['changed']['expose']['description'] = 'An offset from the current date, such as "-1 day"';
  $handler->display->display_options['filters']['changed']['expose']['operator'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['identifier'] = 'changed';
  $handler->display->display_options['filters']['changed']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
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
  $handler->display->display_options['filters']['field_identifications_target_id']['group_info']['label'] = 'Identifications (field_identifications)';
  $handler->display->display_options['filters']['field_identifications_target_id']['group_info']['identifier'] = 'field_identifications_target_id';
  $handler->display->display_options['filters']['field_identifications_target_id']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'No identifications',
      'operator' => 'empty',
      'value' => array(
        'value' => '.',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Has identifications',
      'operator' => 'not empty',
      'value' => array(
        'value' => '.',
        'min' => '',
        'max' => '',
      ),
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/observations';
  $export['admin_observations'] = $view;

  $view = new view();
  $view->name = 'admin_pictures';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Administration: Pictures';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Administer: Pictures';
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
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_image' => 'field_image',
    'nid' => 'nid',
    'uid' => 'uid',
    'title' => 'title',
    'nid_1' => 'nid_1',
    'field_date_taken' => 'field_date_taken',
    'body' => 'body',
    'field_identified_species' => 'field_identified_species',
    'field_location' => 'field_location',
    'tid_1' => 'tid_1',
    'tid' => 'tid',
    'changed' => 'changed',
    'edit_node' => 'edit_node',
    'delete_node' => 'edit_node',
    'title_1' => 'title_1',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
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
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_taken' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_identified_species' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_location' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tid_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = '.masonry sizers';
  $handler->display->display_options['header']['area']['content'] = '<div class="masonry-column-sizer"></div><div class="masonry-gutter-sizer"></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
  /* Relationship: Collection */
  $handler->display->display_options['relationships']['field_collection_target_id']['id'] = 'field_collection_target_id';
  $handler->display->display_options['relationships']['field_collection_target_id']['table'] = 'field_data_field_collection';
  $handler->display->display_options['relationships']['field_collection_target_id']['field'] = 'field_collection_target_id';
  $handler->display->display_options['relationships']['field_collection_target_id']['ui_name'] = 'Collection';
  $handler->display->display_options['relationships']['field_collection_target_id']['label'] = 'Collection';
  /* Relationship: Observation */
  $handler->display->display_options['relationships']['reverse_field_pictures_observation_node']['id'] = 'reverse_field_pictures_observation_node';
  $handler->display->display_options['relationships']['reverse_field_pictures_observation_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_pictures_observation_node']['field'] = 'reverse_field_pictures_observation_node';
  $handler->display->display_options['relationships']['reverse_field_pictures_observation_node']['ui_name'] = 'Observation';
  $handler->display->display_options['relationships']['reverse_field_pictures_observation_node']['label'] = 'Observation';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Author';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'reverse_field_pictures_observation_node';
  $handler->display->display_options['fields']['nid_1']['label'] = 'Observation';
  $handler->display->display_options['fields']['nid_1']['link_to_node'] = TRUE;
  /* Field: Content: Date taken */
  $handler->display->display_options['fields']['field_date_taken']['id'] = 'field_date_taken';
  $handler->display->display_options['fields']['field_date_taken']['table'] = 'field_data_field_date_taken';
  $handler->display->display_options['fields']['field_date_taken']['field'] = 'field_date_taken';
  $handler->display->display_options['fields']['field_date_taken']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Collection */
  $handler->display->display_options['fields']['field_collection']['id'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['table'] = 'field_data_field_collection';
  $handler->display->display_options['fields']['field_collection']['field'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['settings'] = array(
    'link' => 0,
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '50',
  );
  /* Field: Content: Species */
  $handler->display->display_options['fields']['field_identified_species']['id'] = 'field_identified_species';
  $handler->display->display_options['fields']['field_identified_species']['table'] = 'field_data_field_identified_species';
  $handler->display->display_options['fields']['field_identified_species']['field'] = 'field_identified_species';
  $handler->display->display_options['fields']['field_identified_species']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_identified_species']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_location']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 0,
  );
  /* Field: Tags */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['relationship'] = 'field_tags_tid';
  $handler->display->display_options['fields']['tid_1']['ui_name'] = 'Tags';
  $handler->display->display_options['fields']['tid_1']['label'] = 'Tags';
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
  $handler->display->display_options['fields']['tid']['label'] = 'Subject';
  $handler->display->display_options['fields']['tid']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['tid']['element_wrapper_class'] = 'views-field views-field-field-subject';
  $handler->display->display_options['fields']['tid']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['tid']['empty_zero'] = TRUE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_collection_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '<h3>Collection: [title_1]</h3>';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['empty'] = '<h3>No collection</h3>';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'field_collection_target_id';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created_1']['id'] = 'created_1';
  $handler->display->display_options['sorts']['created_1']['table'] = 'node';
  $handler->display->display_options['sorts']['created_1']['field'] = 'created';
  /* Contextual filter: Content: Collection (field_collection) */
  $handler->display->display_options['arguments']['field_collection_target_id']['id'] = 'field_collection_target_id';
  $handler->display->display_options['arguments']['field_collection_target_id']['table'] = 'field_data_field_collection';
  $handler->display->display_options['arguments']['field_collection_target_id']['field'] = 'field_collection_target_id';
  $handler->display->display_options['arguments']['field_collection_target_id']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_collection_target_id']['title'] = 'Edit Information of %1 Pictures';
  $handler->display->display_options['arguments']['field_collection_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_collection_target_id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_collection_target_id']['default_argument_options']['use_alias'] = TRUE;
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
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_collection_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Collection';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/pictures';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Picture info';
  $handler->display->display_options['menu']['description'] = 'Edit information of the pictures';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-contribute-stages';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['admin_pictures'] = $view;

  $view = new view();
  $view->name = 'administration_collections';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Administration: Collections';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Administer: Collections';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_collector' => 'field_collector',
    'field_count_observations' => 'field_count_observations',
    'nid' => 'nid',
    'field_date_collected' => 'field_date_collected',
    'changed' => 'changed',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_collector' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_count_observations' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_collected' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
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
  /* Relationship: Content in Collection */
  $handler->display->display_options['relationships']['reverse_field_collection_node']['id'] = 'reverse_field_collection_node';
  $handler->display->display_options['relationships']['reverse_field_collection_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_collection_node']['field'] = 'reverse_field_collection_node';
  $handler->display->display_options['relationships']['reverse_field_collection_node']['ui_name'] = 'Content in Collection';
  $handler->display->display_options['relationships']['reverse_field_collection_node']['label'] = 'Content in Collection';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Collector */
  $handler->display->display_options['fields']['field_collector']['id'] = 'field_collector';
  $handler->display->display_options['fields']['field_collector']['table'] = 'field_data_field_collector';
  $handler->display->display_options['fields']['field_collector']['field'] = 'field_collector';
  /* Field: Content: Number of observations */
  $handler->display->display_options['fields']['field_count_observations']['id'] = 'field_count_observations';
  $handler->display->display_options['fields']['field_count_observations']['table'] = 'field_data_field_count_observations';
  $handler->display->display_options['fields']['field_count_observations']['field'] = 'field_count_observations';
  $handler->display->display_options['fields']['field_count_observations']['label'] = 'Observations';
  $handler->display->display_options['fields']['field_count_observations']['settings'] = array(
    'link' => 0,
    'link_class' => '',
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Field: Content: Number of pictures */
  $handler->display->display_options['fields']['field_count_pictures']['id'] = 'field_count_pictures';
  $handler->display->display_options['fields']['field_count_pictures']['table'] = 'field_data_field_count_pictures';
  $handler->display->display_options['fields']['field_count_pictures']['field'] = 'field_count_pictures';
  $handler->display->display_options['fields']['field_count_pictures']['label'] = 'Pictures';
  $handler->display->display_options['fields']['field_count_pictures']['settings'] = array(
    'link' => 0,
    'link_class' => '',
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_collection_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'In collection';
  /* Field: Content: Date collected */
  $handler->display->display_options['fields']['field_date_collected']['id'] = 'field_date_collected';
  $handler->display->display_options['fields']['field_date_collected']['table'] = 'field_data_field_date_collected';
  $handler->display->display_options['fields']['field_date_collected']['field'] = 'field_date_collected';
  $handler->display->display_options['fields']['field_date_collected']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'medium';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['changed']['timezone'] = 'Africa/Johannesburg';
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
  $handler->display->display_options['path'] = 'admin/collections';
  $export['administration_collections'] = $view;

  $view = new view();
  $view->name = 'administration_feeds_log';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'feeds_log';
  $view->human_name = 'Administration: Feeds log';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Administration: Feeds log';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: Feeds log: Importer id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Feeds log: Log message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  /* Field: Feeds log: Log time */
  $handler->display->display_options['fields']['log_time']['id'] = 'log_time';
  $handler->display->display_options['fields']['log_time']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['log_time']['field'] = 'log_time';
  $handler->display->display_options['fields']['log_time']['date_format'] = 'medium';
  $handler->display->display_options['fields']['log_time']['second_date_format'] = 'long';
  /* Field: Feeds log: Severity */
  $handler->display->display_options['fields']['severity']['id'] = 'severity';
  $handler->display->display_options['fields']['severity']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['severity']['field'] = 'severity';
  /* Filter criterion: Feeds log: Importer id */
  $handler->display->display_options['filters']['id']['id'] = 'id';
  $handler->display->display_options['filters']['id']['table'] = 'feeds_log';
  $handler->display->display_options['filters']['id']['field'] = 'id';
  $handler->display->display_options['filters']['id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['id']['expose']['operator_id'] = 'id_op';
  $handler->display->display_options['filters']['id']['expose']['label'] = 'Importer id';
  $handler->display->display_options['filters']['id']['expose']['operator'] = 'id_op';
  $handler->display->display_options['filters']['id']['expose']['identifier'] = 'id';
  $handler->display->display_options['filters']['id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Feeds log: Log time */
  $handler->display->display_options['filters']['log_time']['id'] = 'log_time';
  $handler->display->display_options['filters']['log_time']['table'] = 'feeds_log';
  $handler->display->display_options['filters']['log_time']['field'] = 'log_time';
  $handler->display->display_options['filters']['log_time']['exposed'] = TRUE;
  $handler->display->display_options['filters']['log_time']['expose']['operator_id'] = 'log_time_op';
  $handler->display->display_options['filters']['log_time']['expose']['label'] = 'Log time';
  $handler->display->display_options['filters']['log_time']['expose']['operator'] = 'log_time_op';
  $handler->display->display_options['filters']['log_time']['expose']['identifier'] = 'log_time';
  $handler->display->display_options['filters']['log_time']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Feeds log: Severity */
  $handler->display->display_options['filters']['severity']['id'] = 'severity';
  $handler->display->display_options['filters']['severity']['table'] = 'feeds_log';
  $handler->display->display_options['filters']['severity']['field'] = 'severity';
  $handler->display->display_options['filters']['severity']['exposed'] = TRUE;
  $handler->display->display_options['filters']['severity']['expose']['operator_id'] = 'severity_op';
  $handler->display->display_options['filters']['severity']['expose']['label'] = 'Severity';
  $handler->display->display_options['filters']['severity']['expose']['operator'] = 'severity_op';
  $handler->display->display_options['filters']['severity']['expose']['identifier'] = 'severity';
  $handler->display->display_options['filters']['severity']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'administration-feeds-log';
  $export['administration_feeds_log'] = $view;

  $view = new view();
  $view->name = 'administration_habitats';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Administration: Habitats';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Administrater: Habitats';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Bulk operations: Taxonomy term */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
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
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Air moisture */
  $handler->display->display_options['fields']['field_air_moisture']['id'] = 'field_air_moisture';
  $handler->display->display_options['fields']['field_air_moisture']['table'] = 'field_data_field_air_moisture';
  $handler->display->display_options['fields']['field_air_moisture']['field'] = 'field_air_moisture';
  /* Field: Field: Geology */
  $handler->display->display_options['fields']['field_geology']['id'] = 'field_geology';
  $handler->display->display_options['fields']['field_geology']['table'] = 'field_data_field_geology';
  $handler->display->display_options['fields']['field_geology']['field'] = 'field_geology';
  /* Field: Field: Land form */
  $handler->display->display_options['fields']['field_land_form']['id'] = 'field_land_form';
  $handler->display->display_options['fields']['field_land_form']['table'] = 'field_data_field_land_form';
  $handler->display->display_options['fields']['field_land_form']['field'] = 'field_land_form';
  /* Field: Field: Land use */
  $handler->display->display_options['fields']['field_land_use']['id'] = 'field_land_use';
  $handler->display->display_options['fields']['field_land_use']['table'] = 'field_data_field_land_use';
  $handler->display->display_options['fields']['field_land_use']['field'] = 'field_land_use';
  /* Field: Taxonomy term: Soil colour */
  $handler->display->display_options['fields']['field_soil_colour']['id'] = 'field_soil_colour';
  $handler->display->display_options['fields']['field_soil_colour']['table'] = 'field_data_field_soil_colour';
  $handler->display->display_options['fields']['field_soil_colour']['field'] = 'field_soil_colour';
  /* Field: Field: Soil type */
  $handler->display->display_options['fields']['field_soil_type']['id'] = 'field_soil_type';
  $handler->display->display_options['fields']['field_soil_type']['table'] = 'field_data_field_soil_type';
  $handler->display->display_options['fields']['field_soil_type']['field'] = 'field_soil_type';
  /* Field: Taxonomy term: Veld age */
  $handler->display->display_options['fields']['field_veld_age']['id'] = 'field_veld_age';
  $handler->display->display_options['fields']['field_veld_age']['table'] = 'field_data_field_veld_age';
  $handler->display->display_options['fields']['field_veld_age']['field'] = 'field_veld_age';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'habitats' => 'habitats',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/habitats';
  $export['administration_habitats'] = $view;

  $view = new view();
  $view->name = 'administration_identifications';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Administration: Identifications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Administration: Identifications';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'nid' => 'nid',
    'type' => 'type',
    'title' => 'title',
    'field_identified_species' => 'field_identified_species',
    'field_observation' => 'field_observation',
    'field_certainty' => 'field_certainty',
    'field_reliability' => 'field_certainty',
    'name' => 'name',
    'field_identification_source' => 'field_identification_source',
    'changed' => 'changed',
    'edit_node' => 'edit_node',
    'delete_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_identified_species' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_observation' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_certainty' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reliability' => array(
      'sortable' => 0,
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
    'field_identification_source' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* Relationship: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['ui_name'] = 'Author';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
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
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
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
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Species */
  $handler->display->display_options['fields']['field_identified_species']['id'] = 'field_identified_species';
  $handler->display->display_options['fields']['field_identified_species']['table'] = 'field_data_field_identified_species';
  $handler->display->display_options['fields']['field_identified_species']['field'] = 'field_identified_species';
  $handler->display->display_options['fields']['field_identified_species']['settings'] = array(
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Field: Content: Observation */
  $handler->display->display_options['fields']['field_observation']['id'] = 'field_observation';
  $handler->display->display_options['fields']['field_observation']['table'] = 'field_data_field_observation';
  $handler->display->display_options['fields']['field_observation']['field'] = 'field_observation';
  $handler->display->display_options['fields']['field_observation']['settings'] = array(
    'link' => 1,
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Field: Content: Certainty */
  $handler->display->display_options['fields']['field_certainty']['id'] = 'field_certainty';
  $handler->display->display_options['fields']['field_certainty']['table'] = 'field_data_field_certainty';
  $handler->display->display_options['fields']['field_certainty']['field'] = 'field_certainty';
  $handler->display->display_options['fields']['field_certainty']['label'] = 'Certainty / Reliability';
  $handler->display->display_options['fields']['field_certainty']['settings'] = array(
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Field: Field: Reliability */
  $handler->display->display_options['fields']['field_reliability']['id'] = 'field_reliability';
  $handler->display->display_options['fields']['field_reliability']['table'] = 'field_data_field_reliability';
  $handler->display->display_options['fields']['field_reliability']['field'] = 'field_reliability';
  $handler->display->display_options['fields']['field_reliability']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Contributor';
  /* Field: Content: Identification source */
  $handler->display->display_options['fields']['field_identification_source']['id'] = 'field_identification_source';
  $handler->display->display_options['fields']['field_identification_source']['table'] = 'field_data_field_identification_source';
  $handler->display->display_options['fields']['field_identification_source']['field'] = 'field_identification_source';
  $handler->display->display_options['fields']['field_identification_source']['label'] = 'Source';
  $handler->display->display_options['fields']['field_identification_source']['settings'] = array(
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'medium';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
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
    'identification_community' => 'identification_community',
    'identification' => 'identification',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['type']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['type']['group_info']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['group_info']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['type']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Both',
      'operator' => 'in',
      'value' => array(
        'identification_community' => 'identification_community',
        'identification' => 'identification',
        'all' => 0,
        'article' => 0,
        'page' => 0,
        'crew_species_observation' => 0,
        'collection' => 0,
        'gallery' => 0,
        'habitat_record' => 0,
        'link' => 0,
        'observation' => 0,
        'openlayers_example_content' => 0,
        'picture' => 0,
        'slide' => 0,
        'slideshow_page' => 0,
        'source' => 0,
        'threat_assessment' => 0,
        'webform' => 0,
      ),
    ),
    2 => array(
      'title' => 'Identification',
      'operator' => 'in',
      'value' => array(
        'identification' => 'identification',
        'all' => 0,
        'article' => 0,
        'page' => 0,
        'crew_species_observation' => 0,
        'collection' => 0,
        'identification_community' => 0,
        'gallery' => 0,
        'habitat_record' => 0,
        'link' => 0,
        'observation' => 0,
        'openlayers_example_content' => 0,
        'picture' => 0,
        'slide' => 0,
        'slideshow_page' => 0,
        'source' => 0,
        'threat_assessment' => 0,
        'webform' => 0,
      ),
    ),
    3 => array(
      'title' => 'Community identification',
      'operator' => 'in',
      'value' => array(
        'identification_community' => 'identification_community',
        'all' => 0,
        'article' => 0,
        'page' => 0,
        'crew_species_observation' => 0,
        'collection' => 0,
        'gallery' => 0,
        'habitat_record' => 0,
        'identification' => 0,
        'link' => 0,
        'observation' => 0,
        'openlayers_example_content' => 0,
        'picture' => 0,
        'slide' => 0,
        'slideshow_page' => 0,
        'source' => 0,
        'threat_assessment' => 0,
        'webform' => 0,
      ),
    ),
  );
  /* Filter criterion: Content: Certainty (field_certainty) */
  $handler->display->display_options['filters']['field_certainty_value']['id'] = 'field_certainty_value';
  $handler->display->display_options['filters']['field_certainty_value']['table'] = 'field_data_field_certainty';
  $handler->display->display_options['filters']['field_certainty_value']['field'] = 'field_certainty_value';
  $handler->display->display_options['filters']['field_certainty_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_certainty_value']['expose']['operator_id'] = 'field_certainty_value_op';
  $handler->display->display_options['filters']['field_certainty_value']['expose']['label'] = 'Certainty';
  $handler->display->display_options['filters']['field_certainty_value']['expose']['operator'] = 'field_certainty_value_op';
  $handler->display->display_options['filters']['field_certainty_value']['expose']['identifier'] = 'field_certainty_value';
  $handler->display->display_options['filters']['field_certainty_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Species (field_identified_species) */
  $handler->display->display_options['filters']['field_identified_species_tid']['id'] = 'field_identified_species_tid';
  $handler->display->display_options['filters']['field_identified_species_tid']['table'] = 'field_data_field_identified_species';
  $handler->display->display_options['filters']['field_identified_species_tid']['field'] = 'field_identified_species_tid';
  $handler->display->display_options['filters']['field_identified_species_tid']['value'] = '';
  $handler->display->display_options['filters']['field_identified_species_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['operator_id'] = 'field_identified_species_tid_op';
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['label'] = 'Species';
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['operator'] = 'field_identified_species_tid_op';
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['identifier'] = 'field_identified_species_tid';
  $handler->display->display_options['filters']['field_identified_species_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_identified_species_tid']['vocabulary'] = 'taxa';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Updated date */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = '>=';
  $handler->display->display_options['filters']['changed']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['changed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['changed']['expose']['operator_id'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['label'] = 'Updated date';
  $handler->display->display_options['filters']['changed']['expose']['description'] = 'offset from the current time such as "+1 day"';
  $handler->display->display_options['filters']['changed']['expose']['operator'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['identifier'] = 'changed';
  $handler->display->display_options['filters']['changed']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Identification source (field_identification_source) */
  $handler->display->display_options['filters']['field_identification_source_value']['id'] = 'field_identification_source_value';
  $handler->display->display_options['filters']['field_identification_source_value']['table'] = 'field_data_field_identification_source';
  $handler->display->display_options['filters']['field_identification_source_value']['field'] = 'field_identification_source_value';
  $handler->display->display_options['filters']['field_identification_source_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_identification_source_value']['expose']['operator_id'] = 'field_identification_source_value_op';
  $handler->display->display_options['filters']['field_identification_source_value']['expose']['label'] = 'Source';
  $handler->display->display_options['filters']['field_identification_source_value']['expose']['operator'] = 'field_identification_source_value_op';
  $handler->display->display_options['filters']['field_identification_source_value']['expose']['identifier'] = 'field_identification_source_value';
  $handler->display->display_options['filters']['field_identification_source_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Contributor';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Observation (field_observation) */
  $handler->display->display_options['filters']['field_observation_target_id']['id'] = 'field_observation_target_id';
  $handler->display->display_options['filters']['field_observation_target_id']['table'] = 'field_data_field_observation';
  $handler->display->display_options['filters']['field_observation_target_id']['field'] = 'field_observation_target_id';
  $handler->display->display_options['filters']['field_observation_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_observation_target_id']['expose']['operator_id'] = 'field_observation_target_id_op';
  $handler->display->display_options['filters']['field_observation_target_id']['expose']['label'] = 'Observation nid';
  $handler->display->display_options['filters']['field_observation_target_id']['expose']['operator'] = 'field_observation_target_id_op';
  $handler->display->display_options['filters']['field_observation_target_id']['expose']['identifier'] = 'field_observation_target_id';
  $handler->display->display_options['filters']['field_observation_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/identifications';
  $export['administration_identifications'] = $view;

  $view = new view();
  $view->name = 'administration_taxa';
  $view->description = 'Manage tagging, categorization, and classification of your content.';
  $view->tag = 'admin';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Administration: Taxa';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Taxa';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'tid_1' => 'tid_1',
    'name' => 'name',
    'field_common_names' => 'field_common_names',
    'field_taxon_rank' => 'field_taxon_rank',
    'name_2' => 'name_2',
    'field_lsid' => 'field_lsid',
    'imported' => 'imported',
    'description' => 'description',
    'tid' => 'tid',
  );
  $handler->display->display_options['style_options']['default'] = 'tid_1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tid_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'field_common_names' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_taxon_rank' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'imported' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'description' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['label'] = 'Parent term';
  /* Field: Bulk operations: Taxonomy term */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
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
    'action::pathauto_taxonomy_term_update_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['label'] = 'TID';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Term';
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Common names */
  $handler->display->display_options['fields']['field_common_names']['id'] = 'field_common_names';
  $handler->display->display_options['fields']['field_common_names']['table'] = 'field_data_field_common_names';
  $handler->display->display_options['fields']['field_common_names']['field'] = 'field_common_names';
  $handler->display->display_options['fields']['field_common_names']['delta_limit'] = '8';
  $handler->display->display_options['fields']['field_common_names']['delta_offset'] = '0';
  /* Field: Taxonomy term: Rank */
  $handler->display->display_options['fields']['field_taxon_rank']['id'] = 'field_taxon_rank';
  $handler->display->display_options['fields']['field_taxon_rank']['table'] = 'field_data_field_taxon_rank';
  $handler->display->display_options['fields']['field_taxon_rank']['field'] = 'field_taxon_rank';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  $handler->display->display_options['fields']['name_2']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_2']['label'] = 'Parent taxon';
  $handler->display->display_options['fields']['name_2']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: LSID */
  $handler->display->display_options['fields']['field_lsid']['id'] = 'field_lsid';
  $handler->display->display_options['fields']['field_lsid']['table'] = 'field_data_field_lsid';
  $handler->display->display_options['fields']['field_lsid']['field'] = 'field_lsid';
  /* Field: Feeds item: Import date */
  $handler->display->display_options['fields']['imported']['id'] = 'imported';
  $handler->display->display_options['fields']['imported']['table'] = 'feeds_item';
  $handler->display->display_options['fields']['imported']['field'] = 'imported';
  $handler->display->display_options['fields']['imported']['date_format'] = 'medium';
  $handler->display->display_options['fields']['imported']['second_date_format'] = 'long';
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Description';
  $handler->display->display_options['fields']['description']['alter']['max_length'] = '60';
  $handler->display->display_options['fields']['description']['alter']['trim'] = TRUE;
  /* Field: Taxonomy term: Etymology */
  $handler->display->display_options['fields']['field_etymology']['id'] = 'field_etymology';
  $handler->display->display_options['fields']['field_etymology']['table'] = 'field_data_field_etymology';
  $handler->display->display_options['fields']['field_etymology']['field'] = 'field_etymology';
  $handler->display->display_options['fields']['field_etymology']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_etymology']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_etymology']['settings'] = array(
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'Operations';
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['text'] = 'edit';
  $handler->display->display_options['fields']['tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['path'] = 'taxonomy/term/[tid]/edit';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Contextual filter: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['arguments']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['arguments']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['machine_name']['title'] = 'Terms in %1';
  $handler->display->display_options['arguments']['machine_name']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['machine_name']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['machine_name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['machine_name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['machine_name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['machine_name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['machine_name']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['machine_name']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['machine_name']['limit'] = '0';
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['vid']['group'] = '0';
  $handler->display->display_options['filters']['vid']['expose']['operator_id'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['label'] = 'Vocabulary';
  $handler->display->display_options['filters']['vid']['expose']['operator'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['identifier'] = 'vid';
  $handler->display->display_options['filters']['vid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'word';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember'] = TRUE;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_1']['field'] = 'name';
  $handler->display->display_options['filters']['name_1']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['name_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_1']['expose']['operator_id'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['label'] = 'Parent taxon';
  $handler->display->display_options['filters']['name_1']['expose']['operator'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['identifier'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Taxonomy term: Rank (field_taxon_rank) */
  $handler->display->display_options['filters']['field_taxon_rank_value']['id'] = 'field_taxon_rank_value';
  $handler->display->display_options['filters']['field_taxon_rank_value']['table'] = 'field_data_field_taxon_rank';
  $handler->display->display_options['filters']['field_taxon_rank_value']['field'] = 'field_taxon_rank_value';
  $handler->display->display_options['filters']['field_taxon_rank_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_taxon_rank_value']['expose']['operator_id'] = 'field_taxon_rank_value_op';
  $handler->display->display_options['filters']['field_taxon_rank_value']['expose']['label'] = 'Rank';
  $handler->display->display_options['filters']['field_taxon_rank_value']['expose']['operator'] = 'field_taxon_rank_value_op';
  $handler->display->display_options['filters']['field_taxon_rank_value']['expose']['identifier'] = 'field_taxon_rank_value';
  $handler->display->display_options['filters']['field_taxon_rank_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Taxonomy term: Common names (field_common_names) */
  $handler->display->display_options['filters']['field_common_names_value']['id'] = 'field_common_names_value';
  $handler->display->display_options['filters']['field_common_names_value']['table'] = 'field_data_field_common_names';
  $handler->display->display_options['filters']['field_common_names_value']['field'] = 'field_common_names_value';
  $handler->display->display_options['filters']['field_common_names_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_common_names_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_common_names_value']['expose']['operator_id'] = 'field_common_names_value_op';
  $handler->display->display_options['filters']['field_common_names_value']['expose']['label'] = 'Has common names';
  $handler->display->display_options['filters']['field_common_names_value']['expose']['operator'] = 'field_common_names_value_op';
  $handler->display->display_options['filters']['field_common_names_value']['expose']['identifier'] = 'field_common_names_value';
  $handler->display->display_options['filters']['field_common_names_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_common_names_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_common_names_value']['group_info']['label'] = 'Common names';
  $handler->display->display_options['filters']['field_common_names_value']['group_info']['identifier'] = 'field_common_names_value';
  $handler->display->display_options['filters']['field_common_names_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Has common names',
      'operator' => 'not empty',
      'value' => '.',
    ),
    2 => array(
      'title' => 'Doesn’t have common names',
      'operator' => 'empty',
      'value' => '.',
    ),
  );
  /* Filter criterion: Taxonomy term: Term description */
  $handler->display->display_options['filters']['description']['id'] = 'description';
  $handler->display->display_options['filters']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['description']['field'] = 'description';
  $handler->display->display_options['filters']['description']['exposed'] = TRUE;
  $handler->display->display_options['filters']['description']['expose']['operator_id'] = 'description_op';
  $handler->display->display_options['filters']['description']['expose']['label'] = 'Term description';
  $handler->display->display_options['filters']['description']['expose']['operator'] = 'description_op';
  $handler->display->display_options['filters']['description']['expose']['identifier'] = 'description';
  $handler->display->display_options['filters']['description']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['description']['group_info']['label'] = 'Description';
  $handler->display->display_options['filters']['description']['group_info']['identifier'] = 'description';
  $handler->display->display_options['filters']['description']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Has a description',
      'operator' => 'not empty',
      'value' => '.',
    ),
    2 => array(
      'title' => 'Does’t have a description',
      'operator' => 'empty',
      'value' => '.',
    ),
  );
  /* Filter criterion: Taxonomy term: Etymology (field_etymology) */
  $handler->display->display_options['filters']['field_etymology_value']['id'] = 'field_etymology_value';
  $handler->display->display_options['filters']['field_etymology_value']['table'] = 'field_data_field_etymology';
  $handler->display->display_options['filters']['field_etymology_value']['field'] = 'field_etymology_value';
  $handler->display->display_options['filters']['field_etymology_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_etymology_value']['expose']['operator_id'] = 'field_etymology_value_op';
  $handler->display->display_options['filters']['field_etymology_value']['expose']['label'] = 'Etymology (field_etymology)';
  $handler->display->display_options['filters']['field_etymology_value']['expose']['operator'] = 'field_etymology_value_op';
  $handler->display->display_options['filters']['field_etymology_value']['expose']['identifier'] = 'field_etymology_value';
  $handler->display->display_options['filters']['field_etymology_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_etymology_value']['group_info']['label'] = 'Etymology';
  $handler->display->display_options['filters']['field_etymology_value']['group_info']['identifier'] = 'field_etymology_value';
  $handler->display->display_options['filters']['field_etymology_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Has value',
      'operator' => 'not empty',
      'value' => '.',
    ),
    2 => array(
      'title' => 'Has no value',
      'operator' => 'empty',
      'value' => '.',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/taxa';
  $export['administration_taxa'] = $view;

  $view = new view();
  $view->name = 'taxa_aggregated';
  $view->description = 'Manage tagging, categorization, and classification of your content.';
  $view->tag = 'admin';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Administration: Taxa, aggregated';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Taxa, aggregated';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'tid_1' => 'tid_1',
    'name' => 'name',
    'field_common_names' => 'field_common_names',
    'field_taxon_rank' => 'field_taxon_rank',
    'name_2' => 'name_2',
    'field_lsid' => 'field_lsid',
    'imported' => 'imported',
    'description' => 'description',
    'tid' => 'tid',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tid_1' => array(
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
    'field_common_names' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_taxon_rank' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lsid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'imported' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'description' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['label'] = 'Parent term';
  /* Relationship: Taxonomy term: Content using Species */
  $handler->display->display_options['relationships']['reverse_field_identified_species_node']['id'] = 'reverse_field_identified_species_node';
  $handler->display->display_options['relationships']['reverse_field_identified_species_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_identified_species_node']['field'] = 'reverse_field_identified_species_node';
  /* Field: Bulk operations: Taxonomy term */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
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
    'action::pathauto_taxonomy_term_update_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'reverse_field_identified_species_node';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  $handler->display->display_options['fields']['field_image']['group_column'] = 'entity_id';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Term';
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: COUNT(Content: Title) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_identified_species_node';
  $handler->display->display_options['fields']['title']['group_type'] = 'count';
  $handler->display->display_options['fields']['title']['label'] = 'Identifications';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['label'] = 'TID';
  /* Field: Taxonomy term: Common names */
  $handler->display->display_options['fields']['field_common_names']['id'] = 'field_common_names';
  $handler->display->display_options['fields']['field_common_names']['table'] = 'field_data_field_common_names';
  $handler->display->display_options['fields']['field_common_names']['field'] = 'field_common_names';
  $handler->display->display_options['fields']['field_common_names']['delta_offset'] = '0';
  /* Field: Taxonomy term: Rank */
  $handler->display->display_options['fields']['field_taxon_rank']['id'] = 'field_taxon_rank';
  $handler->display->display_options['fields']['field_taxon_rank']['table'] = 'field_data_field_taxon_rank';
  $handler->display->display_options['fields']['field_taxon_rank']['field'] = 'field_taxon_rank';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  $handler->display->display_options['fields']['name_2']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_2']['label'] = 'Parent taxon';
  $handler->display->display_options['fields']['name_2']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: LSID */
  $handler->display->display_options['fields']['field_lsid']['id'] = 'field_lsid';
  $handler->display->display_options['fields']['field_lsid']['table'] = 'field_data_field_lsid';
  $handler->display->display_options['fields']['field_lsid']['field'] = 'field_lsid';
  /* Field: Feeds item: Import date */
  $handler->display->display_options['fields']['imported']['id'] = 'imported';
  $handler->display->display_options['fields']['imported']['table'] = 'feeds_item';
  $handler->display->display_options['fields']['imported']['field'] = 'imported';
  $handler->display->display_options['fields']['imported']['date_format'] = 'medium';
  $handler->display->display_options['fields']['imported']['second_date_format'] = 'long';
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Description';
  $handler->display->display_options['fields']['description']['alter']['max_length'] = '60';
  $handler->display->display_options['fields']['description']['alter']['trim'] = TRUE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'Operations';
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['text'] = 'edit';
  $handler->display->display_options['fields']['tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['path'] = 'taxonomy/term/[tid]/edit';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Contextual filter: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['arguments']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['arguments']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['machine_name']['title'] = 'Terms in %1';
  $handler->display->display_options['arguments']['machine_name']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['machine_name']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['machine_name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['machine_name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['machine_name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['machine_name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['machine_name']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['machine_name']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['machine_name']['limit'] = '0';
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['vid']['group'] = '0';
  $handler->display->display_options['filters']['vid']['expose']['operator_id'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['label'] = 'Vocabulary';
  $handler->display->display_options['filters']['vid']['expose']['operator'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['identifier'] = 'vid';
  $handler->display->display_options['filters']['vid']['expose']['remember'] = TRUE;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'word';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember'] = TRUE;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_1']['field'] = 'name';
  $handler->display->display_options['filters']['name_1']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['name_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_1']['expose']['operator_id'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['label'] = 'Parent taxon';
  $handler->display->display_options['filters']['name_1']['expose']['operator'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['identifier'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Taxonomy term: Rank (field_taxon_rank) */
  $handler->display->display_options['filters']['field_taxon_rank_value']['id'] = 'field_taxon_rank_value';
  $handler->display->display_options['filters']['field_taxon_rank_value']['table'] = 'field_data_field_taxon_rank';
  $handler->display->display_options['filters']['field_taxon_rank_value']['field'] = 'field_taxon_rank_value';
  $handler->display->display_options['filters']['field_taxon_rank_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_taxon_rank_value']['expose']['operator_id'] = 'field_taxon_rank_value_op';
  $handler->display->display_options['filters']['field_taxon_rank_value']['expose']['label'] = 'Rank';
  $handler->display->display_options['filters']['field_taxon_rank_value']['expose']['operator'] = 'field_taxon_rank_value_op';
  $handler->display->display_options['filters']['field_taxon_rank_value']['expose']['identifier'] = 'field_taxon_rank_value';
  $handler->display->display_options['filters']['field_taxon_rank_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Taxonomy term: Common names (field_common_names) */
  $handler->display->display_options['filters']['field_common_names_value']['id'] = 'field_common_names_value';
  $handler->display->display_options['filters']['field_common_names_value']['table'] = 'field_data_field_common_names';
  $handler->display->display_options['filters']['field_common_names_value']['field'] = 'field_common_names_value';
  $handler->display->display_options['filters']['field_common_names_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_common_names_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_common_names_value']['expose']['operator_id'] = 'field_common_names_value_op';
  $handler->display->display_options['filters']['field_common_names_value']['expose']['label'] = 'Has common names';
  $handler->display->display_options['filters']['field_common_names_value']['expose']['operator'] = 'field_common_names_value_op';
  $handler->display->display_options['filters']['field_common_names_value']['expose']['identifier'] = 'field_common_names_value';
  $handler->display->display_options['filters']['field_common_names_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_common_names_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_common_names_value']['group_info']['label'] = 'Common names';
  $handler->display->display_options['filters']['field_common_names_value']['group_info']['identifier'] = 'field_common_names_value';
  $handler->display->display_options['filters']['field_common_names_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Has common names',
      'operator' => 'not empty',
      'value' => '.',
    ),
    2 => array(
      'title' => 'Doesn’t have common names',
      'operator' => 'empty',
      'value' => '.',
    ),
  );
  /* Filter criterion: Taxonomy term: Term description */
  $handler->display->display_options['filters']['description']['id'] = 'description';
  $handler->display->display_options['filters']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['description']['field'] = 'description';
  $handler->display->display_options['filters']['description']['exposed'] = TRUE;
  $handler->display->display_options['filters']['description']['expose']['operator_id'] = 'description_op';
  $handler->display->display_options['filters']['description']['expose']['label'] = 'Term description';
  $handler->display->display_options['filters']['description']['expose']['operator'] = 'description_op';
  $handler->display->display_options['filters']['description']['expose']['identifier'] = 'description';
  $handler->display->display_options['filters']['description']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['description']['group_info']['label'] = 'Description';
  $handler->display->display_options['filters']['description']['group_info']['identifier'] = 'description';
  $handler->display->display_options['filters']['description']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Has a description',
      'operator' => 'not empty',
      'value' => '.',
    ),
    2 => array(
      'title' => 'Does’t have a description',
      'operator' => 'empty',
      'value' => '.',
    ),
  );
  /* Filter criterion: Content: Image (field_image:fid) */
  $handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_image_fid']['expose']['operator_id'] = 'field_image_fid_op';
  $handler->display->display_options['filters']['field_image_fid']['expose']['label'] = 'Image (field_image:fid)';
  $handler->display->display_options['filters']['field_image_fid']['expose']['operator'] = 'field_image_fid_op';
  $handler->display->display_options['filters']['field_image_fid']['expose']['identifier'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_image_fid']['group_info']['label'] = 'Image';
  $handler->display->display_options['filters']['field_image_fid']['group_info']['identifier'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Has an image',
      'operator' => 'not empty',
      'value' => array(
        'value' => '.',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Does not have an image',
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
  $handler->display->display_options['path'] = 'admin/taxa-aggregated';
  $export['taxa_aggregated'] = $view;

  return $export;
}
