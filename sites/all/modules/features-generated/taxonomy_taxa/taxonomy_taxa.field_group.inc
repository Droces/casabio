<?php
/**
 * @file
 * taxonomy_taxa.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function taxonomy_taxa_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|taxonomy_term|taxa|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'taxa';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic info',
    'weight' => '1',
    'children' => array(
      0 => 'field_common_names',
      1 => 'field_taxon_rank',
      2 => 'field_scientific_name',
      3 => 'field_identifications_count',
      4 => 'field_range',
      5 => 'description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_info|taxonomy_term|taxa|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pictures|taxonomy_term|taxa|form';
  $field_group->group_name = 'group_pictures';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'taxa';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pictures',
    'weight' => '2',
    'children' => array(
      0 => 'field_representative_picture',
      1 => 'field_pictures',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-pictures field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_pictures|taxonomy_term|taxa|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scientific|taxonomy_term|taxa|form';
  $field_group->group_name = 'group_scientific';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'taxa';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Scientific info',
    'weight' => '3',
    'children' => array(
      0 => 'field_lsid',
      1 => 'field_etymology',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-scientific field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_scientific|taxonomy_term|taxa|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic info');
  t('Pictures');
  t('Scientific info');

  return $field_groups;
}
