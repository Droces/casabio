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

  // Exported menu link: menu-contribute_span-class-icon-addcirclespan-other:node/62095.
  $menu_links['menu-contribute_span-class-icon-addcirclespan-other:node/62095'] = array(
    'menu_name' => 'menu-contribute',
    'link_path' => 'node/62095',
    'router_path' => 'node/%',
    'link_title' => '<span class=" icon-add_circle"></span> Other',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
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
  // Exported menu link: menu-contribute_span-class-icon-helpspan-request:node/14.
  $menu_links['menu-contribute_span-class-icon-helpspan-request:node/14'] = array(
    'menu_name' => 'menu-contribute',
    'link_path' => 'node/14',
    'router_path' => 'node/%',
    'link_title' => '<span class=" icon-help"></span> Request',
    'options' => array(
      'attributes' => array(
        'title' => 'Request Addition or Alteration',
      ),
      'html' => 1,
      'identifier' => 'menu-contribute_span-class-icon-helpspan-request:node/14',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
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
  // Exported menu link: menu-contribute_span-classicon-photolibraryspan-multiple-observations:contribute/upload.
  $menu_links['menu-contribute_span-classicon-photolibraryspan-multiple-observations:contribute/upload'] = array(
    'menu_name' => 'menu-contribute',
    'link_path' => 'contribute/upload',
    'router_path' => 'contribute/upload',
    'link_title' => '<span class="icon-photo_library"></span> Multiple observations',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'html' => 1,
      'identifier' => 'menu-contribute_span-classicon-photolibraryspan-multiple-observations:contribute/upload',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-my_span-classicon-accountboxspan-profile:user.
  $menu_links['menu-my_span-classicon-accountboxspan-profile:user'] = array(
    'menu_name' => 'menu-my',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => '<span class="icon-account_box"></span> Profile',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
      'html' => 1,
      'identifier' => 'menu-my_span-classicon-accountboxspan-profile:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-my_span-classicon-assessmentspan-contributions:node/7.
  $menu_links['menu-my_span-classicon-assessmentspan-contributions:node/7'] = array(
    'menu_name' => 'menu-my',
    'link_path' => 'node/7',
    'router_path' => 'node/%',
    'link_title' => '<span class="icon-assessment"></span> Contributions',
    'options' => array(
      'attributes' => array(
        'title' => 'Everything you have contributed to CasaBio',
      ),
      'html' => 1,
      'identifier' => 'menu-my_span-classicon-assessmentspan-contributions:node/7',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<span class=" icon-add_circle"></span> Other');
  t('<span class=" icon-help"></span> Request');
  t('<span class="icon-account_box"></span> Profile');
  t('<span class="icon-assessment"></span> Contributions');
  t('<span class="icon-image"></span> An observation');
  t('<span class="icon-photo_library"></span> Multiple observations');

  return $menu_links;
}
