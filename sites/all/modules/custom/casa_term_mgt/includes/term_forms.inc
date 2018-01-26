<?php
/**
 * @file
 * Functions that alter taxonomy term forms before viewing, validate form s 
 * submissions, or act on form submissions.
 */

/**
 * Called by casa_term_mgt_form_taxonomy_form_term_alter().
 */
function form_taxonomy_form_term_alter(&$form, &$form_state, $form_id) {
  // dpm($form, '$form');
  // dpm($form_state, '$form_state');
  // dpm($form_id, '$form_id');

  $form['#after_build'][] = 'form_taxonomy_form_term_alter_after';

  $vocabulary = $form['vocabulary_machine_name']['#value'];
  // dpm($vocabulary, '$vocabulary');
  // $language = $form['language']['#value']; // 'und'

  // Determine the form view mode from build info (or arguments passed to drupal_get_form()).
  $form_view_mode = NULL;
  if (isset($form_state['build_info']['form_view_mode'])) {
    $form_view_mode = $form_state['build_info']['form_view_mode'];
  }
  else {
    foreach ($form_state['build_info']['args'] as $key => $arg) {
      if (is_array($arg)) {
        if (isset($arg['form_view_mode'])) {
          $form_view_mode = $arg['form_view_mode'];
        }
      }
    }
  }
  // dpm($form_view_mode, '$form_view_mode');

  $form['#attributes'] = array(
    'data-view-mode' => $form_view_mode,
    'data-tid' => $form['tid']['#value'],
  );

  $tid = $form['#term']['tid'];
  $term = $tid ? entity_metadata_wrapper('taxonomy_term', $tid) : NULL;

  switch ($vocabulary) {

    // Habitats

    case 'habitats':
      if ($form_view_mode == 'contribute') {
        // dpm('called: ..taxonomy_form_term_alter() > habitats > contribute');
        // $form['relations']['#access'] = FALSE;
      }
      break;

      

    // Taxa

    case 'taxa':
      if (($form_view_mode == 'etymology') || ($form_view_mode == 'maintain_popular')) {
      }

      if ($form_view_mode == 'contribute') {
        // $form['relations']['#access'] = FALSE;
        $form['path']['#access'] = FALSE;
      }

      elseif ($form_view_mode == 'maintain') {

        // dpm('called: ..taxonomy_form_term_alter() > taxa > maintain');
        // $form['relations']['#access'] = FALSE;
        $form['path']['#access'] = FALSE;
      }
      
      elseif ($form_view_mode == 'etymology') {
        // dpm($form, '$form');
        // dpm($form_state, '$form_state');

        $form['#submit'] = ['casa_term_mgt_etymology_form_term_submit'];

        // Hide main term fields
        $form['name']['#access'] = FALSE;
        $form['description']['#access'] = FALSE;
        $form['relations']['#access'] = FALSE;
        
        unset($form['#fieldgroups']);

        // Hide all other fields
        foreach (array_keys($form) as $key) {
          // If this is a field, but not the etymology field
          if (substr($key, 0, 6) == 'field_'
            && $key != 'field_etymology'
            && $key != 'field_long_etymology'
            && $key != 'field_etymology_applies_to') {
            // dpm($key, '$key');
            $form[$key]['#access'] = FALSE;
          }
        }


        if ($term) {
          $rank = $term->field_taxon_rank->value();
          // dpm($rank, '$rank');
          $name_parts = explode(' ', $term->label());

          $name_to_search = (strtolower($rank) == 'species') ?
            end($name_parts) :
            $term->label();
          // dpm($name_to_search, '$name_to_search');
          // $name_to_search = 'capensis'; // For dev
        }

        $similar_taxa = get_taxa_with_name($name_to_search, 'contains', $rank);
        // dpm($similar_taxa, '$similar_taxa');

        $form['similar_taxa'] = [
          '#type' => 'select',
          '#multiple' => TRUE,
          '#description' => '<p>Saving etymologies will apply to all ' 
            . count($similar_taxa) . ' taxa in the list below. Select any taxa '
            . 'that you wish to exclude. Ctrl + click to select multiple.</p>',
          '#options' => [],
        ];
        $short_etymologies = [];
        $long_etymologies = [];
        foreach ($similar_taxa as $tid => $tid_obj) {
          $similar_term = taxonomy_term_load($tid);
          $similar_term_w = entity_metadata_wrapper('taxonomy_term', $tid);
          // $link = l($similar_term->name, 'contribute/taxon/etymology/' . $tid, [
          //   'attributes' => ['target' => '_blank'],
          // ]);
          $form['similar_taxa']['#options'][$tid] = $similar_term->name;

          // $etymology_val = $similar_term_w->field_etymology->value();
          // if ($etymology_val) {
          //   if ($etymology_val['value']) {
          //     $short_etymologies[] = $etymology_val;
          //   }
          // }
          // $etymology_long_val = $similar_term_w->field_long_etymology->value();
          // if ($etymology_long_val) {
          //   if ($etymology_long_val['value']) {
          //     $long_etymologies[] = $etymology_long_val;
          //   }
          // }
        }
        // dpm($short_etymologies, '$short_etymologies');
        // dpm($long_etymologies, '$long_etymologies');
        // if ($short_etymologies) {
        //   $form['field_etymology']['und'][0]['#default_value'] = $short_etymologies[0]['value'];
        // }
        // if ($long_etymologies) {
        //   $form['field_long_etymology']['und'][0]['#default_value'] = $long_etymologies[0]['value'];
        // }


        drupal_set_title('Contribute Etymologies to "' . $name_to_search . '"');

      }

      if (array_key_exists('field_pictures', $form)) {
        // Add 'Pictures of Taxon' view
        add_rep_picture_of_taxon_chooser($form);
        add_pictures_of_taxon_chooser($form);
      }

      break;

    // Localities

    case 'locality':
      $form['path']['#access'] = FALSE;
      if ($form_view_mode == 'contribute') {
        // dpm('altering');

        $form['path']['#access'] = FALSE;
        // $form['path']['#attributes'] = array(
        //   'class' => array('hidden'),
        // );
        // $form['field_range']['#access'] = FALSE;
      }
      break;
  }

  // dpm($form, 'form after alter');
}


