<?php
/**
 * @file
 * blocks_not_views_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function blocks_not_views_blocks_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-maintainer_contribution_options'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'machine_name' => 'maintainer_contribution_options',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'contribute-other',
    'roles' => array(
      'Administrator' => 3,
      'Maintainer' => 5,
    ),
    'themes' => array(
      'casabio' => array(
        'region' => 'content',
        'status' => 1,
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
    'title' => 'Maintainer contribution options',
    'visibility' => 1,
  );

  $export['browse-browse_chooser_form'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'browse_chooser_form',
    'module' => 'browse',
    'node_types' => array(),
    'pages' => 'browse',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Choose',
    'visibility' => 1,
  );

  $export['casa_node_mgt-habitat_form'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'habitat_form',
    'module' => 'casa_node_mgt',
    'node_types' => array(),
    'pages' => 'contribute/habitats*',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => -18,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => 'Add a Habitat Record',
    'visibility' => 1,
  );

  $export['comment-recent'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'recent',
    'module' => 'comment',
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
        'weight' => -22,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['context_ui-devel'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'devel',
    'module' => 'context_ui',
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

  $export['context_ui-editor'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'editor',
    'module' => 'context_ui',
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

  $export['contribute-steps'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'steps',
    'module' => 'contribute',
    'node_types' => array(),
    'pages' => 'contribute/upload
contribute/multiple-observations/group/*
contribute/multiple-observations/observation-info/*',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'highlighted',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => -31,
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

  $export['devel-execute_php'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'execute_php',
    'module' => 'devel',
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
        'weight' => -10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['devel-switch_user'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'switch_user',
    'module' => 'devel',
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
        'weight' => 2,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['edit_selected-edit_selected_buttons'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'edit_selected_buttons',
    'module' => 'edit_selected',
    'node_types' => array(),
    'pages' => 'contribute/upload
contribute/multiple-observations/picture-info*
contribute/multiple-observations/observation-info*',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'toolbar_1',
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

  $export['group_selected-group_selected_buttons'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'group_selected_buttons',
    'module' => 'group_selected',
    'node_types' => array(),
    'pages' => 'contribute/multiple-observations/group*',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'toolbar_1',
        'status' => 1,
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

  $export['group_selected-group_selected_secondary_toolbar'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'group_selected_secondary_toolbar',
    'module' => 'group_selected',
    'node_types' => array(),
    'pages' => 'contribute/multiple-observations/group*',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => -33,
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

  $export['menu-devel'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'devel',
    'module' => 'menu',
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
        'weight' => -13,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-features'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'features',
    'module' => 'menu',
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

  $export['menu-menu-contribute'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'menu-contribute',
    'module' => 'menu',
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
        'weight' => -15,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-contribute-stages'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'menu-contribute-stages',
    'module' => 'menu',
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
        'weight' => -14,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-my'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'menu-my',
    'module' => 'menu',
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
        'weight' => -4,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu_block-1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 1,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'casabio' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => -11,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => -7,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu_block-2'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 2,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'casabio' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => 0,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => -5,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu_block-3'] = array(
    'cache' => -1,
    'css_class' => 'steps',
    'custom' => 0,
    'delta' => 3,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => 'contribute/upload
contribute/multiple-observations/*',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => -17,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => -6,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['node-recent'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'recent',
    'module' => 'node',
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
        'region' => 'dashboard_inactive',
        'status' => 1,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['node-syndicate'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'syndicate',
    'module' => 'node',
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
        'weight' => 3,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['openlayers_block-10cd987e_mapblock'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '10cd987e_mapblock',
    'module' => 'openlayers_block',
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

  $export['openlayers_block-1f40eca1_mapblock'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '1f40eca1_mapblock',
    'module' => 'openlayers_block',
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
        'weight' => -1,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['openlayers_block-a3921b13_mapblock'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'a3921b13_mapblock',
    'module' => 'openlayers_block',
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

  $export['search-form'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => -1,
      ),
      'petal' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'petal',
        'weight' => -16,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['shortcut-shortcuts'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'shortcuts',
    'module' => 'shortcut',
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
        'weight' => 1,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-help'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'help',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => 0,
      ),
      'petal' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'petal',
        'weight' => 5,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'main',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => -31,
      ),
      'petal' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'petal',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => -13,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => -9,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-management'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'management',
    'module' => 'system',
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
        'weight' => -8,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-navigation'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'navigation',
    'module' => 'system',
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
        'weight' => -3,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-powered-by'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'powered-by',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => 10,
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

  $export['system-user-menu'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'user-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'casabio',
        'weight' => -14,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 5,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => 'home',
    'roles' => array(),
    'themes' => array(
      'casabio' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'casabio',
        'weight' => -10,
      ),
      'petal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'petal',
        'weight' => 4,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['user-new'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'new',
    'module' => 'user',
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
        'weight' => -14,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-online'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'online',
    'module' => 'user',
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
        'weight' => -15,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
