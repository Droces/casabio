<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */


/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function casabio_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  casabio_preprocess_html($variables, $hook);
  casabio_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
/* -- Delete this line if you want to use this function
function casabio_preprocess_html(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
}
// */

/**
 * Implements hook_preprocess_html().
 */
function casabio_preprocess_html(&$variables) {
  // dpm($variables, 'variables');
}

/**
 * Implements hook_preprocess_page(). Overrides or inserts variables into the page templates.
 */
function casabio_preprocess_page(&$variables, $hook) {
  // dpm($variables, 'variables');
  // dpm($variables['node'], 'node');
  // dpm(current_path(), 'current_path()');
  // dpm(request_path(), 'request_path()');

  // if (isset($variables['node']) {
  //   if ($variables['type'] == 'observation') {
  //     // $variables['title'] = '';
  //   }
  // }

  $page_container_class = '';

  switch (request_path()) {
    case 'contribute/upload':
    case 'user':
      $page_container_class = 'page_width_regular';
      break;

    case 'contribute/request':
    case 'contribute/locality':
    case 'taxa/lookup-multiple':
      $page_container_class = 'page_width_narrow';
      break;

    default:
      # code...
      break;
  }

  if (drupal_match_path(request_path(), 'search*')) {
    $page_container_class = 'page_width_regular';
  }

  $variables['page_container_class'] = $page_container_class;
}
// */

function casabio_process_page(&$variables, $hook) {
  // dpm($variables, 'variables');

  // If this is a user profile page, and there is a title variable
  if (in_array('page__user', $variables['theme_hook_suggestions'])
    && array_key_exists('title', $variables))  {

    // Unset title; it is provided directly to the user-profile template
    $variables['title'] = '';
  }
}

/**
 * Implements hook_preprocess_node(). Overrides or inserts variables into the node templates.
 */
function casabio_preprocess_node(&$variables, $hook) {
  // dpm($variables, 'variables');

  // // Optionally, run node-type-specific preprocess functions, like
  // // casabio_preprocess_node_page() or casabio_preprocess_node_story().
  // $function = __FUNCTION__ . '_' . $variables['node']->type;
  // if (function_exists($function)) {
  //   $function($variables, $hook);
  // }


  if (($variables['title'] == '') && ($variables['type'] == 'observation')) {
    $variables['title'] = '<em>Untitled</em>';
  }

  // if (isset($variables['user_picture'])) {
  //   // dpm('');
  //   $variables['user_picture'] = theme(
  //     'user_picture',
  //     array(
  //       'account' => $variables['user'],
  //       'style_name' => 'tiny')
  //   );
  //   // dpm($variables['user_picture'], 'user_picture');
  //   // image_style_url($style_name, $path)
  // }


  // Nodes displayed in view mode 'teaser'
  if ($variables['view_mode'] == 'teaser') {
    // dpm($variables, 'variables');

    $variables['submitted'] = "by " . $variables['name'] . ", " . ago($variables['created']);

    // // Display a 'content type' label inside these node teasers
    // $node_types_with_pretitle = array(
    //   'observation',
    //   'identification',
    //   'interaction',
    // );
    // if (in_array($variables['type'], $node_types_with_pretitle)) {
    //   $variables['pretitle'] = $variables['type'];
    // }

  }


  // Nodes displayed in view mode 'text'; Reformat...
  if ($variables['view_mode'] == 'text') {
    $variables['theme_hook_suggestions'][] = 'node__text';

    if (isset($variables['content']['field_certainty'])) {
      $variables['content']['field_certainty']['#label_display'] = 'hidden';
      $variables['content']['field_certainty'][0]['#markup'] =
        '(' . $variables['content']['field_certainty'][0]['#markup'] . ')';
      // dpm($variables, 'variables');
    }
  }

}



/**
 * Implements template_preprocess_user_profile().
 */
function casabio_preprocess_user_profile(&$variables, $hook) {
  // dpm($variables, 'variables');

  $user = $variables['elements']['#account'];
  // dpm($user, '$user');

  $variables['user_profile']['edit_url'] = array(
    // '#markup' => url('user/' . $variables['id'] . '/edit'),
    '#markup' => url('user/' . $user->uid . '/edit'),
  );
  $variables['user_profile']['username'] = array(
    '#markup' => $user->name,
  );
}



/**
 * Copied from andrew macrobert's comment on php.net/manual/en/function.time.php.
 */
