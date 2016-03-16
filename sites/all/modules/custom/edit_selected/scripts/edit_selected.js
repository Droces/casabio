/**
 * @file
 * A JavaScript file for…
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

var edit_form_selector =      ".edit_form_wrapper";
var identify_form_selector =  ".identify_form_wrapper";
var fields_selector =         "[class*='form-field-']";
var fields_altered =          [];
var toolbar;

var api_url =                 'http://localhost/Current/CasaBio/api/v1.0';
// var api_url =                 'http://stage.touchdreams.co.za/CsB/api/v1.0';

var focus_field_value;
var focus_field_value_new;

// Maps the selectable (as a jQ object) to the selectable's nid
var selectables_map = {};
var selectables_data = {};
var security_token = '';


$(document).ready(function() {
  // console.log( "ready!" );
  get_selectables_data();
  get_token();
});


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.edit_selected = {
  attach: function(context, settings) {

    toolbar = $('[role="toolbar"][aria-label*="primary"]', context);

    set_up_page(context);

    adjust_buttons(context);

    // set_up_field_progress(context);

    set_up_keypress_mgmt(context);

    add_listeners(context);

  },
  weight: 6
};




/**
 * Local functions
 *
 * onlyUnique()
 * set_up_page()
 * add_listeners()

 * get_selectables_data()           // Called on page load
 * get_collection_nid()
 * get_token()                      // Called on page load
 * save_identification()
 * create_identification()
 * create_identification_obj()

 * expand_empty_reference_fields()  // @deprecated
 * adjust_buttons()
 * manage_field_change()
 * edit_selected_nid_prefiller()
 * edit_selected_form_prefiller()
 * get_field_values()
 * set_field_value()
 * parse_location()
 * create_layer()
 * clear_field_value()
 * get_field_property()
 * get_selected_nids()
 * rotate_selected()
 * manage_form_number_specimens()
 * manage_form_add_blank_obs()
 * set_up_field_progress()
 * show_field_indicators()

 * set_up_keypress_mgmt()
 * handle_keypress_edit()
 * handle_keypress_identify()
 * handle_keypress_close_dialog()
 */


/**
 * Used by array.filter().
 * Checks if the given value is the first occurring.
 * If not, it must be a duplicate, and function will return false.
 */
function onlyUnique(value, index, self) {
  return self.indexOf(value) === index;
}




function set_up_page(context) {
  // console.log('call: edit_selected module: set_up_page()');

  // Transform the edit form and identify form into dialogs
  // $( '#edit-selected-edit-form', context ).dialog({
  $( edit_form_selector, context ).dialog({
    modal: true,
    autoOpen: false,
    resizable: false,
    width: 800,
    title: 'Edit observations',
    open: function( event, ui ) {
      $(document).trigger('edit-selected.edit-form_dialog-opened');
    }
  });
  $( identify_form_selector, context ).dialog({
    modal: true,
    autoOpen: false,
    resizable: false,
    width: 800,
    title: 'Identify observations'
  });

  // Add a message areas to form fields; used to notify about mixed values.
  $( edit_form_selector + ' ' + fields_selector + ' .form-item > label:first-child'
    + ', ' + edit_form_selector + ' .form-item-title label:first-child', context)
    .after('<div class="messages hidden"></div>');

  // Add a 'show' area to the edit form, which will display the image
  // $('.block-edit-selected > .content > h2').after('<div class="show"></div>');
  // $('li.focussed').find('.views-field-field-image')
  //   .clone()
  //   .appendTo('.block-edit-selected .show');

  // Element to contain the value of the selected field when one of the 'show field' radio buttons is clicked
  $('.selectable', context).append('<span class="field-data"></span>');

}



/**
 * Adds event listeners to page elements.
 */
