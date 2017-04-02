<?php
/**
 * @file
 * Functions that are fired when nodes are created, read, updated, or deleted.
 */

/**
 * CONTENTS

  save_observation_locality_to_taxon()
  filter_identifications_to_one()
  update_matching_comm_identi()
  update_community_identification()
  update_observation_title_from_identi()
  save_locality_to_taxon()
 */



/**
 * If observation has a locality, save to each identified taxon.
 */
function save_observation_locality_to_taxon($observation_nid) {

  $locality_wrapped = entity_metadata_wrapper('node', $observation_nid)
   ->field_locality->raw();

  if (! $locality_wrapped) {
    return;
  }

  $locality = $locality_wrapped[0];
  // dpm($locality, '$locality');

  // Get its community identifications
  $identifications = get_identifications_refing_observation(
    'identification_community', $observation_nid);
  // dpm($identifications, '$identifications');

  foreach ($identifications as $identification_nid => $identification_representation) {
    save_locality_to_taxon($identification_nid, $locality);
  }
}



/**
 * Finds all matching identifications by user, and keeps only one (delete others).
 * Called when an identification is created.
 *
 * @param $node
 *   The identification being saved.
 */
function filter_identifications_to_one($node) {
  // dpm($node, '$node');
  global $user;
  $identification = entity_metadata_wrapper('node', $node);

  if (! $identification->field_observation->raw()) {
    // throw new Exception("Identification does not reference an observation", 1);
    return NULL;
  }

  $matching_identifications = get_identifications_refing_observation(
    'identification',
    $identification->field_observation->raw(), // nid
    $identification->field_identified_species->raw(), // tid
    $user->uid); // uid

  if ($matching_identifications) {
    // dpm($matching_identifications, '$matching_identifications');

    foreach ($matching_identifications as $nid => $identification_raw) {
      // If this isn't the identification being saved
      if ($nid . '' !== $node->nid . '') {
        node_delete($nid);
      }
    }
  }
}



/**
 * Creates or updates a community identification that matches an identification being saved.
 *
 * @param stdClass $identification
 *   The new identification that is being saved (but is not yet in the database).
 */
function update_matching_comm_identi($identification) {
  // dpm($identification, '$identification');
  // Gather data

  $identification = entity_metadata_wrapper('node', $identification);
  $observation = $identification->field_observation->value();
  $identified_species = $identification->field_identified_species->value();

  // If the identification is missing an observation or identified_species
  if (!($observation && $identified_species)) {
    throw new Exception("Saved identification does not reference an observation and a taxon.", 1);
  }

  // Update it
  $community_identification = update_community_identification(
    $observation, $identified_species, $identification);

  // update_users_reputations($community_identification); // @todo create this function

  return $community_identification;
}




/**
 * Updates the community identification of a given observation and species.
 *
 * Typically called when a new identification has been saved, thus requiring the
 * community identification to be re-evaluated.
 *
 * @param stdClass $observation
 *   Regular node object.
 * @param EntityMetadataWrapper $identification
 *   The new identification that is being saved (but is not yet in the database).
 */
function update_community_identification($observation, $identified_species, $identification) {
  // dpm($observation, '$observation');
  // dpm($identified_species, '$identified_species');
  // dpm($identification->raw(), '$identification->raw()');

  $commun_identification_raw;

  // Load all (individual) identifications

  $observation_nid = $observation->nid;
  // dpm($observation_nid, '$observation_nid');
  $identified_species_tid = $identified_species->tid;
  // dpm($identified_species_tid, '$identified_species_tid');

  $referencing_nodes = get_identifications_refing_observation(
    'identification', $observation_nid, $identified_species_tid);

  // Add the new identification to the results (it won't be in the results).
  $referencing_nodes[$identification->getIdentifier()] = $identification;
  // dpm($referencing_nodes, 'referencing_nodes');

  if (!$referencing_nodes) {
    throw new Exception("No existing identifications found", 1);
  }

  // Get the identifications' nids
  $referencing_nids = array_keys($referencing_nodes);
  // dpm($referencing_nids, 'referencing_nids');




  // Get existing community identification if it exists

  $existing_comm_id = get_identifications_refing_observation(
    'identification_community', $observation_nid, $identified_species_tid);
  // dpm($existing_comm_id, 'existing_comm_id');

  // Load existing node or create a new one

  $species_name = $identified_species->name;

  if ($existing_comm_id) {
    $nid = array_keys($existing_comm_id)[0];
    if ($nid) {
      $commun_identification_raw = node_load($nid);
    }
  }
  else {
    $commun_identification_raw = entity_create('node', array(
      'type' =>     'identification_community',
      'title' =>    $species_name,
      'uid' =>      0, // Anonymous
      'status' =>   1, // Published
    ));
  }
  // dpm($commun_identification_raw, 'commun_identification_raw');




  // Update node values

  $commun_identification = entity_metadata_wrapper('node', $commun_identification_raw);

  $current_title = $commun_identification->title->value();
  if ($current_title == 'Untitled' || $current_title == '') {
    $commun_identification->title->set($species_name);
  }

  $commun_identification->field_identification_source-> set(ID_SOURCE_CASABIO_COMMUNITY); // CasaBio community
  $commun_identification->field_observation->           set($observation);
  $commun_identification->field_identified_species->    set($identified_species);

  $commun_identification->field_identifications->       set($referencing_nids);

  $reliability = calculate_identification_reliability($referencing_nids);
  $commun_identification->field_reliability->           set($reliability);

  $commun_identification->save();

  return $commun_identification;
}



