<?php

  namespace Drupal\Casabio\casa_core;
  use Drupal\Casabio\casa_core;



  function site_stats_block_view() {
    $content = '';

    determine_site_stats();

    $iois = get_site_stats_iois();

    $content .= '<ul class="non-list cols-4">';
    foreach ($iois as $name => $info) {
      $val = variable_get('count_' . $name);
      $content .= '<li><strong>' . $info['label'] . '</strong>: ' . $val . '</li>';
    }
    $content .= '</ul>';
    return $content;
  }


  function user_stats_block_view() {
    $content = '';
    if (! (int) arg(1) > 0) {
      return NULL;
    }
    $user = user_load(arg(1));
    $uid = $user->uid;

    $num_pictures = count_nodes_by_user($uid, 'picture');

    $first_id_events = casa_core\historian::getAllHistoryValues('First identification', $uid, TRUE, TRUE);
    $first_identis_count = count($first_id_events);

    $second_id_events = casa_core\historian::getAllHistoryValues('Second identification', $uid, TRUE, TRUE);
    $second_identis_count = count($second_id_events);


    determine_user_achievement('Beginner of first identifications', $user);
    determine_user_achievement('Number of observations submitted', $user);

    $stats = [
      'num_pictures' => [
        'label' => 'Number of pictures',
        'val' => $num_pictures,
        // 'rank' => get_achievement('num_pictures', $num_pictures),
        'rank' => [],
      ],
      'num_observations' => [
        'label' => 'Number of observations',
        'val' => count_nodes_by_user($uid, 'observation'),
        'rank' => [],
      ],
      'num_identifications' => [
        'label' => 'Number of identifications',
        'val' => count_nodes_by_user($uid, 'identification'),
        'rank' => [],
      ],
      'num_taxon_first_identifications' => [
        'label' => 'Number of first observations of taxa',
        'val' => $first_identis_count,
        'rank' => [],
      ],
      'num_taxon_second_identifications' => [
        'label' => 'Number of second observations of taxa',
        'val' => $second_identis_count,
        'rank' => [],
      ],
      'num_identifications_species' => [
        'label' => 'Number of identifications to species level',
        'val' => count(views_get_view_result('identifications_by_user', NULL, $uid, 'species')),
        'rank' => [],
      ],
      'num_identifications_genus' => [
        'label' => 'Number of identifications to genus level',
        'val' => count(views_get_view_result('identifications_by_user', NULL, $uid, 'genus')),
        'rank' => [],
      ],
      'num_identifications_family' => [
        'label' => 'Number of identifications to family level',
        'val' => count(views_get_view_result('identifications_by_user', NULL, $uid, 'family')),
        'rank' => [],
      ],
      'num_unique_sp_obs' => [
        'label' => 'Number of unique species observations',
        'val' => count(views_get_view_result('unique_taxon_obs_user', NULL, $uid)),
        'rank' => [],
      ],
    ];

    $content .= '<ul class="">'; // non-list cols-3
    foreach ($stats as $name => $info) {
      $content .= '<li><strong>' . $info['label'] . '</strong>: '
        . $info['val'];
        if ($info['rank']) {
          // $content .= ' (' . $info['rank']['level'] . ' - ' . $info['rank']['label'] . ')';
        }
      $content .= '</li>';
    }
    $content .= '</ul>';
    return $content;
  }



  // function get_achievement($dimension, $score) {
  //   $dimensions = [
  //     'num_pictures' => [
  //       [
  //         'min' => 0,
  //         'max' => 10,
  //       ],
  //       [
  //         'min' => 10,
  //         'max' => 50,
  //       ],
  //       [
  //         'min' => 50,
  //         'max' => 250,
  //       ],
  //       [
  //         'min' => 250,
  //         'max' => 1500,
  //         'label' => 'Enlightened',
  //       ],
  //       [
  //         'min' => 1500,
  //         'max' => 5000,
  //       ],
  //       [
  //         'min' => 5000,
  //         'max' => NULL,
  //       ],
  //     ],
  //   ];

  //   $level = 1;
  //   foreach ($dimensions[$dimension] as $key => $achievment) {
  //     if ($score >= $achievment['min'] && $score < $achievment['max']) {
  //       $achievment_result = $achievment;
  //       $achievment_result['level'] = $level;
  //       return $achievment_result;
  //     }
  //     $level++;
  //   }
  // }


  /**
   * @param $user
   */
  function determine_user_achievement($dimension, $user) {
    // dpm($user, '$user');

    $achievement_grp_term = taxonomy_get_term_by_name($dimension, 'achievements');
    if (! $achievement_grp_term) {
      return NULL;
    }
    $achievement_grp_tid = array_keys($achievement_grp_term)[0];
    // dpm($achievement_grp->raw(), '$achievement_grp->raw()');
    $achievement_grp = entity_metadata_wrapper('taxonomy_term', $achievement_grp_tid);

    $ranks = taxonomy_get_children($achievement_grp_tid);
    // dpm($ranks, '$ranks');

    if (! $ranks) {
      return NULL;
    }
    
    $user_wrapped = entity_metadata_wrapper('user', $user);

    // Determine the user's current score
    $score = 0;

    switch ($dimension) {
      case 'Beginner of first identifications':
        $first_id_events = casa_core\historian::getAllHistoryValues('First identification', $user->uid, TRUE, TRUE);
        $score = count($first_id_events);
        break;

      case 'Number of observations submitted':
        $score = count_nodes_by_user($user->uid, 'observation');
        break;
      
      default:
        throw new Exception('Dimension ' . $dimension . ' not known.', 1);
        break;
    }

    // Determine the highest rank the user qualifies for

    // The score required of the highest rank qualified for
    $highest_sc = 0;
    $highest_tid = NULL;

    foreach ($ranks as $tid => $rank_raw) {
      $rank = entity_metadata_wrapper('taxonomy_term', $rank_raw);
      $rank_score = $rank->field_score_required->value();
      $qualifies = ($score >= $rank_score);
      // dpm($qualifies, 'qualifies');
      if ($qualifies && ($rank_score >= $highest_sc)) {
        $highest_tid = $tid;
        $highest_sc = $rank_score;
      }
      // dpm($highest_sc, '$highest_sc');
    }

    if ($highest_tid) {
      // Determine if the user has already achieved this
      $current_achievements = $user_wrapped->field_achievements->raw();
      // dpm($current_achievements, '$current_achievements');
      $has_achievement = in_array($highest_tid, $current_achievements);

      if (! $has_achievement) {
        $user_wrapped->field_achievements[] = $highest_tid;
        // dpm($user_wrapped->raw(), '$user_wrapped->raw()');
        // return NULL;
        $user_wrapped->save();
      }
      return TRUE;
    }

    return FALSE;
  }