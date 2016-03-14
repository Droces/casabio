<?php
/**
 * @file
 * taxonomy_taxa.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function taxonomy_taxa_taxonomy_default_vocabularies() {
  return array(
    'taxa' => array(
      'name' => 'Taxa',
      'machine_name' => 'taxa',
      'description' => 'The categorisation of biological organisms on the basis of shared characteristics.',
      'hierarchy' => 0,
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
