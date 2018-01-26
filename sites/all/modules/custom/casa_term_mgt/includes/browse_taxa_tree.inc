<?php
/**
 * @file
 * Functions that build the "Browse Taxa as Tree" page.
 */

/**
  CONTENTS

  browse_taxa_tree_page_callback()
  browse_taxa_tree_content()
  get_animalia_children()
  render_browse_taxa_tree_children()
  provide_taxa_children_callback()
 */


function browse_taxa_tree_page_callback() {
  return browse_taxa_tree_content();
}


/**
 *
 */
function browse_taxa_tree_content() {

  $vid = 2;

  $tree = array(
    (object) array(
      // 'icon' => '/images/_.png',
      'tid' => 101660,
      'name' => 'Plantae',
      'parents' => array(0),
      // 'children' => array(
      //   (object) array(
      //     // 'icon' => '/images/_.png',
      //     'tid' => 101660,
      //     'name' => 'Plantae',
      //     'parents' => array(0),
      //   ),
      // ),
    ),
    (object) array(
      // 'icon' => '/images/_.png',
      'tid' => 101661,
      'name' => 'Animalia',
      'parents' => array(0),
      // 'children' => get_animalia_children(),
    ),
    (object) array(
      // 'icon' => '/images/_.png',
      'tid' => 101662,
      'name' => 'Fungi',
      'parents' => array(0),
    ),
  );

  $content = array(
    '#markup' => '<div class="tree expandable" role="tree">'
      . render_browse_taxa_tree_children($vid, $tree, 1)
      . '</div>',
  );
  // dpm($content, 'content');

  $content['#attached']['js'] = array(
    drupal_get_path('module', 'casa_term_mgt') . '/scripts/casa_term_mgt.js',
  );

  // dpm(taxonomy_get_tree($vid, 103109, 1, FALSE));

  return $content;
}



function get_animalia_children() {
  return array(
    (object) array(
      // 'icon' => '/images/_.png',
      // 'tid' => _,
      'show_children' => FALSE,
      'name' => 'Chordata',
      'parents' => array(0),
      'children' => array(
        (object) array(
          'icon' => '/images/bird_drawing.png',
          // 'tid' => _,
          'show_children' => FALSE,
          'name' => 'Aves',
          'parents' => array(0),
        ),
        (object) array(
          'icon' => '/images/bony_fish_drawing.png',
          // 'tid' => _,
          'show_children' => FALSE,
          'name' => 'Osteichthyes',
          'parents' => array(0),
        ),
        (object) array(
          'icon' => '/images/agnatha_jawless_fish.png',
          // 'tid' => _,
          'show_children' => FALSE,
          'name' => 'Agnatha',
          'parents' => array(0),
        ),
      ),
    ),
    (object) array(
      // 'icon' => '/images/_.png',
      // 'tid' => '_,
      'show_children' => FALSE,
      'name' => 'Echinodermata',
      'parents' => array(0),
      'children' => array(
        (object) array(
          'icon' => '/images/brittlestar_drawing.png',
          // 'tid' => _,
          'show_children' => FALSE,
          'name' => 'Ophiuroidea',
          'parents' => array(0),
        ),
      ),
    ),
    (object) array(
      // 'icon' => '/images/_.png',
      'tid' => 101644,
      'name' => 'Arthropoda',
      'parents' => array(0),
      'children' => array(
        (object) array(
          'icon' => '/images/centipede_drawing.png',
          // 'tid' => _,
          'show_children' => FALSE,
          'name' => 'Myriapoda',
          'parents' => array(0),
        ),
      ),
    ),
    (object) array(
      // 'icon' => '/images/_.png',
      'tid' => 101655,
      'name' => 'Bryozoa',
      'parents' => array(0),
    ),
    (object) array(
      // 'icon' => '/images/_.png',
      'tid' => 101653,
      'name' => 'Platyhelminthes',
      'parents' => array(0),
    ),
    (object) array(
      // 'icon' => '/images/_.png',
      'tid' => 101652,
      'name' => 'Rotifera',
      'parents' => array(0),
    ),
  );
}



/**
 * Creates an html unordered list of child terms from a given taxonomy tree.
 *
 * @param $vid
 *   The identifier of the vocabulary to render from.
 * @param $tree
 *   A 'hierarchical representation of a vocabulary' such as provided by taxonomy_get_tree().
 * @param int $depth
 *   Indicates how many levels deep the tree should be rendered.
 */
