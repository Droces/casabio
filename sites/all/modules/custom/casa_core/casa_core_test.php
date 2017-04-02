<?php
// Using PHPUnit

// The following lines are from index.php

// These constants and variables are needed for the bootstrap process.
define('DRUPAL_ROOT', '/var/www/html/Current/CasaBio');
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
$_SERVER['REMOTE_ADDR'] = '127.0.0.1';

// Bootstrap Drupal.
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);



// namespace Drupal\...?;

// use PHPUnit\Framework\TestCase;

class AdderTest extends \PHPUnit_Framework_TestCase {
  private $user;

  protected function setUp()
  {
    // Create a user
    // Problem is it's incrementing uid each time...
    $this->user = new stdClass();
    $this->user->name = 'test_user';
    $this->user->status = 1;
    user_save($this->user);
  }

  
  public function test_user_has_min_role() {

    // Assign the user to the role
    $role = user_role_load_by_name('Maintainer');
    user_multiple_role_edit(array($this->user->uid), 'add_role', $role->rid);

    // Invoke and test the function
    $this->assertFalse(user_has_min_role($this->user, 'Maintainer'));
  }

  protected function tearDown()
  {
    user_delete($this->user->uid);
  }
}