<?php
/**
 * @file
 * Provides create, validate and process functions for the edit_selected form block
 */




// =============================================================================
/* CONTENTS

  get_edit_selected_form()
  get_identify_selected_form()
*/



/**
 * Assembles renderable array for block content.
 *
 * @return array
 *   Returns a renderable array of block content, or null if no view results are found.
 */
function get_edit_selected_form($bundle) {

  $content = "";

  global $user;
  $values = array(
    'type' => $bundle,
    'uid' => $user->uid,
    'status' => 1,
    // 'comment' => 0,
    // 'promote' => 0,
  );
  $node = entity_create('node', $values);

  // Load node.pages.inc from the node module.
  module_load_include('inc', 'node', 'node.pages');
  $content = drupal_get_form($bundle . '_node_form', $node, ['form_view_mode' => 'contribute_new']);
  // dpm($content, '$content');

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
function get_identify_selected_form() {

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

  try {
    // Load node.pages.inc from the node module.
    module_load_include('inc', 'node', 'node.pages');
    $content['form'] = drupal_get_form('identification_node_form', $node, ['form_view_mode' => 'contribute_new']);
    $content['form']['#weight'] = 2;
    // dpm($content, 'content');
    $content['form']['field_identified_species']['#access'] = FALSE;
  }
  catch (Exception $e) {
    // Set a watchdog message
    watchdog('edit_selected', $e->getMessage(), array(), WATCHDOG_ERROR);

    // Message the error to the user
    // Shouldn't actually message the error to the user; developer must fix.
    drupal_set_message(get_class($e) .
      ' caught: ' . $e->getMessage() .
      ' in ' . $e->getFile() .
      ' on line ' . $e->getLine(), "error");

    // return message in lieu of expected content
    // return "<p>The form could not be created</p>";
  }

  $content['identified_species'] = array(
    '#type' => 'fieldset',
    '#title' => t('Choose a species'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
    '#attributes' => array(
      'class' => array('collapsible', 'collapsed'),
    ),
    '#attached' => array(
      'library' => array(
        array('system', 'drupal.collapse'),
      ),
    ),
  );

  // Embed the view

  $view_name = 'species_reference_selector_widget';
  $display_id = 'entityreference_view_widget_1';

  $view_rendered = views_embed_view($view_name, $display_id);

  $view_markup = str_replace('form-actions', 'form-actions hidden', $view_rendered);
  // dpm(strpos('form-actions', $view_markup), 'strpos');

  $content['identified_species']['chooser'] = array(
    '#type' => 'markup',
    '#markup' => $view_markup,
  );

  return $content;
}
