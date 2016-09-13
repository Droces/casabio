<?php
/**
 * @file
 * content_type_collection.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function content_type_collection_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|node|collection|form';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'collection';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Additional information',
    'weight' => '4',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_description|node|collection|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|node|collection|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'collection';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Basic info',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_date_collected',
      2 => 'field_collector',
      3 => 'field_representative_picture',
      4 => 'field_featured_pictures',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_info|node|collection|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|collection|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'collection';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '3',
    'children' => array(
      0 => 'field_location',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_location|node|collection|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sections|node|collection|form';
  $field_group->group_name = 'group_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'collection';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sections',
    'weight' => '1',
    'children' => array(
      0 => 'group_location',
      1 => 'group_info',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-sections field-group-htabs',
      ),
    ),
  );
  $field_groups['group_sections|node|collection|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional information');
  t('Basic info');
  t('Location');
  t('Sections');

  return $field_groups;
}
