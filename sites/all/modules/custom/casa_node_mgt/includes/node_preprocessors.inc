<?php
/**
 * @file
 * Functions that make changes to node data before they are themed.
 *
 * Fuctions in this file begin with '_' because they are internal functions, not hooks.
 */

namespace Drupal\Casabio\casa_node_mgt\preprocessors;

use Drupal\Casabio\casa_core;

/**
 * CONTENTS

  _preprocess_observation()
  _preprocess_identification()
  _preprocess_identification_community()
  _preprocess_interaction()
  _preprocess_collection()
 */


function _preprocess_node_not_full(&$variables) {

  // Don't display 'submitted info' of the following node types
  $types = array(
    'collection',
    'picture',
    'observation',
    'interaction',
    'habitat_record'
  );

  if (in_array($variables['node']->type, $types)) {
    // Don't display submission info ('Submitted by [user] on [date]')
    // $variables['submitted'] = '';
    $variables['display_submitted'] = FALSE;
  }


  // Don't display 'title' of the following node types
  $types = array(
    'picture',
    'interaction'
  );

  if (in_array($variables['node']->type, $types)) {
    $variables['title'] = '';
  }


  // Don't display 'links' of the following node types
  $types = array(
    'picture'
  );

  if (in_array($variables['node']->type, $types)) {
    $variables['content']['links'] = [];
  }
}



function _preprocess_node_full(&$variables) {
  // dpm($variables, 'variables');

  global $user;
  // dpm($user, 'user');

  $node = entity_metadata_wrapper('node', $variables['nid']);

  if ($variables['node']->type == 'observation') {
    $historian = new casa_core\historian($node);
    $historian->addEvent(NULL, 'View', $user->uid);
    // dpm($historian, '$historian');
  }

  // Show an edit button

  // Types to show an edit button for
  $types = array(
    'collection',
    'picture',
    'observation',
    'interaction',
    'habitat_record'
  );

  if (in_array($variables['node']->type, $types)) {

    // Add an Edit link for the node

    $is_owner = $variables['uid'] === $user->uid;

    // If the user is at least a maintainer
    if (user_access('can maintain content')) {

      $variables['content']['edit_link'] = array(
        '#markup' => l('Edit', 'node/' . $variables['nid'] . '/edit', array(
          'attributes' => array('class' => array('right', 'button', 'raised'),),
        )),
        '#weight' => -5,
      );
    }
  }

  $contributor = user_load($variables['uid']);
  // dpm($contributor, 'contributor');
  $variables['content']['contributor'] = array(
    '#markup' => 
      '<div class="field field-label-inline contributor">'
    . '  <div class="field-label">Owner: </div>'
    . '  <div>' . l($contributor->name, 'user/' . $contributor->uid) . '</div>'
    . '</div>'
  );
}



function _preprocess_observation(&$variables) {
  // dpm($variables, 'variables');
  $owner = user_load($variables['uid']);
  // dpm($user, '$user');

  obscure_location($variables);

  $variables['display_submitted'] = FALSE;

  if ($variables['view_mode'] == 'full') {
    // dpm($variables, 'variables');
    global $user;

    // Add date
    $variables['content']['field_date'] = array(
      '#markup' => '<div class="field field-label-inline">'
        . '<div class="field-label">Date: </div>'
        . format_date($variables['created'], 'medium') . '</div>',
    );

    // Embed the view of community identifications

    $identifications_view = views_embed_view('identifications_of_observation', 'default');
    
    // dpm($identifications_view, 'identifications_view');
    $variables['content']['identifications_view'] = array(
      '#markup' => $identifications_view,
      '#weight' => 9,
    );

    // Embed the view of interactions

    $interactions_view = views_embed_view('interactions_of_observation', 'default');
    // dpm($identifications_view, 'identifications_view');
    $variables['content']['interactions_view'] = array(
      '#markup' => $interactions_view,
      '#weight' => 10,
    );

    // If user is logged in
    if (in_array('authenticated user', $user->roles)) {

      // Embed an identification form styled as "Add new species identification".
      $variables['content']['new_identification_form'] =
        create_new_identification_form();

      // Embed an interaction form styled as "Add new interaction".
      $variables['content']['new_interaction_form'] =
        create_new_interaction_form();
    }
  }

  // If there's an observer name, append user's full name linked to their profile
  if (isset($variables['content']['field_observer_name'])) {
    $variables['content']['field_observer_name'][0]['#markup'] .=
      ' <span>(' . l($owner->name, 'user/' . $owner->uid) . ')</span>';
  }
}


