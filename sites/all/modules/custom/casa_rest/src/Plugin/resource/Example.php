<?php

/**
 * @file
 * Contains \Drupal\casa_rest\Plugin\resource\Example.
 */

namespace Drupal\casa_rest\Plugin\resource;

use Drupal\restful\Plugin\resource\ResourceInterface;
use Drupal\restful\Plugin\resource\Resource;
use Drupal\restful\Http\RequestInterface;
use Drupal\restful\Resource\ResourceManager;

/**
 * Class Example
 * @package Drupal\casa_rest\Plugin\resource
 *
 * @Resource(
 *   name = "example:1.0",
 *   resource = "example",
 *   label = "Example custom resource",
 *   description = "A resource that serves as an example of a custom RESTful resource.",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   formatter = "single_json",
 *   renderCache = {
 *     "render": FALSE
 *   },
 *   menuItem = "example",
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */
class Example extends Resource implements ResourceInterface {

  /**
   * {@inheritdoc}
   */
  protected function publicFields() {
    // dpm('Called: publicFields()');

    return array(
      'field' => array(
        // 'callback' => '\Drupal\restful\Plugin\resource\CsrfToken::getCsrfToken',
        'callback' => '\Drupal\casa_rest\Plugin\resource\Example::callback',
      ),
    );
  }

  /**
   * Value callback; Return the CSRF token.
   *
   * @return string
   *   The token.
   */
  public static function callback() {
    return "Hello World!";
  }

  // protected function dataProviderClassName() {
  //   return '\Drupal\casa_rest\Plugin\resource\DataProvider\DataProviderExample';
  // }

  /**
   * {@inheritdoc}
   */
  // public function getRequest() {}

  /**
   * {@inheritdoc}
   */
  // public function process() {
  //   dpm('Called: process()');

  //   $path = $this->getPath();
  //   // dpm($path, '$path');

  //   return ResourceManager::executeCallback($this->getControllerFromPath($path), array($path));
  // }

  /**
   * Shorthand method to perform a quick GET request.
   */
  public function doGet($path = '', array $query = array()) {
    // dpm('Called: doGet()');

    $this->setPath($path);
    $this->setRequest(Request::create($this->versionedUrl($path, array('absolute' => FALSE)), $query, RequestInterface::METHOD_GET));
    return $this->process();
  }

  /**
   * {@inheritdoc}
   */
  public function doPost(array $parsed_body) {
    // dpm('Called: doPost()');

    return $this->doWrite(RequestInterface::METHOD_POST, '', $parsed_body);
  }

  /**
   * {@inheritdoc}
   */
  public function index($path) {
    // dpm('Called: index()');

    // Create an array of publicFields info containing the fields and their values.

    $values = array();
    foreach ($this->publicFields() as $public_property => $info) {
      $value = NULL;

      if ($info['callback']) {
        $value = ResourceManager::executeCallback($info['callback']);
      }

      if ($value && !empty($info['process_callbacks'])) {
        foreach ($info['process_callbacks'] as $process_callback) {
          $value = ResourceManager::executeCallback($process_callback, array($value));
        }
      }

      $values[$public_property] = $value;
    }

    // dpm($values, '$values');
    return $values;
  }

}
