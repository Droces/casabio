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
Drupal.behaviors.contribute = {
  attach: function(context, settings) {



  }/*,
  weight: 6*/
};



Drupal.contribute = {

  get_collection_nid: function() {
    var path = window.location.pathname;
    var path_parts = path.split('/');
    var nid = path_parts[path_parts.length - 1];
    // console.log( "collection: ", collection );
    return nid;
  }

};


})(jQuery, Drupal, this, this.document);