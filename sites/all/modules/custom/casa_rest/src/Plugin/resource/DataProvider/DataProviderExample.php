<?php

/**
 * @file
 * Contains \Drupal\casa_rest\Plugin\resource\DataProvider\DataProviderExample.
 */

namespace Drupal\casa_rest\Plugin\resource\DataProvider;

use Drupal\restful\Plugin\resource\DataProvider\DataProvider;
use Drupal\restful\Plugin\resource\DataProvider\DataProviderInterface;

/**
 * Class DataProviderExample.
 *
 * @package Drupal\casa_rest\Plugin\resource\DataProvider
 */
class DataProviderExample extends DataProvider implements DataProviderInterface {

  /**
   * {@inheritdoc}
   */
  // public function getRequest();

  /**
   * {@inheritdoc}
   */
  public function index() {
    // dpm('Called: DataProviderExample::index()');
  }

  /**
   * {@inheritdoc}
   */
  // public function discover($path = NULL) {}

  /**
   * Get the data interpreter.
   *
   * @param mixed $identifier
   *   The ID of thing being viewed.
   *
   * @return \Drupal\restful\Plugin\resource\DataInterpreter\DataInterpreterInterface
   *   The data interpreter.
   */
  protected function initDataInterpreter($identifier) {}


  /**
   * Returns the ID to render for the current index GET request.
   *
   * @return array
   *   Numeric array containing the identifiers to be sent to viewMultiple.
   */
  public function getIndexIds() {}

  /**
   * Counts the total results for the index call.
   *
   * @return int
   *   The total number of results for the index call.
   */
  public function count() {}

  /**
   * Create operation.
   *
   * @param mixed $object
   *   The thing to be created.
   *
   * @return array
   *   An array of structured data for the thing that was created.
   */
  public function create($object) {}

  /**
   * Read operation.
   *
   * @param mixed $identifier
   *   The ID of thing being viewed.
   *
   * @return array
   *   An array of data for the thing being viewed.
   */
  public function view($identifier) {
    // dpm('Called: view()');

    // TODO: Compare this with 1.x logic.
    $ids = explode(static::IDS_SEPARATOR, $path);

    // REST requires a canonical URL for every resource.
    $canonical_path = $this->getDataProvider()->canonicalPath($path);
    restful()
      ->getResponse()
      ->getHeaders()
      ->add(HttpHeader::create('Link', $this->versionedUrl($canonical_path, array(), FALSE) . '; rel="canonical"'));

    // If there is only one ID then use 'view'. Else, use 'viewMultiple'. The
    // difference between the two is that 'view' allows access denied
    // exceptions.
    if (count($ids) == 1) {
      return array($this->getDataProvider()->view($ids[0]));
    }
    else {
      return $this->getDataProvider()->viewMultiple($ids);
    }
  }

  /**
   * Read operation.
   *
   * @param array $identifiers
   *   The array of IDs of things being viewed.
   *
   * @return array
   *   An array of structured data for the things being viewed.
   */
  public function viewMultiple(array $identifiers) {
    // dpm('Called: viewMultiple()');
  }

  /**
   * Update operation.
   *
   * @param mixed $identifier
   *   The ID of thing to be updated.
   * @param mixed $object
   *   The thing that will be set.
   * @param bool $replace
   *   TRUE if the contents of $object will replace $identifier entirely. FALSE
   *   if only what is set in $object will replace those properties in
   *   $identifier.
   *
   * @return array
   *   An array of structured data for the thing that was updated.
   */
  public function update($identifier, $object, $replace = FALSE) {}

  /**
   * Delete operation.
   *
   * @param mixed $identifier
   *   The ID of thing to be removed.
   */
  public function remove($identifier) {}
}
