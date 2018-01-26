<?php

// More advanced example: multi-step operation - load all nodes, five by five
function import_synonyms($file_data, &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = count($file_data);
  }

  $start = $context['sandbox']['progress'];
  $batch_size = 10;

  for ($i = $start; $i < ($start + $batch_size); $i++) {
    $context['sandbox']['progress']++;
    if ($context['sandbox']['progress'] == 1)
      continue;

    $data = explode('|', $file_data[$i]);
    // dpm($data, '$data');
    if (count($data) < 6)
      continue;

    // Get the main taxon
    
    // Assumes that all text fields are enclosed in ""
    $taxon_name = substr($data[3], 1, -1);
    // dpm($taxon_name, '$taxon_name');
    $taxon_reps = get_taxa_with_sci_name($taxon_name, 'is', $results_limit = 10);
    // dpm($taxon_reps, '$taxon_reps');
    if (! $taxon_reps) {
      // dpm('Taxon "' . $taxon_name . '" not found');
      $context['results']['failures'][] = $taxon_name;
      continue;
    }
    $taxon = entity_metadata_wrapper('taxonomy_term', array_keys($taxon_reps)[0]);
    // dpm($taxon->raw(), '$taxon->raw()');

    // Get and set the synonym taxon
    
    // Assumes that all text fields are enclosed in ""
    $synonym_name = substr($data[1], 1, -1);
    // dpm($synonym_name, '$synonym_name');
    $synonym_reps = get_taxa_with_sci_name($synonym_name, 'is', $results_limit = 10);
    // dpm($synonym_reps, '$synonym_reps');
    if ($synonym_reps) {
      $synonym_tid = array_keys($synonym_reps)[0];
      // dpm($synonym_tid, '$synonym_tid');
      $taxon->field_synonym_of->set([$synonym_tid]);
    }
    else {
      // dpm('Synonym "' . $synonym_name . '" not found');
    }

    // Set the synonym status

    $field_synonym_status = $data[6];
    // dpm($field_synonym_status, '$field_synonym_status');
    if ($field_synonym_status) {
      $taxon->field_synonym_status->set($field_synonym_status);
    }

    // Save and wrap up

    // dpm($taxon->raw(), '$taxon->raw()');
    $taxon->save();

    $context['results']['successes'][] = $taxon->getIdentifier() . ' : ' . check_plain($taxon->label());
    // $batch_set['total'] = count($batch_set['operations']);
    $context['message'] = $context['sandbox']['progress'] - 1 
      . ' of ' . $context['sandbox']['max']
      . ': ' . check_plain($taxon->label());
  }
  if (($context['sandbox']['progress'] - 1) != $context['sandbox']['max']) {
    $context['finished'] = ($context['sandbox']['progress'] - 1) / $context['sandbox']['max'];
  }
}



function import_synonyms_finished($success, $results, $operations) {
  // The 'success' parameter means no fatal PHP errors were detected. All
  // other error management should be handled using 'results'.
  if ($success) {
    $message = count($results['successes']) . ' Successes.';
    drupal_set_message($message, 'status', FALSE);
    $message = '<details>'
      . '<summary>' . count($results['failures']) . ' Failures:</summary>'
      . '<ul><li>' . implode('</li><li>', $results['failures']) . '</li></ul>'
      . '</details>';
    drupal_set_message($message, 'status', FALSE);
  }
  else {
    $message = t('Finished with an error.');
    drupal_set_message($message, 'error', FALSE);
  }
  
  // // Providing data for the redirected page is done through $_SESSION.
  // foreach ($results as $result) {
  //   $items[] = t('Loaded node %title.', array(
  //     '%title' => $result,
  //   ));
  // }
  // $_SESSION['my_batch_results'] = $items;
}