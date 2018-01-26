<?php
/**
 * @file
 * Functions that alter taxonomy terms before they are viewed.
 */

/**
  CONTENTS

  _preprocess_taxonomy_term()
  preprocess_taxon()
  _process_taxonomy_term()
  get_taxa_tree_base_as_markup()
  get_taxa_tree_as_markup()
  get_taxa_children_tree_as_markup()

 */




/**
 * Implements hook_preprocess_taxonomy_term().
 */
function _preprocess_taxonomy_term(&$variables) {
  // dpm($variables, 'variables');
  // dpm($variables, 'preprocess_taxonomy_term variables');
  // return NULL;

  $tid = $variables['tid'];
  $term = entity_metadata_wrapper('taxonomy_term', $tid);
  $vocab = $variables['vocabulary_machine_name'];
  // dpm($term->raw(), '$term->raw()');
  global $user;

  // Teasers
  if (($variables['view_mode'] == 'teaser') || ($variables['view_mode'] == 'field_guide')) {
    // Add 'block' link to term page
    $variables['content']['term_block_link'] = array(
      '#markup' => l('', 'taxonomy/term/' . $variables['tid'], array(
        'attributes' => array('class' => array('block'),),
      )),
    );
  }

  // Has Range field
  if (isset($variables['field_range'])) {
    // If range has no value, don't show it.
    if ($variables['field_range']) {
      // dpm($variables, "$variables");

      if (array_key_exists(0, $variables['field_range'])) {
        if ($variables['field_range'][0]['geom'] === 'GEOMETRYCOLLECTION EMPTY') {
          $variables['content']['field_range'][0] = array(
            '#markup' => '<em class="no-value">Range unknown</em>',
          );
        }
      }
    }
  }

  // All vocabularies
  switch ($variables['view_mode']) {
    case 'full':

      // If the user is an administrator or maintainer
      if (user_access('can maintain content')) {
        // Add an Edit link for the term

        $variables['content']['edit_link'] = array(
          '#markup' => l('Edit', 'taxonomy/term/' . $tid . '/edit', array(
            'attributes' => array('class' => array('right', 'button', 'raised'),),
          )),
          '#weight' => -10,
        );
      }
      break;
  }

  if ($vocab == 'taxa' || $vocab == 'locality') {

    if ($variables['view_mode'] == 'full') {
      // dpm($variables, 'variables');

      // Embed the taxon tree
      $variables['content']['term_tree']
        = get_taxa_tree_base_as_markup($variables['term'], $vocab);

      switch ($vocab) {
        case 'locality':
          $variables['content']['term_tree']['header']['#markup']
            = '  <h3 class="field-label">Locality relations</h3>';
          break;
      }
    }
  }

  // Specific vocabularies
  switch ($vocab) {
    case 'taxa':
      preprocess_taxon($variables);

    default:
      # code...
      break;
  }
}



