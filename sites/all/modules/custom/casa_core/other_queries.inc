<?php
/**
 * @file
 * 
 */

function get_users() {
  $query = new EntityFieldQuery;
  $query
    ->entityCondition('entity_type', 'user')
    ->propertyCondition('status',1)
    // ->range(0, 1) // Fetch just one
  ;

  $result = $query->execute();
  // dpm($result, '$result');

  $users = isset($result['user']) ? $result['user'] : [];
  return $users;
}



function ml_data_images_callback($num_results = 10, $starting_result = 0) {

  $myview = views_get_view('ml_data_images');
  $myview->set_display('default');
  $myview->set_items_per_page(10); // Get the pagination page 3 
  $myview->set_offset(2);
  $myview->set_current_page(1);
  $myview->pre_execute();
  $myview->execute();
  $results = $myview->result;

  // $results = views_get_view_result('ml_data_images');
  dpm($results, '$results');
  throw new Exception("Error Processing Request", 1);
  

  $output = [];
  // for ($i = $starting_result; $i < $starting_result + $num_results; $i++) { 
  //   $picture_raw = $results[$i];
  foreach ($results as $key => $picture_raw) {

    // dpm($picture_raw, '$picture_raw');
    $picture = entity_metadata_wrapper('node', $picture_raw->nid);
    // dpm($picture->raw(), '$picture->raw()');
    $file = $picture->field_image->raw();
    // dpm($file, '$file');
    $observation = get_observation_referencing_pic($picture_raw->nid);
    // dpm($observation, '$observation');
    if (! $observation) {
      continue;
    }

    $identification = calc_most_reliable_comm_identi($observation);
    if (! $identification) {
      continue;
    }
    // dpm($identification, '$identification');

    $taxon = $identification->field_identified_species->value();
    dpm($taxon, '$taxon');
    if (! $taxon) {
      continue;
    }

    $output_item = [
      'picture_id' => $picture_raw->nid,
      'medium' => image_style_url('medium', $file['uri']),
      'medium_square' => image_style_url('medium_square', $file['uri']),
      'observation' => $observation->nid,
      'taxon' => $taxon->tid,
    ];

    $rank_val = $taxon->field_taxon_rank;
    if ($rank_val) {
      $output_item['rank'] = $rank_val[LANGUAGE_NONE][0]['value'];
    }

    $parent = taxonomy_get_parents($taxon->tid);
    // dpm($parent, '$parent');
    if ($parent) {
      $output_item['parent'] = array_keys($parent)[0];

      $parent_parent = taxonomy_get_parents($output_item['parent']);
      // dpm($parent_parent, '$parent_parent');
      if ($parent_parent) {
        $output_item['parent_parent'] = array_keys($parent_parent)[0];
      }
    }

    $output[] = $output_item;
  }
  // dpm($output, '$output');
  
  $result = array('data' => $output);
  $response = array('#type' => 'ajax', '#commands' => $result);
  return $response;
}