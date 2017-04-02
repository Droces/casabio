<?php
/**
 * @file
 * menus_contribute_and_my.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function menus_contribute_and_my_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-contribute.
  $menus['menu-contribute'] = array(
    'menu_name' => 'menu-contribute',
    'title' => 'Contribute',
    'description' => 'Actions that logged-in users can perform to provide content and help to CasaBio',
  );
  // Exported menu: menu-contribute-stages.
  $menus['menu-contribute-stages'] = array(
    'menu_name' => 'menu-contribute-stages',
    'title' => 'Contribute stages',
    'description' => 'The pages that form part of the contribution process.',
  );
  // Exported menu: menu-my.
  $menus['menu-my'] = array(
    'menu_name' => 'menu-my',
    'title' => 'My',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Actions that logged-in users can perform to provide content and help to CasaBio');
  t('Contribute');
  t('Contribute stages');
  t('My');
  t('The pages that form part of the contribution process.');

  return $menus;
}
