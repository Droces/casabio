<?php
/**
 * @file
 * taxonomy_threats_disturbances.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function taxonomy_threats_disturbances_taxonomy_default_vocabularies() {
  return array(
    'threats_disturbances' => array(
      'name' => 'Threats & Disturbances',
      'machine_name' => 'threats_disturbances',
      'description' => '',
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
