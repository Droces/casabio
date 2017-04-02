/**
 * @file
 * Functions needed on all or most pages of CasaBio.
 */

/**
 * CONTENTS
 *
 * - variable declarations -
 *
 * Drupal.behaviors.casa_core.attach()
 *
 * Drupal.casa_core
 *  .get_site_url()
 *  .get_api_url()
 *  .get_api_resource_url()
 *  .fetch_token()
 *  .get_token()
 *  .set_up_keypress_mgmt()
 *  .get_collection_nid()
 *  .close_dialogs()
 *  .get_values_from_ref_view()

 *  .set_up_dialogs()
 *  .add_listeners()
 *  .submit_identification_agreement()
 *  .submit_identification_contribute_new()
 *  .submit_identification()
 *  .set_up_toastr()
 *  .//switch_background()
 *  .set_up_userlink_hover_dialogs
 */


// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

var page_is_setup = false;

var site_url; // =                'http://localhost/Current/CasaBio/';
// var site_url =                'http://stage.touchdreams.co.za/CsB/';

// var api_url =                 site_url + 'api/v1.0'; // using Services module
var api_url; // =                 site_url + 'services'; // using RESTful module

var security_token =      null;

var timers = {};


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.casa_core = {
  attach: function(context, settings) {
    // console.log('settings: ', settings);

    if (! page_is_setup) {
      // Drupal.casa_utilities.start_timer('casa_core');

      // console.log('settings["node_info"]["fields_info"]: ', settings['node_info']['fields_info']);

      site_url = settings.basePath;
      if (! site_url) {
        throw "site_url not found";
      }
      api_url = site_url + 'services'; // using RESTful module

      if (settings['user']['is_logged_in']) {
        Drupal.casa_core.fetch_token();
      }

      set_up_dialogs(context);

      $('.views-exposed-form').tooltip();

      set_up_toastr();

      set_up_userlink_hover_dialogs(context);

      $('a[disabled]').on('click', function(event) {
        // Check if it still has the disabled attributed
        if ($(this).attr('disabled')) {
          event.preventDefault();
        }
      });

      // Drupal.casa_utilities.end_timer('casa_core');
      page_is_setup = true;
    }

    add_listeners(context, settings);

  },
  weight: 1
};



function ParamException(message) {
  this.message = message;
  this.name = 'ParamException';
}



Drupal.casa_core = {

  /* CONTENTS

    set_up_keypress_mgmt
   */


  get_site_url: function() {
    return site_url;
  },

  get_api_url: function() {
    return api_url;
  },

  get_api_resource_url: function(resource) {
    var resource_urls = {
      observation: api_url + '/v0.1/observations',
      picture: api_url + '/v0.1/pictures',
      identification: api_url + '/v0.1/identifications',
      interaction: api_url + '/v0.1/interactions'
    }
    return resource_urls[resource];
  },


  fetch_token: function(success_callbacks, always_callbacks) {
    var ajax_settings = {
      // type: "POST",
      type: "GET",
      contentType: "application/json",
      // url: api_url + '/users/token'
      url: api_url + '/login-token',
    }
    var jqxhr = $.ajax(ajax_settings);

    jqxhr.fail(function( data ) {
      toastr.error('Sorry, there was a problem fetching the security token.');
      console.log( 'jqxhr: ', jqxhr);
    });

    jqxhr.done(function( data ) {
      // console.log( "In fetch_token() jqxhr.done(), data: ", data );
      // security_token = data['token'];
      security_token = data['access_token'];
      // console.log('security_token: ', security_token);

      Drupal.casa_utilities.invoke_callbacks(success_callbacks);
    });

    jqxhr.done(function( data ) {});
  },


  get_token: function() {
    return security_token;
  },


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
  },


  /**
   * Searches through a 'select species' form (within a table view) for the species tid and name.
   */
  get_values_from_ref_view: function(view_container) {

    var species_selection_form = view_container.find('[id^="views-form-species-reference-selector"]');
    // console.log('species_selection_form: ', species_selection_form);

    // var taxon = form.find('input#edit-field-identified-species-und').val();
    var taxon_tid = species_selection_form.find('input[type="radio"]:checked').val();
    var taxon_name = species_selection_form.find('input[type="radio"]:checked')
      .parents('tr').find('.views-field-name a').html();
    // console.log('taxon_tid: ', taxon_tid);

    return [taxon_tid, taxon_name];
  }

};


function get_dialogs_position() {
  return {
    my: "center top",
    at: "center top+45",
    of: window,
    collision: 'none' };
}


