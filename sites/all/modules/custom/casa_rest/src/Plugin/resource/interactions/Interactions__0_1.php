<?php
/**
 * @file
 * Contains \Drupal\casa_rest\Plugin\resource\interactions\Interactions__0_1.
 */


namespace Drupal\casa_rest\Plugin\resource\interactions;

use Drupal\restful\Plugin\resource\ResourceInterface;
use Drupal\restful\Plugin\resource\ResourceNode;

/**
 * Class Interactions
 * @package Drupal\casa_rest\Plugin\resource\interactions
 *
 * @Resource(
 *   name = "interactions:0.1",
 *   resource = "interactions",
 *   label = "Interactions",
 *   description = "A RESTful service resource exposing interactions contributed to CasaBio.",
 *   authenticationTypes = {
 *     "token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "interaction"
 *     },
 *     "range" = 500,
 *   },
 *   majorVersion = 0,
 *   minorVersion = 1
 * )
 */
class Interactions__0_1 extends ResourceNode implements ResourceInterface {

  public static $field_names_map = array(
    'author' =>               'author',
    'body' =>                 'description',
    'field_observation' =>    'observation',
    'field_interaction_activity' => 'interactionActivity',
    'field_observation_object' => 'observationObject',
  );


  /**
   * Overrides ResourceEntity::publicFields().
   */
  protected function publicFields() {
    $fields = parent::publicFields();

    $interaction_fields = array(

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

      self::$field_names_map['field_observation'] => array(
        'property' => 'field_observation',
        // 'sub_property' => 'target_id',
      ),

      self::$field_names_map['field_interaction_activity'] => array(
        'property' => 'field_interaction_activity',
        // 'sub_property' => 'target_id',
      ),

      self::$field_names_map['field_observation_object'] => array(
        'property' => 'field_observation_object',
        // 'sub_property' => 'target_id',
      ),
    );

    $fields = array_merge($fields, $interaction_fields);

    return $fields;
  }


  public function bodyProcess($value) {
    // watchdog('Called: bodyProcess()', 'RESTful API; observations:0.1');
    // watchdog('RESTful API', 'In observations:0.1 -> bodyProcess(): ' . json_encode($value));

    return $value['value'];
  }

}
