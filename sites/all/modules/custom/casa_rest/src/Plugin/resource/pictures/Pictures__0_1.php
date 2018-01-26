<?php
/**
 * @file
 * Contains \Drupal\casa_rest\Plugin\resource\pictures\Pictures__0_1.
 */


namespace Drupal\casa_rest\Plugin\resource\pictures;

use Drupal\restful\Plugin\resource\ResourceInterface;
use Drupal\restful\Plugin\resource\ResourceNode;



/**
 * Class Pictures
 * @package Drupal\casa_rest\Plugin\resource\pictures
 *
 * @Resource(
 *   name = "pictures:0.1",
 *   resource = "pictures",
 *   label = "Pictures",
 *   description = "A RESTful service resource exposing pictures contributed to CasaBio.",
 *   authenticationTypes = {
 *     "token"
 *   },
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "picture"
 *     },
 *     "range" = 1000,
 *   },
 *   majorVersion = 0,
 *   minorVersion = 1
 * )
 */
class Pictures__0_1 extends ResourceNode implements ResourceInterface {

  public static $field_names_map = array(
    'field_collection' =>     'collection',
    'field_date_taken' =>     'dateTaken',
    'created' =>              'dateCreated',
    'author' =>               'author',
    'comment' =>              'commentsMode',
    'body' =>                 'description',
    'field_exif' =>           'exif',
    'field_image' =>          'image',
    'field_subject' =>        'subject',
    'field_tags' =>           'tags',
    'field_beauty' =>         'beauty',
    'field_usefulness' =>     'usefulness',
    'field_location' =>       'location',
  );

  /**
   * Overrides ResourceEntity::publicFields().
   */
  protected function publicFields() {
    $fields = parent::publicFields();

    $picture_fields = array(

      self::$field_names_map['field_collection'] => array(
        // 'methods' => array(
        //   \Drupal\restful\Http\RequestInterface::METHOD_GET,
        // ),
        'property' => 'field_collection',
        // 'class' => '\Drupal\restful\Plugin\resource\Field\ResourceFieldFileEntityReference',
        'sub_property' => 'target_id',
        // 'resource' => array(
        //   'name' => 'collection',
        //   'fullView' => FALSE,
        //   'majorVersion' => 0,
        //   'minorVersion' => 1,
        // ),
      ),

      'status' => array(
        'property' => 'status',
      ),

      self::$field_names_map['field_date_taken'] => array(
        'property' => 'field_date_taken',
        'process_callbacks' => array(
          array($this, 'dateProcess'),
        ),
      ),

      self::$field_names_map['created'] => array(
        'property' => 'created',
      ),

      self::$field_names_map['author'] => array(
        'property' => 'author',
        'sub_property' => 'uid',
      ),

      self::$field_names_map['comment'] => array(
        'property' => 'comment',
      ),

      self::$field_names_map['body'] => array(
        'property' => 'body',
        // 'sub_property' => 'value',
        'process_callbacks' => array(
          array($this, 'bodyProcess'),
        ),
      ),

      self::$field_names_map['field_exif'] => array(
        'property' => 'field_exif',
      ),

      self::$field_names_map['field_image'] => array(
        'property' => 'field_image',
        'process_callbacks' => array(
          array($this, 'imageProcess'),
        ),
        'image_styles' => array(
          'thumbnail',
          'medium',
          'medium_square',
          'large',
          'very_large'),
      ),

      self::$field_names_map['field_subject'] => array(
        'property' => 'field_subject',
        'sub_property' => 'label',
      ),
      self::$field_names_map['field_tags'] => array(
        'property' => 'field_tags',
      ),
      self::$field_names_map['field_beauty'] => array(
        'property' => 'field_beauty',
      ),
      self::$field_names_map['field_usefulness'] => array(
        'property' => 'field_usefulness',
      ),

      self::$field_names_map['field_location'] => array(
        'property' => 'field_location',
        // 'class' => '\Drupal\restful\Plugin\resource\Field\ResourceFieldEntity',
        'class' => '\Drupal\casa_rest\Plugin\resource\fields\ResourceFieldEntityGeofield',
        'process_callbacks' => array(
          array($this, 'locationProcess'),
        ),
      ),
    );

    $fields = array_merge($fields, $picture_fields);

    return $fields;
  }



  /**
   * Process callback. Removes Drupal-specific items from an image field array.
   *
   * @param array $value
   *   An array of properties and fields.
   *
   * @return array
   *   A cleaned array.
   */
  public function imageProcess($value) {
    // dpm($value, 'imageProcess() $value');

    // if (ResourceFieldBase::isArrayNumeric($value)) {
    //   $output = array();
    //   foreach ($value as $item) {
    //     $output[] = $this->imageProcess($item);
    //   }
    //   return $output;
    // }

    return array(
      'id' => $value['fid'],
      'self' => file_create_url($value['uri']),
      'filemime' => $value['filemime'],
      'filesize' => $value['filesize'],
      'width' => $value['width'],
      'height' => $value['height'],
      'formats' => $value['image_styles'],
    );
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


  public function bodyProcess($value) {
    // watchdog('Called: bodyProcess()', 'RESTful API; observations:0.1');
    // watchdog('RESTful API', 'In observations:0.1->bodyProcess(): ' . json_encode($value));

    return $value['value'];
  }


  // /**
  //  * Get the "self" url.
  //  *
  //  * @param DataInterpreterInterface $interpreter
  //  *   The wrapped entity.
  //  *
  //  * @return string
  //  *   The self URL.
  //  */
  // public function getEntitySelf(DataInterpreterInterface $interpreter) {
  //   return $this->versionedUrl($interpreter->getWrapper()->getIdentifier());
  // }


  public function dateProcess($value) {
    // watchdog('Observations__0_1', '$value: ' . $value, array(), WATCHDOG_NOTICE, 'link');

    // If in format 'dd/mm/yyyy'
    if (preg_match('/^\d{2}\/\d{2}\/\d{4}/', $value)) {
      watchdog('Observations__0_1', 'is preg_match()', array(), WATCHDOG_NOTICE, 'link');
      // global $user;
      // // $submittedDate = "{$datefields['year']}-{$datefields['month']}-{$datefields['day']}";
      // $submittedDate = $value;
      // $timezone = $user->timezone;
      // $newdate = new DateTime($submittedDate, new DateTimeZone($timezone));
      // $unixts = $newdate->getTimestamp();
      // return $unixts;

      $obj_date = DateTime::createFromFormat('d/m/Y', $value);
      return $obj_date->getTimestamp();

      // return $value;
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
}
