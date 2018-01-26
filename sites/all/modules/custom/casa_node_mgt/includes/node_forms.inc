<?php
/**
 * @file
 * Description...
 */

/**
 * CONTENTS

  form_node_form_alter()
  _collection_node_form_alter()
  _picture_node_form_alter()
  _observation_node_form_alter()
  _identification_node_form_alter()
  _interaction_node_form_alter()
  _habitat_record_node_form_alter()
  get_current_path_part()
  casa_node_mgt_form_submit()
 */


/**
 * Called by casa_node_mgt_form_node_form_alter(), an implementation of hook_form_FORM_ID_alter().
 */
function form_node_form_alter(&$form, &$form_state, $form_id) {
  // dpm('Reached: edit_selected_form_node_form_alter');
  // dpm ($form, "form");
  // dpm ($form_state, "form_state");

  if (! isset($form['#bundle'])) {
    return NULL;
  }

  $bundle = $form['#bundle'];

  $language = LANGUAGE_NONE; // 'und'
  if (isset($form['language'])) {
    $language = $form['language']['#value'];
  }

  // Determine the form view mode from arguments passed to drupal_get_form().
  $form_view_mode = NULL;
  foreach ($form_state['build_info']['args'] as $key => $arg) {
    if (is_array($arg)) {
      if (isset($arg['form_view_mode'])) {
        $form_view_mode = $arg['form_view_mode'];
        // $form_state['form_view_mode'] = $form_view_mode;
      }
    }
  }
  // dpm($form_view_mode, 'form_view_mode');

  $form['#attributes']['data-view-mode'] = $form_view_mode;

  // Alter fields depending on the form node's content type
  switch ($bundle) {

    case 'collection':
      _collection_node_form_alter($form, $form_state, $form_view_mode, $language);
      break;

    case 'picture':
      _picture_node_form_alter($form, $form_state, $form_view_mode, $language);
      break;

    case 'observation':
      _observation_node_form_alter($form, $form_state, $form_view_mode, $language);
      break;

    case 'identification':
      _identification_node_form_alter($form, $form_state, $form_view_mode, $language);
      break;

    case 'interaction':
      _interaction_node_form_alter($form, $form_state, $form_view_mode, $language);
      break;

    case 'habitat_record':
      _habitat_record_node_form_alter($form, $form_state, $form_view_mode, $language);
      break;
  }

  // Add a module-wide form_submit callback for general clean-up
  if (isset($form['additional_settings']['#access'])) {
    if ($form['additional_settings']['#access'] == FALSE) {
      $form['actions']['submit']['#submit'][] = 'casa_node_mgt_form_submit';
    }
  }

  // dpm($form, 'form @ end of "casa_node_mgt_form_node_form_alter"');
  // dpm($form, 'Returning form');
  return $form;
}


function _collection_node_form_alter(&$form, &$form_state, $form_view_mode, $language) {
  // dpm($form, '$form');

  $form['title']['#required'] = TRUE;
  $form['title']['#description'] = "A brief description of where and when the photos were taken. Eg. ‘January 2015 field work trip to the Berg mountains’.";

  if ($form_view_mode == 'contribute') {

    // Remove unwanted fields

    $form['additional_settings']['#access'] = FALSE;
    $form['actions']['preview']['#access'] = FALSE;

    $form['field_representative_picture']['#access'] = FALSE;

    $form['actions']['submit']['#value'] = 'Save collection and pictures';
    // $form['field_location']['#description'] = $form['field_location'][$language][0]['#description'];
    $form['#groups']['group_location']->format_settings['instance_settings']['description'] = $form['field_location'][$language][0]['#description'];

    // Add the bulk file upload field
    $form['upload'] = array(
      '#type' => 'plupload',
      '#title' => t('Upload your pictures'),
      '#description' => t('Add your photographs of your observations.'),
      '#required' => TRUE,
      // '#plupload_settings' => array(
      //   // 'runtimes' => 'html5',
      //   // 'chunk_size' => '1mb',
      // ),
    );

    /**
     * @todo solve: Files not persisting in uploader if form submission has errors.
     * If page form has errors, it is rebuilt (with submitted data repopulated),
     * however the uploader widget doesn't display the uploaded files...
     * See https://www.drupal.org/node/2069179 for a fix.
     */

    // Replace the default submit handler with a customised one
    $form['actions']['submit']['#submit'][] = 'casa_upload_node_form_submit';

    // If the media field limits allowed file extensions, set the form to validate this
    if (isset($mediafield_info['settings']['file_extensions'])) {
      $form['upload']['#upload_validators']['file_validate_extensions'][] = $mediafield_info['settings']['file_extensions'];
    }

    // dpm($form, 'form @ end of alter');
  }
}


