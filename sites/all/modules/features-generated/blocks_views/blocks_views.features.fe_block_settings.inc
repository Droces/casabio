<?php
/**
 * @file
 * blocks_views.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function blocks_views_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views--exp-pictures_map-feed_1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '-exp-pictures_map-feed_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'browse/pictures/map',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => -28,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-1098a3e77f89ec86c72349ecded49ae1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '1098a3e77f89ec86c72349ecded49ae1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => 0,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-2588ed9bc64b6686115eba5460025e79'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '2588ed9bc64b6686115eba5460025e79',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => 0,
      ),
      'petal' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'petal',
        'weight' => -25,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-654f89e3aab72bf17e13abf68ab8cc42'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '654f89e3aab72bf17e13abf68ab8cc42',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'observations*',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => 0,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-6a23656c84d4899dc1ac6f75740c035e'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '6a23656c84d4899dc1ac6f75740c035e',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'browse',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => -14,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-73a7e487b9876f5e0e74dfcec31c936b'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '73a7e487b9876f5e0e74dfcec31c936b',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => 0,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-890d731c11f548f12a8b03e269efe7b9'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '890d731c11f548f12a8b03e269efe7b9',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => 0,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-900575682474a0a9e2a34f4c80141f56'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '900575682474a0a9e2a34f4c80141f56',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'browse',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => -13,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-a63079788b0d983bea5a09b9eaa5671b'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'a63079788b0d983bea5a09b9eaa5671b',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => 0,
      ),
      'petal' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'petal',
        'weight' => -23,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-collection_observations-block_1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'collection_observations-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'collections/*',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => -23,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-dashboard_current_user-block_1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'dashboard_current_user-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => 0,
      ),
      'petal' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'petal',
        'weight' => -17,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-dashboard_summary_terms-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'dashboard_summary_terms-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => 0,
      ),
      'petal' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'petal',
        'weight' => -24,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-e3fe442c287db409b744e3397882a8f3'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'e3fe442c287db409b744e3397882a8f3',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => 0,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-observations_of_taxon-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'observations_of_taxon-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'taxa/*',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => -19,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-pictures_map-block_1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'pictures_map-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'browse/pictures/map',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => -25,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-summary_of_user_s_content-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'summary_of_user_s_content-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'my/contributions',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => -30,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 7,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-taxon_observations_map-block_1'] = array(
    'cache' => -1,
    'css_class' => 'left',
    'custom' => 0,
    'delta' => 'taxon_observations_map-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'taxonomy/term/*',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => -25,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-user_content_summary-block_1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'user_content_summary-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'users*',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => 0,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-user_observations-block_1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'user_observations-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'my/contributions',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => -21,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-user_pictures-block_1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'user_pictures-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'my/contributions',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => -20,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-user_s_collections-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'user_s_collections-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'my/contributions',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => -22,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