function _preprocess_picture(&$variables) {
  // dpm($variables, 'variables');

  // Although it shouldn't typically be shown by itself (outside of an observation).
  // obscure_location($variables);

  $observation_repr = get_observation_referencing_pic($variables['nid']);
  // dpm($observation_repr, '$observation_repr');
  $observation_nid = $observation_repr ? $observation_repr->nid : 'no observation';
  // dpm($observation_nid, '$observation_nid');

  if (($variables['view_mode'] == 'small')
    || ($variables['view_mode'] == 'thumbnail')
    || ($variables['view_mode'] == 'medium')
    || ($variables['view_mode'] == 'teaser')) {

    // Add lightbox link

    $picture = entity_metadata_wrapper('node', $variables['node']);
    // dpm($picture->raw(), '$picture->raw()');
    $image = $picture->field_image->value();
    // dpm($image, '$image');
    $lightbox_path = image_style_url('very_large', $image['uri']);
    // dpm($lightbox_path, '$lightbox_path');

    $variables['content']['lightbox_link'] = array(
      '#type' => 'link',
      '#title' => t('Expand'),
      '#href' => $lightbox_path,
      '#attributes' => array(
        'data-title' => $picture->label(),
        'data-lightbox' => $observation_nid,
      ),
    );
  }

  if ($variables['view_mode'] == 'thumbnail') {
    // $variables['content']['lightbox_link']['#attributes']['class'][] = 'hidden'; 
  }


  if ($variables['view_mode'] == 'full') {
    $observation_title = $observation_nid; // '<em>None</em>';
    if ($observation_repr) {
      // dpm($observation_nid, '$observation_nid');
      $observation = node_load($observation_nid);
      if ($observation) {
        // dpm($observation, '$observation');
        $observation_title = $observation->title;
      }
    }
    // dpm($observation_title, '$observation_title');

    $link = l($observation_title, 'node/' . $observation_nid);

    $variables['content']['observation'] = array(
      // '#title' => 'Observation',
      '#prefix' => '<div class="field field-type-text field-label-inline">',
      '#suffix' => '</div>',
      'label' => array(
        '#markup' => '<div class="field-label">Observation</div>',
      ),
      'value' => array(
        '#markup' => '<div class="field-items"><div class="field-item">' . $link . '</div></div>',
      ),
      '#weight' => '6',
    );
  }
}


function _preprocess_identification(&$variables) {
  // dpm($variables, 'variables');

  if ($variables['view_mode'] == 'text') {
    $variables['title'] = '';

    $variables['content']['user'] = array(
      '#type' => 'markup',
      '#markup' => $variables['name'],
      '#weight' => -1,
    );
  }
}


/**
 * Internal function. Preprocesses community identifications before they are rendered.
 */
