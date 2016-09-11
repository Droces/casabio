<?php
/**
 * @file
 * Contains \Drupal\casa_rest\Plugin\resource\collections\Collections__0_1.
 */


namespace Drupal\casa_rest\Plugin\resource\collections;

use Drupal\restful\Plugin\resource\ResourceInterface;
use Drupal\restful\Plugin\resource\ResourceNode;

/**
 * Class Collections
 * @package Drupal\casa_rest\Plugin\resource\collections
 *
 * @Resource(
 *   name = "collections:0.1",
 *   resource = "collections",
 *   label = "Collections",
 *   description = "A RESTful service resource exposing collections contributed to CasaBio.",
 *   authenticationTypes = {
 *     "token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "collection"
 *     },
 *   },
 *   majorVersion = 0,
 *   minorVersion = 1
 * )
 */
class Collections__0_1 extends ResourceNode implements ResourceInterface {
  /**
   * Overrides ResourceEntity::publicFields().
   */
  protected function publicFields() {
    $fields = parent::publicFields();

    $collection_fields = array(

      'author' => array(
        'property' => 'author',
        'sub_property' => 'uid',
      ),

      'description' => array(
        'property' => 'body',
        'sub_property' => 'value',
      ),

      'collector' => array(
        'property' => 'field_collector',
        // 'sub_property' => '',
      ),

      'dateCollected' => array(
        'property' => 'field_date_collected',
        // 'sub_property' => '',
      ),

      'picture' => array(
        'property' => 'field_representative_picture',
        // 'sub_property' => '',
      ),

      'location' => array(
        'property' => 'field_location',
        'class' => '\Drupal\casa_rest\Plugin\resource\fields\ResourceFieldEntityGeofield',
        'process_callbacks' => array(
          array($this, 'locationProcess'),
        ),
      ),
    );

    $fields = array_merge($fields, $collection_fields);

    return $fields;
  }



  /**
   * Process callback. Removes Drupal-specific items from a location field array.
   *
   * @param array $value
   *   An array of properties and fields.
   *
   * @return array
   *   A cleaned array.
   */
  public function locationProcess($value) {
    // dpm($value, 'locationProcess() $value');

    return array(
      'longitude' => $value['lon'],
      'latitude' => $value['lat'],
    );
    return $value;
  }
}
