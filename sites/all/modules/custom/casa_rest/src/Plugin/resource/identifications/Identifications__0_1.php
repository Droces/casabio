<?php
/**
 * @file
 * Contains \Drupal\casa_rest\Plugin\resource\identifications\Identifications__0_1.
 */


namespace Drupal\casa_rest\Plugin\resource\identifications;

use Drupal\restful\Plugin\resource\ResourceInterface;
use Drupal\restful\Plugin\resource\ResourceNode;

/**
 * Class Identifications
 * @package Drupal\casa_rest\Plugin\resource\identifications
 *
 * @Resource(
 *   name = "identifications:0.1",
 *   resource = "identifications",
 *   label = "Identifications",
 *   description = "A RESTful service resource exposing identifications contributed to CasaBio.",
 *   authenticationTypes = {
 *     "token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "identification"
 *     },
 *     "range" = 500,
 *   },
 *   majorVersion = 0,
 *   minorVersion = 1
 * )
 */
class Identifications__0_1 extends ResourceNode implements ResourceInterface {

  public static $field_names_map = array(
    'author' =>               'author',
    'body' =>                 'description',
    'field_observation' =>    'observation',
    'field_identified_species' => 'identifiedSpecies',
    'field_certainty' =>      'certainty',
    'field_identification_source' => 'identificationSource',
  );


  /**
   * Overrides ResourceEntity::publicFields().
   */
  protected function publicFields() {
    $fields = parent::publicFields();

    $identification_fields = array(

      self::$field_names_map['author'] => array(
        'property' => 'author',
        'sub_property' => 'uid',
      ),

      self::$field_names_map['body'] => array(
        'property' => 'body',
        'sub_property' => 'value',
      ),

      self::$field_names_map['field_observation'] => array(
        'property' => 'field_observation',
        // 'sub_property' => 'value',
      ),

      self::$field_names_map['field_identified_species'] => array(
        'property' => 'field_identified_species',
        // 'sub_property' => 'value',
      ),

      self::$field_names_map['field_certainty'] => array(
        'property' => 'field_certainty',
        // 'sub_property' => 'value',
      ),

      self::$field_names_map['field_identification_source'] => array(
        'property' => 'field_identification_source',
        // 'sub_property' => 'value',
      ),

    );

    $fields = array_merge($fields, $identification_fields);

    return $fields;
  }
}
