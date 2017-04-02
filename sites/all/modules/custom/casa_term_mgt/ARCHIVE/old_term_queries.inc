<?php



/**
 * Gets the locations of all identifications of a taxon.
 *
 * @param $results_limit
 *   The maximum number of results to fetch
 *
 * @return
 *   An array of longitudes and latitudes.
 */
function get_taxon_locations($tid, $results_limit) {

  // // Create an object of type SelectQuery
  // $query = db_select('node', 'node');
  // $query->addTag('node_access');

  // // Link to the field_observation table
  // $query->leftJoin('field_data_field_observation', 'field_data_field_observation',
  //   "node.nid = " . 'field_data_field_observation' . ".field_observation_target_id "
  //   . "AND (" . 'field_data_field_observation' . ".entity_type = 'node' "
  //   . "AND " . 'field_data_field_observation' . ".deleted = '0')");

  // // Get the referenced observation
  // $query->leftJoin('node', 'field_observation_node',
  //   'field_data_field_observation.entity_id = field_observation_node.nid');

  // // Link to the field_identified_species table
  // $query->leftJoin('field_data_field_identified_species',
  //     'field_observation_node__field_data_field_identified_species',
  //   'field_observation_node' . '.nid = field_observation_node__field_data_field_identified_species.entity_id '
  //     . "AND (field_observation_node__field_data_field_identified_species.entity_type = 'node' "
  //     . "AND field_observation_node__field_data_field_identified_species.deleted = '0')");

  // // Get the referenced species
  // $query->leftJoin('taxonomy_term_data', 'taxonomy_term_data_field_data_field_identified_species',
  //   'field_observation_node__field_data_field_identified_species' . '.field_identified_species_tid = taxonomy_term_data_field_data_field_identified_species.tid');


  // // Link to the field_location table (used only by 'location not null' filter)
  // $query->leftJoin('field_data_field_location', 'field_data_field_location',
  //     "node.nid = field_data_field_location.entity_id "
  //     . "AND (field_data_field_location.entity_type = 'node' "
  //     . "AND field_data_field_location.deleted = '0')");

  // // Add fields to the query
  // $query->addField('node', 'nid', 'nid');
  // $query->addField('node', 'created', 'node_created');
  // // $query->addField('node', 'node', 'field_data_field_location_node_entity_type');
  // // $query->addField('field_data_field_location', 'node_entity_type', 'field_data_field_location_node_entity_type');
  // // $query->addField('field_data_field_location', 'field_location_geom', 'field_location_geom');
  // $query->addField('field_data_field_location', 'field_location_lon', 'field_location_lon');
  // $query->addField('field_data_field_location', 'field_location_lat', 'field_location_lat');

  // // Add extra detail to the query object: conditions, orders and a range
  // $query
  //   // Pre-defined filters

  //   // Only published nodes
  //   ->condition('node.status', 1, '=')
  //   // That are observations
  //   ->condition('node.type', array('observation',), 'IN')
  //   // Referencing identifications should only be 'community identifications'
  //   ->condition('field_observation_node.type', array('identification_community'), 'IN' )

  //   // Contextual filters

  //   // Where the observation’s identified species’ term id = $tid
  //   ->condition('taxonomy_term_data_field_data_field_identified_species.tid', $tid, '=')

  //   // Where the location field has a value
  //   ->isNotNull('field_data_field_location.field_location_lat')

  //   ->orderBy('node_created', 'DESC')

  //   ->range(0, $results_limit)
  // ;
  // $results = $query->execute();
  // // dpm($results, 'results of dynamic query');

  // $locations = (object) array(
  //   'type' => 'FeatureCollection',
  //   'features' => new \stdClass,
  // );

  // // Convert the results' coordinates into a unencoded GeoJSON feature.
  // foreach ($results as $result) {
  //   // dpm($result, 'result');

  //   $locations->features = (object) array(
  //     "type" => "Feature",
  //     "geometry" => (object) array(
  //       "type" => "Point",
  //       // "coordinates" => $result->field_location_geom,
  //       "coordinates" => [$result->field_location_lon, $result->field_location_lat],
  //     ),
  //     "properties" => new \stdClass,
  //   );
  // }


  // return $locations;
}