function add_listeners(context) {


  // Disable firefox's 'image drag' feature, which messes with our ‘drag-select’
  $(document, context).on("dragstart", function(e) {
    if (e.target.nodeName.toUpperCase() == "IMG") {
      return false;
    }
  });

  // When a selectable is selected, manage it.
  $('.selectable').on('selection:select', function(event) {
    adjust_buttons();
    edit_selected_form_prefiller();
    edit_selected_nid_prefiller();
  });

  $('button.rotate', context).on( 'click', function(event) {
    event.preventDefault();
    rotate_selected($(this));
  });

  $( 'input, textarea, select' ).on( 'change', function() {
    // Add the changed field's name to the list in the hidden edit_selected_altered_fields field.
    manage_field_change( $( this ) );
  });

  // When a dialog's cancel button is clicked, close the dialog.
  $( 'input[value="Cancel"]', context ).on( 'click', function(event) {
  // $( '#cancel', context ).on( 'click', function(event) { // Doesn't work because id finds just one.
    event.preventDefault();
    var dialog = $(this).parents('.ui-dialog-content');
    dialog.dialog('close');
  });

  // The buttons at the top of the pages that show which fields have values.
  var field_shown = null;
  $('#show-fields-radios input[type="radio"]', context).change(function(event) {
    // console.log('event: ', event);
    field_shown = show_field_indicators(context, field_shown, $(this));
  });


  // Populate selectables_map
  $(document, context).on('selectables_data_fetched', function() {
    // console.log('On: selectables_data_fetched');
    // console.log('selectables_data: ', selectables_data);

    // Populate selectables_map
    $.each(selectables_data, function( nid, node ) {
      // console.log('nid: ', nid);
      var selectable = $('.selectable .views-field-nid .field-content:contains("' + nid + '")')
        .parents('.selectable');
      selectables_map[nid] = selectable;
    });
    // console.log('selectables_map: ', selectables_map);
  });


  // Saving a new identification
  $('.node-identification-form .form-actions input[type="submit"][value="Save"]').on('click', function(event){
    event.preventDefault();

    var identification = create_identification();
    var identification_nid = save_identification(identification, context); // Uses AJAX
  });

  // Saving changed observation information
  $(edit_form_selector).submit(function( event ) {
    event.preventDefault();

    var observation = Drupal.casa_node_mgt.convert_form_to_node($( this ));
    console.log("observation: ", observation);

    observation['type'] = "observation";

    var nids = get_selected_nids();

    var is_success = update_observations(observation, nids, context);
  });


  // Forms

  // Manage 'Number specimens' form submission using AJAX
  $('#number-specimens form').submit(function() {
    var form = $(this);
    manage_form_number_specimens(form);

    // Prevent submitting again.
    return false;
  });

  // Manage 'Add blank observations' form submission using AJAX
  $('#create-blank-observations form').submit(function() {
    var form = $(this);
    manage_form_add_blank_obs(form);

    // Prevent submitting again.
    return false;
  });
}













// AJAX functions


function get_selectables_data() {
  var toastr_info = toastr.info('Loading…'); // @todo add an 'undo' button
  var collection_nid = get_collection_nid();
  var url = api_url + '/collections/' + collection_nid + '/observations';
  var jqxhr = $.get(url);

  jqxhr.fail(function( data ) {
    toastr_info.remove();
    toastr.error('Sorry, there was a problem loading the observations.');
    console.log('In jqxhr.fail(), data: ', data );
  });

  jqxhr.done(function( data ) {
    // console.log( "In jqxhr.done(), data: ", data );
    toastr_info.remove();
    // toastr.success('selectables_data loaded successfully.'); // Not needed.
    selectables_data = data;
    // console.log('selectables_data, on page load: ', selectables_data);
    $(document).trigger('selectables_data_fetched');
  });
}

// @todo delete this in favour of the version in contribute.js
function get_collection_nid() {
  var path = window.location.pathname;
  var path_parts = path.split('/');
  var nid = path_parts[path_parts.length - 1];
  // console.log( "collection: ", collection );
  return nid;
}



function get_token() {
  var ajax_settings = {
    type: "POST",
    contentType: "application/json",
    url: api_url + '/users/token'
  }
  var jqxhr = $.ajax(ajax_settings);

  jqxhr.fail(function( data ) {
    toastr.error('Sorry, there was a problem security token the observations.');
    console.log( "In jqxhr.fail(), data: ", data );
  });

  jqxhr.done(function( data ) {
    // console.log( "In jqxhr.done(), data: ", data );
    security_token = data['token'];
    // console.log('security_token: ', security_token);
  });
}


