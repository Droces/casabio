<?php
/**
 * @file
 * content_type_collection.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function content_type_collection_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-collection-body'.
  $field_instances['node-collection-body'] = array(
    'bundle' => 'collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Any significant further information about this collection that might be of interest.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
        ),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'inline' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'text' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Additional information',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-collection-field_collector'.
  $field_instances['node-collection-field_collector'] = array(
    'bundle' => 'collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The <em>full name</em> of the person who recorded the observations; this is probably your full name.',
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
      'teaser' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '<em class="no-value">No collector named</em>',
          'empty_fields_handler' => 'EmptyFieldText',
        ),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'text' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_collector',
    'label' => 'Collector',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'contribution_format' => 'contribution_format',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'contribution_format' => array(
              'weight' => -8,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => -7,
            ),
          ),
        ),
      ),
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
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-collection-field_count_observations'.
  $field_instances['node-collection-field_count_observations'] = array(
    'bundle' => 'collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference_count',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'link' => 1,
          'link_class' => '',
          'plural' => '@count observations',
          'singular' => '1 observation',
        ),
        'type' => 'entityreference_count_formatter_labeled_count',
        'weight' => 6,
      ),
      'inline' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'entityreference_count',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '<em class="no-value">Has no observations</em>',
          'empty_fields_handler' => 'EmptyFieldText',
          'link' => 0,
          'link_class' => '',
          'plural' => '@count observations',
          'singular' => '1 observation',
        ),
        'type' => 'entityreference_count_formatter_labeled_count',
        'weight' => 2,
      ),
      'text' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_count_observations',
    'label' => 'Number of observations',
    'required' => 0,
    'settings' => array(
      'allowed_bundles' => array(
        'observation' => 'observation',
      ),
      'count_only_published' => 1,
      'counted_reference_fields' => array(
        'field_collection' => 'field_collection',
        'field_habitat' => 0,
        'field_identifications' => 0,
        'field_observation' => 0,
        'field_observation_object' => 0,
        'field_pictures_observation' => 0,
        'field_representative_picture' => 0,
        'field_source' => 0,
        'field_threat_assessment' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'entityreference_count',
      'settings' => array(),
      'type' => 'entityreference_count_widget',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-collection-field_count_pictures'.
  $field_instances['node-collection-field_count_pictures'] = array(
    'bundle' => 'collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference_count',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'link' => 1,
          'link_class' => '',
          'plural' => '@count pictures',
          'singular' => '1 picture',
        ),
        'type' => 'entityreference_count_formatter_labeled_count',
        'weight' => 7,
      ),
      'inline' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'entityreference_count',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '<em class="no-value">No pictures</em>',
          'empty_fields_handler' => 'EmptyFieldText',
          'link' => 0,
          'link_class' => '',
          'plural' => '@count pictures',
          'singular' => '1 picture',
        ),
        'type' => 'entityreference_count_formatter_labeled_count',
        'weight' => 3,
      ),
      'text' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_count_pictures',
    'label' => 'Number of pictures',
    'required' => 0,
    'settings' => array(
      'allowed_bundles' => array(
        'picture' => 'picture',
      ),
      'count_only_published' => 1,
      'counted_reference_fields' => array(
        'field_collection' => 'field_collection',
        'field_habitat' => 0,
        'field_identifications' => 0,
        'field_observation' => 0,
        'field_observation_object' => 0,
        'field_pictures_observation' => 0,
        'field_representative_picture' => 0,
        'field_source' => 0,
        'field_threat_assessment' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'entityreference_count',
      'settings' => array(),
      'type' => 'entityreference_count_widget',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-collection-field_date_collected'.
  $field_instances['node-collection-field_date_collected'] = array(
    'bundle' => 'collection',
    'deleted' => 0,
    'description' => 'If the pictures were taken over several days, provide the start and end date.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'date',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 2,
      ),
      'inline' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'date',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '<em class="no-value">No collection date</em>',
          'empty_fields_handler' => 'EmptyFieldText',
          'format_type' => 'medium',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
        ),
        'type' => 'date_default',
        'weight' => 1,
      ),
      'text' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_date_collected',
    'label' => 'Date collected',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'j M Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 1,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-collection-field_featured_pictures'.
  $field_instances['node-collection-field_featured_pictures'] = array(
    'bundle' => 'collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'links' => 0,
          'use_content_language' => TRUE,
          'view_mode' => 'thumbnail',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 8,
      ),
      'inline' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '<em class="no-value">No featured pictures</em>',
          'empty_fields_handler' => 'EmptyFieldText',
          'links' => 0,
          'use_content_language' => TRUE,
          'view_mode' => 'thumbnail',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 0,
      ),
      'text' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_featured_pictures',
    'label' => 'Featured pictures',
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
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-collection-field_representative_picture'.
  $field_instances['node-collection-field_representative_picture'] = array(
    'bundle' => 'collection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The picture that best represents the content of this collection.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 5,
      ),
      'inline' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'text' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_representative_picture',
    'label' => 'Representative picture',
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
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional information');
  t('Any significant further information about this collection that might be of interest.');
  t('Collector');
  t('Date collected');
  t('Featured pictures');
  t('If the pictures were taken over several days, provide the start and end date.');
  t('Number of observations');
  t('Number of pictures');
  t('Representative picture');
  t('The <em>full name</em> of the person who recorded the observations; this is probably your full name.');
  t('The picture that best represents the content of this collection.');

  return $field_instances;
}
