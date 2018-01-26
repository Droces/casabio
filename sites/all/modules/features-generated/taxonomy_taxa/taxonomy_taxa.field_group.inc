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
    'weight' => '3',
    'children' => array(
      0 => 'field_taxon_rank',
      1 => 'field_range',
      2 => 'field_localities',
      3 => 'field_rank',
      4 => 'description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Basic info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group info',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_info|taxonomy_term|taxa|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_names|taxonomy_term|taxa|form';
  $field_group->group_name = 'group_names';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'taxa';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Names',
    'weight' => '2',
    'children' => array(
      0 => 'field_common_names',
      1 => 'field_scientific_name',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Names',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group names',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_names|taxonomy_term|taxa|form'] = $field_group;

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
    'weight' => '6',
    'children' => array(
      0 => 'field_representative_picture',
      1 => 'field_pictures',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Pictures',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group pictures',
        'description' => '',
      ),
      'formatter' => 'closed',
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
    'weight' => '4',
    'children' => array(
      0 => 'field_lsid',
      1 => 'field_etymology',
      2 => 'field_external_references',
      3 => 'field_vulnerability',
      4 => 'field_long_etymology',
      5 => 'field_etymology_applies_to',
      6 => 'field_synonym_of',
      7 => 'field_journal_info',
      8 => 'field_authors',
      9 => 'field_year_sci_name',
      10 => 'field_sci_name_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Scientific info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group scientific',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_scientific|taxonomy_term|taxa|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic info');
  t('Names');
  t('Pictures');
  t('Scientific info');

  return $field_groups;
}