function save_identification(identification, context) {
  console.log('identification: ', identification);

  var observation_nid = get_selected_nids()[0]; // Used below when save is successful.
  var identification_nid = null;

  var settings = {
    type: "POST",
    contentType: "application/json",
    data: JSON.stringify(identification, null, 2),
    headers: {
      "X-CSRF-Token": security_token
      // Session id header is not specified, because it's automatically added by browser (it's a cookie).
    },
    url: api_url + '/identifications'
  }
  var toastr_info = toastr.info('Saving…'); // @todo add an 'undo' button
  var jqxhr = $.ajax(settings);

  jqxhr.fail(function( data ) {
    toastr_info.remove();
    toastr.error('Sorry, there was a problem saving the identification.');
    console.log( "In jqxhr.fail(), data: ", data );
  });

  jqxhr.done(function( data ) {
    // console.log( "In jqxhr.done(), data: ", data );
    toastr_info.remove();
    toastr.success('identification saved successfully.');

    // Update selectables_data with new identification
    identification_nid = data['nid'];
    var identification_vid = identification_nid;

    selectables_data[observation_nid]['identifications'][identification_nid] = {
      nid: identification_nid,
      type: 'identification',
      vid: identification_vid
    };

    refresh_current_field_indicator(context);
  });

  return identification_nid;
}


/**
 * Creates an identifiation object for sending as JSON to the API.
 */
function create_identification() {
  var form = $('.node-identification-form');
  var species_selection_form = $('#views-form-species-reference-selector-widget-default');

  // var taxon = form.find('input#edit-field-identified-species-und').val();
  var taxon_tid = species_selection_form.find('input[type="radio"]:checked').val();
  var taxon_name = species_selection_form.find('input[type="radio"]:checked')
    .parents('tr').find('.views-field-name a').html();
  // console.log('taxon_tid: ', taxon_tid);

  if (!taxon_tid) {
    toastr.warning('You need to select a taxon before saving.');
    return null;
  }

  var observation_nid = get_selected_nids()[0]; // Will always be only one when submitting.
  var observation_name = selectables_data[observation_nid]['title'];
  var observation_reference = observation_name + " (" + observation_nid + ")";
  // console.log('observation_reference: ', observation_reference);

  var language = 'und';

  var title = taxon_name;
  var certainty = $(identify_form_selector + " #edit-field-certainty-und").val();

  var identification = create_identification_obj(title, observation_reference, taxon_tid, certainty);
  // console.log('identification: ', identification);
  return identification;
}


function create_identification_obj(title, observation, taxon_tid, certainty) {
  return {
    "title": title,
    "status": true,
    "type": "identification",
    "field_certainty": {
      "und": certainty
    },
    "field_observation": {
      "und": [
        {"target_id": observation}
      ]
    },
    "field_identified_species": {
      "und": [
        {"tid": taxon_tid}
      ]
    }
  };
}


/**
 * @returns true if successful, false otherwise.
 */
function update_observations(observation_data, nids, context) {
  var is_success = false;

  var settings = {
    type: "PUT",
    contentType: "application/json",
    data: JSON.stringify(observation_data, null, 2),
    headers: {
      "X-CSRF-Token": security_token
      // Session id header is not specified, because it's automatically added by browser (it's a cookie).
    },
    url: api_url + '/observations/' + nids.join( "|" )
  }
  var toastr_info = toastr.info('Saving…'); // @todo add an 'undo' button
  var jqxhr = $.ajax(settings);

  jqxhr.fail(function( data ) {
    toastr_info.remove();
    toastr.error('Sorry, there was a problem updating the observations.');
    console.log( "In jqxhr.fail(), data: ", data );
  });

  jqxhr.done(function( data ) {
    // console.log( "In jqxhr.done(), data: ", data );
    toastr_info.remove();
    is_success = true;
    toastr.success('Observations updated successfully.');

    // Update selectables_data
    // @todo complete this.

    // Update selectables_data with saved observation info
    $.each(nids, function(index, observation_nid) {
        // console.log('observation_nid: ', observation_nid);

      $.each(observation_data, function(field_name, field_value) {
        // console.log('field_name: ', field_name);
        // console.log('field_value: ', field_value);

        selectables_data[observation_nid][field_name] = field_value;

      });
    });

    refresh_current_field_indicator(context);
  });

  return is_success;
}















/**
 * Trigger the 'Add node' button on all reference fields that have no references.
 */
