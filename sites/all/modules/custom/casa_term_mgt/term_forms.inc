<?php
/**
 * @file
 * Description...
 */

/**
 * Called by casa_term_mgt_form_taxonomy_form_term_alter().
 */
function form_taxonomy_form_term_alter(&$form, &$form_state, $form_id) {
  // dpm($form, '$form');
  // dpm($form_state, '$form_state');
  // dpm($form_id, '$form_id');

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

  switch ($vocabulary) {

    // Habitats

    case 'habitats':
      if ($form_view_mode == 'contribute') {
        // dpm('called: ..taxonomy_form_term_alter() > habitats > contribute');
        // $form['relations']['#access'] = FALSE;
        $form['path']['#access'] = FALSE;
      }
      break;

      

    // Taxa

    case 'taxa':
      if (($form_view_mode == 'etymology') || ($form_view_mode == 'maintain_popular')) {
        $form['path']['#access'] = FALSE;
        // $form['relations']['#access'] = FALSE;
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
        $form['name']['#access'] = FALSE;
        $form['description']['#access'] = FALSE;
        
        unset($form['#fieldgroups']);

        foreach (array_keys($form) as $key) {
          // If this is a field, but not the etymology field
          if (substr($key, 0, 6) == 'field_' && $key != 'field_etymology') {
            // dpm($key, '$key');
            $form[$key]['#access'] = FALSE;
          }
        }

        drupal_set_title('Contribute Etymology to ' . $form['#term']['name']);
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