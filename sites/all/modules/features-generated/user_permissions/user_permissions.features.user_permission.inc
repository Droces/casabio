<?php
/**
 * @file
 * user_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function user_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'Administrator' => 'Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'access overlay'.
  $permissions['access overlay'] = array(
    'name' => 'access overlay',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'overlay',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site-wide contact form'.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      'Administrator' => 'Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user contact forms'.
  $permissions['access user contact forms'] = array(
    'name' => 'access user contact forms',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer admin paths'.
  $permissions['administer admin paths'] = array(
    'name' => 'administer admin paths',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'admin_path',
  );

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'administer block classes'.
  $permissions['administer block classes'] = array(
    'name' => 'administer block classes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'block_class',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer contact forms'.
  $permissions['administer contact forms'] = array(
    'name' => 'administer contact forms',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer date tools'.
  $permissions['administer date tools'] = array(
    'name' => 'administer date tools',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'date_tools',
  );

  // Exported permission: 'administer entity view modes'.
  $permissions['administer entity view modes'] = array(
    'name' => 'administer entity view modes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'entity_view_mode',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer feeds'.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'administer feeds_tamper'.
  $permissions['administer feeds_tamper'] = array(
    'name' => 'administer feeds_tamper',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer linkit'.
  $permissions['administer linkit'] = array(
    'name' => 'administer linkit',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'linkit',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer media wysiwyg view mode'.
  $permissions['administer media wysiwyg view mode'] = array(
    'name' => 'administer media wysiwyg view mode',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'media_wysiwyg_view_mode',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer openlayers'.
  $permissions['administer openlayers'] = array(
    'name' => 'administer openlayers',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'openlayers',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer services'.
  $permissions['administer services'] = array(
    'name' => 'administer services',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'clear habitats_taxonomy_terms_ feeds'.
  $permissions['clear habitats_taxonomy_terms_ feeds'] = array(
    'name' => 'clear habitats_taxonomy_terms_ feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear identifications feeds'.
  $permissions['clear identifications feeds'] = array(
    'name' => 'clear identifications feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear observations_nodes feeds'.
  $permissions['clear observations_nodes feeds'] = array(
    'name' => 'clear observations_nodes feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear pictures_nodes feeds'.
  $permissions['clear pictures_nodes feeds'] = array(
    'name' => 'clear pictures_nodes feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear taxa_taxonomy_terms_ feeds'.
  $permissions['clear taxa_taxonomy_terms_ feeds'] = array(
    'name' => 'clear taxa_taxonomy_terms_ feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create collection content'.
  $permissions['create collection content'] = array(
    'name' => 'create collection content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create crew_species_observation content'.
  $permissions['create crew_species_observation content'] = array(
    'name' => 'create crew_species_observation content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create gallery content'.
  $permissions['create gallery content'] = array(
    'name' => 'create gallery content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create habitat_record content'.
  $permissions['create habitat_record content'] = array(
    'name' => 'create habitat_record content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create identification content'.
  $permissions['create identification content'] = array(
    'name' => 'create identification content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create identification_community content'.
  $permissions['create identification_community content'] = array(
    'name' => 'create identification_community content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create link content'.
  $permissions['create link content'] = array(
    'name' => 'create link content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create observation content'.
  $permissions['create observation content'] = array(
    'name' => 'create observation content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create openlayers_example_content content'.
  $permissions['create openlayers_example_content content'] = array(
    'name' => 'create openlayers_example_content content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create picture content'.
  $permissions['create picture content'] = array(
    'name' => 'create picture content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create source content'.
  $permissions['create source content'] = array(
    'name' => 'create source content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create threat_assessment content'.
  $permissions['create threat_assessment content'] = array(
    'name' => 'create threat_assessment content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any collection content'.
  $permissions['delete any collection content'] = array(
    'name' => 'delete any collection content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any crew_species_observation content'.
  $permissions['delete any crew_species_observation content'] = array(
    'name' => 'delete any crew_species_observation content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any gallery content'.
  $permissions['delete any gallery content'] = array(
    'name' => 'delete any gallery content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any habitat_record content'.
  $permissions['delete any habitat_record content'] = array(
    'name' => 'delete any habitat_record content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any identification content'.
  $permissions['delete any identification content'] = array(
    'name' => 'delete any identification content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any identification_community content'.
  $permissions['delete any identification_community content'] = array(
    'name' => 'delete any identification_community content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any link content'.
  $permissions['delete any link content'] = array(
    'name' => 'delete any link content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any observation content'.
  $permissions['delete any observation content'] = array(
    'name' => 'delete any observation content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any openlayers_example_content content'.
  $permissions['delete any openlayers_example_content content'] = array(
    'name' => 'delete any openlayers_example_content content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any picture content'.
  $permissions['delete any picture content'] = array(
    'name' => 'delete any picture content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any source content'.
  $permissions['delete any source content'] = array(
    'name' => 'delete any source content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any threat_assessment content'.
  $permissions['delete any threat_assessment content'] = array(
    'name' => 'delete any threat_assessment content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own collection content'.
  $permissions['delete own collection content'] = array(
    'name' => 'delete own collection content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own crew_species_observation content'.
  $permissions['delete own crew_species_observation content'] = array(
    'name' => 'delete own crew_species_observation content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own gallery content'.
  $permissions['delete own gallery content'] = array(
    'name' => 'delete own gallery content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own habitat_record content'.
  $permissions['delete own habitat_record content'] = array(
    'name' => 'delete own habitat_record content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own identification content'.
  $permissions['delete own identification content'] = array(
    'name' => 'delete own identification content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own identification_community content'.
  $permissions['delete own identification_community content'] = array(
    'name' => 'delete own identification_community content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own link content'.
  $permissions['delete own link content'] = array(
    'name' => 'delete own link content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own observation content'.
  $permissions['delete own observation content'] = array(
    'name' => 'delete own observation content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own openlayers_example_content content'.
  $permissions['delete own openlayers_example_content content'] = array(
    'name' => 'delete own openlayers_example_content content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own picture content'.
  $permissions['delete own picture content'] = array(
    'name' => 'delete own picture content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own source content'.
  $permissions['delete own source content'] = array(
    'name' => 'delete own source content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own threat_assessment content'.
  $permissions['delete own threat_assessment content'] = array(
    'name' => 'delete own threat_assessment content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in data_sources'.
  $permissions['delete terms in data_sources'] = array(
    'name' => 'delete terms in data_sources',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in habitats'.
  $permissions['delete terms in habitats'] = array(
    'name' => 'delete terms in habitats',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in locality'.
  $permissions['delete terms in locality'] = array(
    'name' => 'delete terms in locality',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in picture_subject'.
  $permissions['delete terms in picture_subject'] = array(
    'name' => 'delete terms in picture_subject',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in picture_tags'.
  $permissions['delete terms in picture_tags'] = array(
    'name' => 'delete terms in picture_tags',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in taxa'.
  $permissions['delete terms in taxa'] = array(
    'name' => 'delete terms in taxa',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in threats_disturbances'.
  $permissions['delete terms in threats_disturbances'] = array(
    'name' => 'delete terms in threats_disturbances',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any collection content'.
  $permissions['edit any collection content'] = array(
    'name' => 'edit any collection content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any crew_species_observation content'.
  $permissions['edit any crew_species_observation content'] = array(
    'name' => 'edit any crew_species_observation content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any gallery content'.
  $permissions['edit any gallery content'] = array(
    'name' => 'edit any gallery content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any habitat_record content'.
  $permissions['edit any habitat_record content'] = array(
    'name' => 'edit any habitat_record content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any identification content'.
  $permissions['edit any identification content'] = array(
    'name' => 'edit any identification content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any identification_community content'.
  $permissions['edit any identification_community content'] = array(
    'name' => 'edit any identification_community content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any link content'.
  $permissions['edit any link content'] = array(
    'name' => 'edit any link content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any observation content'.
  $permissions['edit any observation content'] = array(
    'name' => 'edit any observation content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any openlayers_example_content content'.
  $permissions['edit any openlayers_example_content content'] = array(
    'name' => 'edit any openlayers_example_content content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any picture content'.
  $permissions['edit any picture content'] = array(
    'name' => 'edit any picture content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any source content'.
  $permissions['edit any source content'] = array(
    'name' => 'edit any source content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any threat_assessment content'.
  $permissions['edit any threat_assessment content'] = array(
    'name' => 'edit any threat_assessment content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own collection content'.
  $permissions['edit own collection content'] = array(
    'name' => 'edit own collection content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own crew_species_observation content'.
  $permissions['edit own crew_species_observation content'] = array(
    'name' => 'edit own crew_species_observation content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own gallery content'.
  $permissions['edit own gallery content'] = array(
    'name' => 'edit own gallery content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own habitat_record content'.
  $permissions['edit own habitat_record content'] = array(
    'name' => 'edit own habitat_record content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own identification content'.
  $permissions['edit own identification content'] = array(
    'name' => 'edit own identification content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own identification_community content'.
  $permissions['edit own identification_community content'] = array(
    'name' => 'edit own identification_community content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own link content'.
  $permissions['edit own link content'] = array(
    'name' => 'edit own link content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own observation content'.
  $permissions['edit own observation content'] = array(
    'name' => 'edit own observation content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own openlayers_example_content content'.
  $permissions['edit own openlayers_example_content content'] = array(
    'name' => 'edit own openlayers_example_content content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own picture content'.
  $permissions['edit own picture content'] = array(
    'name' => 'edit own picture content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own source content'.
  $permissions['edit own source content'] = array(
    'name' => 'edit own source content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own threat_assessment content'.
  $permissions['edit own threat_assessment content'] = array(
    'name' => 'edit own threat_assessment content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit terms in data_sources'.
  $permissions['edit terms in data_sources'] = array(
    'name' => 'edit terms in data_sources',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in habitats'.
  $permissions['edit terms in habitats'] = array(
    'name' => 'edit terms in habitats',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in locality'.
  $permissions['edit terms in locality'] = array(
    'name' => 'edit terms in locality',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in picture_subject'.
  $permissions['edit terms in picture_subject'] = array(
    'name' => 'edit terms in picture_subject',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in picture_tags'.
  $permissions['edit terms in picture_tags'] = array(
    'name' => 'edit terms in picture_tags',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in taxa'.
  $permissions['edit terms in taxa'] = array(
    'name' => 'edit terms in taxa',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in threats_disturbances'.
  $permissions['edit terms in threats_disturbances'] = array(
    'name' => 'edit terms in threats_disturbances',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'get a system variable'.
  $permissions['get a system variable'] = array(
    'name' => 'get a system variable',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get any binary files'.
  $permissions['get any binary files'] = array(
    'name' => 'get any binary files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get own binary files'.
  $permissions['get own binary files'] = array(
    'name' => 'get own binary files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'import habitats_taxonomy_terms_ feeds'.
  $permissions['import habitats_taxonomy_terms_ feeds'] = array(
    'name' => 'import habitats_taxonomy_terms_ feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import identifications feeds'.
  $permissions['import identifications feeds'] = array(
    'name' => 'import identifications feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import observations_nodes feeds'.
  $permissions['import observations_nodes feeds'] = array(
    'name' => 'import observations_nodes feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import pictures_nodes feeds'.
  $permissions['import pictures_nodes feeds'] = array(
    'name' => 'import pictures_nodes feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import taxa_taxonomy_terms_ feeds'.
  $permissions['import taxa_taxonomy_terms_ feeds'] = array(
    'name' => 'import taxa_taxonomy_terms_ feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'perform unlimited index queries'.
  $permissions['perform unlimited index queries'] = array(
    'name' => 'perform unlimited index queries',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'save file information'.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'set a system variable'.
  $permissions['set a system variable'] = array(
    'name' => 'set a system variable',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'tamper habitats_taxonomy_terms_'.
  $permissions['tamper habitats_taxonomy_terms_'] = array(
    'name' => 'tamper habitats_taxonomy_terms_',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper identifications'.
  $permissions['tamper identifications'] = array(
    'name' => 'tamper identifications',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper observations_nodes'.
  $permissions['tamper observations_nodes'] = array(
    'name' => 'tamper observations_nodes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper pictures_nodes'.
  $permissions['tamper pictures_nodes'] = array(
    'name' => 'tamper pictures_nodes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper taxa_taxonomy_terms_'.
  $permissions['tamper taxa_taxonomy_terms_'] = array(
    'name' => 'tamper taxa_taxonomy_terms_',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'unlock habitats_taxonomy_terms_ feeds'.
  $permissions['unlock habitats_taxonomy_terms_ feeds'] = array(
    'name' => 'unlock habitats_taxonomy_terms_ feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock identifications feeds'.
  $permissions['unlock identifications feeds'] = array(
    'name' => 'unlock identifications feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock observations_nodes feeds'.
  $permissions['unlock observations_nodes feeds'] = array(
    'name' => 'unlock observations_nodes feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock pictures_nodes feeds'.
  $permissions['unlock pictures_nodes feeds'] = array(
    'name' => 'unlock pictures_nodes feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock taxa_taxonomy_terms_ feeds'.
  $permissions['unlock taxa_taxonomy_terms_ feeds'] = array(
    'name' => 'unlock taxa_taxonomy_terms_ feeds',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use media wysiwyg'.
  $permissions['use media wysiwyg'] = array(
    'name' => 'use media wysiwyg',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'media_wysiwyg',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format raw_html'.
  $permissions['use text format raw_html'] = array(
    'name' => 'use text format raw_html',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view advanced help index'.
  $permissions['view advanced help index'] = array(
    'name' => 'view advanced help index',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'advanced_help',
  );

  // Exported permission: 'view advanced help popup'.
  $permissions['view advanced help popup'] = array(
    'name' => 'view advanced help popup',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'advanced_help',
  );

  // Exported permission: 'view advanced help topic'.
  $permissions['view advanced help topic'] = array(
    'name' => 'view advanced help topic',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'advanced_help',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Contributor' => 'Contributor',
      'Maintainer' => 'Maintainer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  return $permissions;
}
