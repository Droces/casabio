/**
 * @file
 * A JavaScript file for…
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.contribute_maps = {
  attach: function(context, settings) {
    // console.log('Called: Drupal.behaviors.contribute_maps');
    // console.log('context: ', context);
    // console.log('settings: ', settings);

    add_listeners(context, settings);

  },
  weight: 11
};



/**
 * Adds event listeners to page elements.
 */
function add_listeners(context, settings) {

  $( window ).load(function() {
    // console.log('window has loaded');

    // On Upload page, in the map, set path ('linestring') as default edit mode.
    var button_selector = '.page-contribute-upload .openlayers-map-container button.ol-geofield-linestring';
    $(button_selector).trigger('click');
  });
}



})(jQuery, Drupal, this, this.document);
