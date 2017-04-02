/**
 * @file
 *   Provides functions that enable the selection of elements on a webpage, which can then be manipulated.
 *
 * HTML elements on the webpage that have a class containing '.selectable'
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


/**
 * CONTENTS
 *
 * - variable declarations -
 *
 * Drupal.behaviors.selection.attach()
 *
 * Drupal.edit_selected
 *  .find_selectables()
 *  .get_selecteds_indexes()
 *  .are_selecteds()
 *  .set_selecteds_indexes()
 *  .selecteds_indexes_push()
 *  .selecteds_indexes_remove()
 *  .add_selection_listeners()
 *  .get_selected_selectables() // Simplest get function.
 *  .get_selected_nids()
 *  .get_selectable()
 *  .get_index()
 *  .deselect()
 *  .deselect_all()
 */

/*
 * @todo Change primary storage array `selecteds_indexes`
 * to store the jQ elements rather than their 'indexes' (unreliable!).
 */

var page_is_setup = false;

var selectables; // View row numbers of the
// The selecteds array temporarily stores the 'pictures' that are currently selected
// The indexes refer to the 'result numbers' of the elements within the view content (for easy JQuery retrieval)
var selecteds_indexes = []; // View row numbers of the

var mouseIsDown = false;   // Tracks status of mouse button

var shift_key_down = false;



// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.selection = {
  attach: function(context, settings) {
    // console.log('context: ', context);
    // console.log('context: ', $(context));
    // console.log('selectables: ', selectables);

    if (! page_is_setup) {

      // disable_image_drag(); // Not needed anymore.

      Drupal.selection.find_selectables();

      register_focus( selectables.eq(0) );

      set_up_keypress_mgmt(context);

      set_up_page(context);

      $(document).mousedown(function(event) {
        // event.preventDefault();
        mouseIsDown = true;      // When mouse goes down, set mouseIsDown to true
        // return false;
      })
      .mouseup(function() {
        mouseIsDown = false;    // When mouse goes up, set mouseIsDown to false
      });

      selectables.each(function() {
        Drupal.selection.add_selection_listeners($(this));
      });

      $( '#deselect_all', context ).click( function() {
        Drupal.selection.deselect_all();
      });


      page_is_setup = true;
    }

  },
  weight: 3
};

Drupal.selection = {

  find_selectables: function(context) {
    if (typeof context === 'undefined') {
      context = document;
    }
    selectables = $('.selectable', context);
  },

  get_selecteds_indexes: function() {
    return selecteds_indexes;
  },

  are_selecteds: function() {
    var num_selected = Drupal.selection.get_selecteds_indexes().length;
    return num_selected > 0 ? true : false;
  },

  set_selecteds_indexes: function( array ) {
    selecteds_indexes = array;
  },

  selecteds_indexes_push: function( index ) {
    selecteds_indexes.push(index);
  },

  selecteds_indexes_remove: function( index ) {
    selecteds_indexes.splice( $.inArray( index, selecteds_indexes), 1 );
  },


  /**
   * The first element could after the last element (if select was made in reverse).
   */
  select_multiple: function( first_element, last_element ) {
    // console.log('first_element: ', first_element);
    // console.log('last_element: ', last_element);

    var select_on = false;
    selectables.each(function(key, element) {
      var selectable = $(element);

      if (selectable.is(first_element) || selectable.is(last_element)) {
        if (! select_on) {
          select_on = true;
        }
        else {
          register_selection( selectable ); // For the last one.
          select_on = false;
        }
      }

      if (select_on && (! selectable.hasClass('selected'))) {
        register_selection( selectable );
      }

    });
  },

  add_selection_listeners: function(selectable) {
    selectable.find('.selectable-target').mousedown( function(event) {
      event.preventDefault(); // Prevents browser's "text selection"

      var selectable = $(this).parents('.selectable');

      if (shift_key_down) {
        Drupal.selection.select_multiple(
          selectables.filter('.focussed'),
          selectable
        );
      }
      else {
        register_selection( selectable );
      }
      register_focus( selectable );
    });

    selectable.find('.selectable-target').mouseenter( function(event) {
      var selectable = $(this).parents('.selectable');

      if (mouseIsDown) {
        register_selection( selectable );
      }
    });
  },



  /**
   * @returns a list of Jquery elements
   */
  get_selected_selectables: function(id) {
    var selecteds_indexes = Drupal.selection.get_selecteds_indexes();
    // console.log('selecteds_indexes received: ', selecteds_indexes);

    selecteds = [];

    $.each( selecteds_indexes, function( key, index ) {
      selecteds.push(selectables.filter('.views-row-' + index ));
      // console.log('elements: ', element.length);
    });

    return selecteds;
  },



  /**
   * Gets the array of selectable indexes, and creates an array of the nids from it.
   */
  get_selected_nids: function() {
    var selecteds_indexes = Drupal.selection.get_selecteds_indexes();
    // console.log('selecteds_indexes received: ', selecteds_indexes);

    selecteds_nids = [];

    $.each( selecteds_indexes, function( key, index ) {
      var selectable = selectables.filter('.views-row-' + index );
      // console.log('elements: ', selectable.length);
      var nid = selectable.find( ".property-nid" ).html().trim();
      // console.log('nid: ', nid);
      selecteds_nids.push( nid );
    });

    // console.log('selecteds_nids: ', selecteds_nids);
    return selecteds_nids;
  },



  /**
   * @returns a Jquery element, regardless of whether it's in a group
   */
  get_selectable: function(id) {
    return selectables.filter('.views-row-' + id );
  },



  /**
   * Determines the position that a result is in within view results.
   */
  get_index: function(target) {
    var index;

    var classes = target.attr( "class" ).split( " " );
    // console.log('classes: ', classes);
    if(classes) {
      // Determine the picture's result number (within view)
      $.each( classes, function( key, value ) {
        // We use "views-row-#" because it's reliable, and doesn't change (as long as the layout is 'list')
        if ( value.substr( 0, 10 ) == "views-row-" ) {
          // console.log('substr: ', value.substr( 10, value.length));
          index = parseInt( value.substr( 10, value.length ), 10 );
        }
        else return;
      });
    }
    return index;
  },



  /**
   * Does not remove the element from the 'selecteds' arrays
   */
  deselect: function(index) {
    // console.log('call: Drupal.selection.deselect()');

    var element = Drupal.selection.get_selectable( index );
    element.removeClass( "selected" );

    adjust_buttons();
    adjust_toolbar();
  },



  /**
   * Calls Drupal.selection.deselect() for all selected elements.
   */
  deselect_all: function() {
    // console.log('call: Drupal.selection.deselect_all()');

    $.each( selecteds_indexes, function( key, index ) {
      Drupal.selection.deselect(index); // Cannot use index as parameter, because the loop won't work
      // Drupal.selection.deselect(selecteds_indexes[0]);
    });
    selecteds_indexes = [];

    adjust_buttons();
    adjust_toolbar();

    $(window).trigger( "selection:deselect_all" );
  }

}




