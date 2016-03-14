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
Drupal.behaviors.casa_core = {
  attach: function(context, settings) {

    set_up_pages(context);

    add_listeners(context);

    set_up_toastr();

    set_up_dialogs(context);

  },
  weight: 1
};



Drupal.casa_core = {

  /* CONTENTS

    set_up_keypress_mgmt
   */



  set_up_keypress_mgmt: function(context) {
    Drupal.casabio.add_keypress_info(
      "<tr><td><strong>shift</strong> <small>+</small> <strong>/</strong> : </td><td>Show shortcuts</td></tr>"
      + "<tr><td><strong>esc</strong> : </td><td>Close windows</td></tr>"
    );

    $(document, context).bind('keydown', 'shift+/',   handle_keypress_see_shortcuts);
    $(document, context).bind('keydown', 'x',         handle_keypress_select);
    $(document, context).bind('keydown', 'c',         handle_keypress_unselect_all);
    $(document, context).bind('keydown', 'left',      handle_keypress_prev);
    $(document, context).bind('keydown', 'right',     handle_keypress_next);
  },



  // Retrieves the nid from the current path.
  // Should only be called within the 'Contribute MO section'.
  get_collection_nid: function() {
    var path = window.location.pathname;
    var path_parts = path.split('/');
    var nid = path_parts[path_parts.length - 1];
    // console.log( "collection: " + collection );
    return nid;
  },



  close_dialogs: function() {
    // console.log("Called: Drupal.casa_core.close_dialogs()");
    // Hide the form dialog
    fields_altered = [];
    $('.ui-dialog[role="dialog"] .ui-dialog-content').dialog('close');
  }

};



function set_up_pages(context) {

  // Adds div element that will contain information about keyboard shortcuts.
  $( 'body', context).append("<div id='display-shortcuts' data-transform='to-dialog' style='display: none;' title='Keyboard Shortcuts'></div>");

  // Transform elements to dialogs.
  $('[data-transform="to-dialog"]', context).dialog({
    modal: true,
    autoOpen: false,
    resizable: false
  });
  // $('[data-transform="to-dialog"]').dialog('open');

}



/**
 * Adds event listeners to page elements.
 */
function add_listeners(context) {

  // Display a dialog when open button clicked.
  $('[data-display]').click(function(event) {
    event.preventDefault();
    var target = $(this).attr('data-display');
    // console.log('target: ', target);
    var do_open = true;

    if (target == 'number-specimens') {
      // If no observations are selected, display warning.
      var num_selected = Drupal.selection.get_selecteds_indexes().length;
      if (! num_selected > 0) {
        toastr.warning('You need to select at least one observation.');
        var do_open = false;
      }
    }

    if (do_open) {
      $(target).dialog('open');
    }
  });


  // Dialogs

  // When a dialog is opened.
  $( ".ui-dialog[role='dialog']", context ).on( "dialogopen", function( event, ui ) {
    // console.log('dialog opened');

    // When the overlay is clicked, close dialogs. 
    $( '.ui-widget-overlay', context ).on( 'click', function(event) {
      Drupal.casa_core.close_dialogs();
    });
  });
}



function set_up_dialogs(context) {
  // Bind a click handler on the ctools modal dialog's backdrop that closes that modal.
  $('#modalBackdrop', context).once('ctools-backdrop-close-modal')
  .click(function() {
    Drupal.CTools.Modal.dismiss();
    return false;
  });
}



function set_up_toastr() {
  // These are simply global settings that can be overridden on specific pages.
  toastr.options.closeButton =      true;
  toastr.options.newestOnTop =      false;
  toastr.options.positionClass =    'toast-bottom-left';
  // toastr.options.showMethod =       'slideDown';
  // toastr.options.hideMethod =       'slideUp';
  // toastr.options.closeMethod =      'fadeOut';
  // toastr.options.timeOut =          0;
  // toastr.options.extendedTimeOut =  0;
}


})(jQuery, Drupal, this, this.document);