function expand_empty_reference_fields(block) {
  var ref_fields = block.find( '[class*="field-widget-entityreference"]');
  ref_fields.each(function(){
    var html = block.find( 'tbody > tr > td:first-child' ).html();
    var no_refs = html.substring(0, 8) == 'No items';
    // console.log('no_refs: ', no_refs);

    if (no_refs) {
      var button = $( this ).find( '[type="submit"]' );
      // console.log(button.attr('class'));
      button.trigger('click');
      button.trigger('mousedown');
      // button[0].click();
    }
  });
}



/**
 * Enables and disables the buttons according to selections.
 */
function adjust_buttons(context) {
  // console.log("Called: adjust_buttons()");

  var num_selected = Drupal.selection.get_selecteds_indexes().length;
  // console.log('num_selected: ', num_selected);

  // Disable buttons if there are no selections
  if (num_selected == 0) {
    toolbar.find('button#edit, button#identify').prop( "disabled", true );
  }
  else if (num_selected == 1) {
    toolbar.find('button#edit, button#identify').prop( "disabled", false );
  }
  else if (num_selected > 1) {
    toolbar.find('#identify').prop( "disabled", true );
  }
}



/**
 * Adds the changed field's name to the list in the hidden edit_selected_altered_fields field
 */
function manage_field_change(target) {
  var field = target.parents( fields_selector + ', .form-item-title' );
  var field_name = get_field_property( field, "field_name" );
  // console.log("field changed: ", field_name );

  if ( typeof field_name != 'undefined' ) {
    fields_altered.push( field_name );
    // console.log("fields_altered: ", fields_altered);

    $( '[name="edit_selected_altered_fields"]' ).val( fields_altered.join( "|" ));
  }
}



/**
 * Inserts the selected elements' node IDs into the hidden nids field.
 */
function edit_selected_nid_prefiller() {
  // console.log('called: edit_selected_nid_prefiller()');

  var nids_field = $( "form input[name*='nids']" );
  // console.log('nids_field: ', nids_field);

  var selecteds_nids = get_selected_nids();
  // console.log('selecteds_nids: ', selecteds_nids);

  nids_field.val( selecteds_nids.join( "|" ) );
  // alert("nids_field.val: " + nids_field.val() );
}



/**
 * For all selected nodes, fill their aggregated values into the edit form.
 *
 * If their values differ, sets the associated field's message to indicate mixed values.
 */