/* CONTENTS

  disable_image_drag()
  set_up_page()
  register_selection()
  register_focus()
  toggle_selected_element()
  adjust_buttons()

  set_up_keypress_mgmt()
  handle_keypress_see_shortcuts()
  handle_keypress_select()
  handle_keypress_prev()
  get_focussed_prev()
  handle_keypress_next()
  get_focussed_next()
  handle_keypress_group()
*/



function disable_image_drag() {
  // Disable firefox's 'image drag' feature, which messes with our ‘drag-select’
  $(document).on("dragstart", function(event) {
    event.preventDefault();
    // console.log('On: dragstart');
    return false;
  });
}


function set_up_page(context) {
  var toolbar = $('[role="toolbar"][aria-label="primary toolbar"]', context);

  $( '.page__title', context )
    .after('<div class="action_buttons"></div>');
  toolbar
    .append("<button id='deselect_all' type='button' disabled>Un-select all</button>");
  toolbar.find('#deselect_all').prepend("<span class='icon-select_all'></span> ");
}



/**
 * Adds or removes the result number from the selected array.
 *
 * @param target
 *   JQuery object that was selected or unselected.
 *
 * @param checked
 *   Boolean indicating if the target's checked attribute should be set to true.
 */
function register_selection(target) {
  // console.log('Call: register_selection');

  var checked = toggle_selected_element( target );
  // console.log('checked: ', checked);

  var index = Drupal.selection.get_index(target);
  // console.log('index: ', index);

  if (checked) {
    // Add the picture to the 'selecteds' arrays
    selecteds_indexes.push( index );
  } else {
    // Remove the picture from the 'selecteds' arrays
    selecteds_indexes.splice( $.inArray( index, selecteds_indexes), 1 );
  }
  // console.log("selecteds_indexes: ", selecteds_indexes);

  adjust_buttons();
  adjust_toolbar();

  target.trigger( "selection:select" );
}



/**
 * Adds or removes the result number from the selected array.
 */
function register_focus(target) {
  selectables.removeClass('focussed');
  target.toggleClass('focussed');
}



/**
 * Toggles the selected state of the selected element.
 *
 * @return boolean
 *   Returns true if the selected element is now 'selected', or false otherwise.
 */
function toggle_selected_element(target) {
  target.toggleClass( "selected" );
  var checked = target.hasClass( "selected" );

  return checked;
}



/**
 * Enables and disables the buttons according to selections.
 */
