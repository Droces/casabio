<?php
/**
 * @file
 * content_type_interaction.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function content_type_interaction_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-interaction-body'.
  $field_instances['node-interaction-body'] = array(
    'bundle' => 'interaction',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
        ),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'inline' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'medium' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'small' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'text' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'thumbnail' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Notes',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-interaction-field_interaction_activity'.
  $field_instances['node-interaction-field_interaction_activity'] = array(
    'bundle' => 'interaction',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => 'No activity set',
          'empty_fields_handler' => 'EmptyFieldText',
        ),
        'type' => 'list_default',
        'weight' => 1,
      ),
      'inline' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'medium' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'small' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => 'No provided',
          'empty_fields_handler' => 'EmptyFieldText',
        ),
        'type' => 'list_default',
        'weight' => 1,
      ),
      'text' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'thumbnail' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_interaction_activity',
    'label' => 'Activity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-interaction-field_observation'.
  $field_instances['node-interaction-field_observation'] = array(
    'bundle' => 'interaction',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The observation that was doing the action.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => 'No subject observation',
          'empty_fields_handler' => 'EmptyFieldText',
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
      'inline' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'medium' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'small' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => 'No provided',
          'empty_fields_handler' => 'EmptyFieldText',
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
      'text' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'thumbnail' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_observation',
    'label' => 'Subject',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-interaction-field_observation_object'.
  $field_instances['node-interaction-field_observation_object'] = array(
    'bundle' => 'interaction',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The observation that is being acted upon.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => 'No object observation',
          'empty_fields_handler' => 'EmptyFieldText',
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'inline' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'medium' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'small' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => 'No provided',
          'empty_fields_handler' => 'EmptyFieldText',
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'text' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'thumbnail' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_observation_object',
    'label' => 'Object',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Activity');
  t('Notes');
  t('Object');
  t('Subject');
  t('The observation that is being acted upon.');
  t('The observation that was doing the action.');

  return $field_instances;
}