function ago($timestamp){
  $difference = time() - $timestamp;
  $periods = array("second", "minute", "hour", "day", "week", "month", "years", "decade");
  $lengths = array("60","60","24","7","4.35","12","10");

  for($j = 0; $difference >= $lengths[$j]; $j++)
    $difference /= $lengths[$j];

  $difference = round($difference);

  if($difference != 1)
    $periods[$j].= "s";

  $text = "$difference $periods[$j] ago";
  return $text;
}



function casabio_preprocess_field(&$variables, $hook) {
  // dpm('casabio_preprocess_field');
  // dpm($variables, 'variables');

  // Remove the clearfix class from all fields.
  // 'Self-clearing' will be handled by CSS directly
  // The 'clearfix' class is added to 'inline-label' fields
  // by the fields module's template_preprocess_field() function
  foreach ($variables['classes_array'] as $key => $class) {
    if ($class == 'clearfix') {
      unset($variables['classes_array'][$key]);
    }
  }

  // Make raw image links open in a new tab

  if ($variables['field_type_css'] == 'image') {
    // dpm($variables, 'variables');

    foreach ($variables['items'] as $index => $timestamp) {

      // If this field is linked.
      if($variables['items'][$index]['#path']) {

        // If the image link points to the file directly
        $is_file_link = (strpos($variables['items'][$index]['#path']['path'], '/files/') !== FALSE);

        if ($is_file_link) {
          $variables['items'][$index]['#path']['options'] = array(
            'attributes' => array(
              'target' => '_blank',
            ),
          );
        }
      }
    }
  }
  // dpm($variables, 'variables after');
}



/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
function casabio_preprocess_comment(&$variables, $hook) {
  // dpm($variables, '$variables');
  // dpm($variables['comment'], 'comment object');
  // $variables['sample_variable'] = t('Lorem ipsum.');
  $variables['created'] = format_date($variables['comment']->created, 'custom', 'd M');
  // copied from zen_preprocess_comment
  $variables['pubdate'] = '<time pubdate datetime="' . format_date($variables['comment']->created, 'custom', 'c') . '">' . $variables['created'] . '</time>';
  $variables['submitted'] = t('!username <br />!datetime', array('!username' => $variables['author'], '!datetime' => $variables['pubdate']));
  // $variables['submitted'] = "by " . $variables['author'] . ", " . ago($variables['created']);
}



/**
 * Override or insert variables into the search result template.
 */
function casabio_preprocess_search_result(&$variables) {
  // dpm($variables, '$variables');
  $variables['type'] = $variables['result']['type'];

  // If this search result is a node
  if (array_key_exists('node', $variables['result'])) {
    // Get the node rendered as a teaser
    $teaser = node_view($variables['result']['node'], 'teaser');
    // $variables['result_rendered'] = drupal_render($teaser);
  }

  // $variables['theme_hook_suggestions'][] = 'search_result_wrapper';
  $variables['theme_hook_suggestions'] = array('search_result_wrapper');
}



/**
 * Override or insert variables into the search result template.
 */
function casabio_preprocess_search_results(&$variables) {
  // dpm($variables, '$variables');
}

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function casabio_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  //if (strpos($variables['region'], 'sidebar_') === 0) {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  //}
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function casabio_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
}
// */


function group_fields(&$variables, $fields, $classes = '', $weight = '') {
  $are_fields = FALSE;
  if (isset($variables['content'][$fields[0]]) || isset($variables['content'][$fields[2]])) {
    $are_fields = TRUE;
  }

  if ($are_fields) {
    // Wrap the 'small' fields together, so that they can be styled as a table

    $wrapper_tag = 'div';
    $wrapper_class = 'field-wrapper ' . $classes;

    $variables['content']['group'] = array(
      // '#markup' => t('Text…'),
      '#prefix' => '<' . $wrapper_tag . ' class="' . $wrapper_class . '">',
      'child' => [],
      '#suffix' => '</' . $wrapper_tag . '>',
      '#weight' => $weight,
    );
    foreach ($fields as $field) {
      if (isset($variables['content'][$field])) {
        // dpm('isset');
        $variables['content']['group']['child'][] = $variables['content'][$field];
        unset($variables['content'][$field]);
      }
    }
  }
}




/**
 * Implements theme_status_messages(). Provides markup for a status messages.
 */
function casabio_status_messages($variables) {

  // Include a 'remove' button.

  $display = $variables['display'];
  $output = '';
  $remove_button = '<button class="right" data-action="remove">×</button>';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );
  foreach (drupal_get_messages($display) as $type => $messages) {
    $output .= "<div class=\"messages $type\">\n";
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>\n";
    }
    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message;
        $output .= $remove_button;
        $output .= "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= reset($messages);
      $output .= $remove_button;
    }
    $output .= "</div>\n";
  }
  return $output;
}