function _preprocess_identification_community(&$variables) {
  // dpm($variables, 'variables');

  $community_identification = entity_metadata_wrapper('node', $variables['nid']);
  // dpm($community_identification->raw(), '$community_identification');

  // $species_data = $variables['field_identified_species'][0]; // Should always have 1.
  // dpm($species_data, '$species_data');

  if (! isset($variables['field_identified_species'][0])) {
    // throw new Exception("Community identification doesn't reference a species", 1);
    return NULL;
  }

  $identified_species = entity_metadata_wrapper('taxonomy_term',
    $variables['field_identified_species'][0]['tid']);
  // dpm($identified_species->raw(), '$identified_species');

  if ($variables['view_mode'] == 'teaser') {

    if (user_has_role(2)) { // User is authenticated

      // Embed an identification form styled as "Agree?", with selection of certainty.

      $bundle = 'identification';
      $values = array(
        'type' =>     $bundle,
        'status' =>   1,
        'comment' =>  0,
        'promote' =>  0,
      );
      $new_identification = entity_create('node', $values);


      // Add agreement form

      module_load_include('inc', 'node', 'node.pages');
      $agreement_form = drupal_get_form($bundle . '_node_form', $new_identification, ['form_view_mode' => 'agreement']);
      // dpm($agreement_form, 'agreement_form');

      $current_identification_species = $identified_species->label();
      $agreement_form['field_identified_species']['und']['#default_value'] =
        $current_identification_species;
      // $agreement_form['field_identified_species']['und']['#value'] =
      //   $current_identification_species;
      // dpm($agreement_form, 'agreement_form');

      $agreement_form['identified_species_nid'] = array(
        '#type' => 'hidden',
        '#value' => $identified_species->getIdentifier(),
        '#attributes' => array('name' => 'identified_species_nid'),
      );

      $variables['content']['agreement_form'] = $agreement_form;
      $variables['content']['agreement_form']['#weight'] = 10;
    }


    // Add picture (of identified species)

    $representative_picture = $identified_species->field_representative_picture->raw();
    // dpm($representative_picture, '$representative_picture');
    if ($representative_picture) {
      $picture = node_load($representative_picture);
      if ($picture) {
        $variables['content']['picture'] = node_view($picture, 'small');
      }
    }

    // If there are individual identifications, add a link to show them
    if (isset($variables['content']['field_identifications'])) {

      // Add "# users voted (show)" link
      $variables['content']['field_identifications_trigger'] = array(
        '#type' => 'markup',
        '#markup' => '<button data-display="#identifications-' . $variables['nid'] . '" class="user-votes flat">'
          . count($variables['field_identifications']) . ' users voted (show)</button>',
      );

      // Add the dialog that displays individual identifications
      $variables['content']['field_identifications_dialog'] = array(
        '#type' => 'markup',
        '#title' => t('Identifications'),
        '#prefix' => '<div id="identifications-' . $variables['nid'] . '" data-transform="to-dialog" style="display: none;" title="Identifications">',
        'field_identifications' => $variables['content']['field_identifications'],
        '#suffix' => '</div>',
        '#tree' => TRUE,
      );
    }
    else {
      $variables['content']['field_identifications_trigger'] = array(
        '#markup' => '<span>No user identifications recorded...?</span>',
      );
    }

    unset($variables['content']['field_identifications']);

  }
  // dpm($variables, 'variables');
}



function _preprocess_interaction(&$variables) {
  // dpm($variables, 'variables');
  $interaction = entity_metadata_wrapper('node', $variables['nid']);

  $observation = $interaction->field_observation->raw();
  if ($observation) {
    $pictures = entity_metadata_wrapper('node', $observation)->field_pictures_observation->value();

    if ($pictures) {
      $variables['content']['picture_subject'] = node_view($pictures[0], 'small');
    }
  }

  $observation_object = $interaction->field_observation_object->raw();
  if ($observation_object) {
    $pictures = entity_metadata_wrapper('node', $observation_object)->field_pictures_observation->value();

    if ($pictures) {
      $variables['content']['picture_object'] = node_view($pictures[0], 'small');
    }
  }
  // dpm($variables['content']['picture_subject'], 'picture_subject');
}



function _preprocess_collection(&$variables) {
  // dpm($variables, 'variables');
  $user = user_load($variables['uid']);
  // dpm($user, '$user');

  if ($variables['view_mode'] == 'teaser') {
    // $variables['content']['user'] = array(
    //   '#markup' => '<div class="field field-label-inline">'
    //     . '<div class="field-label">By: </div>'
    //     . l($user->name, 'user/' . $user->uid) . '</div>',
    // );

    $variables['content']['field_collector'][0]['#markup'] .=
      ' <span>(' . l($user->name, 'user/' . $user->uid) . ')</span>';
  }

  if ($variables['view_mode'] == 'full') {
    $collection_locations = get_collection_locations($variables['nid'], 5000);
    // dpm($collection_locations, '$collection_locations');
    
    if ($collection_locations) {

      $map_renderable = setup_QDS_map_container($collection_locations, $variables['nid']);
      // $variables['content']['locations'] = $map_renderable;

      $variables['content']['field_locations'] = array(
        'map' => $map_renderable,
      );
    }
  }
}



/**
 *
 */
