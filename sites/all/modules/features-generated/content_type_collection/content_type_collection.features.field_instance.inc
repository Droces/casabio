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
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
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
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
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
      'teaser' => array(
        'label' => 'inline',
        'module' => 'date',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'format_type' => 'medium',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
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

  // Exported field_instance: 'node-collection-field_location'.
  $field_instances['node-collection-field_location'] = array(
    'bundle' => 'collection',
    'default_value' => array(
      0 => array(
        'dataType' => 'WKT',
        'geom' => 'GEOMETRYCOLLECTION EMPTY',
        'input_format' => 'wkt',
      ),
    ),
    'deleted' => 0,
    'description' => '<p>Where the pictures were taken. Adding this now will help in later steps, because the map will be zoomed in on what you add here.</p>
<p>Click once to add a point, and double-click to finish.<br />
If the pictures were taken along a route, use the <strong>path</strong> feature (recommended).<br />
For an area, use the <strong>polygon</strong> (defined by multiple points) feature.<br />
If the images were all taken in one place, use the <strong>point</strong> feature.</p>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'openlayers_geofield',
        'settings' => array(
          'data' => 'full',
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'map_layer_preset' => 'openlayers_geofield_map_geofield_formatter:openlayers_geofield_layer_formatter',
          'map_preset' => 'openlayers_geofield_map_geofield_formatter',
        ),
        'type' => 'openlayers_geofield',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'inline',
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
    ),
    'entity_type' => 'node',
    'field_name' => 'field_location',
    'label' => 'Location',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'openlayers_geofield',
      'settings' => array(
        'allow_edit' => 1,
        'data_storage' => 'single',
        'feature_types' => array(
          'path' => 'path',
          'point' => 'point',
          'polygon' => 'polygon',
        ),
        'openlayers_map' => 'contribute_mo_collection_geofield_widget',
        'showInputField' => 0,
      ),
      'type' => 'openlayers_geofield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-collection-field_main_image'.
  $field_instances['node-collection-field_main_image'] = array(
    'bundle' => 'collection',
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'links' => 0,
          'view_mode' => 'thumbnail',
        ),
        'type' => 'entityreference_entity_view',
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
    'field_name' => 'field_main_image',
    'label' => 'Preview image',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference_view_widget',
      'settings' => array(
        'allow_duplicates' => 0,
        'close_modal' => 0,
        'pass_argument' => 1,
        'pass_arguments' => '',
        'rendered_entity' => 0,
        'view' => 'reference_images_for_observation|entityreference_view_widget_1',
        'view_mode' => 'full',
      ),
      'type' => 'entityreference_view_widget',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>Where the pictures were taken. Adding this now will help in later steps, because the map will be zoomed in on what you add here.</p>
<p>Click once to add a point, and double-click to finish.<br />
If the pictures were taken along a route, use the <strong>path</strong> feature (recommended).<br />
For an area, use the <strong>polygon</strong> (defined by multiple points) feature.<br />
If the images were all taken in one place, use the <strong>point</strong> feature.</p>');
  t('Additional information');
  t('Any significant further information about this collection that might be of interest.');
  t('Collector');
  t('Date collected');
  t('If the pictures were taken over several days, provide the start and end date.');
  t('Location');
  t('Preview image');
  t('The <em>full name</em> of the person who recorded the observations; this is probably your full name.');

  return $field_instances;
}