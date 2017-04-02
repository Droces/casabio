<?php
/**
 * @file
 * 
 */

function get_users() {
  $query = new EntityFieldQuery;
  $query
    ->entityCondition('entity_type', 'user')
    ->propertyCondition('status',1)
    // ->range(0, 1) // Fetch just one
  ;

  $result = $query->execute();
  // dpm($result, '$result');

  $users = isset($result['user']) ? $result['user'] : [];
  return $users;
}