function create_new_identification_form() {

  $content = array(
    '#prefix' => '<details class="add-new identify_form_wrapper">',
    '#suffix' => '</details>',
  );

  $content['summary'] = array(
    '#markup' => '<summary><strong>+</strong> New Identification</summary>',
    '#weight' => -100,
  );

  $content['contents'] = array(
    '#prefix' => '<div class="details-contents">',
    '#suffix' => '</div>',
  );
  

  // Embed the view

  $view_name = 'species_reference_selector_widget';
  $display_id = 'default';

  $view_rendered = views_embed_view($view_name, $display_id);

  // Not in ['identified_species'] fieldset anymore
  $content['contents']['chooser'] = array(
    '#type' => 'markup',
    '#markup' => $view_rendered,
  );

  // Embed the form

  $bundle = 'identification';
  $values = array(
    'type' =>     $bundle,
    'status' =>   1,
    'comment' =>  0,
    'promote' =>  0,
  );
  $new_identification = entity_create('node', $values);

  module_load_include('inc', 'node', 'node.pages');
  $new_identification_form = drupal_get_form($bundle . '_node_form', $new_identification,
    ['form_view_mode' => 'contribute_new']);
  // dpm($new_identification_form, 'new_identification_form');

  $new_identification_form['#weight'] = 10;

  $content['contents']['identification_form'] = $new_identification_form;

  return $content;
}



/**
 *
 */
function create_new_interaction_form() {

  $content = array(
    '#prefix' => '<details class="add-new">',
    '#suffix' => '</details>',
  );

  $content['summary'] = array(
    '#markup' => '<summary><strong>+</strong> New Interaction</summary>',
    '#weight' => -100,
  );

  $content['contents'] = array(
    '#prefix' => '<div class="details-contents">',
    '#suffix' => '</div>',
  );

  // Embed the view

  $view_name = 'species_reference_selector_widget';
  $display_id = 'default';

  $view_rendered = views_embed_view($view_name, $display_id);

  // Not in ['identified_species'] fieldset anymore
  $content['contents']['chooser'] = array(
    '#type' => 'markup',
    '#markup' => $view_rendered,
    // '#weight' => 10, // Makes no difference; must be above the form
  );

  // Embed the form

  $bundle = 'interaction';
  $values = array(
    'type' =>     $bundle,
    'status' =>   1,
    'comment' =>  0,
    'promote' =>  0,
  );
  $new_interaction = entity_create('node', $values);

  module_load_include('inc', 'node', 'node.pages');
  $new_interaction_form = drupal_get_form($bundle . '_node_form', $new_interaction,
    ['form_view_mode' => 'contribute_new']);
  // dpm($new_identification_form, 'new_identification_form');

  $new_interaction_form['#weight'] = 10;
  // $new_identification_form['title'] = array(
  //   '#type' => 'markup',
  //   '#markup' => '<h2>Add new species identification</h2>',
  // );

  $content['contents']['interaction_form'] = $new_interaction_form;


  return $content;
}


/**
 * Converts the location of a taxon from a point to a QDS. Should be called from
 * a template_preprocess function.
 */
function obscure_location(&$variables) {
  // dpm($variables, 'variables');

  global $user;

  // If current user was the contributor
  if ($variables['uid'] === $user->uid) {
    return NULL;
  }

  // If the taxon has no location
  if (! array_key_exists('field_location', $variables['content'])) {
    return NULL;
  }
  if (! array_key_exists(0, $variables['content']['field_location']['#items'])) {
    return NULL;
  }
  if (is_null($variables['content']['field_location']['#items'][0]['geom'])) {
    return NULL;
  }

  $geometry = $variables['content']['field_location']['#items'][0];
  // dpm($geometry, 'geometry');

  // $QDS = determine_QDS($geometry['lon'], $geometry['lat']);
  // // dpm($QDS, 'QDS');

  // $wkt = convert_QDS_to_WKT($QDS);
  // dpm($wkt, 'wkt');

  // // $field = array('wkt' => $wkt);
  // $geofield_values = geofield_compute_values($wkt, 'wkt');
  // dpm($geofield_values, 'geofield_values');


  $collection = create_point_collection($geometry['lon'], $geometry['lat']);

  $variables['content']['field_location'] =
    setup_QDS_map_container($collection, $variables['nid']);
  // dpm($variables, 'variables after');
}