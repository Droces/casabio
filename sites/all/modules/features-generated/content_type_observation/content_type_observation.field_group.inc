<?php
/**
 * @file
 * content_type_observation.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function content_type_observation_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|node|observation|form';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'observation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '3',
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
  $field_groups['group_description|node|observation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_habitat|node|observation|form';
  $field_group->group_name = 'group_habitat';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'observation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Habitat',
    'weight' => '5',
    'children' => array(
      0 => 'field_habitat',
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
  $field_groups['group_habitat|node|observation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_identifications|node|observation|form';
  $field_group->group_name = 'group_identifications';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'observation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Identifications',
    'weight' => '7',
    'children' => array(
      0 => 'field_identifications',
      1 => 'field_most_likely_species',
      2 => 'field_mls_probability',
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
  $field_groups['group_identifications|node|observation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|node|observation|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'observation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Basic info',
    'weight' => '1',
    'children' => array(
      0 => 'field_observer_name',
      1 => 'field_date_observed',
      2 => 'field_count',
      3 => 'field_collection',
      4 => 'field_specimen_id',
      5 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Basic info',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'fields-as-table-rows',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_info|node|observation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|observation|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'observation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '4',
    'children' => array(
      0 => 'field_location',
      1 => 'field_locality',
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
  $field_groups['group_location|node|observation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pictures|node|observation|form';
  $field_group->group_name = 'group_pictures';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'observation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Pictures',
    'weight' => '2',
    'children' => array(
      0 => 'field_pictures_observation',
      1 => 'field_main_image',
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
  $field_groups['group_pictures|node|observation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sections|node|observation|form';
  $field_group->group_name = 'group_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'observation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sections',
    'weight' => '0',
    'children' => array(
      0 => 'group_description',
      1 => 'group_location',
      2 => 'group_identifications',
      3 => 'group_info',
      4 => 'group_pictures',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-sections field-group-htabs',
      ),
    ),
  );
  $field_groups['group_sections|node|observation|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic info');
  t('Description');
  t('Habitat');
  t('Identifications');
  t('Location');
  t('Pictures');
  t('Sections');

  return $field_groups;
}
