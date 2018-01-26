<?php
/**
 * @file
 * Contains \Drupal\casa_rest\Plugin\resource\user\User__0_1.
 */

namespace Drupal\casa_rest\Plugin\resource\user;

use Drupal\restful\Http\RequestInterface;
use Drupal\restful\Http\Request;
use Drupal\restful\Plugin\resource\Resource;
use Drupal\restful\Plugin\resource\ResourceInterface;
use Drupal\restful\Exception\UnprocessableEntityException;

/**
 * Class User
 * @package Drupal\casa_rest\Plugin\resource\user
 *
 * @Resource(
 *   name = "user:0.1",
 *   resource = "user",
 *   label = "User",
 *   description = "An endpoint for actions on individual users.",
 *   authenticationOptional = TRUE,
 *   authenticationTypes = {
 *     "token"
 *   },
 *   dataProvider = {
 *     "entityType": "user",
 *     "bundles": {
 *       "user"
 *     },
 *   },
 *   majorVersion = 0,
 *   minorVersion = 1
 * )
 */

class User__0_1 extends Resource implements ResourceInterface {

  /**
   * {@inheritdoc}
   */
  public function controllersInfo() {
    return array(
      '' => array(
        RequestInterface::METHOD_POST => 'addAccount',
      ),
    );
  }
  
  /**
   * {@inheritdoc}
   */
  protected function publicFields() {
    return array();
  }

  /**
   * Add user account into Drupal.
   * Filched from the Services module's user_resource.inc.
   */
  public function addAccount() {
    watchdog('User__0_1', 'message', array(), WATCHDOG_NOTICE, 'link');
    
    $request_body = $this->getRequest()->getParsedBody();

    // Check if the request has the valid parameters defined.
    if (!$this->isValidateRequest($request_body)) {
      throw new UnprocessableEntityException('Missing required parameters.');
    }
    
    $name = $request_body['name'];
    $pass = $request_body['pass'];
    $mail = $request_body['mail'];
    
    $account = array(
      'name' => $name,
      'mail' => $mail,
      'pass' => $pass,
    );

    // Load the required includes for saving profile information
    // with drupal_form_submit().
    module_load_include('inc', 'user', 'user.pages');

    // Register a new user.
    $form_state['values'] = $account;

    // Determine the password(s). Passwords may not be available as this callback
    // is used for registration as well.
    $pass1 = '';
    $pass2 = '';
    if (isset($account['pass'])) {
      // For legacy usage, passwords come in as a single string. To match the
      // actual form state value keys used by Drupal, we also can collect two
      // passwords via an array.
      if (is_array($account['pass'])) {
        $pass1 = $account['pass']['pass1'];
        $pass2 = $account['pass']['pass2'];
      }
      else {
        $pass1 = $account['pass'];
        $pass2 = $account['pass'];
      }
    }
    $form_state['values']['pass'] = array(
      'pass1' => $pass1,
      'pass2' => $pass2
    );

    // Set the form state op.
    $form_state['values']['op'] = t('Create new account');

    // Execute the register form.
    $form_state['programmed_bypass_access_check'] = FALSE;

    drupal_form_submit('user_register_form', $form_state);
    // find and store the new user into the form_state
    if(isset($form_state['values']['uid'])) {
      $form_state['user'] = user_load($form_state['values']['uid']);
    }

    // Error if needed.
    if ($errors = form_get_errors()) {
      $exception = new UnprocessableEntityException('There were errors in your submission.');
      foreach ($errors as $field => $message) {
        $output = strip_tags($message);

        $exception->addFieldError($field, $output);
      }
      throw $exception;
    }
    else {
      $user = array('uid' => $form_state['user']->uid);
      return $user;
    }
  }

  /**
   * Determine if the request has the valid parameters defined.
   */
  protected function isValidateRequest($request_body) {
    return $request_body['name'] && $request_body['pass'] && $request_body['mail'] ?: FALSE;
  }

}
