/**
 * @file
 * A JavaScript file for…
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

// var page_is_setup = false;


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.es_maps = {
  attach: function(context, settings) {
    // console.log('es_maps');

    // if (! page_is_setup) {

    //   page_is_setup = true;
    // }

  }/*,
  weight: 10*/
};


Drupal.es_maps = {

  set_field_value: function(value) {
    // console.log('Called: Drupal.es_maps.set_field_value()');
  }
}



})(jQuery, Drupal, this, this.document);