function adjust_buttons() {

  // if( selecteds_indexes.length ) {
  //   $( '#deselect_all' ).attr('disabled', false);
  // } else {
  //   $( '#deselect_all' ).attr('disabled', true);
  // }
  $( '#deselect_all' ).attr('disabled', selecteds_indexes.length ? false : true);
}



/**
 * Shows or hides the toolbar according to selections.
 */
function adjust_toolbar() {
  var toolbar = $('[role="toolbar"][aria-label*="primary"]');
  toolbar.attr('aria-expanded', selecteds_indexes.length ? true : false);

  toolbar.find('.selection-count .count').html(selecteds_indexes.length);
}



function set_up_keypress_mgmt(context) {
  Drupal.casabio.add_keypress_info(
    "<tr><td><strong>shift</strong> <small>+</small> <strong>/</strong> : </td><td>Show shortcuts</td></tr>"
  );
  // Further keypress info will be customised by page and added by edit_selected.js.
  // Drupal.casabio.add_keypress_info();

  // console.log('document, context: ', $(context).find(document));

  $('body', context).bind('keydown', 'shift+/',   handle_keypress_see_shortcuts);
  $('body', context).bind('keydown', 'x',         handle_keypress_select);
  $('body', context).bind('keydown', 'c',         handle_keypress_unselect_all);
  $('body', context).bind('keydown', 'left',      handle_keypress_prev, context);
  $('body', context).bind('keydown', 'right',     handle_keypress_next, context);

  $('body', context).bind('keydown', 'ctrl+a',     handle_keypress_select_all, context);

  $('body', context).bind('keydown', 'shift',     handle_keypress_shift_down);
  $('body', context).bind('keyup',   'shift',     handle_keypress_shift_up);
}



function handle_keypress_see_shortcuts() {
  // console.log('handle_keypress_see_shortcuts');

  var is_open = $( '#display-shortcuts[style*="display: block"]' ).length > 0;

  if (is_open) {
    $( '#display-shortcuts' ).dialog('close');
  }
  else {
    $( '#display-shortcuts' ).dialog('open');
  }
}

function handle_keypress_select() {
  var focussed = selectables.filter('.focussed');
  register_selection( focussed );
}

function handle_keypress_unselect_all() {
  Drupal.selection.deselect_all();
}

function handle_keypress_prev() {
  var selectable = selectables.filter('.focussed');
  prev = get_focussed_prev(selectable);
  if (prev !== null) {
    register_focus(prev);
  }

  $(window).trigger( "selection:prev", prev );
}

/**
 * Gets the previous selectable before an element (which can be a selectable or a group).
 */
function get_focussed_prev(element) {
  var prev;
  // If in a group and is the last in the group
  if ((element.parent('.group').length > 0) && (element.prev().length == 0)) {
    // console.log('is in group')
    prev = get_focussed_prev(element.parent());
  }
  // If the previous li or ul is a group
  else if (element.prevAll('li, ul').eq(0).hasClass('group')) {
    // console.log('next is group')
    prev = element.prevAll('li, ul').eq(0).children('.selectable').eq(-1);
  }
  // If this is the first selectable
  else if (element.prevAll('.selectable').length == 0) {
    prev = null;
  }
  else {
    prev = element.prevAll('.selectable').eq(0);
  }
  return prev;
}

function handle_keypress_next(context) {
  // console.log('called: handle_keypress_next()');

  var selectable = selectables.filter('.focussed');
  next = get_focussed_next(selectable);
  if (next !== null) {
    register_focus(next);
  }

  $(window).trigger( "selection:next", next );
}


function handle_keypress_select_all(context) {
  Drupal.selection.select_multiple(selectables.first(), selectables.last());
  return false;
}


/**
 * Gets the next selectable following an element (which can be a selectable or a group).
 */
function get_focussed_next(element) {
  // console.log('element class: ', element.attr('class'));

  var next;
  // If in a group and is the last in the group
  if ((element.parent('.group').length > 0) && (element.nextAll('li, ul').eq(0).length == 0)) {
    // console.log('is in group')
    next = get_focussed_next(element.parent());
  }
  // If the next li or ul is a group
  else if (element.nextAll('li, ul').eq(0).hasClass('group')) {
    // console.log('next is group')
    next = element.nextAll('li, ul').eq(0).children('.selectable').eq(0);
  }
  // If this is the last selectable
  else if (element.nextAll('.selectable').length == 0) {
    next = null;
  }
  else {
    next = element.nextAll('.selectable').eq(0);
    // console.log('next class: ', next.attr('class'));
  }
  return next;
}

function handle_keypress_group() {
  group();
}

function handle_keypress_ungroup() {
  ungroup_all();
}

function handle_keypress_shift_down() {
  shift_key_down = true;
}

function handle_keypress_shift_up() {
  shift_key_down = false;
}

})(jQuery, Drupal, this, this.document);