function edit_selected_form_prefiller() {
  // console.log("Reached: edit_selected_form_prefiller");

  // var supported_field_types = [
  //  'form-type-textfield', // Incl. Autocomplete entity reference widget
  //  'form-type-textarea', // Incl. Long text, with or without summary
  //  'form-type-select',
  //  'form-type-radios',
  //  'form-type-checkboxes'
  // ];

  // var supported_field_types = [
  //  // From core's File API (https://www.drupal.org/node/1879542)
  //  'file',
  //  'image',
  //  'taxonomy-term-reference',
  //  'list-boolean',
  //  'list-float',
  //  'list-integer',
  //  'list-text',
  //  'number-decimal',
  //  'number-float',
  //  'number-integer',
  //  'text',
  //  'text-long',
  //  'text-with-summary' // Long Text with Summary
  // ];


  var supported_field_widgets = [
    'number',
    'options-select',
    'options-buttons', // Checkboxes and radio buttons
    'text-textfield',
    'text-textarea-with-summary',
    'openlayers-geofield',
    'entityreference-autocomplete'
  ];

  var supported_special_fields = [
    'form-item-title'
  ];

  // ??
  var form_fields =
       $( edit_form_selector + " " + fields_selector )
    .add( edit_form_selector + ' .form-item-title' )
    .add( identify_form_selector + " " + fields_selector );
  // alert( form_fields.length );

  // For each field in the block, find matching view result field, and use it's value
  form_fields.each( function( index ) {

    var form_field = $( this );
    var field_name;
    var field_type;
    var field_widget = get_field_property(form_field, "field_widget");
    var special_field = false;

    var field_values = [];
    var field_values_mixed = false;

    // If this field has a class in the supported_special_fields array, flag it as special
    $.each( supported_special_fields, function( key, value ) {
      form_field.hasClass(value) ? special_field = true : false;
    });

    // Get field's values (from selected nodes).
    // If this field uses a supported widget, it can be pre-filled
    if ($.inArray(field_widget, supported_field_widgets) >= 0 || special_field) {
      // alert(field_type + " is supported");
      var field_value = '';

      field_name = get_field_property(form_field, "field_name");
      // console.log('field_name: ', field_name);

      // field_type = get_field_property(form_field, "field_type");

      // Fields whose 'form name' doesn't match its 'node name'
      // (such as entity reference fields) need to be handled uniquely.
      if (field_widget == 'entityreference-autocomplete') {
        if (field_name == 'field-observation') {
          field_name = 'nid';
        }
      }

      // For all selected nodes, find their values for the field.
      field_values = get_field_values(field_name);
      // console.log( 'field_values: ', field_values);

      // Set the field value (according to valued found).
      // If the selected nodes have at least one value for this field
      if ( field_values.length > 0 ) {

        field_values_mixed = field_values.filter( onlyUnique ).length > 1  ? true : false; //selecteds_indexes.length
        // console.log('field_values_mixed: ', field_values_mixed);

        // For mixed-values fields, display a message to notify the user
        if( field_values_mixed ) {
          field_values_mixed = true;
          // form_field.find( ".messages" ).html( "mixed values" );
          // form_field.find( ".messages" ).addClass( "warning" );
          // form_field.find( ".messages" ).removeClass( "hidden" );
          form_field.attr( 'data-values-status', "mixed" );

          // Unset field value
          clear_field_value(form_field);
        }

        // For non-mixed fields, set the form item's value to the field value
        else {
          field_values_mixed = false;
          // form_field.find( ".messages" ).html( "" );
          // form_field.find( ".messages" ).removeClass( "warning" );
          // form_field.find( ".messages" ).addClass( "hidden" );
          form_field.attr( 'data-values-status', "" );

          // Fields whose 'form name' doesn't match its 'node name'
          // (such as entity reference fields) need to be handled uniquely.
          if (field_widget == 'entityreference-autocomplete') {
            field_values = [' (' + field_values + ')'];
          }

          // console.log( 'form_field: ', form_field);
          // console.log( 'field_values: ', field_values);
          // console.log( 'field_widget: ', field_widget);
          set_field_value(form_field, field_values, field_widget);
        }
      }
      // If the selected nodes have no values for this field
      else {
        clear_field_value(form_field);
      }
    }
  });
}


/**
 * Creates and array of field values from all selected nodes.
 */
function get_field_values(field_name) {
  var field_values = [];

  $.each( Drupal.selection.get_selecteds_indexes(), function( key, index ) {
    // console.log('index: ', index);
    var element = $( '.selectable.views-row-' + index );
    // console.log("element found: ", element.length);
    field_value = element.find( ".views-field-" + field_name + " .field-content" ).html();
    // console.log(field_name + " field_value: ", field_value);

    // If this field has a valid value
    if (field_value != '' && field_value != null) {
      // alert("field_value: " + field_value );
      field_values.push( field_value ); // even if blank (== "")
    }
    else {
      field_values.push( '' );
    }
  });
  return field_values;
}


/**
 * Set's the value of one field.
 *
 * @param field
 *   jQuery element of the .field
 *
 * @param values
 *   array of field values to set. More than 1 value for selects & checkboxes.
 *
 * @param field_widget
 *   string representing the type of widget (eg. '.field-widget-[type]').
 */
