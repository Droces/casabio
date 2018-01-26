<?php
/**
 * @file
 * menu_admin.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function menu_admin_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_admin:<front>.
  $menu_links['management_admin:<front>'] = array(
    'menu_name' => 'management',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Admin',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_admin:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'management_content:admin/content',
  );
  // Exported menu link: management_collections:admin/collections.
  $menu_links['management_collections:admin/collections'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/collections',
    'router_path' => 'admin/collections',
    'link_title' => 'Collections',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_collections:admin/collections',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'management_admin:<front>',
  );
  // Exported menu link: management_habitat:node/add/habitat.
  $menu_links['management_habitat:node/add/habitat'] = array(
    'menu_name' => 'management',
    'link_path' => 'node/add/habitat',
    'router_path' => 'node/add',
    'link_title' => 'Habitat',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_habitat:node/add/habitat',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'management_add:node/add',
  );
  // Exported menu link: management_identifications:admin/identifications.
  $menu_links['management_identifications:admin/identifications'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/identifications',
    'router_path' => 'admin/identifications',
    'link_title' => 'Identifications',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_identifications:admin/identifications',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'management_admin:<front>',
  );
  // Exported menu link: management_locality:admin/structure/taxonomy/locality.
  $menu_links['management_locality:admin/structure/taxonomy/locality'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/taxonomy/locality',
    'router_path' => 'admin/structure/taxonomy/%',
    'link_title' => 'Locality',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_locality:admin/structure/taxonomy/locality',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'management_add:node/add',
  );
  // Exported menu link: management_observations:admin/observations.
  $menu_links['management_observations:admin/observations'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/observations',
    'router_path' => 'admin/observations',
    'link_title' => 'Observations',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_observations:admin/observations',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'management_admin:<front>',
  );
  // Exported menu link: management_pictures:admin/pictures.
  $menu_links['management_pictures:admin/pictures'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/pictures',
    'router_path' => 'admin/pictures',
    'link_title' => 'Pictures',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_pictures:admin/pictures',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'management_admin:<front>',
  );
  // Exported menu link: management_taxa-aggregated:admin/taxa-aggregated.
  $menu_links['management_taxa-aggregated:admin/taxa-aggregated'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/taxa-aggregated',
    'router_path' => 'admin/taxa-aggregated',
    'link_title' => 'Taxa, aggregated',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_taxa-aggregated:admin/taxa-aggregated',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'management_admin:<front>',
  );
  // Exported menu link: management_taxa:admin/taxa.
  $menu_links['management_taxa:admin/taxa'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/taxa',
    'router_path' => 'admin/taxa',
    'link_title' => 'Taxa',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_taxa:admin/taxa',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'management_admin:<front>',
  );
  // Exported menu link: management_taxon--species:admin/structure/taxonomy/taxa/add.
  $menu_links['management_taxon--species:admin/structure/taxonomy/taxa/add'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/taxonomy/taxa/add',
    'router_path' => 'admin/structure/taxonomy/%/add',
    'link_title' => 'Taxon / Species',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_taxon--species:admin/structure/taxonomy/taxa/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'management_add:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Admin');
  t('Collections');
  t('Habitat');
  t('Identifications');
  t('Locality');
  t('Observations');
  t('Pictures');
  t('Taxa');
  t('Taxa, aggregated');
  t('Taxon / Species');

  return $menu_links;
}
