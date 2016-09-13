<?php

/**
 * @file
 * Contains \Drupal\restful\Plugin\resource\fields\ResourceFieldEntityGeofield.
 */

namespace Drupal\casa_rest\Plugin\resource\fields;

use Drupal\restful\Plugin\resource\Field\ResourceFieldEntity;
use Drupal\restful\Plugin\resource\Field\ResourceFieldEntityInterface;

class ResourceFieldEntityGeofield extends ResourceFieldEntity implements ResourceFieldEntityInterface {

  /**
   * {@inheritdoc}
   */
  public function preprocess($value) {
    // dpm($value, 'preprocess $value');

    $valueOut = $value;

    // Change 'latitude' and 'longitude' to their accepted forms
    if (isset($value['longitude']) && $value['longitude']) {
      $valueOut['lon'] = $value['longitude'];
      unset($valueOut['longitude']);
    }
    if (isset($value['latitude']) && $value['latitude']) {
      $valueOut['lat'] = $value['latitude'];
      unset($valueOut['latitude']);
    }

    // dpm($valueOut, '$valueOut');
    return $valueOut;
  }

}
