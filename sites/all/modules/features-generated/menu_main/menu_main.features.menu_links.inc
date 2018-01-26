<?php
/**
 * @file
 * menu_main.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function menu_main_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_home:<front>.
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_latest:latest.
  $menu_links['main-menu_latest:latest'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'latest',
    'router_path' => 'latest',
    'link_title' => 'Latest',
    'options' => array(
      'identifier' => 'main-menu_latest:latest',
      'attributes' => array(
        'title' => 'See the latest contributions to CasaBio',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_span-classicon-mailoutlinespan-contact:contact.
  $menu_links['main-menu_span-classicon-mailoutlinespan-contact:contact'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => '<span class="icon-mail_outline"></span> Contact',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_span-classicon-mailoutlinespan-contact:contact',
      'html' => 1,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<span class="icon-mail_outline"></span> Contact');
  t('Home');
  t('Latest');

  return $menu_links;
}