function etymology_form_alter(&$form, &$form_state, $form_id) {
}


function form_taxonomy_form_term_alter_after($form, &$form_state) {

  $vocabulary = $form['vocabulary_machine_name']['#value'];
  // dpm($vocabulary, '$vocabulary');

  // Determine the form view mode from build info (or arguments passed to drupal_get_form()).
  $form_view_mode = NULL;
  if (isset($form_state['build_info']['form_view_mode'])) {
    $form_view_mode = $form_state['build_info']['form_view_mode'];
  }
  else {
    foreach ($form_state['build_info']['args'] as $key => $arg) {
      if (is_array($arg)) {
        if (isset($arg['form_view_mode'])) {
          $form_view_mode = $arg['form_view_mode'];
        }
      }
    }
  }
  // dpm($form_view_mode, '$form_view_mode');

  switch ($vocabulary) {
    
    case 'taxa':
      if (($form_view_mode == 'etymology') || ($form_view_mode == 'maintain_popular')) {
        $form['path']['#access'] = FALSE;
      }
      break;

    case 'habitats':
      if ($form_view_mode == 'contribute') {
        // dpm('called: ..taxonomy_form_term_alter() > habitats > contribute');
        // $form['relations']['#access'] = FALSE;
        $form['path']['#access'] = FALSE;
      }
      break;
  }

  // dpm($form, 'form after alter');
  return $form;
}


/**
 * Adds a field widget that...
 */
function add_rep_picture_of_taxon_chooser(&$form) {
  
  // Add view of pictures

  $view_name = 'pictures_of_taxon';
  $display_id = 'default';
  $view = views_get_view($view_name);

  if ($view && $view->access($display_id)) {

    // dpm($form, '$form');
    $args = array(
      // $form['#term']->tid
      $form['tid']['#value']
    );
    $view_rendered = $view->preview($display_id, $args);
    // dpm($view_rendered, 'view_rendered');
    $form['field_representative_picture']['chooser'] = array(
      // '#type' => 'container',
      '#type' => 'fieldset',
        '#title' => t('Choose a representative picture'), 
        '#weight' => 5, 
        '#collapsible' => TRUE, 
        '#collapsed' => TRUE,
      '#attributes' => array(
        'class' => array('representative_picture_chooser'),
      ),
    );
    $form['field_representative_picture']['chooser']['view'] = array(
      '#type' => 'markup',
      '#markup' => $view_rendered,
    );
  }
}


