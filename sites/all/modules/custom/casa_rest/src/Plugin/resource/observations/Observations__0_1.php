<?php
/**
 * @file
 * Contains \Drupal\casa_rest\Plugin\resource\observations\Observations__0_1.
 */


namespace Drupal\casa_rest\Plugin\resource\observations;

use Drupal\restful\Plugin\resource\ResourceInterface;
use Drupal\restful\Plugin\resource\ResourceNode;

/**
 * Class Observations
 * @package Drupal\casa_rest\Plugin\resource\observations
 *
 * @Resource(
 *   name = "observations:0.1",
 *   resource = "observations",
 *   label = "Observations",
 *   description = "A RESTful service resource exposing observations contributed to CasaBio.",
 *   authenticationTypes = {
 *     "token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "observation"
 *     },
 *     "range" = 500,
 *   },
 *   majorVersion = 0,
 *   minorVersion = 1
 * )
 */
class Observations__0_1 extends ResourceNode implements ResourceInterface {

  public static $field_names_map = array(
    'author' =>               'author',
    'body' =>                 'description',
    'field_collection' =>     'collection',
    'field_observer_name' =>  'observerName',
    'field_date_observed' =>  'dateObserved',
    'field_count' =>          'count',
    'field_specimen_id' =>    'specimenId',
    'field_locality' =>       'locality',
    'field_pictures_observation' => 'picturesInObservation',
    // 'field_observation_id' => 'observationId',
    'field_source' =>         'source',
    'field_external_id' =>    'externalId',
    'field_location' =>       'location',
  );


  /**
   * Overrides ResourceEntity::publicFields().
   */
  protected function publicFields() {
    $fields = parent::publicFields();

    // // Change 'label' to 'name'
    // $public_fields['name'] = $public_fields['label'];
    // unset($public_fields['label']);

    $observation_fields = array(

      self::$field_names_map['author'] => array(
        'property' => 'author',
        'sub_property' => 'uid',
      ),

      self::$field_names_map['body'] => array(
        'property' => 'body',
        // 'sub_property' => 'value',
        'process_callbacks' => array(
          array($this, 'bodyProcess'),
        ),
      ),

      self::$field_names_map['field_collection'] => array(
        'property' => 'field_collection',
        'sub_property' => 'target_id',
      ),

      self::$field_names_map['field_observer_name'] => array(
        'property' => 'field_observer_name',
        // 'sub_property' => '',
      ),

      self::$field_names_map['field_date_observed'] => array(
        'property' => 'field_date_observed',
        // 'sub_property' => '',
        'process_callbacks' => array(
          array($this, 'dateProcess'),
        ),
        // 'callback' => array($this, 'dateObservedDataProviderCallback'),
      ),

      self::$field_names_map['field_count'] => array(
        'property' => 'field_count',
        // 'sub_property' => '',
      ),

      self::$field_names_map['field_specimen_id'] => array(
        'property' => 'field_specimen_id',
        // 'sub_property' => '',
      ),

      self::$field_names_map['field_locality'] => array(
        'property' => 'field_locality',
        // 'sub_property' => '',
      ),

      self::$field_names_map['field_pictures_observation'] => array(
        'property' => 'field_pictures_observation',
        // 'sub_property' => '',
      ),

      // $field_names_map['field_observation_id'] => array(
      //   'property' => 'field_observation_id',
      //   // 'sub_property' => '',
      // ),

      self::$field_names_map['field_source'] => array(
        'property' => 'field_source',
        // 'sub_property' => '',
      ),

      self::$field_names_map['field_external_id'] => array(
        'property' => 'field_external_id',
        // 'sub_property' => '',
      ),

      self::$field_names_map['field_location'] => array(
        'property' => 'field_location',
        'class' => '\Drupal\casa_rest\Plugin\resource\fields\ResourceFieldEntityGeofield',
        'process_callbacks' => array(
          array($this, 'locationProcess'),
        ),
      ),
    );

    $fields = array_merge($fields, $observation_fields);

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
    // watchdog('Called: locationProcess()', 'RESTful API; observations:0.1');

    return array(
      'longitude' => $value['lon'],
      'latitude' => $value['lat'],
    );
    // return $value;
  }


  public function bodyProcess($value) {
    // watchdog('Called: bodyProcess()', 'RESTful API; observations:0.1');
    // watchdog('RESTful API', 'In observations:0.1 -> bodyProcess(): ' . json_encode($value));

    return $value['value'];
  }


  public function dateProcess($value) {
    // watchdog('Called: dateProcess()', 'RESTful API; observations:0.1');
    watchdog('RESTful API', 'In observations:0.1 -> dateProcess(): ' . '$value: ' . json_encode($value));

    // If in format 'dd/mm/yyyy'
    if (preg_match('/^\d{2}\/\d{2}\/\d{4}/', $value)) {
      // watchdog('Observations__0_1', 'is preg_match()', array(), WATCHDOG_NOTICE, 'link');

      // $obj_date = DateTime::createFromFormat('d/m/Y', $value);
      // return $obj_date->getTimestamp();
      return $value;
    }
    // If a unix timestamp
    // elseif (preg_match('/^\d{1,11}/', $value)) {
    //   // $date = format_date($timestamp, $type = 'medium', $format = '', $timezone = NULL, $langcode = NULL)
    // }
    else {
      return format_date($value, $type = 'custom', $format = 'd/m/Y');
      // return $value;
    }
  }

  public function dateObservedDataProviderCallback($DataInterpreterEMW) {
    // watchdog('Observations__0_1', '$arg1: ' . $arg1, array(), WATCHDOG_NOTICE, 'link');
    // $EMW = $DataInterpreterEMW->getWrapper();
    // dpm($EMW->value(), '$arg1');
  }
}