function _picture_node_form_alter(&$form, &$form_state, $form_view_mode, $language) {
  // dpm ($form, "form");

  $form['title']['#required'] = FALSE;
  $form['title']['#description'] = "The common name of the animal / plant / specimen, and perspective of the photograph. Eg. ‘Leaf and stem of berry bush’.";

  if ($form_view_mode == 'contribute_new') {
    // Basic info
    $form['title']['#access'] =               FALSE;
    $form['field_image']['#access'] =         FALSE;
    $form['field_collection']['#access'] =    FALSE;

    $form['field_location']['#access'] =      FALSE;
    $form['field_exif']['#disabled'] =        TRUE;

    $form['additional_settings']['#access'] = FALSE;
    $form['actions']['preview']['#access'] =  FALSE;

    $form['field_subject'][LANGUAGE_NONE]['#attributes'] = array('class' => array('cols-3'),);
    $form['field_tags'][LANGUAGE_NONE]['#attributes'] = array('class' => array('cols-3'),);
    $form['field_beauty'][LANGUAGE_NONE]['#attributes'] = array('class' => array('children-inline'),);
    $form['field_usefulness'][LANGUAGE_NONE]['#attributes'] = array('class' => array('children-inline'),);
  }
}


function _observation_node_form_alter(&$form, &$form_state, $form_view_mode, $language) {
  // dpm ($form, "form");

  $form['title']['#required'] = FALSE;
  $form['title']['#description'] = "The common name of the animal / plant / specimen, and it's place or position. Eg. ‘Berry bush on a rock’.";

  $form['field_locality'][LANGUAGE_NONE]['#description']
    .= ' Can’t find the locality you’re looking for? '
    . l('Contribute new locality', 'contribute/locality', array(
        'attributes' => array('target' => '_blank'),
      ));


  if ($form_view_mode == 'contribute_new') {
    // Basic info
    $form['title']['#access'] =                   FALSE;
    $form['field_collection']['#access'] =        FALSE;
    $form['field_observation_id']['#access'] =    FALSE;
    $form['field_source']['#access'] =            FALSE;

    $form['field_count']['#access'] =             FALSE;
    $form['field_identifications']['#access'] =   FALSE;
    $form['field_most_likely_species']['#access'] = FALSE;
    $form['field_mls_probability']['#access'] =   FALSE;
    $form['field_history']['#access'] =           FALSE;

    $form['field_external_id']['#access'] =       FALSE;
    // $form['field_specimen_id']['#access'] =       FALSE;

    $form['field_pictures_observation']['#access'] = FALSE;
    $form['field_filenames']['#access'] =         FALSE;

    $form['additional_settings']['#access'] =     FALSE;
    $form['actions']['preview']['#access'] =      FALSE;

    // Set the Observer Name field's default value to user's full name
    global $user;
    $user_wrapped = entity_metadata_wrapper('user', $user);
    $full_name = $user_wrapped->field_full_name->value();
    // dpm($full_name, '$full_name');
    $form['field_observer_name'][LANGUAGE_NONE][0]['value']['#default_value'] = $full_name;
    $form['field_observer_name'][LANGUAGE_NONE][0]['value']['#attributes'] = array(
      'data-default-value' => $full_name,
    );

    $form['field_location'][LANGUAGE_NONE][0]['geom']['#attributes'] = array(
      // 'class' => array('hidden'),
      'rows' => '1',
    );
    $form['field_location']['#attached'] = array(
      'js' => array(
        libraries_get_path('openlayers3') . '/build/ol-debug.js',
      ),
      'css' => array(
        libraries_get_path('openlayers3') . '/css/ol.css',
      ),
    );
  }

  // dpm ($form, "form after alter");
}


function _identification_node_form_alter(&$form, &$form_state, $form_view_mode, $language) {
  
  // dpm ($form, "form");
  // Hide undesired fields and options
  $form['title']['#access'] = FALSE;
  $form['field_reliability']['#access'] = FALSE;

  // Ensure an node.pages.inc file is loaded whenever the form is processed.
  // Needed for the entity reference widget to work
  form_load_include($form_state, 'inc', 'node', 'node.pages');



  // VM: Agreement or Contribute new

  if ($form_view_mode == 'agreement' || $form_view_mode == 'contribute_new') {

    // Disable or hide undesired fields.

    $form['additional_settings']['#access'] = FALSE;
    $form['actions']['preview']['#access'] = FALSE;

    $form['field_identification_source']['#attributes']['class'][] = 'hidden';

    $form['field_observation']['#attributes']['class'][] = 'hidden';

    // If there is a node id in the URL path, use it as the default value of the observation reference field.

    // @todo Make this only work for specific desired paths like 'node/*'.
    $observation_nid = get_current_path_part(1);
    if ((int) $observation_nid) {
      $observation = node_load($observation_nid);
      // dpm($observation, 'observation');
      $form['field_observation'][$language][0]['target_id']['#default_value'] = $observation->title . " (" . $observation_nid . ")";
    }

    // Set the identification form to always redirect back to requesting page.
    $form['redirect'] = array(
      '#type' => 'value',
      '#value' => current_path(),
    );
  }

  // VM: Contribute new

  if ($form_view_mode == 'contribute_new') {
    // dpm($form, 'form');

    $form['field_identified_species']['#attributes']['class'][] = 'hidden';

    $form['field_certainty']['#attributes']['class'][] = 'inline';

    // $view_name = 'species_reference_selector_widget';
    // $display_id = 'entityreference_view_widget_1';
    // $form['field_identified_species'][LANGUAGE_NONE] = array(
    //   '#markup' => views_embed_view($view_name, $display_id),
    // );
    // views_add_js('dependent');
    // views_add_js('ajax_view');
  }

  // VM: Agreement

  if ($form_view_mode == 'agreement') {

    $form['field_identified_species']['#attributes']['class'][] = 'hidden';

    $form['field_certainty'][$language]['#description'] = '';
    $form['field_certainty'][$language]['#title'] = 'Agree?';

    $form['#attributes']['class'][] = 'inline';
  }



  // /**
  //  * Checks URL for queries that should be used to auto-fill the form.
  //  * For example, “?field_observation=624" in the URL means that the
  //  * 'field_observation' form field should be set to '624'.
  //  *
  //  * This is used for a 'new identification' form (not for identification agreements).
  //  */
  // $query_fragments = drupal_get_query_array($_SERVER['QUERY_STRING']);
  // // dpm($query_fragments, 'query_fragments');

  // foreach ($query_fragments as $key => $value) {
  //   if (in_array($key, array_keys($form))) {
  //     $field = $form[$key][$language][0];

  //     // Standard Drupal field
  //     if (isset($field['value'])) {
  //       $form[$key][$language][0]['value']['#default_value'] = $value;
  //     }
  //     // Entity reference field
  //     elseif (isset($field['target_id'])) {
  //       // Needs to be formatted as: "node_title (nid)".
  //       $node = node_load($value);
  //       // dpm($node);
  //       $form[$key][$language][0]['target_id']['#default_value'] =
  //         $node->title . ' (' . $value . ')';
  //     }
  //   }
  // }

  // Add a custom form submit handler.
  $form['actions']['submit']['#submit'][] = 'identification_form_submit';
}


