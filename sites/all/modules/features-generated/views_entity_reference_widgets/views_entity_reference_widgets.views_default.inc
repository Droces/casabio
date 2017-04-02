<?php
/**
 * @file
 * views_entity_reference_widgets.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_entity_reference_widgets_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'habitat_reference_selector';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Habitat reference selector';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Habitat reference selector';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_air_moisture' => 'field_air_moisture',
    'field_geology' => 'field_geology',
    'field_land_form' => 'field_land_form',
    'field_land_use' => 'field_land_use',
    'field_soil_colour' => 'field_soil_colour',
    'field_soil_type' => 'field_soil_type',
    'field_veld_age' => 'field_veld_age',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_air_moisture' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_geology' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_land_form' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_land_use' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_soil_colour' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_soil_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_veld_age' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Entity Reference View Widget Checkbox: Taxonomy term */
  $handler->display->display_options['fields']['entityreference_view_widget']['id'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['entityreference_view_widget']['field'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['label'] = '';
  $handler->display->display_options['fields']['entityreference_view_widget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['entityreference_view_widget']['ervw']['force_single'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
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

  /* Display: Entity Reference View Widget */
  $handler = $view->new_display('entityreference_view_widget', 'Entity Reference View Widget', 'entityreference_view_widget_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'entityreference_view_widget' => 'entityreference_view_widget',
    'name' => 'name',
    'field_air_moisture' => 'field_air_moisture',
    'field_geology' => 'field_geology',
    'field_land_form' => 'field_land_form',
    'field_land_use' => 'field_land_use',
    'field_soil_colour' => 'field_soil_colour',
    'field_soil_type' => 'field_soil_type',
    'field_veld_age' => 'field_veld_age',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'entityreference_view_widget' => array(
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
    'field_air_moisture' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_geology' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_land_form' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_land_use' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_soil_colour' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_soil_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_veld_age' => array(
      'sortable' => 1,
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
    'name' => 0,
    'field_air_moisture' => 0,
    'field_geology' => 0,
    'field_land_form' => 0,
    'field_land_use' => 0,
    'field_soil_colour' => 0,
    'field_soil_type' => 0,
    'field_veld_age' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['habitat_reference_selector'] = $view;

  $view = new view();
  $view->name = 'species_reference_selector_widget';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Species reference selector widget';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'entityreference_view_widget' => 'entityreference_view_widget',
    'field_representative_picture' => 'field_representative_picture',
    'name' => 'name',
    'field_taxon_rank' => 'field_taxon_rank',
    'field_common_names' => 'field_common_names',
    'field_scientific_name' => 'field_scientific_name',
    'description' => 'description',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'entityreference_view_widget' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_representative_picture' => array(
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
    'field_taxon_rank' => array(
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
    'field_scientific_name' => array(
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
  );
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total matches';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Link to lookup taxon';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No species found. <a href="taxa/lookup" target="_blank">Add the species</a> to CasaBio.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Parent */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['ui_name'] = 'Parent';
  /* Field: Entity Reference View Widget Checkbox: Taxonomy term */
  $handler->display->display_options['fields']['entityreference_view_widget']['id'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['entityreference_view_widget']['field'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['label'] = 'Select';
  $handler->display->display_options['fields']['entityreference_view_widget']['ervw']['force_single'] = 1;
  /* Field: Field: Representative picture */
  $handler->display->display_options['fields']['field_representative_picture']['id'] = 'field_representative_picture';
  $handler->display->display_options['fields']['field_representative_picture']['table'] = 'field_data_field_representative_picture';
  $handler->display->display_options['fields']['field_representative_picture']['field'] = 'field_representative_picture';
  $handler->display->display_options['fields']['field_representative_picture']['label'] = 'Picture';
  $handler->display->display_options['fields']['field_representative_picture']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_representative_picture']['settings'] = array(
    'view_mode' => 'thumbnail',
    'links' => 0,
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Species name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Rank */
  $handler->display->display_options['fields']['field_taxon_rank']['id'] = 'field_taxon_rank';
  $handler->display->display_options['fields']['field_taxon_rank']['table'] = 'field_data_field_taxon_rank';
  $handler->display->display_options['fields']['field_taxon_rank']['field'] = 'field_taxon_rank';
  $handler->display->display_options['fields']['field_taxon_rank']['settings'] = array(
    'empty_fields_handler' => '',
    'empty_fields_emptyfieldtext_empty_text' => '',
  );
  /* Field: Taxonomy term: Common names */
  $handler->display->display_options['fields']['field_common_names']['id'] = 'field_common_names';
  $handler->display->display_options['fields']['field_common_names']['table'] = 'field_data_field_common_names';
  $handler->display->display_options['fields']['field_common_names']['field'] = 'field_common_names';
  $handler->display->display_options['fields']['field_common_names']['delta_limit'] = '8';
  $handler->display->display_options['fields']['field_common_names']['delta_offset'] = '0';
  /* Field: Taxonomy term: Scientific name */
  $handler->display->display_options['fields']['field_scientific_name']['id'] = 'field_scientific_name';
  $handler->display->display_options['fields']['field_scientific_name']['table'] = 'field_data_field_scientific_name';
  $handler->display->display_options['fields']['field_scientific_name']['field'] = 'field_scientific_name';
  $handler->display->display_options['fields']['field_scientific_name']['exclude'] = TRUE;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Description';
  $handler->display->display_options['fields']['description']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['description']['alter']['trim'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'taxa' => 'taxa',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine_1']['id'] = 'combine_1';
  $handler->display->display_options['filters']['combine_1']['table'] = 'views';
  $handler->display->display_options['filters']['combine_1']['field'] = 'combine';
  $handler->display->display_options['filters']['combine_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine_1']['expose']['operator_id'] = 'combine_1_op';
  $handler->display->display_options['filters']['combine_1']['expose']['label'] = 'Search by names';
  $handler->display->display_options['filters']['combine_1']['expose']['description'] = 'Type a common or scientific name';
  $handler->display->display_options['filters']['combine_1']['expose']['operator'] = 'combine_1_op';
  $handler->display->display_options['filters']['combine_1']['expose']['identifier'] = 'combine_1';
  $handler->display->display_options['filters']['combine_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['combine_1']['fields'] = array(
    'name' => 'name',
    'field_common_names' => 'field_common_names',
    'field_scientific_name' => 'field_scientific_name',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Parent taxon';
  $handler->display->display_options['filters']['name']['expose']['description'] = 'Type an order, family, genus, etc.';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  /* Filter criterion: Taxonomy term: Rank (field_taxon_rank) */
  $handler->display->display_options['filters']['field_taxon_rank_value_1']['id'] = 'field_taxon_rank_value_1';
  $handler->display->display_options['filters']['field_taxon_rank_value_1']['table'] = 'field_data_field_taxon_rank';
  $handler->display->display_options['filters']['field_taxon_rank_value_1']['field'] = 'field_taxon_rank_value';
  $handler->display->display_options['filters']['field_taxon_rank_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_taxon_rank_value_1']['expose']['operator_id'] = 'field_taxon_rank_value_1_op';
  $handler->display->display_options['filters']['field_taxon_rank_value_1']['expose']['label'] = 'Rank';
  $handler->display->display_options['filters']['field_taxon_rank_value_1']['expose']['operator'] = 'field_taxon_rank_value_1_op';
  $handler->display->display_options['filters']['field_taxon_rank_value_1']['expose']['identifier'] = 'field_taxon_rank_value_1';
  $handler->display->display_options['filters']['field_taxon_rank_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );

  /* Display: Widget1 */
  $handler = $view->new_display('entityreference_view_widget', 'Widget1', 'entityreference_view_widget_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;

  /* Display: Widget2 */
  $handler = $view->new_display('entityreference_view_widget', 'Widget2', 'entityreference_view_widget_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $export['species_reference_selector_widget'] = $view;

  return $export;
}
