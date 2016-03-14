<?php
/**
 * @file
 * Provides create, validate and process functions for the edit_selected form block
 */





/**
* 
*/
class SelectableForm extends Form {
  
  function __construct(array $specifications) {
    parent::__construct($specifications);
  }



  /**
   * Unsets 'title', 'body', and other parts of the base form.
   */
  public function removeUndesirableProperties($accepted_fields) {
    $specifications = $this -> getSpecifications();

    $undesirable_properties = array(
      'revision_information',
      'comment_settings',
      'author',
      'options',
    );
    $undesirable_actions = array(
      'preview',
    );

    if (!in_array('title', $accepted_fields)) {
      $undesirable_properties[] = 'title';
    }
    if (!in_array('body', $accepted_fields)) {
      $undesirable_properties[] = 'body';
    }

    foreach ($undesirable_properties as $property) {
      unset($specifications[$property]);
    }
    foreach ($undesirable_actions as $action) {
      unset($specifications[$action]);
    }

    // Cannot remove these here; they are removed in #after_build callback
    // unset($this -> getSpecifications()['menu']);
    // unset($this -> getSpecifications()['path']);
    $this -> setSpecifications($specifications);
  }



  /**
   * Unsets fields that haven't been selected by the user.
   */
  public function removeUndesirableFields($accepted_fields) {
    $specifications = $this -> getSpecifications();

    // Create an array of just the entity 'field' form elements
    foreach ($specifications as $key => $value) {
      $is_field = substr($key, 0, 6) == 'field_';

      if ($is_field) {
        // Retain only user-defined fields
        if (!in_array ($key, $accepted_fields)) { // not using array_key_exists ()
          // dpm($key);
          unset($specifications[$key]);
          // $this -> getSpecifications()[$key] = array();
        }
        else {
          $form_field_keys[] = $key;
        }
      }
    }
    // dpm($form_field_keys, 'form_field_keys');
    // dpm($this -> getSpecifications(), 'form');
    $this -> setSpecifications($specifications);
  }



  /**
   * Adds necessary hidden fields.
   * 
   * @param $prefill
   *   A boolean representing a field that indicates if selecting a node should 
   *   prefill the form with that node's field values.
   */
  public function addHiddenFields($prefill) {
    $specifications = $this -> getSpecifications();

    // Add a hidden field specifying if the form should allow pre-filling values from selected nodes
    $specifications['prefill'] = array(
      '#id' => 'prefill',
      '#type' => 'hidden',
      '#default_value' => 'false',
    );
    if ($prefill == TRUE) {
      $specifications['prefill']['#default_value'] = 'true';
    }

    // Adds a hidden field that stores the NIDs of selected nodes.
    $specifications['edit_selected_nids'] = array(
      '#id' => 'edit_selected_nids',
      '#type' => 'hidden',
      '#default_value' => t('Node IDs'),
    );

    // Adds a hidden field that stores the names of the fields whose values are altered by the user.
    $specifications['edit_selected_altered_fields'] = array(
      '#id' => 'edit_selected_altered_fields',
      '#type' => 'hidden',
      '#default_value' => t('Altered Fields'),
    );
    $this -> setSpecifications($specifications);
  }



  /**
   * Manipulates the 'Save' and 'Delete' buttons, and optionally adds a 'Cancel' button
   */
  public function manipulateActions($actions) {
  }



  /**
   * Sets field-groups (any format) to the fieldset format, and makes them collapsible
   */
  public function fieldGroupsToFieldsets() {
    $specifications = $this -> getSpecifications();
    $field_groups = $specifications['#fieldgroups'];
    // dpm ($field_groups, "field_groups");

    foreach ($field_groups as $group) {
      $group -> format_type = 'fieldset';
      $group -> format_settings['instance_settings']['classes'] .= ' collapsible';
    }
    // dpm ($field_groups, "field_groups");
  }

}