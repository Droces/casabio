<?php
/**
 * @file
 * Functions that fetch taxonomy term information from external sources like 
 * IUCN and GBIF.
 */

/**
  CONTENTS

  taxa_lookup_form()
  taxa_lookup_multiple_formtaxa_lookup_form_submit()
  taxa_lookup_multiple_form_submit()
  taxa_lookup_multiple()
  taxa_lookup()
  lookup_catalogueoflife()
  lookup_gbif()
  lookup_iucn()
  update_vulnerability()
 */


/**
 * Implements hook_form(). Creates a small form for adding a taxon that CasaBio does not yet have.
 *
 * If CasaBio does not have the taxon, it will be created.
 */
function taxa_lookup_form() {
  $form['description'] = array(
    '#markup' => 'Use this to search for a species (or other taxon) that CasaBio doesn’t currently have. If the species is not found, it will be added to CasaBio.',
  );
  $form['scientific_name'] = array(
    '#title' => t('Scientific name'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#value' => 'Lookup using Catalogue of Life',
    '#type' => 'submit',
    '#name' => 'col',
    // 'text' => array(
    //   '#markup' => 'Search Catalogue of Life',
    // ), // Irrelevant, since D7 FAPI doesn't support <button> elements
  );
  $form['submit'] = array(
    '#value' => 'Lookup using GBIF',
    '#type' => 'submit',
    '#name' => 'gbif',
    // 'text' => array(
    //   '#markup' => 'Search GBIF (Global Biodiversity Information Facility)',
    // ), // Irrelevant, since D7 FAPI doesn't support <button> elements
  );
  return $form;
}


/**
 * Implements hook_form(). Creates a small form for adding a taxon that CasaBio does not yet have.
 *
 * If CasaBio does not have the taxon, it will be created.
 */
function taxa_lookup_multiple_form() {
  $form['description'] = array(
    '#markup' => '<p>Use this to add multiple (or a whole lot) of taxa to CasaBio at once. Each taxon will be checked if it exists in CasaBio, and if not, it will be checked if it exists in the service you select when you submit them. If it exists in that service, it will be added to CasaBio.</p>'
      . '<p>When complete, CasaBio will inform you how many were successfully '
      . 'added, how many were already in CasaBio, and how many were not found in'
      . ' CasaBio or the service and thus were not successfully added.</p>'
  );
  $form['scientific_names'] = array(
    '#title' => t('Scientific names'),
    '#type' => 'textarea',
    '#description' => t('Add each scientific name on a new line.'),
    '#required' => TRUE,
  );
  $form['localities'] = array(
    '#title' => t('Localities'),
    '#type' => 'textfield',
    '#description' => t('OPTIONAL. Localities (such as a country) that these taxa are found in.<br>'
      . 'These must be locality IDs, separated by a semi-colon only.<br>'
      . 'Eg. "31;61". See ' . l('Explore Localities', 'browse/localities/table')),
  );

  $form['update_mode'] = array(
    '#title' => t('Update mode'),
    '#type' => 'select',
    '#options' => array(
        'none' =>     t('Do not update any existing taxa'),
        'empties' =>  t('Update where field values are missing'),
        'all' =>      t('Update all field values'),
       ),
    '#default_value' => 'none',
    '#description' => t('For taxa that are already in CasaBio, choose how they should be updated.'),
  );

  $form['service'] = array(
    '#title' => t('Service'),
    '#type' => 'select',
    '#options' => array(
        'CoL' => t('Catalogue of Life'),
        'gbif' => t('GBIF (Global Biodiversity Information Facility)'),
       ),
    '#default_value' => 'gbif',
    '#description' => t('The taxonomic database that the taxa should be looked up in.'),
  );
  $form['submit'] = array(
    '#value' => 'Lookup and Add',
    '#type' => 'submit',
    // '#name' => 'col',
    // 'text' => array(
    //   '#markup' => 'Search Catalogue of Life',
    // ), // Irrelevant, since D7 FAPI doesn't support <button> elements
  );
  return $form;
}



// function taxa_lookup_form_validate() {}



function taxa_lookup_form_submit($form_id, &$form_state) {
  // dpm($form_id, 'form_id');
  // dpm($form_state, 'form_state');

  $sc_name = $form_state['values']['scientific_name'];
  // dpm($sc_name, 'sc_name');
  $taxa_service = $form_state['triggering_element']['#name'];

  taxa_lookup($sc_name, $taxa_service);
}



function taxa_lookup_multiple_form_submit($form_id, &$form_state) {
  // dpm($form_id, 'form_id');
  // dpm($form_state, 'form_state');

  // Panthera pardus
  // Acinonyx jubatus
  // Hermannia

  // $sc_names = $form_state['values']['scientific_names'];
  $sc_names_string = trim($form_state['values']['scientific_names']);
  $sc_names_untrimmed = explode(PHP_EOL, $sc_names_string); // split on lines
  $sc_names = array_map('trim', $sc_names_untrimmed);
  // dpm($sc_names, '$sc_names');


  $localities_string = trim($form_state['values']['localities']);
  // dpm($localities_string, '$localities_string');
  if ($localities_string) {
    $localities_untrimmed = explode(';', $localities_string); // split on lines
    $localities = array_map('trim', $localities_untrimmed);
    // dpm($localities, '$localities');
  }
  else {
    $localities = NULL;
  }

  $taxa_service = $form_state['values']['service'];
  $update_mode = $form_state['values']['update_mode'];

  taxa_lookup_multiple($sc_names, $taxa_service, $update_mode, $localities);
}



/**
 * @param $taxa
 *   An array of strings; the scientific names of the taxa.
 * 
 * @param string $update_mode
 *   Possible values: 'none', empties', 'all'
 */
function taxa_lookup_multiple($taxa, $taxa_service, $update_mode = NULL, $localities = NULL, $show_messages = TRUE) {
  // dpm($taxa, '$taxa');

  $lookup_existings = [];
  $lookup_updates   = [];
  $lookup_successes = [];
  $lookup_failures  = [];

  $update_existing =  true;
  $service_name =     '';

  if (!$taxa) {
    return NULL;
  }

  foreach ($taxa as $taxon_name) {
    $sc_name = $taxon_name;

    // Check if it exists.
    // $is_taxon_in_casabio = is_taxon_in_casabio($sc_name);
    $taxa_in_casabio = get_taxa_with_name($sc_name, 'is');
    // dpm($taxa_in_casabio, '$taxa_in_casabio');

    $taxon_repr = NULL;
    if ($taxa_in_casabio) {

      $taxon_repr = reset($taxa_in_casabio);

      // $lookup_existings[] = $sc_name;
      $name = ($sc_name === $taxon_name) ? $sc_name
        : $sc_name . ' (' . $taxon_name . ')';
      $lookup_existings[] = l($name, 'taxonomy/term/' . $taxon_repr->tid);

      if ($update_mode === 'none') {
        continue;
      }
    }
    // dpm($taxon_repr, '$taxon_repr');

    $taxon_info;

    if ($taxon_repr) {
      $taxon = taxonomy_term_load($taxon_repr->tid);
      $taxon_wrapped = entity_metadata_wrapper('taxonomy_term', $taxon_repr->tid);
      // dpm($taxon_wrapped->raw(), '$taxon_wrapped->raw()');
      $sc_name = $taxon_wrapped->field_canonical_name->value();
      if (! $sc_name) {
        $sc_name = $taxon_wrapped->label();
      }
      // dpm($sc_name, '$sc_name');
    }
    // dpm($sc_name, '$sc_name');

    switch ($taxa_service) {

      case 'gbif':
        $taxon_info = lookup_gbif($sc_name);
        $service_name = 'GBIF';
        break;

      case 'col':
      default:
        $taxon_info = lookup_catalogueoflife($sc_name);
        $service_name = 'Catalogue of Life';
        break;
    }

    if(!$taxon_info) {
      $lookup_failures[] = $sc_name;
      continue;
    }

    if ($localities) {
      $taxon_info['localities'] = $localities;
    }

    if ($taxon_repr) {
      $term_updated = update_taxon($taxon, $taxon_info, FALSE, $update_mode);
      // dpm($term_updated, '$term_updated');
      if ($term_updated) {
        $name = ($sc_name === $taxon_name) ? $sc_name
          : $sc_name . ' (' . $taxon_name . ')';
        $lookup_updates[] = l($name, 'taxonomy/term/' . $term_updated->getIdentifier());
      }
    }
    else {
      $taxon = create_taxon($taxon_info, FALSE);
      $name = ($sc_name === $taxon_name) ? $sc_name
        : $sc_name . ' (' . $taxon_name . ')';
      $lookup_successes[] = l($name, 'taxonomy/term/' . $taxon->tid);
    }
  }

  if ($lookup_existings && $show_messages) {
    $list_existings = '<ol><li>' . implode('</li><li>', $lookup_existings) . '</li></ol>';
    drupal_set_message('The following taxa already exists in CasaBio:'
      . '<br>' . $list_existings, 'warning', FALSE);
  }

  if ($lookup_updates && $show_messages) {
    $message_params = array('@service' => $service_name);
    $list_updates = '<ol><li>' . implode('</li><li>', $lookup_updates) . '</li></ol>';
    drupal_set_message(t('The following taxa were found on @service '
      . 'and successfully updated:', $message_params)
      . '<br>' . $list_updates, 'status', FALSE);
  }

  if ($lookup_failures && $show_messages) {
    $message_params = array('@service' => $service_name);
    $list_failures = '<ol><li>' . implode('</li><li>', $lookup_failures) . '</li></ol>';
    drupal_set_message(t('The following taxa were not found on @service:', $message_params)
      . '<br>' . $list_failures, 'warning', FALSE);
  }

  if ($lookup_successes && $show_messages) {
    $message_params = array('@service' => $service_name);
    $list_successes = '<ol><li>' . implode('</li><li>', $lookup_successes) . '</li></ol>';
    drupal_set_message(t('The following taxa were found on @service '
      . 'and successfully added to CasaBio:', $message_params)
      . '<br>' . $list_successes, 'status', FALSE);
  }
}


/**
 * Looks up a taxon from an external service, and if found and not in CasaBio, adds it.
 * 
 * @param string $sc_name
 *   The complete scientific name of the taxon to be looked-up. Eg. 'Panthera pardus'
 * @param string $taxa_service
 *   Code of a biodiversity data service. Eg. 'CoL' or 'gbif'
 */
function taxa_lookup($sc_name, $taxa_service) {

  // Check if it exists.
  $is_taxon_in_casabio = is_taxon_in_casabio($sc_name);

  if ($is_taxon_in_casabio) {
    drupal_set_message(t('<em>@taxon</em> already exists in CasaBio.', array('@taxon' => $sc_name)), 'warning', FALSE);
    return NULL;
  }

  $taxon_info = [
    'name' => $sc_name,
  ];

  switch ($taxa_service) {
    case 'CoL':
      $taxon_info = lookup_catalogueoflife($sc_name);
      $service_name = 'Catalogue of Life';
      break;

    case 'gbif':
      $taxon_info = lookup_gbif($sc_name);
      $service_name = 'GBIF';
      break;

    default:
      $taxon_info = lookup_catalogueoflife($sc_name);
      $service_name = 'Catalogue of Life';
      break;
  }

  if(!$taxon_info) {
    $message_params = array('@taxon' => $sc_name, '@service' => $service_name);
    drupal_set_message(t('<em>@taxon</em> was not found on @service.', $message_params), 'warning', FALSE);
    return NULL;
  }
  // dpm($taxon_info, '$taxon_info');

  $message_params = array('@taxon' => $sc_name, '@service' => $service_name);
  drupal_set_message(t('<em>@taxon</em> was found on @service.', $message_params), 'status', FALSE);

  create_taxon($taxon_info);
}



/**
 * @param string $sc_name
 *   The complete scientific name of the taxon to be looked-up. Eg. 'Panthera pardus'
 *
 * @return
 *   An array in the form "['name' = '', 'rank' = '']" if found, or [] if not found.
 */
function lookup_catalogueoflife($sc_name) {
  // Settings
  $year = 2015;
  // $service_name = 'Catalogue of Life';
  $lookup_url = "http://www.catalogueoflife.org"
    . "/annual-checklist/" . $year . "/webservice?"
    . "name=" . str_replace(' ', '+', $sc_name);
  // dpm($lookup_url, 'lookup_url');

  $response = drupal_http_request($lookup_url, array());
  // dpm($response, 'response');

  if (!isset($response->data)) {
    drupal_set_message(t('Lookup failed.'), 'error', FALSE);
    // dpm($response, '$response');
    return NULL;
  }


  $xml = simplexml_load_string($response->data);
  // dpm($xml, 'xml');

  $taxon_info = array();
  $is_found = isset($xml->result[0]);
  // $is_found = TRUE; // For testing only.
  if($is_found) {
    $taxon_info = array(
      'name' => $xml->result[0]->name->__toString(), // $name = 'test'; // testing
      // dpm($name, 'result name');
      'rank' => $xml->result[0]->rank->__toString(), // $rank = 'specum'; // testing
    );
  }
  return $taxon_info;
}



/**
 * @param string $sc_name
 *   The complete scientific name of the taxon to be looked-up. Eg. 'Panthera pardus'.
 *   Alternatively, can be a GBIF key.
 * @param int $num_ancestors
 *   The maxiumum number of ancestors to lookup when running recursively
 *
 * @return
 *   An array in the form "['name' = '', 'rank' = '']" if found, or [] if not found.
 */
function lookup_gbif($sc_name, $num_ancestors = 12) {
  // dpm('lookup_gbif()');
  // dpm($sc_name, '$sc_name');
  // Example: 'http://api.gbif.org/v1/species?name=Abrodictyum+rigidum'

  $is_search;
  if ((int) $sc_name > 0) {
    $is_search = FALSE;
    $lookup_url = "http://api.gbif.org/v1/species/" . $sc_name;
  }
  else {
    $is_search = TRUE;
    $lookup_url = "http://api.gbif.org"
      . "/v1/species?"
      . "name=" . str_replace(' ', '+', $sc_name);
  }
  // dpm($lookup_url, '$lookup_url');

  $response = drupal_http_request($lookup_url, array());
  // dpm($response, 'response');

  if (!isset($response->data)) {
    drupal_set_message(t('Lookup failed. Reason: ' . $response->error), 'error', FALSE);
    // dpm($response, '$response');
    return NULL;
  }


  $json = json_decode($response->data);
  // dpm($json, 'json');

  $taxon_info = array();
  if ($is_search) {
    $is_found = (count($json->results) >= 1);
  }
  else {
    $is_found = TRUE;
  }
  // dpm($is_found, '$is_found');
  // $is_found = TRUE; // For testing only.
  if ($is_found) {
    $result = NULL;
    $results = [];
    if ($is_search) {
      foreach ($json->results as $key => $result_i) {
        if ($result_i->synonym === FALSE) {
          $result = $result_i;
          // break;
          $results[] = $result_i;
        }
      }
    }
    else {
      $result = $json;
    }
    // dpm($result, '$result');



    // if (count($results) > 1) {
    //   dpm($results, '$results');
    // }
    // throw new Exception("Error Processing Request", 1);
    


    // If this taxon has a parent, look for it in CasaBio or create it
    $parent_tid = NULL;
    if (property_exists($result, 'parent')) {
      $parent_matches = get_taxa_with_name($result->parent, 'is');
      // If found in CasaBio
      if ($parent_matches) {
        $parent = reset($parent_matches);
        $parent_tid = $parent->tid; // Needs nid
      }
      else {
        // Create it
        $parent_info = lookup_gbif($result->parentKey, $num_ancestors - 1);
        $parent = create_taxon($parent_info, FALSE);
        $parent_tid = $parent->tid;
      }


      // Update missing fields of the ancestor term_forms
      $do_update_parents = FALSE;
      if ($do_update_parents) {
        $taxon_info = lookup_gbif($result->parent, $num_ancestors - 1);
        $parent_updated = update_taxon(taxonomy_term_load($parent_tid), $taxon_info, FALSE, 'empties');
      }
    }

    $taxon_info = array(
      'name' =>     $result->canonicalName,
      'sc_name' =>  $result->scientificName,
      'rank' =>     '',
      'parent' =>   $parent_tid,
      'key' =>      $result->key,
      'common_names' => NULL,
    );

    if (property_exists($result, 'rank')) {
      $taxon_info['rank'] = $result->rank;
    }
    if (property_exists($result, 'canonicalName')) {
      $taxon_info['canonical_name'] = $result->canonicalName;
    }
    if (property_exists($result, 'vernacularName')) {
      $taxon_info['common_names'] = [$result->vernacularName];
    }
    // dpm($taxon_info, '$taxon_info');


    // Check the number of children
    $get_num_children = TRUE;
    if ($get_num_children) {
      $lookup_url = "http://api.gbif.org"
        . "/v1/species/" . $taxon_info['key'] . '/children';
        // dpm($lookup_url, '$lookup_url');

      $response = drupal_http_request($lookup_url, array());

      if (isset($response->data)) {
        $json = json_decode($response->data);
        // dpm($json, '$json');
        $taxon_info['num_children'] = sizeof($json->results);
      }
    }
  }


  // dpm($taxon_info, '$taxon_info');
  return $taxon_info;
}



/**
 * @param string $sc_name
 *   The complete scientific name of the taxon to be looked-up. Eg. 'Panthera pardus'
 *
 * @return
 *   An array in the form "['vulnerability' => '', 'vulnerability_criteria' => '']".
 */
function lookup_iucn($sc_name) {

  // See https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/Status_iucn3.1.svg/1000px-Status_iucn3.1.svg.png
  
  // ** EXTINCT **
  // EX - Extinct (black)
  // EW - Extinct in the Wild (black)

  // ** THREATENED **
  // CR - Critically Endangered (red)
  // EN - Endangered (orange)
  // VU - Vulnerable (yellow)

  // ** OTHER **
  // NE - Not Evaluated (grey)
  // DD - Data Deficient (grey)

  // ** LOWER RISK **
  // NT - Near Threatened (lime)
  // LC - Least Concern (green)

  // Extinct (EX)               – No known individuals remaining.
  // Extinct in the wild (EW)   – Known only to survive in captivity, or as a naturalized population outside its historic range.
  // Critically endangered (CR) – Extremely high risk of extinction in the wild.
  // Endangered (EN)            – High risk of extinction in the wild.
  // Vulnerable (VU)            – High risk of endangerment in the wild.
  // Near threatened (NT)       – Likely to become endangered in the near future.
  // Least concern (LC)         – Lowest risk. Does not qualify for a more at-risk category. Widespread and abundant taxa are included in this category.
  // Data deficient (DD)        – Not enough data to make an assessment of its risk of extinction.
  // Not evaluated (NE)         – Has not yet been evaluated against the criteria.

  // $sc_name = 'loxodonta africana';
  // dpm($sc_name, 'sc_name');

  $token = get_site_setting('iucn_api_token');
  // dpm($token, '$token');
  $lookup_url =  'http://apiv3.iucnredlist.org/api/v3/species/'
    . str_replace(' ', '%20', $sc_name)
    . '?token=' . $token;
  // dpm($lookup_url, 'lookup_url');

  $response = drupal_http_request($lookup_url, array());
  // dpm($response, 'response');

  if (!isset($response->data)) {
    drupal_set_message(t('Lookup failed.'), 'error', FALSE);
    // dpm($response, '$response');
    return NULL;
  }

  $json = json_decode($response->data);
  // dpm($json, 'json');

  $taxon_info = array();
  $is_found = ! empty($json->result);
  // $is_found = TRUE; // For testing only.
  if ($is_found) {
    $result_info = $json->result[0];
    // dpm($result_info, 'result_info');
    $taxon_info = array(
      'vulnerability' => $result_info->category,
      'vulnerability_criteria' => $result_info->criteria,
    );
  }
  // dpm($taxon_info, '$taxon_info');
  return $taxon_info;
}



/**
 * Calls lookup_iucn() on the taxon.
 * 
 * @param EntityMetadataWrapper
 */
function update_vulnerability($taxon) {
  // return NULL; // Can't work until we get a key

  // $sc_name = $taxon->field_scientific_name->value();
  $sc_name = strtolower($taxon->label());
  // dpm($sc_name, '$sc_name');
  $taxon_info = lookup_iucn($sc_name);
  if ($taxon_info) {
    // dpm($taxon_info, '$taxon_info');
    $taxon->field_vulnerability->set($taxon_info['vulnerability']);
  }
  else {
    // Set it to 'Not evaluated'.
    $taxon->field_vulnerability->set('NE');
  }
  $taxon->save();
}



/**
 * Fetch GBIF's key (ID) of a taxon.
 */
function get_gbif_key($tid) {
  // dpm('get_gbif_key()');
  $term = entity_metadata_wrapper('taxonomy_term', $tid);
  $sc_name = $term->label();

  $gbif_key = '';

  $external_refs = json_decode($term->field_external_references->value());
  // dpm($external_refs, '$external_refs');

  if ($external_refs) {
    if (property_exists($external_refs, 'gbif')) {
      if (property_exists($external_refs->gbif, 'key')) {
        $gbif_key = $external_refs->gbif->key;
        return $gbif_key;
      }
    }
  }

  if (! $gbif_key) {
    // Query the GBIF web service for the key

    // dpm('Performing GBIF key lookup');
    $taxon_info = lookup_gbif($sc_name);
    // dpm($taxon_info, '$taxon_info');

    if (! $taxon_info) {
      return NULL;
    }

    $gbif_key = $taxon_info['key'];

    // if (! $gbif_key) {
    //   return NULL;
    // }

    if (! $external_refs) {
      $external_refs = new stdClass();;
    }
    if (! property_exists($external_refs, 'gbif')) {
      $external_refs->gbif = new stdClass();
    }
    if (! property_exists($external_refs->gbif, 'key')) {
      $external_refs->gbif->key = $gbif_key;
    }
    // dpm($external_refs, '$external_refs after');
    $term->field_external_references->set(json_encode($external_refs));
    $term->save();
  }
  return $gbif_key;
}