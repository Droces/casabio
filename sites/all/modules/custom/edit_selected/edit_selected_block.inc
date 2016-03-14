<?php
/**
 * @file
 * Provides create, validate and process functions for the edit_selected form block
 */




// =============================================================================
/* CONTENTS

  identify_selected_block_get_content()
  edit_selected_block_get_content()
  edit_selected_form_node_form_alter()
  edit_selected_node_form_validate()
  edit_selected_node_form_submit()
  edit_selected_node_form_delete_submit()

  * Note that none of these functions are hooks.
*/





/**
 * Assembles renderable array for block content.
 *
 * @return array
 *   Returns a renderable array of block content, or null if no view results are found.
 *
 * @throws Exception
 *   Throws Exception if there are no existing nodes of this type.
 */
function identify_selected_block_get_content($delta) {

  $content = "";
  global $user;

  $values = array(
    'type' => 'identification',
    'uid' => $user->uid,
    'status' => 1,
    // 'comment' => 0,
    // 'promote' => 0,
  );
  $node = entity_create('node', $values);


  // @todo Need to resolve the ajax error caused by clicking 'Add item' submit button of block form's entity ref field.
  // Load node.pages.inc from the node module.
  // module_load_include('inc', 'node', 'node.pages');
  // module_load_include('inc', 'ctools', 'includes/modal');

  try {
    $content['form'] = drupal_get_form('node_form', $node, ['form_view_mode' => 'contribute_new']);
    $content['form']['#weight'] = 2;
    // dpm($content, 'content');
    $content['form']['field_identified_species']['#access'] = FALSE;
  }
  // catch (ParameterNotValidException $e) {}
  catch (Exception $e) {
    // Set a watchdog message
    watchdog('edit_selected', $e->getMessage(), array(), WATCHDOG_ERROR);

    // Message the error to the user
    // Shouldn't actually message the error to the user; developer must fix.
    drupal_set_message(get_class($e) .
      ' caught: ' . $e -> getMessage() .
      ' in ' . $e -> getFile() .
      ' on line ' . $e -> getLine(), "error");

    // return message in lieu of expected content
    // return "<p>The form could not be created</p>";
  }

  $view_name = 'species_reference_selector_widget';
  $display_id = 'default';

  $view_rendered = views_embed_view($view_name, $display_id);

  $content['identified_species'] = array(
    '#type' => 'fieldset',
    '#title' => t('Choose a species'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $content['identified_species']['chooser'] = array(
    '#type' => 'markup',
    '#markup' => $view_rendered,
  );

  return $content;
}





/**
 * Assembles renderable array for block content.
 *
 * @return array
 *   Returns a renderable array of block content, or null if no view results are found.
 *
 * @throws Exception
 *   Throws Exception if there are no existing nodes of this type.
 */
function edit_selected_block_get_content($delta) {

  $content = "";

  $bundle = get_block_info($delta)['bundle'];


  $node;
  // Get first node of this type to use, using EntityFieldQuery
  $query = new EntityFieldQuery();
  $query -> entityCondition('entity_type', 'node')
    -> entityCondition('bundle', $bundle)
    -> range(0, 1) // Return 1 result
    // ->addMetaData('account', user_load(1)) // Run the query as user 1.
  ;
  $result = $query -> execute();

  if (!isset($result) || empty($result)) {
    throw new Exception("No existing entities found", 1);
  }

  $nid = reset($result['node']) -> nid; // reset() returns the first element in the array
  $node = node_load($nid);
  // dpm($node, 'node');


  // @todo Need to resolve the ajax error caused by clicking 'Add item' submit button of block form's entity ref field.
  // Load node.pages.inc from the node module.
  // module_load_include('inc', 'node', 'node.pages');

  try {
    $content = drupal_get_form('node_form', $node, 'edit_selected', $delta);
    // dpm($content, 'content');
  }
  // catch (ParameterNotValidException $e) {}
  catch (Exception $e) {
    // Set a watchdog message
    watchdog('edit_selected', $e->getMessage(), array(), WATCHDOG_ERROR);

    // Message the error to the user
    // Shouldn't actually message the error to the user; developer must fix.
    drupal_set_message(get_class($e) .
      ' caught: ' . $e -> getMessage() .
      ' in ' . $e -> getFile() .
      ' on line ' . $e -> getLine(), "error");

    // return message in lieu of expected content
    // return "<p>The form could not be created</p>";
  }

  // $content['#attributes']['id'][] = 'edit-selected-identify-form';


  return $content;
}





/**
 * Implements hook_form_FORM_ID_alter(), for 'node_form' forms. Returns a simplified node edit form.
 *
 * Includes a hidden field for storing node IDs (nids), so that multiple nodes
 * can be edited at once using this form. The form in intended to be used within a block.
 *
 * @throws ParameterNotValidException
 *   Throws this exception if $bundle isn't a valid bundle type
 *
 * @return array
 *   A renderable form array (Drupal's Node API) containing node edit fields.
 */
function edit_selected_form_node_form_alter(&$form, &$form_state, $form_id) {
  // dpm('Reached: edit_selected_form_node_form_alter');
  // dpm ($form, "form");
  // dpm ($form_state, "form_state");
  // dpm($form_id, 'form_id');

  $bundle = $form['#bundle'];

  // Determine the source of the drupal_get_form() request
  $arg1;
  if(isset($form_state['build_info']['args'][1])) {
    $arg1 = $form_state['build_info']['args'][1];
  }
  else {
    return $form;
  }
  // dpm($arg1, 'arg1');

  // If the drupal_get_form() request came from this module
  if ($arg1 == 'edit_selected') {

    $block_id = $form_state['build_info']['args'][2];
    // dpm($block_id, 'block_id');
    // dpm(get_block_info($block_id), 'block_info');

    $selectable_form = new SelectableForm($form, $block_id);

    $prefill = get_block_info($block_id)['prefill'];
    $selectable_form -> addHiddenFields($prefill);
    // For explanation of $prefill, see the selectable_form.class

    $form = $selectable_form -> getSpecifications();

    // Hide undesired fields and options
    $form['additional_settings']['#access'] = FALSE;
    $form['actions']['preview']['#access'] = FALSE;
    $form['actions']['delete']['#access'] = FALSE;

    $form['title']['#access'] = FALSE;
    $form['field_collection']['#access'] = FALSE;
    $form['field_observation_id']['#access'] = FALSE;
    $form['field_source']['#access'] = FALSE;
    $form['field_external_id']['#access'] = FALSE;
    $form['field_specimen_id']['#access'] = FALSE;

    $form['field_pictures_observation']['#access'] = FALSE;

    // @todo Remove these; these fields are no longer relevant, as the identifications now reference the obserservation.
    $form['field_identifications']['#access'] = FALSE;
    $form['field_most_likely_species']['#access'] = FALSE;
    $form['field_mls_probability']['#access'] = FALSE;

    // $form['actions']['submit']['#submit'] = array('edit_selected_node_form_submit');
    foreach ($form['actions']['submit']['#submit'] as $key => $callback) {
      if ($callback == 'node_form_submit') {
        $form['actions']['submit']['#submit'][$key] = 'edit_selected_node_form_submit';
      }
    }

    // $form['additional_settings']['#access'] = FALSE;

    // $selectable_form -> fieldGroupsToFieldsets();

    $form['#attributes']['class'][] = 'edit-selected-form';

    $form['#attributes']['id'][] = 'edit-selected-edit-form';

    // Remove default values of existing fields
    $form = array_replace_recursive_search($form, array('#default_value' => NULL));
    $form = array_replace_recursive_search($form, array('entities' => []));
    // dpm($form, 'form after removal of default values');

    // Give the title and body 'fields' a class like the other fields (for more-consistent javascript handling)
    // $form['title']['#attributes']['class'][] = 'form-field-title'; // Puts the class on the input, not on a wrapper…
    $form['body']['#attributes']['class'][] = 'form-field-name-body';

    $form['#validate'][] = 'edit_selected_node_form_validate';

    // Set the identification form to always redirect back to requesting page.
    $form['redirect'] = array(
      '#type' => 'value',
      '#value' => current_path(),
    );


    // dpm($form, 'form @ end of "edit_selected_form_node_form_alter"');
  }

  // Needed to resolve the ajax error caused by clicking 'Add item' submit button of block form's entity ref field.
  form_load_include($form_state, 'inc', 'node', 'node.pages');

  // dpm('End of "edit_selected_form_node_form_alter"');
  // dpm($form, 'Returning form');
  return $form;
}





/**
 * Form validation handler for the altered node_form()
 */
function edit_selected_node_form_validate($form, &$form_state) {
  // dpm('Reached: edit_selected_form_validate');
  // dpm ($form, "form");
  // dpm ($form_state, "form_state");

  // If there is a variable tracking altered fields, then remove all non-altered fields
  if(isset($form_state['values']['edit_selected_altered_fields'])) {

    $altered_fields = $form_state['values']['edit_selected_altered_fields'];
    $altered_fields = str_replace('-', '_', $altered_fields);

    $altered_fields = explode('|', $altered_fields);
    $altered_fields[] = 'edit_selected_nids';
    // dpm($altered_fields, 'altered_fields');

    foreach($form_state['values'] as $key => $value) {
      if(!in_array($key, $altered_fields)) {
        unset($form_state['values'][$key]);
      }
    }
  }

  // dpm ($form_state, "form_state");
  // dpm($cause_error);
}





/**
 * Form submission handler replacement for node_form_submit()
 */
function edit_selected_node_form_submit($form, &$form_state) {
  // dpm('Reached: edit_selected_node_form_submit');
  // dpm ($form, "form");
  // dpm ($form_state, "form_state");
  // dpm ($form_state['node'], "form_state['node']");

  // dpm($cause_error);

  $bundle = $form['#bundle'];

  // edit_selected_node_submit($node, $form_state);

  $nids = $form_state['values']['edit_selected_nids'];
  $nids = explode('|', $nids);
  // dpm ($nids, "nids");

  $nodes_saved = [];
  foreach($nids as $nid) {
    // dpm($nid, 'nid');

    // If the first nid is an integer
    $is_valid_nid = is_numeric($nid);

    if ($is_valid_nid) {
      // dpm ($nid, "nid");

      $form_state['node'] = node_load($nid);

      unset($form_state['values']['created']);
      unset($form_state['node'] -> created);

      // dpm ($form_state['node'], "form_state['node']");

      $node = node_form_submit_build_node($form, $form_state);
      node_save($node);
      // dpm($node, "node");

      // If the node was saved successfully
      if ($node->nid) {
        $nodes_saved[] = $nid;
      }
    }

  }

  // If at least one node was saved successfully
  if (count($nodes_saved) > 0) {
    $args = array(
      '%count' => count($nodes_saved),
      '%bundle' => $bundle,
    );
    watchdog('edit_selected', '%count %bundles saved successfully.', $args, WATCHDOG_NOTICE);
    drupal_set_message(t('%count %bundles were saved successfully.', $args), 'status');
  }
  else {
    $args = array(
      '%bundle' => $bundle,
    );
    watchdog('edit_selected', 'No %bundles saved.', WATCHDOG_ERROR);
    drupal_set_message(t('Sorry; no %bundles were saved. Please let the website owners know.', $args), 'error');
  }

  // Clear the page and block caches.
  cache_clear_all();

  // dpm($cause_error);
}





/**
 * Form submission handler replacement for node_form_delete_submit()
 */
function edit_selected_node_form_delete_submit($form, &$form_state) {

  // This was tested in the validation step
  $nids = $form_state['values']['edit_selected_nids'];
  $nids = explode('|', $nids);
  // dpm ($nids, "nids");

  $destination = array();
  if (isset($_GET ['destination'])) {
    $destination = drupal_get_destination();
    unset($_GET ['destination']);
  }

  // The ordinary delete confirmation page: not used here
  // $form_state ['redirect'] = array('node/' . $nid . '/delete', array('query' => $destination));
  // That page calls node_delete_confirm()

  // @todo Redirect to a (customised multiple-) node deletion confirmation form
  // @todo Create a (get_form) page callback, like ['node/%node/delete'] in the node module
  //    which calls node_delete_confirm()
  // @todo Create that form's submit handler, like node_delete_confirm_submit()
  // -- or, even better:
  // @todo Create a front-end javascript confirmation message (that has the above as a fallback…?)


  foreach($nids as $nid) {
    node_delete($nid);
  }

  cache_clear_all();

  $messages_args = array('@count' => count($nids));
  watchdog('edit_selected', '@count nodes deleted.', $messages_args);
  drupal_set_message(t('@count nodes have been deleted.', $messages_args));

  // dpm($cause_error);
}
