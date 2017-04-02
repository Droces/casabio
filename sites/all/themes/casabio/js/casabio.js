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

// var is_mouse_down = false;

// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.casabio = {
  attach: function(context, settings) {
    // console.log('Called: Drupal.behaviors.casabio.attach()');
    // console.log('context: ', context);
    // console.log('settings: ', settings);

    // Drupal.casa_core.start_timer('casabio_theme');

    // $(document).mousedown(function() {
    //   is_mouse_down = true;
    // }).mouseup(function() {
    //   is_mouse_down = false;  
    // });

    set_up_pages(context);

    add_listeners(context);

    // set_up_masonry();

    // Highlight 'Drop to upload'
    // $('.plupload_droptext').on('mouseenter', function() {
    //   if (is_mouse_down) {
    //     $(this).addClass('mouseOver');
    //   }
    // })
    // .on('mouseleave', function() {
    //   $(this).removeClass('mouseOver');
    // });

    // Drupal.casa_core.end_timer('casabio_theme');

    // animate_teaser_transforms();

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
  $('form .required', context).attr('required', true);

  // Choice-block
  var choice_blocks = $('.choice-block', context);
  choice_blocks.children().on('click', function() {
    $(this).siblings().attr('aria-selected', null);
    $(this).siblings().find('input[type="checkbox"]').prop('checked', false);
    // $(this).siblings().find('input').prop('disabled', true);

    $(this).attr('aria-selected', true);
    $(this).find('input[type="checkbox"]').prop('checked', true);
    // $(this).find('input').prop('disabled', null);
  });
}



/**
 * Adds event listeners to page elements.
 */
function add_listeners(context) {

  // console.log('close buttons count: ', $('.messages [data-action="remove"]', context).length);
  $('.messages [data-action="remove"]', context).on('click', function() {
    if($(this).parent().is('li:first-child:last-child')) {
      $(this).parents('.messages').remove(); // Also removes $(this)
    }
    else {
      $(this).parent().remove();
    }
  });

  // Tabs
  $('[role="tab"]', context).on('click', function() {
    $(this).parent().find('[role="tab"][aria-selected]')
      .attr('aria-selected', null);
    $(this).parent().siblings('[role="tabpanel"][aria-selected]')
      .attr('aria-selected', null);

    $(this).attr('aria-selected', true);
    $('[role="tabpanel"][data-name="' + $(this).attr('data-name') + '"]')
      .attr('aria-selected', true);
  });

  // Views with bulk operations
  // Clicking on a row selects the item
  $('.view form table', context).find('tr').on('click', function() {
    $(this).find('input[type="radio"]').prop( "checked", true );
  });

  $('.expandable').find('[role="expand"]').on('click', function() {
    var container = $(this).parents('.expandable');

    if (container.attr('data-expanded') == 'true') {
      console.log('contracting');
      $(this).parents('.expandable').animate({height: 250}, 'slow');
      container.attr('data-expanded', 'false');
    }
    else {
      console.log('expanding');
      var height = container.children().height();
      console.log('height: ', height);
      $(this).parents('.expandable').animate({height: height}, 'slow');
      container.attr('data-expanded', 'true');
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
 * Experimental: Community identification teasers
 * On click: Animate to / from shown 'as text'
 */
function animate_teaser_transforms() {

  $('[data-type="identification_community"]').on('click', function() {
    $(this).toggleClass('as-text');

    var rectObject = $(this)[0].getBoundingClientRect();
    console.log('rectObject: ', rectObject);

    var wrapper = $('<div></div>')
      .css('display',   'block')
      .css('width',     $(this).width())
      .css('height',    $(this).height())
      .css('background', 'red')
    ;
    $(this)
      .wrap(wrapper)
      .css('position',  'fixed')
      .css('left', rectObject.x)
      .css('top', rectObject.y)
    ;
    $(this).animate({
        left: '200px',
        top: '200px'
      },
      500,
      function() {
        // Animation complete.
    });

  });
}


/**
 * Calculates the position of a given element within the viewport
 *
 * @param {string} obj jQuery object of the dom element to be monitored
 * @return {array} An array containing both X and Y positions as a number
 * ranging from 0 (under/right of viewport) to 1 (above/left of viewport)
 */
function visibility(obj) {
    var winw = jQuery(window).width(), winh = jQuery(window).height(),
        elw = obj.width(), elh = obj.height(),
        o = obj[0].getBoundingClientRect(),
        x1 = o.left - winw, x2 = o.left + elw,
        y1 = o.top - winh, y2 = o.top + elh;

    return [
        Math.max(0, Math.min((0 - x1) / (x2 - x1), 1)),
        Math.max(0, Math.min((0 - y1) / (y2 - y1), 1))
    ];
}


})(jQuery, Drupal, this, this.document);