function preprocess_taxon(&$variables) {
  // dpm($variables, 'variables');

  $tid = $variables['tid'];
  $term = entity_metadata_wrapper('taxonomy_term', $tid);
  // dpm($term->raw(), '$term->raw()');
  global $user;

  // dpm($term->raw(), '$term->raw()');
  assess_new_pics_for_taxon($term->raw());

  // If doesn't have a vulnerability, update it
  $vulnerabilty = $term->field_vulnerability->value();
  if (! $vulnerabilty) {
    // dpm('updating vulnerabilty');
    update_vulnerability($term);
  }

  // Get rank
  $rank = strtolower($term->field_taxon_rank->value());

  // Hide vulnerability if not a species
  if (! $rank == 'species') {
    // Hide vulnerability
    $variables['content']['field_vulnerability']['#access'] = FALSE;
    // dpm($variables, 'variables');
  }

  // If a family, make title uppercase
  $variables['title_class'] = '';
  if ($rank == 'family') {
    $variables['title_class'] = 'upper';
  }

  $variables['children_suffix'] = get_taxa_rank_children_suffix($rank);

  // Add suffix to number of children. Eg. "7 genera"
  if (array_key_exists('field_num_children', $variables['content'])) {
    // $variables['content']['field_num_children'][0]['#markup'] .= ' ' . $children_suffix;
    $variables['num_children'] = (int) $variables['content']['field_num_children'][0]['#markup'];
  }
  else {
    $variables['num_children'] = 0;
  }


  // Embed a map of the locations of all observations of this taxon.

  $locations_data = get_taxon_locations($tid, 500); // 5000
  // $locations_data['features'] = array_slice($locations_data['features'], 0, 5); // For testing only.
  // dpm($locations_data,'$locations_data');

  $gbif_key = get_gbif_key($tid);

  $map_renderable = setup_QDS_map_container($locations_data, $tid, array(
    'gbif' => array('key' => $gbif_key))
  );
  $variables['content']['locations'] = array(
    'map' => $map_renderable,
    '#weight' => 0,
  );

  // Get parent taxon

  $parents = taxonomy_get_parents($tid);
  // dpm($parents, '$parents');
  $parent_raw = reset($parents);
  $parent = NULL;
  if ($parent_raw) {
    $parent = entity_metadata_wrapper('taxonomy_term', $parent_raw);
    // dpm($parent->raw(), '$parent->raw()');
  }

  // Add parent taxon field

  $variables['content']['parent'] = array();
  if ($parent) {
  }


  switch ($variables['view_mode']) {

    case 'full':
      // dpm($variables, '$variables');


      // Embed the pictures_of_taxon view

      $observations_view = views_embed_view('pictures_of_taxon', 'default');
      
      // dpm($identifications_view, 'identifications_view');
      $variables['content']['pictures_of_taxon'] = array(
        '#markup' => '<label class="field-label">Pictures from Observations</label>'
          . $observations_view,
        '#weight' => 0,
      );


      // Embed the observations_of_taxon view

      $observations_view = views_embed_view('observations_of_taxon', 'default');
      
      // dpm($identifications_view, 'identifications_view');
      $variables['content']['observations_view'] = array(
        '#markup' => '<label class="field-label">Observations of Taxon</label>'
          . $observations_view,
        '#weight' => 20,
      );

      $variables['content']['locations']['#prefix'] =
        '<label class="field-label">Locations of Identifications</label>';

      // Embed parent taxon's etymology
      if (strtolower($term->field_taxon_rank->value()) == 'species') {

        // Add parent etymology field

        preprocess_taxon_add_parent_etymology($variables, $term, $parent);
      }

      $variables['content']['parent']['#weight'] = -5;
      $variables['content']['parent_etymology']['#weight'] = -4;
      $variables['content']['field_etymology']['#weight'] = -3;

      break;

    case 'field_guide':
      // dpm($variables, '$variables');
      
      // Hide the 5th picture
      if ($variables['content']['field_pictures']) {
        unset($variables['content']['field_pictures'][4]);
      }

      // Description
      if (array_key_exists('description', $variables['content'])) {
        $variables['content']['description']['#prefix']
          .= '<div class="field-label">Description:</div>';
          
        $variables['content']['description']['#attributes']['class']
          = array('field-label-inline');
      }

      // Rank
      if ($variables['content']['field_taxon_rank']) {
        $rank = $term->field_taxon_rank->value();
        $variables['content']['field_taxon_rank'][0]['#markup'] =
          '<span title="' . $rank . '">' 
            . substr($rank, 0, 1) . '</span>';
      }

      // Common name: Wrap it in brackets
      if (array_key_exists('field_common_names', $variables['content'])) {
        $common_names = $term->field_common_names->value();
        // dpm($common_names, '$common_names');
        if ($term->field_common_names->value()[0]) {
          $variables['content']['field_common_names'][0]['#markup'] =
            '(' . $variables['content']['field_common_names'][0]['#markup'] . ')';
        }
      }
      break;
  }



  // If term doesn't have an etymology
  if (! $variables['field_etymology']) {
    $field_etymology_new_value;
    // If the user is at least a maintainer
    if (user_access('can maintain content')) {
      // Add an 'Add etymology?' link for the term
      // dpm($variables, '$variables');
      $url = 'contribute/taxon/etymology/' . $tid;
      // dpm($url, '$url');

      // Provide link to add etymology
      $field_etymology_new_value = 
        '<em class="no-value"></em>'
          . l('Add etymology?', $url, array(
              'attributes' => array('target' => '_blank'),
          ))
      ;
    }
    else {
      global $base_url;
      $field_etymology_new_value = 
        '<em class="no-value"></em>'
          . l('Add etymology?', $base_url . '/user/register')
      ;
    }
    $variables['content']['field_etymology'][0]['#markup'] = $field_etymology_new_value;
  }
}