function set_up_dialogs(context) {

  // Adds div element that will contain information about keyboard shortcuts.
  $( 'body', context).append("<div id='display-shortcuts' data-transform='to-dialog' style='display: none;' title='Keyboard Shortcuts'></div>");

  // Transform elements to dialogs.
  var to_dialog = $('[data-transform="to-dialog"]', context);

  to_dialog.each(function(index, element) {

    var width = $(this).attr('data-width');
    width = typeof width != 'undefined' ? width : 600;
    // console.log('width: ', width);
    
    var is_modal = $(this).attr('data-is-modal');
    is_modal = typeof is_modal != 'undefined' ? is_modal : true;

    var is_resizable = $(this).attr('data-is-resizable');
    is_resizable = typeof is_resizable != 'undefined' ? is_resizable : false;


    $(this).dialog({
      modal: is_modal,
      autoOpen: false,
      resizable: is_resizable,
      width: width,
      position: get_dialogs_position(),
      open: function( event, ui ) {
        $(document).trigger('dialog_opened');
      },
      close: function( event, ui ) {
        $(document).trigger('dialog_closed');
      }
    });
    // $('[data-transform="to-dialog"]').dialog('open');
  });


  // Bind a click handler on the ctools modal dialog's backdrop that closes that modal.
  $('#modalBackdrop', context).once('ctools-backdrop-close-modal')
  .click(function() {
    Drupal.CTools.Modal.dismiss();
    return false;
  });
  $(document).on('dialog_opened', function(event) {
    // Bind a click handler on the modal dialogs' backdrops that closes modals.
    $('.ui-widget-overlay', context).once('backdrop-close-modal').click(function() {
      // console.log('.ui-widget-overlay.click()');
      to_dialog.dialog( "close" );
    });
  });
}



/**
 * Adds event listeners to page elements.
 */
function add_listeners(context, settings) {

  // Display a dialog when open button clicked.
  $('[data-display]', context).click(function(event) {
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

    if (target == '.edit_form_wrapper') {}
      
    if (do_open) {
      $(target).dialog('open');
    }
  });

  // Handle submission of 'identification agreement form'
  var id_agreement_form = $('.node-identification-form[data-view-mode="agreement"]', context);
  id_agreement_form.submit(function( event ) {
    // event.preventDefault();
    try {
      submit_identification_agreement($(this));
    }
    catch (e) {
      console.log('e: ', e);
      toastr.error(e.message);
    }
    finally {
      return false; // Cancels form action
    }
  });

  // Handle submission of 'add new identification form'
  var id_contribute_new_form = $('.node-identification-form[data-view-mode="contribute_new"]', context);
  id_contribute_new_form.submit(function( event ) {
    // event.preventDefault();
    var identify_form_wrapper = $(this).parents('.identify_form_wrapper');
    submit_identification_contribute_new(identify_form_wrapper);
    return false; // return false to cancel form action
  });
}


function submit_identification_agreement(form) {
  // console.log('form: ', form);

  var observation = form.parents('.node-observation').attr('data-nid');
  var species = form.find('[name="identified_species_nid"]').val();
  var certainty = form.find('[name="field_certainty[und]"] option:checked').val();
  var source = form.find('[name="field_identification_source[und]"] option:checked').val();

  if (! observation) {
    throw new ParamException('Observation not valid.');
  }
  if (! species) {
    throw new ParamException('Species not valid.');
  }
  if (! certainty) {
    throw new ParamException('Please select how certain you are.');
  }
  if (! source) {
    throw new ParamException('Source not valid.');
  }

  var identification = {
    // label: "string",
    observation: observation,
    identifiedSpecies: species,
    certainty: certainty,
    identificationSource: source
  };
  // console.log('identification: ', identification);

  submit_identification(identification);
}


/**
 * Manages the saving of a "Add identification" form from within a full-page observation.
 * 
 * @param form
 *   An HTML wrapper containing the species chooser view and the simplified identification form.
 */
function submit_identification_contribute_new(form) {
  // console.log('form: ', form);

  var taxon_values = Drupal.casa_core.get_values_from_ref_view(form);
  // console.log('taxon_values: ', taxon_values);
  var taxon_tid = taxon_values[0];
  var taxon_name = taxon_values[1];

  if (!taxon_tid) {
    toastr.warning('You need to select a taxon before saving a new identification.');
    return null;
  }

  var observation = form.parents('.node-observation').attr('data-nid');
  var species = taxon_tid;
  var certainty = form.find('[name="field_certainty[und]"] option:checked').val();
  var source = form.find('[name="field_identification_source[und]"] option:checked').val();

  if (! observation) {
    throw new ParamException('Observation not valid.');
  }
  if (! species) {
    throw new ParamException('Please select a species.');
  }
  if (! certainty) {
    throw new ParamException('Please select how certain you are.');
  }
  if (! source) {
    throw new ParamException('Source not valid.');
  }

  var identification = {
    label: taxon_name,
    observation: observation,
    identifiedSpecies: species,
    certainty: certainty,
    identificationSource: source
  };
  // console.log('identification: ', identification);

  submit_identification(identification);
}


/**
 * Manages "add identification" form submission from an Observation node page.
 */
