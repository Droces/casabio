<?php
/**
 * @file
 * taxonomy_habitats.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function taxonomy_habitats_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_air_moisture'.
  $field_bases['field_air_moisture'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_air_moisture',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'seasonally_wet' => 'Seasonally wet',
        'seasonally_moist' => 'Seasonally moist',
        'permanently_wet' => 'Permanently wet',
        'permanently_moist' => 'Permanently moist',
        'mist_fog' => 'Mist/fog',
        'unknown' => 'Unknown',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_geology'.
  $field_bases['field_geology'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_geology',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'conglomerate' => 'Conglomerate',
        'sandstone' => 'Sandstone',
        'shale' => 'Shale',
        'limestone' => 'Limestone',
        'dolomite' => 'Dolomite',
        'dolorite' => 'Dolorite',
        'basalt' => 'Basalt',
        'granite' => 'Granite',
        'quartzite' => 'Quartzite',
        'silcrete' => 'Silcrete',
        'laterite' => 'Laterite',
        'ferricrete' => 'Ferricrete',
        'other' => 'Other',
        'unknown' => 'Unknown',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_land_form'.
  $field_bases['field_land_form'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_land_form',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'mountain_peak' => 'Mountain peak',
        'mountain_slope' => 'Mountain slope',
        'hilltop' => 'Hilltop',
        'hill_slope' => 'Hill slope',
        'ridge' => 'Ridge',
        'cliff_face' => 'Cliff face',
        'kloof_ravine' => 'Kloof/ravine',
        'talus_scree' => 'Talus/scree',
        'flat_plain' => 'Flat/plain',
        'valley' => 'Valley',
        'floodplain' => 'Floodplain',
        'waterfall' => 'Waterfall',
        'river_bank' => 'River bank',
        'river_stream' => 'River stream',
        'dry_streambed' => 'Dry streambed',
        'donga' => 'Donga',
        'pan' => 'Pan',
        'depression' => 'Depression',
        'wetland_marsh' => 'Wetland/marsh',
        'seepage' => 'Seepage',
        'dune_coastal' => 'Dune(coastal)',
        'dune_desert' => 'Dune(desert)',
        'dune_slack' => 'Dune slack',
        'littoral' => 'Littoral',
        'lagoon' => 'Lagoon',
        'standing_water' => 'Standing water',
        'estuary' => 'Estuary',
        'mountain_plateau' => 'Mountain plateau',
        'stream_Bank' => 'Stream Bank',
        'other' => 'Other',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_land_use'.
  $field_bases['field_land_use'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_land_use',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'crops' => 'Crops',
        'game' => 'Game',
        'mining' => 'Mining',
        'stock' => 'Stock',
        'urban' => 'Urban',
        'industry' => 'Industry',
        'orchards' => 'Orchards',
        'poultry' => 'Poultry',
        'conservation' => 'Conservation',
        'plantations' => 'Plantations',
        'recreational' => 'Recreational',
        'other' => 'Other',
        'uknown' => 'Uknown',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_soil_colour'.
  $field_bases['field_soil_colour'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_soil_colour',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'black' => 'Black',
        'brown' => 'Brown',
        'grey' => 'Grey',
        'white' => 'White',
        'yellow' => 'Yellow',
        'orange' => 'Orange',
        'red' => 'Red',
        'unknown' => 'Unknown',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_soil_type'.
  $field_bases['field_soil_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_soil_type',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'sand' => 'Sand',
        'loam' => 'Loam',
        'clay' => 'Clay',
        'peat' => 'Peat',
        'gravel' => 'Gravel',
        'rocky' => 'Rocky',
        'silt' => 'Silt',
        'rocky-sandy' => 'Rocky / Sandy',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_veld_age'.
  $field_bases['field_veld_age'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_veld_age',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'mature_veld' => 'Mature veld',
        'recently_burnt' => 'Recently burnt',
        'senescent_veld' => 'Senescent veld',
        'young_veld' => 'Young veld',
        'unknown' => 'Unknown',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
