<?php
/**
 * @file
 * taxonomy_habitats.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function taxonomy_habitats_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic|taxonomy_term|habitats|form';
  $field_group->group_name = 'group_generic';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'habitats';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Generic factors',
    'weight' => '2',
    'children' => array(
      0 => 'field_air_moisture',
      1 => 'field_land_form',
      2 => 'field_land_use',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-generic field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_terrestrial_botanical|taxonomy_term|habitats|form';
  $field_group->group_name = 'group_terrestrial_botanical';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'habitats';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Terrestrial botanical factors',
    'weight' => '3',
    'children' => array(
      0 => 'field_veld_age',
      1 => 'field_geology',
      2 => 'field_soil_type',
      3 => 'field_soil_colour',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-terrestrial-botanical field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Generic factors');
  t('Terrestrial botanical factors');

  return $field_groups;
}
