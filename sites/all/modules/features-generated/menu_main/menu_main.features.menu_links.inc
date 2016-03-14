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
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_span-classicon-info2span-about:node/1.
  $menu_links['main-menu_span-classicon-info2span-about:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => '<span class="icon-info2"></span> About',
    'options' => array(
      'identifier' => 'main-menu_span-classicon-info2span-about:node/1',
      'attributes' => array(),
      'html' => 1,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_span-classicon-lifebuoyspan-help:node/10.
  $menu_links['main-menu_span-classicon-lifebuoyspan-help:node/10'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/10',
    'router_path' => 'node/%',
    'link_title' => '<span class="icon-lifebuoy"></span> Help',
    'options' => array(
      'identifier' => 'main-menu_span-classicon-lifebuoyspan-help:node/10',
      'attributes' => array(
        'title' => '',
      ),
      'html' => 1,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
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
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_span-classicon-viewlistspan-browse:node/11.
  $menu_links['main-menu_span-classicon-viewlistspan-browse:node/11'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/11',
    'router_path' => 'node/%',
    'link_title' => '<span class="icon-view_list"></span> Browse',
    'options' => array(
      'attributes' => array(
        'title' => 'Find pictures, observations, collections, habitats, etc.',
      ),
      'identifier' => 'main-menu_span-classicon-viewlistspan-browse:node/11',
      'html' => 1,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<span class="icon-info2"></span> About');
  t('<span class="icon-lifebuoy"></span> Help');
  t('<span class="icon-mail_outline"></span> Contact');
  t('<span class="icon-view_list"></span> Browse');
  t('Home');

  return $menu_links;
}