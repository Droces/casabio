/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.casabio = {
  attach: function(context, settings) {

  set_up_pages(context);

  add_listeners(context);

  // set_up_masonry();

  // set_up_jCarousel();

  },
  weight: 0
};



/**
 * Public functions that can be called by other JavaScript files.
 */
Drupal.casabio = {

  /**
   * Add information about keyboard shortcuts to the info dialog.
   */
  add_keypress_info: function(text) {
    var info_table = $( '#display-shortcuts table' );

    // If it doesn't contain a table yet, append one.
    if(! $( '#display-shortcuts table' ).length > 0) {
      $( '#display-shortcuts' ).append("<table></table>");
    }

    $( '#display-shortcuts table' ).append(text);
  },

};



function set_up_pages(context) {
  
  // Move Cancel button to end of form's actions
  var actions = $('.form-actions', context);
  actions.each(function(index, el) {
    $(this).find('input#cancel')
      .detach()
      .appendTo($(this));
  });

  // No longer used; form is altered by PHP to do this
  // $('fieldset.collapse-on-load', context).addClass('collapsed');

  // Set the HTML5 required attribute for form fields that are required.
  $('form .required').attr('required', true);
}



/**
 * Adds event listeners to page elements.
 */
function add_listeners(context) {

  $('.messages [data-action="remove"]').on('click', function() {
    if($(this).parent().is('li:first-child:last-child')) {
      $(this).parents('.messages').remove(); // Also removes $(this)
    }
    else {
      $(this).parent().remove();
    }
  });
}



/**
 * Enables the Masonry layout library to be used.
 */
// function set_up_masonry() {

//  var $container = $('.view-administer-pictures .view-content');
//  // initialize
//  $container.masonry({
//    columnWidth: 200,
//    itemSelector: '.item-list'
//  });
//  var msnry = $container.data('masonry');

//  // add a class of 'ungrouped' to only the group of pictures not part of an observation
//  $( '.masonry .group h3' ).filter(function() {
//    return $(this).text() === 'Observation: ';
//  }).parent().addClass( "unattached" );

//  var container = document.querySelector('.masonry');
//  var msnry = new Masonry( container, {
//    // options
//    columnWidth:  '.view-content .group:not(.unattached)',
//    // columnWidth:   'masonry-column-sizer',
//    itemSelector:   '.view-header, .view-filters, .group',
//    gutter:     '.masonry-gutter-sizer',
//  });
// }



/**
 * Enables the jCarousel layout library to be used.
 */
// function set_up_jCarousel() {
//  $('.jcarousel')
//    .on('jcarousel:create jcarousel:reload', function() {
//      var element = $(this),
//        width = element.innerWidth();

//      // This shows 1 item at a time.
//      // Divide `width` to the number of items you want to display,
//      // eg. `width = width / 3` to display 3 items at a time.
//      element.jcarousel('items').css('width', width + 'px');
//    })
//    .jcarousel({
//      // Configuration goes here
//      wrap: 'both',
//    })
//    .jcarouselAutoscroll({
//      interval: 3000,
//      target: '+=1',
//      autostart: true
//    })
//  ;

//  $('.jcarousel-prev').jcarouselControl({
//    target: '-=1'
//  });

//  $('.jcarousel-next').jcarouselControl({
//    target: '+=1'
//  });
// }


})(jQuery, Drupal, this, this.document);