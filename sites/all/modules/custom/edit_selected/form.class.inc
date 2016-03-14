<?php
/**
 * @file
 * Provides create, validate and process functions for the edit_selected form block
 */


/**
* 
*/
class Form {

  // Within the Drupal Forms API, this is the $form array, usually passed to functions by reference
  protected $specifications = array(
    '#form_id'  => '',
    '#type'     => 'form',
    '#build_id' => '',
    '#token'    => '',
    '#method'   => 'post',
    '#tree'     => '',
  );

  // Within the Drupal Forms API, this is the $form_info array, which is filled upon submission
  protected $info = array();

  
  public function __construct(array $specifications) {
    $this -> specifications = $specifications;
    // dpm($specifications, 'specifications');
  }


  /**
   * @throws InvalidArgumentException
   *   Throws exception if argument is not given, or if it isn't an array
   */
  public function setSpecifications($specifications) {
    if ((! isset($specifications)) || (gettype($specifications) != 'array')) {
      throw new InvalidArgumentException("Must supply a non-null array.");
    }

    $this -> specifications = $specifications;
  }


  public function getSpecifications() {
    return $this -> specifications;
  }


  public function setInfo($info) {
    $this -> info = $info;
  }


  public function getInfo() {
    return $this -> info;
  }

}