function set_field_value(field, values, field_widget) {
  // console.log('field:', field);
  // console.log('values:', values);
  // console.log('field_widget: ', field_widget);

  field.find( "input:not([type='checkbox'])" ).val(values[0]);
  field.find( "textarea" ).val(values[0]);
  $.each(values, function(index, value) {
    var radio = "select option[value='" + value + "']";
    field.find( radio ).prop('selected', true);

    var checkbox = "input[type='checkbox'][name*='" + value + "']";
    field.find( checkbox ).prop('checked', true);
  });


  // For the Geofield map widget

  if (field_widget == 'openlayers-geofield') {

    var map_instances = Drupal.openlayers.instances;

    $.each(map_instances, function(map_id, map_instance) {
      var map = map_instance.map;
      // console.log('map:', map);

      var layers = map.getLayers();
      // console.log('layers:', layers);
      var observation_location_layer = null;
      var location = parse_location(values);

      // Manage the layers

      layers.forEach(function(layer, index, array) {
        // console.log('layer:', layer);

        // layer.mn is the layer’s ID
        if (layer.mn == 'geofield_field_formatter_layer' || layer.mn == 'openlayers_geofield_layer_widget') {
          // Hide these layers because of a bug preventing altering the point features.
          layer.setVisible(false);
          // This is ideal; shows bug in console.
          // var point = layer.getSource().getFeatures()[0].getGeometry();
          // point.setCoordinates(location);
        }
        if (layer.mn == 'observation_location') {
          observation_location_layer = layer;
        }
      });

      var point;

      // If the layer hasn't yet been created, create it.
      if (observation_location_layer == null) {
        point = new ol.geom.Point(location);
        map.addLayer(create_layer(point));
      }
      else {
        point = observation_location_layer.getSource().getFeatures()[0].getGeometry();
        // console.log('point:', point);
        point.setCoordinates(location);
      }

      // Transform the point (from WGS84 geographic coordinates to Spherical Mercator).
      var current_projection = new ol.proj.Projection({code: "EPSG:4326"});
      var new_projection = new ol.proj.Projection({code: "EPSG:3857"});
      point.transform(current_projection, new_projection);

    });

  }
}


/**
 * Takes a string representation of a lat-lon location and turns it into lon-lat coordinates.
 * Eg. ["13, 17"] returns [17, 13].
 */
function parse_location(raw_field_value) {
  if (typeof(raw_field_value) == 'undefined' || ! raw_field_value instanceof Array) {
    return null;
  }
  var location = [];
  var location_strings = raw_field_value[0].split(', ');
  $.each(location_strings, function(index, val) {
    location.push(parseFloat(val));
  });
  location.reverse();
  // console.log('location:', location);
  return location;
}


/**
 * Creates a layer with a point feature.
 */
function create_layer(point) {
  if (typeof(point) == 'undefined' || ! point instanceof ol.geom.Point) {
    return null;
  }
  var feature = new ol.Feature({geometry: point});
  var source = new ol.source.Vector({features: [feature]});
  var layer = new ol.layer.Vector({source: source});
  layer.mn = 'observation_location';
  return layer;
}


/**
 * Clears one field, so that it has no value.
 */
function clear_field_value(field) {
  // console.log('field: ', field);
  // field.find( "input" ).val('');
  field.find( "input:not([type='checkbox'])" ).val('');
  field.find( 'input[type="checkbox"]' ).prop('checked', false);
  // field.find( "input[type='checkbox'], input[type='radio']" ).prop('checked', false);
  field.find( "textarea" ).val('');
  field.find( 'select option' ).prop('selected', false);
}



/**
 * Provides the field's name, type or widget according to its class
 */
function get_field_property(field, property) {
  var classes = field.attr( "class" );
  if ( typeof classes == 'undefined') {
    return;
  }
  var classes = field.attr( "class" ).split( " " );
  var field_value;

  // Get the form item's type and field name
  $.each( classes, function( key, value ) {
    // alert( value );
    // alert((property == "field_name"));

    if ( (property == "field_name") && (value.substr( 0, 16 ) == "form-field-name-") ) {
      field_value = value.substr( 16 );
    }
    else if ( (property == "field_name") && (value.substr( 0, 10 ) == "form-item-") ) {
      // alert( value.substr( 10 ) );
      field_value = value.substr( 10 );
    }

    if ( (property == "field_type") && (value.substr( 0, 16 ) == "form-field-type-") ) {
      field_value = value.substr( 16 );
      // alert( field_type );
    }

    if ( (property == "field_widget") && (value.substr( 0, 13 ) == "field-widget-") ) {
      field_value = value.substr( 13 );
      // alert( field_widget );
    }
  });
  return field_value;
}



/**
 * Gets the array of selectable indexes, and creates an array of the nids from it.
 */
