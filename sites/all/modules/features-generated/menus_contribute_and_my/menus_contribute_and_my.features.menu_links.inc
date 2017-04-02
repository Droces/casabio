<?php
/**
 * @file
 * menus_contribute_and_my.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function menus_contribute_and_my_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-contribute-stages_group:contribute/multiple-observations/group.
  $menu_links['menu-contribute-stages_group:contribute/multiple-observations/group'] = array(
    'menu_name' => 'menu-contribute-stages',
    'link_path' => 'contribute/multiple-observations/group',
    'router_path' => 'contribute/multiple-observations/group',
    'link_title' => 'Group',
    'options' => array(
      'attributes' => array(
        'title' => 'Group pictures into observations',
      ),
      'identifier' => 'menu-contribute-stages_group:contribute/multiple-observations/group',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-contribute-stages_upload:contribute/upload.
  $menu_links['menu-contribute-stages_upload:contribute/upload'] = array(
    'menu_name' => 'menu-contribute-stages',
    'link_path' => 'contribute/upload',
    'router_path' => 'contribute/upload',
    'link_title' => 'Upload',
    'options' => array(
      'attributes' => array(
        'title' => 'Submit multiple images to CasaBio.',
      ),
      'identifier' => 'menu-contribute-stages_upload:contribute/upload',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-contribute_request:node/73552.
  $menu_links['menu-contribute_request:node/73552'] = array(
    'menu_name' => 'menu-contribute',
    'link_path' => 'node/73552',
    'router_path' => 'node/%',
    'link_title' => 'Request',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-contribute_request:node/73552',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-contribute_span-class-icon-addcirclespan-other:node/62095.
  $menu_links['menu-contribute_span-class-icon-addcirclespan-other:node/62095'] = array(
    'menu_name' => 'menu-contribute',
    'link_path' => 'node/62095',
    'router_path' => 'node/%',
    'link_title' => '<span class=" icon-add_circle"></span> Other',
    'options' => array(
      'attributes' => array(),
      'html' => 1,
      'identifier' => 'menu-contribute_span-class-icon-addcirclespan-other:node/62095',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-contribute_span-classicon-imagespan-an-observation:contribute/observation.
  $menu_links['menu-contribute_span-classicon-imagespan-an-observation:contribute/observation'] = array(
    'menu_name' => 'menu-contribute',
    'link_path' => 'contribute/observation',
    'router_path' => 'contribute/observation',
    'link_title' => '<span class="icon-image"></span> An observation',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'html' => 1,
      'identifier' => 'menu-contribute_span-classicon-imagespan-an-observation:contribute/observation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-contribute_span-classicon-photolibraryspan-observations:contribute/upload.
  $menu_links['menu-contribute_span-classicon-photolibraryspan-observations:contribute/upload'] = array(
    'menu_name' => 'menu-contribute',
    'link_path' => 'contribute/upload',
    'router_path' => 'contribute/upload',
    'link_title' => '<span class="icon-photo_library"></span> Observations',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'html' => 1,
      'identifier' => 'menu-contribute_span-classicon-photolibraryspan-observations:contribute/upload',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-my_profile:user.
  $menu_links['menu-my_profile:user'] = array(
    'menu_name' => 'menu-my',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Profile',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
      'html' => 1,
      'identifier' => 'menu-my_profile:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<span class=" icon-add_circle"></span> Other');
  t('<span class="icon-image"></span> An observation');
  t('<span class="icon-photo_library"></span> Observations');
  t('Group');
  t('Profile');
  t('Request');
  t('Upload');

  return $menu_links;
}
