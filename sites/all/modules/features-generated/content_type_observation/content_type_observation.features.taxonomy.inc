<?php
/**
 * @file
 * content_type_observation.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function content_type_observation_taxonomy_default_vocabularies() {
  return array(
    'locality' => array(
      'name' => 'Locality',
      'machine_name' => 'locality',
      'description' => 'An area of land that can be any size and has a defined boundary. Countries, provinces, municipalities, and suburbs are examples ',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
