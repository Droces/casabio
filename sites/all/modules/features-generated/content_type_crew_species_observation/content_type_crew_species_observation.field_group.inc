<?php
/**
 * @file
 * content_type_crew_species_observation.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function content_type_crew_species_observation_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_habitat|node|crew_species_observation|form';
  $field_group->group_name = 'group_habitat';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'crew_species_observation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Habitat',
    'weight' => '2',
    'children' => array(
      0 => 'field_land_form',
      1 => 'field_soil_type',
      2 => 'field_geology',
      3 => 'field_slope',
      4 => 'field_land_use',
      5 => 'field_aspect',
      6 => 'field_land_ownership',
      7 => 'field_habitat_notes',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Habitat',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|node|crew_species_observation|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'crew_species_observation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Core info',
    'weight' => '0',
    'children' => array(
      0 => 'field_collector',
      1 => 'field_locality_description',
      2 => 'field_date_collected',
      3 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Core info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_population|node|crew_species_observation|form';
  $field_group->group_name = 'group_population';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'crew_species_observation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Population info',
    'weight' => '4',
    'children' => array(
      0 => 'field_population_size',
      1 => 'field_nu_individuals',
      2 => 'field_distrib_plants',
      3 => 'field_population_composition',
      4 => 'field_population_dimensions',
      5 => 'field_extent_area',
      6 => 'field_next_population_dist',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Population info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_species|node|crew_species_observation|form';
  $field_group->group_name = 'group_species';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'crew_species_observation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Species',
    'weight' => '1',
    'children' => array(
      0 => 'field_plant_features',
      1 => 'field_pollination_type',
      2 => 'field_pollination_agent',
      3 => 'field_species_name',
      4 => 'field_dispersal',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Species',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-species field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_threats|node|crew_species_observation|form';
  $field_group->group_name = 'group_threats';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'crew_species_observation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Threats & disturbances',
    'weight' => '3',
    'children' => array(
      0 => 'field_threat_assessment',
      1 => 'field_alien_plants',
      2 => 'field_alien_plant_density',
      3 => 'field_threats_notes',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Threats & disturbances',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Core info');
  t('Habitat');
  t('Population info');
  t('Species');
  t('Threats & disturbances');

  return $field_groups;
}
