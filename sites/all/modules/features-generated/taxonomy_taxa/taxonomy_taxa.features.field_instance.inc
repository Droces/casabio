<?php
/**
 * @file
 * taxonomy_taxa.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function taxonomy_taxa_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-taxa-field_common_names'.
  $field_instances['taxonomy_term-taxa-field_common_names'] = array(
    'bundle' => 'taxa',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The non-scientific names that people typically call this species / taxon. There may be several names in different languages.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => 'No common names',
          'empty_fields_handler' => 'EmptyFieldText',
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'field_guide' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
        ),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'small' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_common_names',
    'label' => 'Common names',
    'required' => 0,
    'settings' => array(
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
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'taxonomy_term-taxa-field_identifications_count'.
  $field_instances['taxonomy_term-taxa-field_identifications_count'] = array(
    'bundle' => 'taxa',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The number of observations that have been identified as being this species.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 5,
      ),
      'field_guide' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'small' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_identifications_count',
    'label' => 'Number of identifications',
    'required' => 0,
    'settings' => array(
      'max' => 1000000,
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'taxonomy_term-taxa-field_lsid'.
  $field_instances['taxonomy_term-taxa-field_lsid'] = array(
    'bundle' => 'taxa',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A Life Science IDentifier (LSID) is the globally-unique code that is a reference to an authoritative source of information on this taxon. 
It should be written in the form: urn:lsid:<authority>:<namespace>:<ObjectID>:[version].',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => 'Unknown',
          'empty_fields_handler' => '',
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'field_guide' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
        ),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'small' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_lsid',
    'label' => 'LSID',
    'required' => 0,
    'settings' => array(
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
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'taxonomy_term-taxa-field_range'.
  $field_instances['taxonomy_term-taxa-field_range'] = array(
    'bundle' => 'taxa',
    'default_value' => array(
      0 => array(
        'dataType' => 'WKT',
        'geom' => 'GEOMETRYCOLLECTION EMPTY',
        'input_format' => 'wkt',
      ),
    ),
    'deleted' => 0,
    'description' => '<p>The geographical area within which this species can be found.</p>
<p>Specifically, this is the area where the species is currently found, rather than where it is endemic, because this is used to aid identifications.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'geofield',
        'settings' => array(
          'data' => 'full',
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
        ),
        'type' => 'geofield_wkt',
        'weight' => 7,
      ),
      'field_guide' => array(
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
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_range',
    'label' => 'Range',
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
          'path' => 0,
          'point' => 0,
          'polygon' => 'polygon',
        ),
        'openlayers_map' => 'openlayers_geofield_map_geofield_widget',
        'showInputField' => 0,
      ),
      'type' => 'openlayers_geofield',
      'weight' => 38,
    ),
  );

  // Exported field_instance: 'taxonomy_term-taxa-field_representative_picture'.
  $field_instances['taxonomy_term-taxa-field_representative_picture'] = array(
    'bundle' => 'taxa',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
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
        'weight' => 8,
      ),
      'field_guide' => array(
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
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_representative_picture',
    'label' => 'Representative picture',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(),
      ),
      'type' => 'inline_entity_form_single',
      'weight' => 39,
    ),
  );

  // Exported field_instance: 'taxonomy_term-taxa-field_scientific_name'.
  $field_instances['taxonomy_term-taxa-field_scientific_name'] = array(
    'bundle' => 'taxa',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'field_guide' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'small' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_scientific_name',
    'label' => 'Scientific name',
    'required' => 0,
    'settings' => array(
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
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'taxonomy_term-taxa-field_taxon_rank'.
  $field_instances['taxonomy_term-taxa-field_taxon_rank'] = array(
    'bundle' => 'taxa',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => 'Unknown rank',
          'empty_fields_handler' => 'EmptyFieldText',
        ),
        'type' => 'list_default',
        'weight' => 0,
      ),
      'field_guide' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '',
          'empty_fields_handler' => '',
        ),
        'type' => 'list_default',
        'weight' => 1,
      ),
      'small' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_taxon_rank',
    'label' => 'Rank',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>The geographical area within which this species can be found.</p>
<p>Specifically, this is the area where the species is currently found, rather than where it is endemic, because this is used to aid identifications.</p>');
  t('A Life Science IDentifier (LSID) is the globally-unique code that is a reference to an authoritative source of information on this taxon. 
It should be written in the form: urn:lsid:<authority>:<namespace>:<ObjectID>:[version].');
  t('Common names');
  t('LSID');
  t('Number of identifications');
  t('Range');
  t('Rank');
  t('Representative picture');
  t('Scientific name');
  t('The non-scientific names that people typically call this species / taxon. There may be several names in different languages.');
  t('The number of observations that have been identified as being this species.');

  return $field_instances;
}