/**
 * @param $node
 *   A community identification that has just been updated.
 */
function update_observation_title_from_identi($observation) {
  // dpm($observation, '$observation');

  if (! $observation) {
    throw new Exception("Param \$observation not valid.", 1);
  }

  // Update the observation's title based on the community identification identified
  $most_reliable_comm_identi = calc_most_reliable_comm_identi($observation);

  if ($most_reliable_comm_identi) {
    $observation->title = $most_reliable_comm_identi->label();
    node_save($observation);
  }

  // drupal_goto('node/' . $observation->getIdentifier());
}



/**
 * @return
 *   The most reliable community identification of an observation.
 */
function calc_most_reliable_comm_identi($observation) {

  $comm_identis = get_identifications_refing_observation(
    'identification_community',
    $observation->nid);
  // dpm($comm_identis, '$comm_identis');

  if (! $comm_identis) {
    return;
  }

  $most_reliable_comm_identi = array_values($comm_identis)[0];
  $highest_reliability = 0;

  // Determine the community identification with the highest reliability.

  foreach ($comm_identis as $nid => $comm_identi_raw) {
    $comm_identi = entity_metadata_wrapper('node', $nid);
    // dpm($comm_identi->raw(), '$comm_identi->raw()');
    $reliability = $comm_identi->field_reliability->value();
    // dpm($reliability, '$reliability');


    // Treat lower (more specific) ranks with more weight
    $rank = strtolower($comm_identi->field_identified_species->field_taxon_rank->value());
    // dpm($rank, '$rank');
    $taxon_multiplier = 1;
    $rank_multiplier = 1.6; // How much more each successive rank should be weighted.
    switch ($rank) {
      case 'kingdom':
        $taxon_multiplier = pow(1.0, 1); // 1
        break;
      case 'phylum':
        $taxon_multiplier = pow($rank_multiplier, 1); // 1.6
        break;
      case 'class':
        $taxon_multiplier = pow($rank_multiplier, 2); // 2.56
        break;
      case 'order':
        $taxon_multiplier = pow($rank_multiplier, 3);
        break;
      case 'family':
        $taxon_multiplier = pow($rank_multiplier, 4);
        break;
      case 'genus':
        $taxon_multiplier = pow($rank_multiplier, 5);
        break;
      case 'species':
        $taxon_multiplier = pow($rank_multiplier, 6);
        break;
      default:
        $taxon_multiplier = pow(1.0, 1); // 1
        break;
    }
    // dpm($taxon_multiplier, '$taxon_multiplier');
    $reliability *= $taxon_multiplier;
    // dpm($reliability, '$reliability after taxon_multiplier');

    if ($reliability > $highest_reliability) {
      $most_reliable_comm_identi = $comm_identi;
      $highest_reliability = $reliability;
    }
  }
  // dpm($most_reliable_comm_identi->raw(), '$most_reliable_comm_identi->raw()');
  // dpm($highest_reliability, '$highest_reliability');

  if ($highest_reliability <= 10) {
    return NULL;
  }

  return $most_reliable_comm_identi;
}



/**
 * If observation has a locality, save to each identified taxon.
 * 
 * @param $identification_nid
 *   ID of an identification or community identification node.
 * @param $locality
 */
function save_locality_to_taxon($identification_nid, $locality = NULL) {
  
  if (! is_valid_eid($identification_nid)) {
    throw new InvalidArgumentException("Parameter $identification_nid, " . $identification_nid . ", needs to be a valid NID.", 1);
  }

  // Get the taxon node (wrapped)
  
  $species_tid = entity_metadata_wrapper('node', $identification_nid)
   ->field_identified_species->raw();
  // dpm($species_tid, '$species_tid');
  $species = entity_metadata_wrapper('taxonomy_term', $species_tid);
  // dpm($species->value(), '$species');

  // dpm($locality, '$locality');

  // @TODO Validation of this locality for this species
  $passed_validation = TRUE;

  if (! $passed_validation) {
    return NULL;
  }

  // Get locality from identification
  if (! $locality) {
    $observation_nid = entity_metadata_wrapper('node', $identification_nid)
     ->field_observation->raw();

    $localities = entity_metadata_wrapper('node', $observation_nid)
     ->field_locality->raw();

    if (! $localities) {
      return;
    }

    $locality = $localities->raw();
    // dpm($locality, '$locality');
  }

  $has_locality = in_array($locality->nid, $species->field_localities->raw());
  // dpm($has_locality, '$has_locality');

  if ($passed_validation && ! $has_locality) {
    $species->field_localities[] = $locality;
    // dpm($species, '$species before save');
    $species->save();
    // dpm($species->value(), '$species after save');
  }
}