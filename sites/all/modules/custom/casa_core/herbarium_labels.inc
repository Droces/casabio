<?php

/**
 * CONTENTS
 *
 * herbarium_labels_callback()
 * herbarium_labels_printable_callback()
 * herbarium_labels_get_nids()
 * herbarium_labels_render()
 */
namespace Drupal\Casabio\casa_core;



function _herbarium_labels_callback($collection_nid = '') {
  if (! $collection_nid) {
    return NULL;
  }

  $nids = herbarium_labels_get_nids($collection_nid);
  // dpm($nids, '$nids');

  $output = [
    'fields' => [],
    'options' => [],
    'nodes' => [],
  ];
  $output['fields'] = [
    'herbarium_title' => [
      '#markup' => '<div><p><label for="herbarium">Type the label title</label>'
        . '<input type="text" id="herbarium" name="herbarium" placeholder="Eg. Herbarium name"></p></div>',
    ],
    'nids' => [
      '#markup' => '<div><p><label for="nids">Observation ids for print page</label>'
        . '<input type="text" id="nids" name="nids" value="' . implode(',', $nids) . '"></p></div>',
    ],
  ];
  $output['options'] = [
    '#prefix' => '<p>',
    '#suffix' => '</p>',
    'remove_all' => [
      '#markup' => '<button id="remove_all">Remove all</button>',
    ],
    'add_all' => [
      '#markup' => '<button id="add_all">Add all</button>',
    ],
    'add_spec_numbered' => [
      '#markup' => '<button id="add_spec_numbered">Add numbered</button>',
    ],
    'print_link' => [
      '#markup' => l('View printable version', current_path() . '/printable', 
        ['attributes' => ['class' => ['printables']]]),
    ],
  ];
  $output['nodes'] = [
    'herbarium_labels' => [
      '#markup' => herbarium_labels_render($nids),
    ],
  ];

  return $output;
}



function _herbarium_labels_printable_callback($collection_nid = '') {
  if (! $collection_nid) {
    return NULL;
  }

  $print_css = drupal_get_path('module', 'casa_core') . '/print.css';
  $print_css_tag = '<link rel="stylesheet" type="text/css" href="' . base_path() . $print_css . '"></link>';

  $nids = herbarium_labels_get_nids($collection_nid);

  return $print_css_tag . herbarium_labels_render($nids);
}



/**
 * Gets nids of herbarium labels to be shown; either from a URL parameter, or from the user's collection specified.
 */
function herbarium_labels_get_nids($collection_nid) {
  global $user;
  // $collection_nid = '72953';
  $range_max = 5000;

  $collection = entity_metadata_wrapper('node', $collection_nid);
  if (! $user->uid === $collection->author->uid->value()) {
    drupal_set_message(t("You may only view your own collections"), 'error', FALSE);
  }

  $nids = [];

  // Get the URL parameters
  $query_params = drupal_get_query_parameters();
  
  if ($query_params) {
    if (array_key_exists('nids', $query_params)) {
      $nids = explode(',', $query_params['nids']);
    }
  }

  if (! $nids) {
    // $observations = get_nodes_by_user($user->uid, 'observation', $collection_nid, 
    //   $range_max, []);
    $observations = get_observations_referencing_collection($collection_nid);
    // dpm($observations, '$observations');
    $nids = array_keys($observations);
  }
  return $nids;
}


/**
 * Creates rendered markup of herbarium labels for the given nids.
 */
