<?php
/**
 * @file
 * Description…
 */



/**
 * Saves a new interaction that references the specified 'Subject' observation.
 * Also creates a new observation for the interaction's 'Object'.
 *
 * @param $nid
 *   The nid of the observation that should be 'Subject' of the interaction.
 * @param $params
 *   An array of field data to be used in creating the 'Object' observation,
 *   the identification of it, and the interaction.
 *
 * @return
 *   The new interaction node.
 */
function observation_add_interaction($nid, $params) {
  // dpm($nid, '$nid');
  // dpm($params, '$params');

  if (! is_valid_eid($nid)) {
    throw new InvalidArgumentException("Parameter $nid, " . $nid . ", needs to be a valid NID.", 1);
  }
  if (gettype($params) !== 'array') {
    throw new InvalidArgumentException("Parameter $params, " . $params . ", is not an array.", 1);
  }

  $observation_raw = node_load($nid);
  $language = 'und';

  // If the node isn't an observation
  if ($observation_raw->type != 'observation') {
    throw new Exception("Node " . $nid . " is not an observation.", 1);
    return NULL;
  }

  // If a value in $params isn't valid
  $tid = $params['identifiedSpecies'];
  if (!is_valid_eid($tid)) {
    throw new Exception("Value of field_identified_species, " . $tid . ", needs to be a valid tid.", 1);
  }

  global $user;



  // Create the new observation node

  $observation_subj = duplicate_observation($observation_raw);
  // dpm($observation_subj, '$observation_subj');



  // Create an identification node for the new observation

  $values = array(
    'uid' => $user->uid,
    'species_tid' => $tid,
    'observation_subj_nid' => $observation_subj->nid,
    'certainty' => $params['certainty'],
  );

  $identification = create_identification($values);



  // Create the interaction node

  $values = array(
    'uid' => $user->uid,
    'field_observation' => $nid,
    'field_interaction_activity' =>
      $params['interactionActivity'],
    'field_observation_object' =>
      $observation_subj->nid,
    'body' => array(
      'value' => $params['body'],
      'format' => $params['body'],
    )
  );

  $interaction = create_interaction($values);
  // dpm($interaction, '$interaction');

  return $interaction;
}



/**
 * Creates a copy of an observation, keeping some properties and field values.
 */
function duplicate_observation($observation) {
  // dpm($observation, '$observation');

  $observation_new = entity_create('node', array(
    'type' => 'observation',
    'title' => '',
    'uid' => $observation->uid,
    'status' => 1, // published
  ));

  // The fields that should be copied from the original observation
  $fields_to_keep = array (
    'field_observer_name',
    'field_date_observed',
    // 'field_collection',
    'field_location',
    'field_locality',
    'field_pictures_observation',
    'field_source');
  // Not keeping: title, body, count, any id fields, identifications.

  foreach ($fields_to_keep as $field_name) {
    // dpm($observation->$field_name, $field_name . ' value');
    $observation_new->$field_name = $observation->$field_name;
  }

  node_save($observation_new);
  // dpm($observation_new, '$observation_new');

  return $observation_new;
}



/**
 * @param $values
 *   Array of properties and field values containing:
 *   uid, field_observation, field_interaction_activity, field_observation_object, body
 */
function create_interaction($values) {

  $interaction_raw = entity_create('node', array(
    'type' => 'interaction',
    'title' => '',
    'uid' => $values['uid'],
    'status' => 1, // published
  ));
  // dpm($interaction_raw, '$interaction_raw');

  $interaction = entity_metadata_wrapper('node', $interaction_raw);

  $interaction->field_observation->set(
    $values['field_observation']);

  $interaction->field_interaction_activity->set(
    $values['field_interaction_activity']);

  $interaction->field_observation_object->set(
    $values['field_observation_object']);

  $interaction->body->set(
    $values['body']);

  $interaction->title->set(
    $values['field_observation']
      . ' ' . $interaction->field_interaction_activity->value()
      . ' ' . $interaction->field_observation_object->raw()
  );

  $interaction->save();

  return $interaction->value();
}



/**
 * @param $values
 *   Array of properties and field values containing:
 *   uid, species_tid, observation_subj_nid, certainty
 */
function create_identification($values) {

  $identification_raw = entity_create('node', array(
    'type' =>   'identification',
    'title' =>  '',
    'uid' =>    $values['uid'],
    'status' => 1, // published
  ));

  // dpm($identification_raw, '$identification_raw');
  $identification = entity_metadata_wrapper('node', $identification_raw);

  // $tid = 88216;
  $taxon = taxonomy_term_load($values['species_tid']);
  // dpm($taxon, '$taxon');

  if (!$taxon || $taxon->vocabulary_machine_name != 'taxa') {
    throw new Exception("Tid, " . $values['species_tid'] . ", is not the tid of a taxon.", 1);
  }

  $identification->title->set(
    $taxon->name);
  $identification->field_observation->set(
    $values['observation_subj_nid']);
  $identification->field_identified_species->set(
    $taxon);
  $identification->field_certainty->set(
    $values['certainty']);
  $identification->save();

  return $identification;
}
