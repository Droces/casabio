<?php
/**
 * @file
 * Functions that determine which pictures should be referenced by (represent) 
 * taxa.
 */

/**
  CONTENTS

  taxa_assess_community_identification()
  assess_new_pic_for_taxon()
  assess_new_main_pic_for_taxon()
  assess_new_pics_for_taxon()
  get_picture_reliability()
  get_observation_primary_picture_nid()
 */



/**
 * For a given community identification, calls a function that assesses whether
 * to replace the picture of the referenced taxon with the new picture.
 *
 * The taxon is referenced by the community identification provided.
 *
 * @param $new_comm_id_raw
 *   A new community identification node. It should reference a taxon, and an
 *   observation with at least one picture.
 */
function taxa_assess_community_identification($new_comm_id_raw) {
  // dpm($new_comm_id_raw, '$new_comm_id_raw');

  // ---------------------------------------------------------------------------
  // Get the taxon

  if (!$new_comm_id_raw)
    throw new InvalidArgumentException("Param $new_comm_id_raw needed.", 1);

  $new_comm_id = entity_metadata_wrapper('node', $new_comm_id_raw);

  $taxon_raw = $new_comm_id->field_identified_species->value();
  // dpm($taxon_raw, '$taxon_raw');

  if (! $taxon_raw) {
    throw new Exception("Community identifications must reference a taxon.", 1);
  }

  $taxon = entity_metadata_wrapper('taxonomy_term', $taxon_raw);

  // ---------------------------------------------------------------------------
  // Get the new picture and its reliability

  $new_reliability = $new_comm_id->field_reliability->value();
  // dpm($new_reliability, '$new_reliability');

  if (! $new_reliability) {
    return NULL;
  }

  // Get the community identification's picture

  $observation_raw = $new_comm_id->field_observation->value();
  // dpm($observation_raw, '$observation_raw');

  if (! $observation_raw) {
    throw new Exception("Community identifications must reference an observation.", 1);
  }

  $new_picture_nid = get_observation_primary_picture_nid($observation_raw);
  // dpm($new_picture_nid, '$new_picture_nid');

  // ---------------------------------------------------------------------------
  // Call the assess function for the taxon

  assess_new_pic_for_taxon($taxon, $new_reliability, $new_picture_nid);
}


/**
 * Determines if a new picture should replace a taxon's existing representative picture.
 *
 * This compares the reliabilities of the community identifications of the
 * observations referencing the (new and existing) pictures. If the 'new
 * reliability' is greater than the old, will replace the existing picture with
 * the new one.
 * See https://docs.google.com/drawings/d/13dJgc1QnqIg4WIHkGFYt66IKmEVeP87zuwEJF2uRVXw
 * for a diagram of the entities and fields used here/
 *
 * @return
 *   TRUE if the picture was replaced, false otherwise
 */
function assess_new_pic_for_taxon($taxon, $new_reliability, $new_picture_nid) {
  // dpm($taxon, '$taxon');
  // dpm($new_reliability, '$new_reliability');
  // dpm($new_picture_nid, '$new_picture_nid');

  $picture_is_replaced = FALSE;

  // ---------------------------------------------------------------------------
  // Get the existing picture's reliability

  $exis_pic_raw = $taxon->field_representative_picture->value();
  // dpm($exis_pic_raw, '$exis_pic_raw');

  $exis_reliability;
  if (! $exis_pic_raw) {
    $exis_reliability = 0;
  }
  else {
    $exis_reliability = get_picture_reliability($exis_pic_raw, $taxon->getIdentifier());
    // dpm($exis_reliability, '$exis_reliability');
  }

  // ---------------------------------------------------------------------------
  // Compare the new and existing pictures' reliabilities

  $is_new_picture_better = $new_reliability > $exis_reliability;
  // dpm($is_new_picture_better, '$is_new_picture_better');

  // ---------------------------------------------------------------------------
  // If the new community identification has a higher reliability than the
  // current picture's community identification, replace the reference to
  // the old picture with the new one.

  if (! $is_new_picture_better) {
    return $picture_is_replaced;
  }

  // Replace the current picture with the new picture

  $taxon->field_representative_picture->set($new_picture_nid);
  $taxon->save();
  $picture_is_replaced = TRUE;
  // dpm($picture_is_replaced, '$picture_is_replaced');

  // If this taxon has a parent
  // assess_new_pic_for_taxon() for parent

  return $picture_is_replaced;
}


