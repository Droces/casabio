<?php
/**
 * @file
 * Taxonomy term preprocessors
 */

/**
  CONTENTS

  _preprocess_taxonomy_term()
  get_taxa_tree_as_markup()
  get_taxa_children_tree_as_markup()

 */




/**
 * Implements hook_preprocess_taxonomy_term().
 */
function _preprocess_taxonomy_term(&$variables) {
  // dpm(func_get_args(), 'func_get_args');
  // dpm($variables, 'preprocess_taxonomy_term variables');
  // return NULL;

  $tid = $variables['tid'];
  $term = entity_metadata_wrapper('taxonomy_term', $tid);
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
      if (in_array('Administrator', $user->roles) || in_array('Maintainer', $user->roles)) {
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

  // Specific vocabularies
  switch ($variables['vocabulary_machine_name']) {
    case 'taxa':

      // Display parent taxon's name
    
      $parents = taxonomy_get_parents($tid);
      // dpm($parents, '$parents');
      $parent_raw = reset($parents);
      $parent = NULL;
      if ($parent_raw) {
        $parent = entity_metadata_wrapper('taxonomy_term', $parent_raw);
        // dpm($parent->raw(), '$parent->raw()');
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

      // Add parent taxon field

      $variables['content']['parent'] = array();
      if ($parent) {
        // Display parent taxon

        // $parent_rank = $parent->field_taxon_rank->value();
        // $parent_rank = $parent_rank ? $parent_rank : 'Parent';
        // $parent_name = $parent->label();
        // $parent_url = 'taxonomy/term/' . $parent->getIdentifier();
        // $variables['content']['parent'] = array(
        //   '#markup' => 
        //     '<div class="field field-label-inline parent" data-rank="' . $parent_rank . '">'
        //   . '  <div class="field-label">' . $parent_rank . ':&nbsp;</div>'
        //   . '  <div class="field-items">'
        //   . '    <div class="field-item">' . l($parent->name->value(), $parent_url) . '</div>'
        //   . '  </div>'
        //   . '</div>',
        // );
      }


      switch ($variables['view_mode']) {

        case 'full':
          // dpm($variables, '$variables');

          $variables['rank'] = $term->field_taxon_rank->value();

          // Embed the taxon tree

          $taxa_tree_markup = get_taxa_tree_as_markup($variables['term'], '');
          $variables['content']['taxa_tree'] = array(
            '#type' => 'markup',
            '#markup' =>
                '<div class="taxa-tree expandable" data-expanded="false" style="height: 250px;"><div>'
              . '  <h3 class="field-label">Taxonomic relations</h3>'
              .    $taxa_tree_markup
              . '  <button role="expand">See all</button>'
              . '</div></div>',
            '#weight' => '9',
          );


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

            $variables['content']['parent_etymology'] = array();
            if ($parent) {
              $parent_etymology = $parent->field_etymology->value();

              $parent_add_etym_url = 'contribute/taxon/etymology/' . $parent->getIdentifier();
              $parent_etymology = $parent_etymology ? $parent_etymology :
                '<em class="no-value">Unknown ' . l('Add etymology?', $parent_add_etym_url, array(
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

              $species_epithet = explode(' ', $term->label())[1];
              $variables['content']['field_etymology']['#title'] =
                'Etymology of ' . $species_epithet;
            }
          }


          $variables['content']['parent']['#weight'] = -5;
          $variables['content']['parent_etymology']['#weight'] = -4;
          $variables['content']['field_etymology']['#weight'] = -3;

          break;

        case 'field_guide':
          // dpm($variables, '$variables');
          if ($variables['content']['field_pictures']) {
            unset($variables['content']['field_pictures'][4]);
          }
          break;

        default:
          # code...
          break;
      }


      // If the user is an administrator or maintainer
      if (in_array('Administrator', $user->roles) || in_array('Maintainer', $user->roles)) {
        // Add an 'Add etymology?' link for the term
        // dpm($variables, '$variables');

        // If term doesn't have an etymology
        if (! $variables['field_etymology']) {
          $url = 'contribute/taxon/etymology/' . $tid;
          // dpm($url, '$url');

          // Provide link to add etymology
          $variables['content']['field_etymology'][0]['#markup'] = 
            '<em class="no-value">Unknown</em> '
              . l('Add etymology?', $url, array(
                  'attributes' => array('target' => '_blank'),
              ))
          ;
        }
      }

    default:
      # code...
      break;
  }
}



/**
 * Implements hook_process_taxonomy_term().
 */
function _process_taxonomy_term(&$variables) {
  // dpm($variables, '$variables in _process_taxonomy_term()');

  switch ($variables['vocabulary_machine_name']) {
    case 'taxa':

      switch ($variables['view_mode']) {

        case 'full':
          break;

        case 'field_guide':
          break;
      }
      break;
  }
}



function get_taxa_tree_as_markup($term, $branches) {
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

  // Rank
  $rank = $term_wrapped->field_taxon_rank->value();
  if ($rank) {
    $rank = ' (' . $rank . ')';
  }
  else {
    $rank = ', <span class="no-value">Rank unknown</span>';
  }

  // Common names
  $common_names = implode(', ', $term_wrapped->field_common_names->value());
  $common_names = $common_names ? ', ' . $common_names : '';

  $children = $branches === '' ? get_taxa_children_tree_as_markup($tid) : '';

  $branch = '<ul>'
    . '<li>' . $term_name
    . $common_names
    . $rank
    . $children
    . '</li>'
    . $branches
    . '</ul>';

  $parents = taxonomy_get_parents($tid);
  // dpm($parents, 'parents');

  if (!empty($parents)) {
    foreach ($parents as $tid => $parent_term) {
      $markup .= get_taxa_tree_as_markup($parent_term, $branch);
    }
  }
  else {
    $markup = $branch;
  }

  return $markup;
}


function get_taxa_children_tree_as_markup($tid) {
  $children = '<ul class="children">';

  $vocab = taxonomy_vocabulary_machine_name_load('taxa')->vid;
  $vid = $vocab;
  $children_terms = taxonomy_get_children($tid, $vid);
  // dpm($children_terms, '$children_terms');

  foreach ($children_terms as $child_term) {
    $children .= '<li>' . l($child_term->name, 'taxonomy/term/' . $child_term->tid, array()) . '</li>';
  }

  $children .= '</ul>';

  return $children;
}