function add_pictures_of_taxon_chooser(&$form) {

  // Add 'which picture to change' radio buttons

  $picture_subjects = array(
    'leaf',
    'flower',
    'fruit',
    'flowering branch',
    'other',
  );
  // dpm($form, '$form');
  for ($i=0; $i < $form['field_pictures']['und']['#cardinality']; $i++) { 
    // dpm($i, '$i');
    $form['field_pictures'][LANGUAGE_NONE][$i]['checkbox'] = array(
      'radio' => array(
        '#markup' => '<input'
          . ' id="' . $picture_subjects[$i] . '"'
          . ' type="' . 'radio' . '"'
          . ' name="' . 'picture_chooser' . '"'
          . ' value="' . $i . '">',
      ),
      'label' => array(
        '#markup' => '<label'
          . ' for="' . $picture_subjects[$i] . '">'
          . $picture_subjects[$i]
          . '</label>',
      ),
      '#weight' => 5,
    );
  }


  // Add view of pictures

  $view_name = 'pictures_of_taxon';
  $display_id = 'default';
  $view = views_get_view($view_name);

  if ($view && $view->access($display_id)) {

    // dpm($form, '$form');
    $args = array(
      // $form['#term']->tid
      $form['tid']['#value']
    );
    $view_rendered = $view->preview($display_id, $args);
    // dpm($view_rendered, 'view_rendered');
    $form['field_pictures']['chooser'] = array(
      // '#type' => 'container',
      '#type' => 'fieldset',
        '#title' => t('Choose pictures'), 
        '#weight' => 5, 
        '#collapsible' => TRUE, 
        '#collapsed' => TRUE,
      '#attributes' => array(
        'class' => array('pictures_chooser'),
      ),
    );
    $form['field_pictures']['chooser']['view'] = array(
      '#type' => 'markup',
      '#markup' => $view_rendered,
    );
  }
}


/**
 * Saves values of "etymology" and "long etymology" to all "similar taxa" that 
 * were not excluded (selected) in the form.
 */
function casa_term_mgt_etymology_form_term_submit($form, &$form_state) {
  // dpm('casa_term_mgt_form_term_submit()');
  // dpm($form, '$form');
  // dpm($form_state, '$form_state');

  $terms_updated = [];
  $similar_taxa_to_exclude = $form_state['values']['similar_taxa'];
  // dpm($similar_taxa_to_exclude, '$similar_taxa_to_exclude');

  $similar_taxa = $form['similar_taxa']['#options'];
  // dpm($similar_taxa, '$similar_taxa');

  $etymology = $form_state['values']['field_etymology'][LANGUAGE_NONE][0]['value'];
  // dpm($etymology, '$etymology');
  $long_etymology = $form_state['values']['field_long_etymology'][LANGUAGE_NONE][0]['value'];
  // dpm($long_etymology, '$long_etymology');

  foreach ($similar_taxa as $tid => $term_name) {
    // dpm($tid, '$tid');
    // If the taxon was selected (to be excluded), skip it
    if (in_array($tid, $similar_taxa_to_exclude)) {
      continue;
    }

    // dpm($tid, '$tid');
    $term = entity_metadata_wrapper('taxonomy_term', $tid);

    if ($tid == $form['#term']['tid']) {
      $term->field_etymology_applies_to->set(
        $form_state['values']['field_etymology_applies_to'][LANGUAGE_NONE][0]['value']);
    }
    // dpm($term->raw(), '$term->raw()');
    $term->field_etymology->set([
      'value' => $etymology,
      'format' => 'filtered_html',]);
    $term->field_long_etymology->set([
      'value' => $long_etymology,
      'format' => 'filtered_html',]);
    // dpm($term->raw(), '$term->raw()');
    $terms_updated[] = l($term_name, '/taxonomy/term/' . $tid);
    $term->save();
  }
  $msg = '<p>The following taxa were updated:</p><ul><li>';
  $msg .= implode('</li><li>', $terms_updated);
  $msg .= '</li></ul>';
  drupal_set_message($msg, 'status', FALSE);

  return FALSE;
}