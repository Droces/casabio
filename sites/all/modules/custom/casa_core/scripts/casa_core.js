/**
 * @file
 * A JavaScript file for…
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

var security_token =      '';


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.casa_core = {
  attach: function(context, settings) {
    // console.log('settings: ', settings);

    if (! page_is_setup) {

      // console.log('settings["node_info"]["fields_info"]: ', settings['node_info']['fields_info']);

      site_url = settings.basePath;
      api_url = site_url + 'services'; // using RESTful module

      Drupal.casa_core.fetch_token();

      set_up_pages(context);

      set_up_toastr();

      set_up_dialogs(context);

      page_is_setup = true;
    }

    add_listeners(context, settings);

  },
  weight: 1
};



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


  fetch_token: function() {
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
      console.log( "In fetch_token() jqxhr.fail(), data: ", data );
    });

    jqxhr.done(function( data ) {
      // console.log( "In fetch_token() jqxhr.done(), data: ", data );
      // security_token = data['token'];
      security_token = data['access_token'];
      // console.log('security_token: ', security_token);
    });

    jqxhr.done(function( data ) {});
  },


  get_token: function() {
    return security_token;
  },


  /**
   * Converts an array to an object.
   */
  toObject: function(arr) {
    var rv = {};
    for (var i = 0; i < arr.length; ++i)
      rv[i] = arr[i];
    return rv;
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
  },


  get_loader_markup: function() {
    var markup =
    '<div class="loader" id="floatingCirclesG">' +
    '  <div class="f_circleG" id="frotateG_01"></div>' +
    '  <div class="f_circleG" id="frotateG_02"></div>' +
    '  <div class="f_circleG" id="frotateG_03"></div>' +
    '  <div class="f_circleG" id="frotateG_04"></div>' +
    '  <div class="f_circleG" id="frotateG_05"></div>' +
    '  <div class="f_circleG" id="frotateG_06"></div>' +
    '  <div class="f_circleG" id="frotateG_07"></div>' +
    '  <div class="f_circleG" id="frotateG_08"></div>' +
    '</div>';
    return markup;
  }

};



function set_up_pages(context) {

  // Adds div element that will contain information about keyboard shortcuts.
  $( 'body', context).append("<div id='display-shortcuts' data-transform='to-dialog' style='display: none;' title='Keyboard Shortcuts'></div>");

  // Transform elements to dialogs.
  var to_dialog = $('[data-transform="to-dialog"]', context);
  to_dialog.each(function(index, element) {
    var width = $(this).attr('data-width');
    // console.log('width: ', width);
    width = typeof width != 'undefined' ? width : 600;

    $(this).dialog({
      modal: true,
      autoOpen: false,
      resizable: false,
      width: width
    });
    // $('[data-transform="to-dialog"]').dialog('open');
});

  // @todo Parse data-width="450" as the width of the dialog.

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

    if (do_open) {
      $(target).dialog('open');
    }
  });

  var id_agreement_form = $('.node-identification-form[data-view-mode="agreement"]', context);
  id_agreement_form.submit(function( event ) {
    // event.preventDefault();
    submit_identification_agreement($(this));
    return false; // return false to cancel form action
  });

  var id_contribute_new_form = $('.node-identification-form[data-view-mode="contribute_new"]', context);
  id_contribute_new_form.submit(function( event ) {
    // event.preventDefault();
    submit_identification_contribute_new($(this));
    return false; // return false to cancel form action
  });
}


function submit_identification_agreement(form) {
  // console.log('form: ', form);

  var observation = form.parents('.node-observation').attr('data-nid');
  var species = form.find('[name="identified_species_nid"]').val();
  var certainty = form.find('#edit-field-certainty-und option:checked').val();
  var source = form.find('#edit-field-identification-source-und option:checked').val();

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


function submit_identification_contribute_new(form) {
  // console.log('form: ', form);

  var taxon_values = Drupal.casa_core.get_values_from_ref_view(form.parents('.full-form'));
  var taxon_tid = taxon_values[0];
  var taxon_name = taxon_values[1];

  if (!taxon_tid) {
    toastr.warning('You need to select a taxon before saving.');
    return null;
  }

  var observation = form.parents('.node-observation').attr('data-nid');
  var species = taxon_tid;
  var certainty = form.find('#edit-field-certainty-und option:checked').val();
  var source = form.find('#edit-field-identification-source-und option:checked').val();

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


function submit_identification(identification) {
  // console.log('identification: ', identification);

  var request_params = {
    // url: form.attr('action'),
    type: 'POST',
    contentType: "application/json",
      headers: {
        "access_token": Drupal.casa_core.get_token()
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
    var reload_timeout = window.setTimeout(function(){
      document.location.reload();
    }, 3000);
  });

  jqxhr.always(function( data ) {
    toastr_info.remove();
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


/**
 * Creates JCarousel for background images.
 */
function switch_background(carousel_item_selector) {

  var stay_duration = 5 * 1000; // 5 seconds in milliseconds.
  var animation_speed = 'slow';

  var carousel_item = $(carousel_item_selector);
  var carousel_length = carousel_item.length; // How many items (li).
  var current_item = carousel_length;

  var change_item = function () { // Changes the background image.

    carousel_item.eq(current_item-1).fadeOut(animation_speed , function () {

      carousel_item.eq(current_item-1).css("z-index","-2") // Send to back .
      carousel_item.eq(current_item-1).show(); // Show item again , after is has faded.

      current_item -= 1; // Decrement for next item.

      if (current_item == 0) { // If no more items.
        current_item = carousel_length;  //reset current_item.
      }

      if (current_item == carousel_length) { // If carousel has reached end.
        carousel_item.css("z-index","-1") // Bring all forward.
      }

    });
  };

  setInterval( change_item, stay_duration ); // Interval between changes.
}


})(jQuery, Drupal, this, this.document);