function herbarium_labels_render($nids) {
  $content = '';

  // Get the URL parameters
  $query_params = drupal_get_query_parameters();

  // Builds markup for a field
  function field($label, $value, $options = []) {
    $class = ['field'];
    if ($options) {
      if (array_key_exists('attributes', $options)) {
        if (array_key_exists('class', $options['attributes'])) {
          $class = array_merge($class, $options['attributes']['class']);
        }
      }
    }

    if ($label) {
      $label .= ': ';
    }
    $allow_empty = FALSE;
    if (array_key_exists('allow_empty', $options)) {
      $allow_empty = $options['allow_empty'] ? TRUE : FALSE;
    }
    return '<p class="' . implode(' ', $class) . '">' . label($label)
      . value($value, $allow_empty) .'</p>';
  }

  function label($text) {
    return '<span class="name" contenteditable="true">' . $text . '</span>';
  }

  function value($text, $allow_empty) {
    if (! $text) {
      $text = $allow_empty ? '' : '[no value]';
    }
    return '<span class="value" contenteditable="true">' . $text . '</span>';
  }

  foreach ($nids as $nid) {
    $observation = entity_metadata_wrapper('node', $nid);
    // dpm($observation, '$observation');

    $specimen_id = $observation->field_specimen_id->value();
    // $content .= field('Collector number', $specimen_id);

    $content .= '<article class="printable" data-type="observation" data-view-mode="printable"'
      . ' data-specimen_id="' . $specimen_id . '"">';
    // dpm($query_params, '$query_params');

    // Herbarium name

    if ($query_params) {
      if (array_key_exists('herbarium', $query_params)) {
        $content .= field('', $query_params['herbarium'], 
          [
            'attributes' => ['class' => ['title']],
            'allow_empty' => TRUE,
          ]); // eg. Family Genus species
      }
    }

    $family = \get_family($observation);
    // dpm($family, '$family');

    // $content .= field('Title', $observation->label());
    $provis_name = $observation->label();

    if ($family) {
      $family_name = $family->name;
      $provis_name = strtoupper($family_name) . ' <em>' . $provis_name . '</em>';
    }

    $content .= '<button class="remove" data-nid="' . $nid . '">remove</button>'; // eg. Family Genus species

    $content .= field('Provisional name', $provis_name, ['allow_empty' => TRUE,]); // eg. Family Genus species

    $content .= field('Collector', 
      $observation->field_observer_name->value() . ' <strong>Num. </strong>' . $specimen_id);

    $content .= field('Date', date('j M Y', ($observation->field_date_observed->value())));

    $locality_text = get_localities_hierarchical($observation);
    if ($locality_text) {
      $content .= field('Localities', $locality_text); // eg. South Africa, W. Cape, Cape Town, Rondebosch Common
    }

    $location = $observation->field_location->value();
    $lat_label = ($location['lat'] > 0) ? 'N' : 'S';
    $lon_label = ($location['lon'] > 0) ? 'E' : 'W';
    $coordinates = 
      round(abs($location['lon']), 5) . '&deg;' . $lon_label . ', '
      . round(abs($location['lat']), 5) . '&deg;' . $lat_label . '; Elev: '
      . round($observation->field_elevation->value(), 0) . 'm';

    if (! $location) {
      $coordinates = '';
    }
    $content .= field('Coordinates', $coordinates); // eg. (decimal degrees)

    // $content .= field('Elevation', 
    //   round($observation->field_elevation->value(), 0) . 'm'); // eg. South Africa, W. Cape, Cape Town, Rondebosch Common
    
    // $content .= field('Altitude', '');

    $body = $observation->body->value()['value'];
    $content .= field('Description / notes', $body);
    $content .= field('Filenames', $observation->field_filenames->value());

    // $content .= field('Habitat info', '');
    $content .= field('CasaBio number', $observation->getIdentifier());

    $pictures_markup = '';
    $pictures = $observation->field_pictures_observation->value();
    foreach ($pictures as $picture_raw) {
      $picture = entity_metadata_wrapper('node', $picture_raw);
      $image = $picture->field_image->value();
      // dpm($image, '$image');
      $picture_renderable = theme('image_style', array(
        'style_name' =>'thumbnail',
        'path' => $image['uri'],
      ));
      // dpm($picture_renderable, '$picture_renderable');
      $pictures_markup .= $picture_renderable;
    }
    $content .= field('', $pictures_markup);

    $content .= '</article>';
  }

  return $content;
}