/**
 * Implements theme_link().
 */
function casabio_link($variables) {
  // dpm($variables, '$variables');

  // If path matches 'user/digits' exactly
  if (preg_match('/^user\/[0-9]+$/', $variables['path'])) {
    // dpm($variables, '$variables');
    $variables['options']['attributes']['class'][] = 'user-link';
  }

  $path = check_plain(url($variables['path'], $variables['options']));
  $attributes = drupal_attributes($variables['options']['attributes']);
  $html = ($variables['options']['html'] ? $variables['text'] : check_plain($variables['text']));
  return '<a href="' . $path . '"' . $attributes . '>' . $html . '</a>';
}



/**
 * Implements hook_form_FORM_ID_alter().
 */
function casabio_form_comment_node_observation_form_alter(&$form, &$form_state, $form_id) {
  // dpm($form, 'form');
  // module_load_include('inc', 'casa_node_mgt', 'node_forms');
  // $form = form_node_form_alter($form, $form_state, $form_id);
  // return $form;
  if($form['is_anonymous']['#value'] == FALSE) {
    $form['author']['#access'] = FALSE;
  }
  $form['subject']['#access'] = FALSE;

  $form['comment_body']['und'][0]['#rows'] = 2;
  $form['comment_body']['und'][0]['#attributes']['placeholder'] = 'Add a comment';
}




// These 2 functions move the primary page tabs into a contextual menu
// See https://www.drupal.org/node/951088#comment-3987026
// Requires class 'contextual-links-region' to be put on .content in page.tpl.php

/**
 * Implements theme_menu_local_task().
 * "Returns HTML for a single local task link."
 */
function casabio_menu_local_task($variables) {
  // dpm($variables, '$variables');

  // Make a link from the task element
  $link = $variables['element']['#link'];
  $link['localized_options']['html'] = TRUE;

  // Rename search link text
  switch ($link['path']) {
    case 'search/term':
      $link['title'] = 'Species & other taxa, and categorisations';
      break;

    case 'search/node':
      $link['title'] = 'Observations, collections, and other contributions';
      break;
  }

  $link_markup = l($link['title'], $link['href'], $link['localized_options']);
  // Return the link as a list item
  return '<li>' . $link_markup . '</li>' . "\n";
}
/**
 * Implements theme_menu_local_tasks().
 * "Returns HTML for primary and secondary local tasks."
 */
function casabio_menu_local_tasks($variables) {
  // dpm($variables, '$variables');
  $output = '';
  // If these are primary tasks
  if (!empty($variables['primary'])) {
    $tasks_are_search = substr($variables['primary'][0]['#link']['path'], 0, 7) === 'search/';

    if ($tasks_are_search) {
      $variables['primary']['#prefix'] =
        '<div><ul class="tabs">';
      $variables['primary']['#suffix'] = '</ul></div>';
    }
    else {
      $variables['primary']['#prefix'] =
        '<div class="contextual-links-wrapper"><ul class="contextual-links">';
      $variables['primary']['#suffix'] = '</ul></div>';
    }
    $output .= drupal_render($variables['primary']);
  }
  // If these are secondary tasks
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<ul class="tabs secondary clearfix">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }
  return $output;
}


// function casabio_link($variables) {
//   // dpm($variables, '$variables');

//   // // Allow links to contain HTML

//   // $variables['options']['html'] = TRUE;

//   // $href = check_plain(url($variables['path'], $variables['options']));
//   // $attributes = drupal_attributes($variables['options']['attributes']);
//   // $content = $variables['options']['html'] ? $variables['text'] : check_plain($variables['text']);

//   // return '<a href="' . $href . '"' . $attributes . '>' . $content . '</a>';
// }



/**
 * Display a single views grouping.
 */
function casabio_views_view_grouping($vars) {
  // dpm($vars, '$vars');
  $view = $vars['view'];
  $title = $vars['title'];
  $content = $vars['content'];

  if ((int) $title > 0) {
    $term = taxonomy_term_load($title);
    $term_renderable = taxonomy_term_view($term, 'field_guide');
    $title = drupal_render($term_renderable);
  }

  $output = '<div class="view-grouping">';
  $output .= '<div class="view-grouping-header">' . $title . '</div>';
  $output .= '<div class="view-grouping-content">' . $content . '</div>' ;
  $output .= '</div>';

  return $output;
}