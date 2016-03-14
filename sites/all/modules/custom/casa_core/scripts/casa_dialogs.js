/**
 * @file
 * A JavaScript file for…

 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {



Drupal.casa_dialogs = {

  /* CONTENTS

    to_dialog
    close_dialogs
   */


  to_dialog: function(element, title, has_close, is_modal) {
    element.before('<button>Button</button>');
    element.attr('role', 'dialog');

    return 'dialog_id';
  },



  close_dialogs: function(dialog_ids) {
    // Hide the form dialog
    fields_altered = [];
    $( form_region_selector ).attr( 'aria-hidden', true );
    $( '.cover' ).removeClass('visible');
    $( '.cover' ).attr( 'aria-hidden', true );
  }


};


})(jQuery, Drupal, this, this.document);