function get_selected_nids() {
  var selecteds_indexes = Drupal.selection.get_selecteds_indexes();

  selecteds_nids = [];

  // console.log('selecteds_indexes received: ', selecteds_indexes);

  $.each( selecteds_indexes, function( key, index ) {
    var element = $( '.selectable.views-row-' + index );
    // console.log('elements: ', element.length);
    var nid = element.find( ".views-field-nid .field-content" ).html();
    // alert(nid);
    selecteds_nids.push( nid );
  });
  // alert("selecteds_nids: " + selecteds_nids);

  return selecteds_nids;
}




function rotate_selected(button) {
    // console.log('called: rotate_selected()');
    var toastr_info = toastr.info('Rotating pictures…'); // @todo add an 'undo' button

    var url = Drupal.settings.basePath + 'casa-node-mgt/rotate';
    var selecteds_nids = get_selected_nids().join( "|" );
    var rotation_params = {
      'nids': selecteds_nids,
      'degrees': '90'
    };

    if (button.attr('id') == 'rotate-ccw') rotation_params['degrees'] = '-90';

    var rotate_result = $.post(url, rotation_params, function(data, textStatus, xhr) {
      // console.log('Rotate POST request completed…');
    });

    rotate_result.fail(function( data ) {
      toastr_info.remove();
      toastr.error('Sorry; there was a problem rotating the pictures.');
      console.log( "In rotate_result.fail(), Reason: " + data['reason'] );
    });

    rotate_result.done(function( data ) {
      toastr_info.remove();
      var result = data['result'];
      // console.log( "Result: ", result );

      if (result == "success") {
        toastr.success('Pictures rotated successfully. Reloading the page…');
        // console.log( "Reason: ", data['reason'] );
        // Refresh the page to show updated (rotated) pictures.
        document.location.reload();
      } else {
        toastr.error('Sorry; there was a problem rotating the pictures.');
        console.log( "In rotate_result.done(), data: ", data );
      }
      // console.log('data: ', data);
    });
}




function manage_form_number_specimens(form) {
  // var are_selecteds = Drupal.selection.are_selecteds();
  // console.log('are_selecteds: ', are_selecteds);
  var toastr_info = toastr.info('Numbering observations…'); // @todo add an 'undo' button

  // Disable buttons if there are no selections
  if (! Drupal.selection.are_selecteds()) {
    toastr.error('You need to select an observation.');
    return false;
  }

  // Send xhr request.
  $.ajax({
    url: form.attr('action'),
    type: form.attr('method'),
    data: form.serialize(),
    error: function(data) {
      toastr_info.remove();
      toastr.error('Sorry; there was a problem numbering the observations.');
      console.log( "In ajax.error(), data: ", data );
    },
    success: function(data) {
      toastr_info.remove();
      toastr.success('Observations have been numbered successfully. Reloading in 3 seconds…');
      var reload_timeout = window.setTimeout(function(){
        document.location.reload();
      }, 3000);
    }
  });
}




function manage_form_add_blank_obs(form) {
  form.find('#collection-id').val(Drupal.casa_core.get_collection_nid());
  // console.log('form.serialize: ', form.serialize());

  // Send xhr request.
  $.ajax({
    url: form.attr('action'),
    type: form.attr('method'),
    data: form.serialize(),
    error: function(data) {
      toastr.error('Sorry; there was a problem adding picture-less observations.');
    },
    success: function(data) {
      toastr.success('Picture-less observations have been created successfully. Reloading in 3 seconds…');
      var reload_timeout = window.setTimeout(function(){
        document.location.reload();
      }, 3000);
    }
  });
}




function set_up_field_progress(context) {
  // console.log('Called: set_up_field_progress()');
  var fields_count = 10;

  for (var i = 0; i < fields_count; i++) {
    $('.progress-container', context).append('<div></div>');
  };

  var fields_active = 3;

  for (var i = 0; i < fields_active; i++) {
    $('.progress-container > div:nth-of-type(' + (i + 1) + ')', context).addClass('active');
  };
}



/**
 * On edit pages, changes appearance of selectables with the specified field to
 * indicate that they have a value for this field.
 *
 * @param field_shown
 *   The name of the field that is currently showing (eg. 'body').
 * @param button
 *   The jQuery button element that was clicked to call this function.
 */
