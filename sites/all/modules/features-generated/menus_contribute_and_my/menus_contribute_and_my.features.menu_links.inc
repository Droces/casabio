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
  t('Group');
  t('Profile');
  t('Upload');

  return $menu_links;
}