function render_browse_taxa_tree_children($vid, $tree, $depth) {
  // dpm($vid, 'vid');
  // dpm($tree, 'tree');
  // dpm($depth, 'depth');

  if (!is_int($depth)) throw new InvalidArgumentException(
    "Argument $depth must be an integer; "  . gettype($depth) . " provided.", 1);

  $content;

  $content = '<ul role="group">';
  foreach ($tree as $branch) {
    // dpm($branch, '$branch');

    /* Eg.
      <li [role="treeitem"]>
        <span class="action"><button class="expand" data-ajax="$ajax_url">+</button></span>
        <span class="name"><a href="$term_url"></a></span>
        <span class="count">(1)</span>
        <div class="children"><ul>…</ul></div>
      </li>
    */

    $leaves = NULL;
    $rank = '';
    $picture = NULL;
    $image = '';
    $common_name = '';

    if (isset($branch->show_children)) {
      if ($branch->show_children === FALSE) {
        // dpm('Taxon ' . $branch->name . ' should not show children.');
      }
    }
    else {
      $term = entity_metadata_wrapper('taxonomy_term', $branch->tid);

      // Get and render children terms

      $parent = $branch->tid;
      $max_depth = 1;
      $load_entities = FALSE; // full entity load for each
      $leaves = taxonomy_get_tree($vid, $parent, $max_depth, $load_entities);

      // Get rank

      $rank = $term->field_taxon_rank->value();

      $picture = $term->field_representative_picture->value();

      $common_name = implode(', ', $term->field_common_names->value());
    }




    $content .= '<li role="treeitem" aria-level="?" aria-expanded="?">';

    // Button
    if ($leaves) {
      $ajax_url = base_path() . 'services/taxa/get-children/' . $branch->tid;

      $content .= '<span class="action">'
        . '<button class="expand" aria-expanded="false"'
        . ' data-ajax="' . $ajax_url . '">' . '+' . '</button></span>';
    }
    else {
      $content .= '<span class="action"><button class="expand" disabled="true">&nbsp;</button></span>';
    }

    // Picture
    if ($picture) {
      // dpm($picture, '$picture');
      $picture_renderable = node_view($picture, 'thumbnail');
      if ($picture_renderable) {
        $content .= drupal_render($picture_renderable);
      }
    }

    // $content .= $picture;


    // Build the row
    // Name + rank + icon link
    $content .= ' <span class="name">';

    // Icon
    if (isset($branch->icon)) {
      $module_path = base_path() . drupal_get_path('module', 'casa_term_mgt');
      $content .= '<img src="' . $module_path . $branch->icon . '">';
    }

    $content .= $rank;
    // Link
    if (isset($branch->tid)) {
      $term_url = base_path() . 'taxonomy/term/' . $branch->tid;
      $content .= ' <a href="' . $term_url . '">';
    }
    // Name
    $content .= $branch->name;

    if (isset($branch->tid)) {
      $content .= '</a>';
    }

    // Common name
    if ($common_name) {
      $content .= ' (' . $common_name . ')';
    }

    $content .= '</span>';



    // Count
    // @todo Rather use this to indicate how many species (collectively) are within this taxon.
    // $content .= ' <span class="count">(' . ')</span>';

    // Children
    if (isset($branch->children)) {
      $children = render_browse_taxa_tree_children($vid, $branch->children, $depth - 1);
    }
    elseif ($leaves) {
      $children = $depth > 1 ? render_browse_taxa_tree_children($vid, $leaves, $depth - 1) : '';
    }
    else {
      $children = '';
    }

    $content .= '<div class="children">';
    $content .= $children;
    $content .= '</div>';

    $content .= '</li>';
  }
  $content .= '</ul>';

  return $content;
}



/**
 * An AJAX function. Provides rendered HTML of the taxa children of an taxonomy
 * term, in the format provided by render_browse_taxa_tree_children().
 */
function provide_taxa_children_callback($tid) {
  // dpm('param: ' . $tid . ' is of type: ' . gettype($tid));

  $vid = 2;
  $max_depth = 1;
  $load_entities = FALSE;

  if ((int) $tid >! 0) {
    return;
  }

  // dpm(gettype($tid));

  $tree = taxonomy_get_tree($vid, (int) $tid, $max_depth, $load_entities);
  // dpm($tree);

  $content = render_browse_taxa_tree_children($vid, $tree, 1);
  // dpm($content, 'content');

  $result = array(
    'result' => 'success',
    'content' => $content,
  );
  $response = array('#type' => 'ajax', '#commands' => $result);

  return $response;
}