function show_field_indicators(context, field_shown, button) {
  // console.log('field_shown: ', field_shown);
  // console.log('button: ', button);

  var field_name = button.attr('value');
  // console.log('field_name: ', field_name);

  // @todo Validate: Check that selectables data has been fetched (using AJAX).

  // Make sure .field-data elements are empty, and no .selectables are 'matched'.
  $('.selectable').find('.field-data').html('');
  $('.selectable').attr('data-is-match', 'false');

  // console.log('field_name: ', field_name);
  if (field_name == 'no_fields') {
    button.addClass('active');
    field_shown = field_name;
  }
  else {
    // console.log('selectables_data: ', selectables_data);

    // Correct field names; Convert button values to field names
    switch (field_name) {
      case 'identification':
        field_name = 'identifications';
        break;
      case 'title':
        field_name = 'title';
        break;
      default:
        field_name = 'field_' + field_name;
    }

    $.each(selectables_map, function( nid, selectable ) {
      // console.log( nid, ": ", selectable );

      var has_data = false;
      if (selectables_data[nid].hasOwnProperty(field_name) && selectables_data[nid][field_name] != null && selectables_data[nid][field_name] != '') {
        has_data = true;
      }

      var language = 'und';

      if (has_data) {
        var field_data = '';
        switch (field_name) {

          case 'identifications':
            var field_data = selectables_data[nid][field_name];
            // Will be like: {nid: "Species (certainty)", ...}

            var ids = [];
            $.each(field_data, function (nid, value) {
              var identification = value['species'] + '<br>(' + value['certainty'] + ')';
              ids.push(identification);
            });
            field_data = ids.join(',<br>');
            break;

          case 'title':
            // console.log('data: ', selectables_data[nid][field_name]);
            field_data = selectables_data[nid][field_name];
            break;
          default:
            // console.log('data: ', selectables_data[nid][field_name]);
            field_data = selectables_data[nid][field_name][language][0]['value'];
        }

        selectable.attr('data-is-match', 'true');
        selectable.find('.field-data').append(field_data);
      }
    });

    // $('.selectable .field-data').append('data');

    field_shown = field_name;
  }

  // console.log('field_shown: ' + field_shown);
  return field_shown;
}

function refresh_current_field_indicator(context) {
  var field_shown = null;
  var radio_selected = $('#show-fields-radios input[type="radio"]:checked', context);
  field_shown = show_field_indicators(context, field_shown, radio_selected);
}



function set_up_keypress_mgmt(context) {

  var current_page = Drupal.settings.edit_selected.current_page;
  // console.log('current_page: ', current_page);

  $(document, context).bind('keydown', 'e',         handle_keypress_edit);

  if (current_page == 'picture-info') {
    Drupal.casabio.add_keypress_info(
      "<tr><td><strong>left</strong> : </td><td>Previous picture</td></tr>"
      + "<tr><td><strong>right</strong> : </td><td>Next picture</td></tr>"
      + "<tr><td><strong>x</strong> : </td><td>Select picture</td></tr>"
      + "<tr><td><strong>c</strong> : </td><td>Un-select all pictures</td></tr>"
      + "<tr><td><strong>e</strong> : </td><td>Edit selected pictures</td></tr>"
    );
  }

  if (current_page == 'observation-info') {
    Drupal.casabio.add_keypress_info(
      "<tr><td><strong>left</strong> : </td><td>Previous observation</td></tr>"
      + "<tr><td><strong>right</strong> : </td><td>Next observation</td></tr>"
      + "<tr><td><strong>x</strong> : </td><td>Select observation</td></tr>"
      + "<tr><td><strong>c</strong> : </td><td>Un-select all observations</td></tr>"
      + "<tr><td><strong>e</strong> : </td><td>Edit selected observations</td></tr>"
      + "<tr><td><strong>i</strong> : </td><td>Identify selected observations</td></tr>");

    $(document, context).bind('keydown', 'i',         handle_keypress_identify);
  }

  // $(document, context).bind('keydown', 'esc',       handle_keypress_close_dialog);
}

function handle_keypress_edit() {
  $(edit_form_selector).dialog('open');
}

function handle_keypress_identify() {
  $(identify_form_selector).dialog('open');
}

// Not needed; jQuery ui Dialogs close with 'esc' automatically.
// function handle_keypress_close_dialog() {
//   Drupal.casa_core.close_dialogs();
// }


})(jQuery, Drupal, this, this.document);
