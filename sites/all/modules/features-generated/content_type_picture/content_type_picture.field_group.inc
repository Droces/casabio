<?php
/**
 * @file
 * content_type_picture.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function content_type_picture_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|node|picture|form';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'picture';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Description',
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
  $field_groups['group_description|node|picture|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|node|picture|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'picture';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Basic info',
    'weight' => '3',
    'children' => array(
      0 => 'field_image',
      1 => 'field_collection',
      2 => 'field_date_taken',
      3 => 'title',
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
  $field_groups['group_info|node|picture|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interaction|node|picture|form';
  $field_group->group_name = 'group_interaction';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'picture';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Interaction',
    'weight' => '7',
    'children' => array(
      0 => 'field_interaction_subject',
      1 => 'field_interaction_activity',
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
  $field_groups['group_interaction|node|picture|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|picture|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'picture';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '6',
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
  $field_groups['group_location|node|picture|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sections|node|picture|form';
  $field_group->group_name = 'group_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'picture';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sections',
    'weight' => '0',
    'children' => array(
      0 => 'group_description',
      1 => 'group_info',
      2 => 'group_tags',
      3 => 'group_interaction',
      4 => 'group_location',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-sections field-group-htabs',
      ),
    ),
  );
  $field_groups['group_sections|node|picture|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tags|node|picture|form';
  $field_group->group_name = 'group_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'picture';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '5',
    'children' => array(
      0 => 'field_beauty',
      1 => 'field_usefulness',
      2 => 'field_tags',
      3 => 'field_subject',
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
  $field_groups['group_tags|node|picture|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic info');
  t('Description');
  t('Interaction');
  t('Location');
  t('Sections');
  t('Tags');

  return $field_groups;
}