function preprocess_taxon_add_parent_etymology(&$variables, $term, $parent) {
  $variables['content']['parent_etymology'] = array();
  if ($parent) {
    $parent_etymology = $parent->field_etymology->value();
    // dpm($parent_etymology, '$parent_etymology');

    $parent_add_etym_url = 'contribute/taxon/etymology/' . $parent->getIdentifier();
    $parent_etymology = $parent_etymology ? $parent_etymology['value'] :
      '<em class="no-value">' . l('Add etymology?', $parent_add_etym_url, array(
        'attributes' => array('target' => '_blank'),
      )) . '</em>';

    $variables['content']['parent_etymology'] = array(
      '#markup' => 
        '<div class="field field-label-inline parent-etymology">'
      . '  <div class="field-label">Etymology of ' . $parent->label() . ':&nbsp;</div>'
      . '  <div class="field-items">'
      . '    <div class="field-item">' . $parent_etymology . '</div>'
      . '  </div>'
      . '</div>',
      '#weight' => 2
    );

    // Update title of etymology to include epithet
    $term_label_exploded = explode(' ', $term->label());
    $species_epithet = array_key_exists(1, $term_label_exploded) ?
      $term_label_exploded[1]
      : $term_label_exploded[0];
    $variables['content']['field_etymology']['#title'] =
      'Etymology of ' . $species_epithet;
  }
}



/**
 * Implements hook_process_taxonomy_term().
 */
function _process_taxonomy_term(&$variables) {}



function get_taxa_tree_base_as_markup($term, $vocab) {
  $taxa_tree_markup = get_taxa_tree_as_markup($term, '', $vocab);
  return array(
    '#type' => 'container',
    '#prefix' => '<div class="term-tree expandable" data-expanded="false" style="height: 250px;"><div>',
    'header' => [
      '#markup' => '  <h3 class="field-label">Taxonomic relations</h3>',
    ],
    'tree' => [
      '#markup' => $taxa_tree_markup,
    ],
    'button' => [
      '#markup' => '  <button role="expand">See all</button>',
    ],
    '#suffix' => '</div></div>',
    '#weight' => '9',
  );
}


/**
 * Recursive.
 */
function get_taxa_tree_as_markup($term, $branches, $vocab_name) {
  // dpm($term, 'term');
  $markup = '';

  $tid = $term->tid;

  $term_wrapped = entity_metadata_wrapper('taxonomy_term', $term);

  // Name
  if ($branches != '') { // If this is not the current term
    $term_name = l($term->name, 'taxonomy/term/' . $term->tid, array());
  }
  else {
    $term_name = '<strong>' . $term->name . '</strong>';
  }

  // Rank (taxa)
  $rank = '';
  if (property_exists($term_wrapped, 'field_taxon_rank')) {
    $rank = $term_wrapped->field_taxon_rank->value();
    if ($rank) {
      $rank = ' (' . $rank . ')';
    }
    else {
      $rank = ', <span class="no-value">Rank unknown</span>';
    }
  }

  // Common names (taxa)
  $common_names_str = '';
  if (property_exists($term_wrapped, 'field_common_names')) {
    $common_names = $term_wrapped->field_common_names->value();
    // dpm($common_names, '$common_names');
    $common_names_str = $common_names ? ', ' . implode(', ', array_slice($common_names, 0, 3)) : '';
  }

  $children = $branches === '' ? get_taxa_children_tree_as_markup($tid, $vocab_name) : '';

  $branch = '<ul>'
    . '<li>' . $term_name
    . $common_names_str
    . $rank
    . $children
    . '</li>'
    . $branches
    . '</ul>';

  $parents = taxonomy_get_parents($tid);
  // dpm($parents, 'parents');

  if (!empty($parents)) {
    foreach ($parents as $tid => $parent_term) {
      $markup .= get_taxa_tree_as_markup($parent_term, $branch, $vocab_name);
    }
  }
  else {
    $markup = $branch;
  }

  return $markup;
}


function get_taxa_children_tree_as_markup($tid, $vocab_name) {
  $children = '<ul class="children">';

  $vocab = taxonomy_vocabulary_machine_name_load($vocab_name)->vid;
  $vid = $vocab;
  $children_terms = taxonomy_get_children($tid, $vid);
  // dpm($children_terms, '$children_terms');

  foreach ($children_terms as $child_term_raw) {
    $child_term = entity_metadata_wrapper('taxonomy_term', $child_term_raw);
    // $child_term->field_common_names[LANGUAGE_NONE][0]['value']

    $common_names_str = '';
    if (property_exists($child_term, 'field_common_names')) {
      $common_names = $child_term->field_common_names->value();
      // dpm($common_names, '$common_names');
      $common_names_str = $common_names ? ', ' . implode(', ', array_slice($common_names, 0, 3)) : '';
    }
    
    $children .= '<li>'
      . l($child_term_raw->name, 'taxonomy/term/' . $child_term_raw->tid, array())
      . $common_names_str
      . '</li>';
  }

  $children .= '</ul>';

  return $children;
}