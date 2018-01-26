<?php
/**
 * @file
 * Functions that build and process the 'Import Etymologies' form.
 */

/**
  CONTENTS

  import_etymologies_form()
  import_etymologies_form_submit()
  import_etymologies()
 */

/**
 * Implements hook_form(). Creates a small form for adding a taxon that CasaBio does not yet have.
 *
 * If a taxon already has an etymology...
 * Try: Abietinella>From the Latin ‘abie’ / ‘abies’ meaning.
 */
function import_etymologies_form() {

  $form['#attributes'] = array(
    'class' => array('width_narrow'),
  );

  $form['description'] = array(
    '#markup' => '<p>Use this to add etymologies to taxa (species, genus, etc.) in CasaBio. Taxa that already have an etymology can be skipped.</p>',
  );

  $form['data'] = array(
    '#title' => t('Taxa names and etymologies'),
    '#description' => '<p>Each taxon / etymology pair should be separated by a pipe character (&lsquo;|&rsquo;) and be on their own line, eg: </p><pre>Taxon name|etymology<br>...</pre>'
      . '<p>Taxon names are <em>not</em> case sensitive.</p>',
    '#type' => 'textarea',
    '#required' => TRUE,
  );

  $form['match_type'] = array(
    '#type' => 'select', 
    '#title' => t('Taxon name match type'),
    '#description' => '<p>Should the taxon name be exactly the same as the name you provide, or should your provided name be in the taxon name?</p>'
      . '<p>For example, "Ablus" can match the genus "Ablus" (must be exact) or the species "Ablus coritus" (can contain).</p>',
    '#options' => array(
      'is' => t('Name must be exact (default)'),
      'contains' => t('Name must contain'),
    ),
    '#default_value' => 'is',
  );

  $form['skip_or_overwrite'] = array(
    '#type' => 'select', 
    '#title' => t('Skip or overwrite existing etymologies'),
    '#description' => '<p>For taxa that already have an etymology, should they be skipped, or should their existing etymology be overwritten?</p>',
    '#options' => array(
      'skip' => t('Skip (default)'),
      'overwrite' => t('Overwrite'),
    ),
    '#default_value' => 'skip',
  );

  $form['submit'] = array(
    '#value' => 'Import',
    '#type' => 'submit',
    '#name' => 'import',
    '#attributes' => array(
      'class' => array('raised', 'right'),
    ),
  );

  return $form;
}



/**
 * See taxa_lookup_form().
 */
function import_etymologies_form_submit($form_id, &$form_state) {
  // dpm($form_id, 'form_id');
  // dpm($form_state, 'form_state');

  // dpm($form_state['values']['data'], "form_state['values']['data']");
  $etymology_data_raw = explode(PHP_EOL, $form_state['values']['data']);
  // dpm($etymology_data_raw, 'etymology_data_raw');

  $etymology_data = [];
  foreach ($etymology_data_raw as $key => $name_and_etymology) {
    $data = explode('|', $name_and_etymology);

    if (! $data[0]) {
      drupal_set_message(t('Taxon name is blank'), 'status', FALSE);
      continue;
    }
    if (! array_key_exists(1, $data)) {
      drupal_set_message(t('Etymology missing for taxon "%name"',
        array('%name' => $data[0])), 'status', FALSE);
      continue;
    }

    $etymology_data[] = array(
      'name' => $data[0],
      'etymology' => $data[1]
    );
  }
  // dpm($etymology_data, 'etymology_data');

  import_etymologies($etymology_data,
    $form_state['values']['match_type'],
    $form_state['values']['skip_or_overwrite']);
}



function import_etymologies($etymology_data, $match_type, $skip_or_overwrite) {
  // dpm('Importing etymologies...');

  // $file_url = drupal_get_path('module', 'casa_core') . '/taxa_etymologies.json';
  // $file_contents = file_get_contents($file_url);
  // // dpm($file_contents, '$file_contents');
  // $etymology_data = json_decode($file_contents);
  // // dpm($etymology_data, '$etymology_data');

  // $etymology_data = array_slice($etymology_data, 1200, 400);
  // // dpm($etymology_data, '$etymology_data');

  $taxa_not_existing = [];

  $taxa_failed = [];

  $taxa_skipped = [];

  $count_changed = 0;

  // ELXONURUS|From the Greek eleuein, to roll; oura, -urus, tailed; the racemes curl when old.

  // $etymology_data = [];

  foreach ($etymology_data as $index => $term_data) {
    // dpm($term_data, '$term_data');

    if (! $term_data) {
      $taxa_failed[] = $term_data['name'];
      continue;
    }

    $taxa = get_taxa_with_name($term_data['name'], $match_type);
    // dpm($taxa, '$taxa');

    if (empty($taxa)) {
      $taxa_not_existing[] = $term_data['name'];
      continue;
    }

    foreach ($taxa as $nid => $node) {
      $taxon = entity_metadata_wrapper('taxonomy_term', $nid);
      // dpm($taxon->raw(), '$taxon');

      // If taxon already has an etymology, and existing etymologies should be skipped
      if (($taxon->field_etymology->value()) && ($skip_or_overwrite == 'skip')) {
        $taxa_skipped[] = $term_data['name'];
        continue;
      }

      $taxon->field_etymology->set($term_data['etymology']);
      $taxon->save();
      $count_changed ++;
    }
  }

  if (count($taxa_failed)) {
    drupal_set_message(t('<strong>%count</strong> taxa failed to be processed:',
      array('%count' => count($taxa_failed)))
        . '<br><ul><li>' . implode('</li><li>', $taxa_failed) . '</li></ul>', 
      'error', FALSE);
  }

  if (count($taxa_not_existing)) {
    drupal_set_message(t('<strong>%count</strong> taxa do not exist:',
      array('%count' => count($taxa_not_existing)))
        . '<br><ul><li>' . implode('</li><li>', $taxa_not_existing) . '</li></ul>', 
      'warning', FALSE);
  }

  if (count($taxa_skipped)) {
    drupal_set_message(t('<strong>%count</strong> taxa were skipped:',
      array('%count' => count($taxa_skipped)))
        . '<br><ul><li>' . implode('</li><li>', $taxa_skipped) . '</li></ul>', 
      'status', FALSE);
  }

  drupal_set_message(t('<strong>%count</strong> taxa were given new etymologies.',
    array('%count' => $count_changed)), 'status', FALSE);
}