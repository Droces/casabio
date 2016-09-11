SELECT node.nid AS nid,
  node.created AS node_created,
  'node' AS field_data_field_location_node_entity_type
FROM
  {node} node

LEFT JOIN {field_data_field_observation} field_data_field_observation
  ON node.nid = field_data_field_observation.field_observation_target_id
  AND (field_data_field_observation.entity_type = 'node'
  AND field_data_field_observation.deleted = '0')

LEFT JOIN {node} field_observation_node
  ON field_data_field_observation.entity_id = field_observation_node.nid

LEFT JOIN {field_data_field_identified_species} field_observation_node__field_data_field_identified_species
  ON field_observation_node.nid = field_observation_node__field_data_field_identified_species.entity_id
  AND (field_observation_node__field_data_field_identified_species.entity_type = 'node'
  AND field_observation_node__field_data_field_identified_species.deleted = '0')

LEFT JOIN {taxonomy_term_data} taxonomy_term_data_field_data_field_identified_species
  ON field_observation_node__field_data_field_identified_species.field_identified_species_tid
    = taxonomy_term_data_field_data_field_identified_species.tid

LEFT JOIN {field_data_field_location} field_data_field_location
  ON node.nid = field_data_field_location.entity_id
  AND (field_data_field_location.entity_type = 'node'
  AND field_data_field_location.deleted = '0')


WHERE
  -- Contextual filters
  (( (taxonomy_term_data_field_data_field_identified_species.tid = ' 96540' ) )
  -- Pre-defined filters
  AND (
    ( (node.status = '1')
    AND (node.type IN ('observation'))
    AND (field_observation_node.type IN ('identification_community')) )
    AND (field_data_field_location.field_location_geom IS NOT NULL ) )
  ))
ORDER BY node_created DESC
LIMIT 5 OFFSET 0