function assess_new_pics_for_taxon($taxon_raw) {
  // dpm($taxon_raw, '$taxon_raw');
  // @todo FIX this! The save() function gives an error every time.
  // assess_new_main_pic_for_taxon($taxon_raw);
  // assess_new_secondary_pics_for_taxon($taxon_raw);
}


function get_pictures_of_taxon($tid) {
  // Create an array of all pictures of observations
  $pictures = [];
  $observations = get_observations_referencing_taxon($tid);
  // dpm($observations, '$observations');
  foreach ($observations as $nid) {
    $observation = entity_metadata_wrapper('node', $nid);
    $pictures = array_merge($pictures, $observation->field_pictures_observation->raw());
  }
  return $pictures;
}


function assess_new_main_pic_for_taxon($taxon_raw) {
  // dpm($taxon_raw, '$taxon_raw');
  $taxon = entity_metadata_wrapper('taxonomy_term', $taxon_raw);
  // dpm($taxon->raw(), '$taxon->raw()');
  $existing_picture = $taxon->field_representative_picture->value();
  // dpm($existing_picture, '$existing_picture');
  
  // If it already has pictures, skip
  if ($existing_picture) {
    return NULL;
  }

  $pictures = get_pictures_of_taxon($taxon->getIdentifier());
  if (! $pictures) {
    return NULL;
  }
  // dpm($pictures, '$pictures');

  // Get the first one
  $picture = $pictures[0];
  // dpm($picture, '$picture');

  $taxon->field_representative_picture->set($picture);
  // dpm($taxon->raw(), '$taxon->raw()');
  $taxon->save();
  // dpm($taxon, '$taxon after save');
}


function assess_new_secondary_pics_for_taxon($taxon_raw) {
  // dpm($taxon_raw, '$taxon_raw');

  $taxon = entity_metadata_wrapper('taxonomy_term', $taxon_raw);
  $existing_pictures = $taxon->field_pictures->value();
  // dpm($existing_pictures, '$existing_pictures');
  
  // If it already has pictures, skip
  if ($existing_pictures) {
    return NULL;
  }

  $pictures = get_pictures_of_taxon($taxon->getIdentifier());
  // dpm($pictures, '$pictures');
  if (! $pictures) {
    return NULL;
  }

  // Get the first 5 (because the first is used as the main pic)
  $pictures = array_slice($pictures, 1, 5);

  $taxon->field_pictures->set($pictures);
  $taxon->save();
  // dpm($taxon, '$taxon after save');
}


/**
 * Determines the reliability of a picture.
 *
 * Gets the observation referencing the pic (there should be only 1),
 * then gets the observation's community identifications (sorted by reliability),
 * then gets the first comm identification's reliability.
 *
 * @param $tid
 *   The tid of the species taxon that the picture should be of.
 *
 * @return int
 *   An integer between 0 and 100.
 */
function get_picture_reliability($picture, $tid) {

  $observation = get_observation_referencing_pic($picture->nid);
  // dpm($observation, '$observation');

  if (!$observation)
    return NULL;

  $comm_ids = get_identifications_refing_observation(
    'identification_community', $observation->nid, $tid);
  // dpm($comm_ids, '$comm_ids');

  if (!$comm_ids || $comm_ids == [])
    return NULL;

  // Just take the first one; they're already ordered by reliability.
  $comm_id_raw = node_load(reset($comm_ids)->nid);
  // dpm($comm_id_raw, '$comm_id_raw');

  $comm_id = entity_metadata_wrapper('node', $comm_id_raw);
  $reliability = $comm_id->field_reliability->value();
  // dpm($reliability, '$reliability');

  // If there is no existing reliability, set it to 0.
  if ($reliability) {
    return $reliability;
  }
  else {
    return NULL;
  }
}


function get_observation_primary_picture_nid($observation_raw) {

  $observation = entity_metadata_wrapper('node', $observation_raw);
  $pictures = $observation->field_pictures_observation->value();
  // dpm($pictures, '$pictures');

  if (!$pictures)
    return NULL;

  $new_picture_nid = $pictures[0]->nid; // Use the first, which should be the primary pic.
  // dpm($new_picture_nid, '$new_picture_nid');

  return $new_picture_nid;
}