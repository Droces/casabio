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
Drupal.behaviors.maintain = {
  attach: function(context, settings) {

    // $('main').append('<fieldset class="form">Loading the edit form here…</fieldset>');
    // var nid = $('.view-id-most_popular_taxon .view-content tbody td.views-field-tid-1').html().trim();
    
    // $('main .form').load(
    //   Drupal.settings.basePath + 'ajax/popular_taxa_form/' + nid,
    //   function( response, status, xhr ) {
    //     if ( status == "error" ) {
    //       toastr.error('Sorry; there was a loading the edit form.');
    //       console.log( "response: ", response );
    //       console.log( "xhr: ", xhr );
    //       $('main .form').html('Could not load the edit form.');
    //     }
    //   }
    // );


  }/*,
  weight: 1*/
};


})(jQuery, Drupal, this, this.document);