function submit_identification(identification, success_callbacks, always_callbacks) {
  console.log( 'identification for submission: ', identification);

  var request_params = {
    // url: form.attr('action'),
    type: 'POST',
    contentType: "application/json",
      headers: {
        "access-token": Drupal.casa_core.get_token()
        // Session id header is not specified, because it's automatically added by browser (it's a cookie).
      },
    url: Drupal.casa_core.get_api_resource_url('identification'),
    data: JSON.stringify(identification, null, 2),
  };

  var toastr_info = toastr.info('Saving identification…'); // @todo add an 'undo' button

  // Send jq xhr request.
  var jqxhr = $.ajax(request_params);

  jqxhr.error(function(data) {
    toastr.error('Sorry; there was a problem saving your identification.');
    console.log( "In ajax.error(), data: ", data );
  });

  jqxhr.success(function(data) {
    toastr.success('Your identification has been saved successfully. Reloading in 3 seconds…');

    Drupal.casa_utilities.invoke_callbacks(success_callbacks);

    var reload_timeout = window.setTimeout(function(){
      document.location.reload();
    }, 3000);
  });

  jqxhr.always(function( data ) {
    toastr_info.remove();
    Drupal.casa_utilities.invoke_callbacks(always_callbacks);
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


// /**
//  * Creates JCarousel for background images.
//  */
// function switch_background(carousel_item_selector) {

//   var stay_duration = 5 * 1000; // 5 seconds in milliseconds.
//   var animation_speed = 'slow';

//   var carousel_item = $(carousel_item_selector);
//   var carousel_length = carousel_item.length; // How many items (li).
//   var current_item = carousel_length;

//   var change_item = function () { // Changes the background image.

//     carousel_item.eq(current_item-1).fadeOut(animation_speed , function () {

//       carousel_item.eq(current_item-1).css("z-index","-2") // Send to back .
//       carousel_item.eq(current_item-1).show(); // Show item again , after is has faded.

//       current_item -= 1; // Decrement for next item.

//       if (current_item == 0) { // If no more items.
//         current_item = carousel_length;  //reset current_item.
//       }

//       if (current_item == carousel_length) { // If carousel has reached end.
//         carousel_item.css("z-index","-1") // Bring all forward.
//       }

//     });
//   };

//   setInterval( change_item, stay_duration ); // Interval between changes.
// }



function set_up_userlink_hover_dialogs(context) {
  // var user_links = $('main a[href*="/user/"], main a[href*="/users/"]', context);
  var user_links = $('main a.user-link', context);

  user_links.each(function() {
    var href = $(this).attr('href');
    var username = href.substring(href.lastIndexOf('/') + 1);
    // console.log('username: ', username);

    // $(this).append('-');

    $(this).attr('data-username', username);

    var dialog_element = $('.user-dialog[data-username="' + username + '"]');
    // console.log('.user-dialog[data-username="' + username + '"].length: ', dialog_element.length);

    if (dialog_element.length < 1) { // If it doesn't exist yet
      var dialog = $('<div class="user-dialog" data-username="' + username + '">Loading…</div>');
      $(this).after(dialog);
      
      dialog.dialog({
        autoOpen: false,
        width: 450,
        position: get_dialogs_position()
      }); 
    }
  });

  // $('.user-dialog').each(function{
  // });

  // When a link to a user is hovered, show a dialog displaying user info
  user_links.on('mouseenter', function() {
    // console.log('User linked hovered');

    var link = this;

    // show_userlink_hover_dialog(this);

    var user_link_delay = 0.8; // In seconds
    setTimeout(function(){
        show_userlink_hover_dialog(link);
    }, user_link_delay * 1000);
  });

  $('a[href*="/user/"], a[href*="/users/"]').on('mouseleave', function() {
    var username = $(this).attr('data-username');
    var dialog_element = $('.user-dialog[data-username="' + username + '"]');
    dialog_element.dialog( "close" );
  });

  page_is_setup = true;
}

/**
 * Creates a dialog used to alert of ungrouped pictures when moving to next phase.
 */
Drupal.theme.group_individuals_dialog = function () {
}


function show_userlink_hover_dialog(link) {
    var username = $(link).attr('data-username');
    // console.log('username: ', username);
    var dialog_element = $('.user-dialog[data-username="' + username + '"]');
    // console.log('dialog_element.length: ', dialog_element.length);

    if (! dialog_element.hasClass('dialog-fetched')) {
      var username = dialog_element.attr('data-username');
      var url = Drupal.casa_core.get_site_url() + '/user/tooltip/' + username;

      dialog_element.load(url, function(){
        // console.log('opened');
        dialog_element.dialog( "open" );
      });
      dialog_element.addClass('dialog-fetched');
    }

    dialog_element.dialog( "open" );
}


})(jQuery, Drupal, this, this.document);