function _interaction_node_form_alter(&$form, &$form_state, $form_view_mode, $language) {
  // dpm($form, "form");
  // dpm($form_state, "form_state");

  if ($form_view_mode == 'add_to_observation' || $form_view_mode == 'contribute_new') {
    // Basic info
    $form['title']['#access'] = FALSE;

    $form['field_observation']['#access'] = FALSE;
    $form['field_observation_object']['#access'] = FALSE;

    $form['additional_settings']['#access'] = FALSE;
  }

  if ($form_view_mode == 'contribute_new') {
    $form['field_interaction_activity']['#attributes']['class'][] = 'inline';
  }
}


function _habitat_record_node_form_alter(&$form, &$form_state, $form_view_mode, $language) {

  // Fetch the identifying variable that was provided in drupal_get_form().
  $arg1;
  if(isset($form_state['build_info']['args'][1])) {
    $arg1 = $form_state['build_info']['args'][1];
  }
  else {
    return $form;
  }
  // dpm($arg1, 'arg1');


  if ($arg1 == 'contribute') {
    // dpm('ctb_observation_form_node_form_alter altering…');

    $form['title']['#access'] = FALSE;

    // Includes vertical tab settings groups for:
    // Menu, Revision, Path, Comment, Authoring, Publishing.
    $form['additional_settings']['#access'] = FALSE;
    $form['options']['status']['#value'] = 1;

    unset($form['actions']['preview']);
  }
  $form['actions']['submit']['#submit'][] = 'habitat_record_form_submit';
}


/**
 * Provides the string value of a part of the current path.
 *
 * @param $part_no
 *   The position of the part. Eg. for path 'node/32', use 1 to get '32'.
 */
function get_current_path_part($part_no) {
  $current_path = current_path();
  $current_path_parts = drupal_parse_url($current_path);
  // dpm($current_path_parts, 'current_path_parts');
  $value = explode('/', $current_path_parts['path'])[$part_no];
  return $value;
}



/**
* Custom, module-wide form submit handler callback for general clean-up.
* Only called when submit (Save) button is used.
*/
function casa_node_mgt_form_submit($form, &$form_state) {
  // dpm('Called: identification_form_submit');
  // dpm($form, "form");
  // dpm($form_state, "form_state");
  // dpm($form_state['node'], "node");

  // // Determine the form view mode from arguments passed to drupal_get_form().
  // $form_view_mode = NULL;
  // foreach ($form_state['build_info']['args'] as $key => $arg) {
  //   if (is_array($arg)) {
  //     if (isset($arg['form_view_mode'])) {
  //       $form_view_mode = $arg['form_view_mode'];
  //     }
  //   }
  // }

  // For new nodes, set status to published, and author to current user.
  // @needed_because Altering to #access to additional_settings means these fields aren't set correctly.
  if (isset($form['additional_settings']['#access'])) {
    if ($form['additional_settings']['#access'] == FALSE) {
      // $node = $form_state['node'];
      // $node->status = 1; // Published
      // global $user;
      // $node->uid = $user->uid;
      // node_save($node);

      // Get the default values for the hidden fields and save them to the node.
      // Is needed because hiding (denying access) fields makes them saved as '0'.

      $additional_settings = array('promote', 'status', 'sticky');

      foreach ($additional_settings as $setting) {
        $value = $form['options'][$setting]['#default_value'];
        $form_state['values'][$setting] = $value;
      }
    }
  }
}
