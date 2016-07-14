/**
 * @file
 * A JavaScript file for…
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
 * Drupal.behaviors.edit_selected.attach()
 *
 * Drupal.edit_selected
 *  .is_page()
 *  .set_selectables_data()
 *  .set_selectable()
 *  .get_selectables_data()
 *  .get_selectable_data()
 *  .get_selectables_map()
 *  .get_selectable_from_nid()
 *  .refresh_current_field_indicator()
 *  // .get_selectable_field_value()
 *
 * misc_page_set_up()
 * add_listeners()
 *
 * set_up_dialogs()
 * dialog_close_handler()
 * expand_empty_reference_fields()  // @deprecated
 * adjust_buttons()
 * manage_field_change()
 * remove_unaltered_node_fields()
 * parse_location()
 * create_layer()
 * rotate_selected()
 * manage_form_number_specimens()
 * manage_form_add_blank_obs()
 * set_up_field_progress()
 * show_field_indicators()
 *
 * set_up_keypress_mgmt()
 * handle_keypress_edit()
 * handle_keypress_identify()
 */


var page_is_setup = false;
var settings_of_setup;

var edit_form;
var identify_form;
var interaction_form;
var toolbar;

var current_page;
var page_has_map;

var map_layer_all_locations;
var standard_feature_style;
var selected_feature_style;

var fields_altered_names = [];

var selectables = {}; // jQuery objects

var selectables_data = []; // Data returned from API requests
var selectables_map = {}; // Maps selectable's nid: its position in the selectables_data array

var identifications_data = [];
var identifications_map = {}; // Maps selectable's nid: list of positions of identifications of it

var interactions_data = [];
var interactions_map = {}; // Maps selectable's nid: list of positions of identifications of it


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.edit_selected = {
  attach: function(context, settings) {
    // console.log('settings: ', settings);

    if (! page_is_setup) {
      settings_of_setup = settings;

      current_page = settings.edit_selected.current_page;
      // console.log('current_page: ', current_page);

      edit_form =         $('.edit_form_wrapper', context);
      identify_form =     $('.identify_form_wrapper', context);
      interaction_form =  $('.interaction_form_wrapper', context);
      toolbar =           $('[role="toolbar"][aria-label*="primary"]', context);

      selectables =       $('.selectable', context);
      // console.log('selectables: ', selectables);

      if (Drupal.edit_selected.is_page('observation_info')) {
        page_has_map = true;
      }
      else {
        page_has_map = false;
      }


      if (page_has_map) {
        var colour_semi_red = [255, 0, 0, 0.4];
        standard_feature_style = Drupal.casa_map_mgt.create_style('point', 5, colour_semi_red, 'red');
        var colour_semi_blue = [0, 0, 255, 0.4];
        selected_feature_style = Drupal.casa_map_mgt.create_style('point', 5, colour_semi_blue, 'blue');
      }

      // fetch_selectables_data
      if (Drupal.edit_selected.is_page('observation_info') || Drupal.edit_selected.is_page('picture_info')) {
        // console.log('Calling fetch_selectables_data()');
        Drupal.es_api_interactions.fetch_selectables_data();
      }
      if (Drupal.edit_selected.is_page('observation_info')) {
        Drupal.es_api_interactions.fetch_identifications_data();
        Drupal.es_api_interactions.fetch_interactions_data();
      }

      // fetch_token
      Drupal.es_api_interactions.fetch_token();



      // Page setup

      set_up_dialogs(context);

      misc_page_set_up(context, settings);

      adjust_buttons(context);

      // set_up_field_progress(context);

      set_up_keypress_mgmt(context);

      add_listeners(context, settings);

      page_is_setup = true;
    }

  },
  weight: 6
};


Drupal.edit_selected = {

  is_page: function(page) {
    return current_page == page;
  },


  selectables_append: function(selectable) {
    selectables = selectables.add(selectable);
  },

  // ===========================================================================
  //                                      selectables_data

  set_selectables_data: function(selectables_data_in) {
    selectables_data = selectables_data_in;
  },

  set_selectable: function(nid, selectable) {
    // If nid not provided, just append selectable to the end of the array
    if (nid == null) {
      var index = selectables_data.push(selectable);
      populate_selectables_map();
      // selectables_map[nid] = index;
    }
    else {
      var index = Drupal.edit_selected.get_selectables_map()[nid];
      selectables_data[index] = selectable;
    }
  },

  selectables_data_append: function(selectable) {
    selectables_data.push(selectable);
  },

  get_selectables_data: function() {
    return selectables_data;
  },

  get_selectable_data: function(nid) {
    return selectables_data[selectables_map[nid]];
  },

  populate_selectables_map: function() {
    // Populate selectables_map
    $.each(selectables_data, function( index, node ) {
      var nid = node.id;
      // console.log('nid: ', nid);
      selectables_map[nid] = index;
    });
    // console.log('selectables_map: ', selectables_map);
  },

  get_selectables_map: function() {
    return selectables_map;
  },


  get_selectable_from_nid: function(nid) {
    var selectable = selectables.find('.property-nid:contains("' + nid + '")')
      .parents('.selectable');
    return selectable;
  },

  // ===========================================================================
  //                                      identifications_data

  set_identifications_data: function(identifications_data_in) {
    identifications_data = identifications_data_in;
  },

  identifications_data_append: function(identification_in) {
    identifications_data.push(identification_in);
  },

  populate_identifications_map: function() {
    // Populate selectables_map
    $.each(identifications_data, function( index, node ) {
      var nid = node.attributes.observation;
      // console.log('nid: ', nid);

      if (typeof identifications_map[nid] == 'undefined') {
        identifications_map[nid] = [];
      }

      identifications_map[nid].push(index);
    });
    // console.log('identifications_map: ', identifications_map);
  },

  // ===========================================================================
  //                                      interactions_data

  set_interactions_data: function(interactions_data_in) {
    interactions_data = interactions_data_in;
  },

  interactions_data_append: function(interaction_in) {
    interactions_data.push(interaction_in);
  },

  populate_interactions_map: function() {
    // Populate selectables_map
    $.each(interactions_data, function( index, node ) {
      var nid = node.attributes.observation;
      // console.log('nid: ', nid);

      if (typeof interactions_map[nid] == 'undefined') {
        interactions_map[nid] = [];
      }

      interactions_map[nid].push(index);
    });
    // console.log('interactions_map: ', interactions_map);
  },



  refresh_current_field_indicator: function(context) {
    var field_shown = null;
    var radio_selected = $('#show-fields-radios input[type="radio"]:checked', context);
    field_shown = show_field_indicators(context, field_shown, radio_selected);
  },



  add_selection_listeners: function(selectable, settings) {
    // console.log("Called add_selection_listeners(), settings: ", settings);
    // When a selectable is selected, manage it.
    selectable.on('selection:select', function(event) {
      adjust_buttons();

      Drupal.form_prefiller.clear_form(edit_form);
      if (page_has_map) {
        Drupal.edit_selected.reset_features_style();
      }

      // Set 'Number Specimens' form's 'nids' (hidden) field
      $('form[action="ajax/number_specimens"] input[name="nids"]')
        .val(Drupal.selection.get_selected_nids().join(','));

      Drupal.form_prefiller.prefill_form(edit_form, selectables_data, settings);
    });
  },


  trigger_manage_field_change: function(target) {
    manage_field_change(target);
  },



  // Map features

  set_selectable_feature_as_selected: function() {
    // console.log('Called: Drupal.edit_selected.set_selectable_feature_as_selected()');
    var nid = Drupal.selection.get_selected_nids()[0]; // Will only be one when called.
    var features = map_layer_all_locations.getSource().getFeatures();
    $.each(features, function(index, feature) {
      if (feature.nid == nid) {
        // console.log('nid: ', nid);
        feature.setStyle(selected_feature_style);
      }
    });
  },


  reset_features_style: function(form) {
    var features = map_layer_all_locations.getSource().getFeatures();
    $.each(features, function(index, feature) {
      feature.setStyle(standard_feature_style);
    });
  },


  update_feature: function(nid) {
    // console.log('nid: ', nid);
    if (! page_has_map) {
      return null;
    }

    var features = map_layer_all_locations.getSource().getFeatures();
    var feature;
    $.each(features, function(index, feature_index) {
      // console.log('feature_index: ', feature_index);
      if (feature_index.nid == nid) {
        feature = feature_index;
      }
    });

    // If this nid doesn't yet have a feature on the map
    if (typeof feature == 'undefined') {
      var selectable = Drupal.edit_selected.get_selectable_data(nid);
      add_observation_to_map(selectable, selected_feature_style);
    }

    else {
      var location = selectables_data[selectables_map[nid]].attributes.location;
      // console.log('location: ', location);
      feature.getGeometry().setCoordinates([
        parseFloat(location.longitude),
        parseFloat(location.latitude)
      ]);
      // console.log('coords after: ', feature.getGeometry().getCoordinates());
      Drupal.casa_map_mgt.transform_geometry_from_4326(feature);
    }
  }


};




function misc_page_set_up(context, settings) {
  // console.log('call: edit_selected module: set_up_page()');

  // Add a message areas to form fields; used to notify about mixed values.
  edit_form.find("[class*='form-field-'] .form-item > label:first-child"
    + ', .form-item-title label:first-child', context)
    .after('<div class="messages hidden"></div>');

  // Add a 'show' area to the edit form, which will display the image
  // edit_form.find('.content > h2').after('<div class="show"></div>');
  // $('li.focussed').find('.views-field-field-image')
  //   .clone()
  //   .appendTo('.block-edit-selected .show');

  // Element to contain the value of the selected field when one of the 'show field' radio buttons is clicked
  selectables.append('<span class="field-data"></span>');


}



/**
 * Adds event listeners to page elements.
 */
function add_listeners(context, settings) {


  // Disable firefox's 'image drag' feature, which messes with our ‘drag-select’
  $(document, context).on("dragstart", function(e) {
    if (e.target.nodeName.toUpperCase() == "IMG") {
      return false;
    }
  });

  // When a selectable is selected, manage it.
  selectables.each(function(index, selectable) {
    Drupal.edit_selected.add_selection_listeners($(selectable), settings);
  });
  // selectables.on('selection:select', function(event) {
  //   adjust_buttons();

  //   Drupal.form_prefiller.clear_form(edit_form);
  //   if (page_has_map) {
  //     Drupal.edit_selected.reset_features_style();
  //   }

  //   Drupal.form_prefiller.prefill_form(edit_form, selectables_data, settings);
  // });

  $('button.rotate', context).on( 'click', function(event) {
    event.preventDefault();
    rotate_selected($(this));
  });

  $('input, textarea, select', context ).on( 'change', function() {
    // console.log('changed');
    // Add the changed field's name to the list in the hidden edit_selected_altered_fields field.
    manage_field_change( $( this ) );
  });

  // When a dialog's cancel button is clicked, close the dialog.
  $('input[value="Cancel"]', context ).on( 'click', function(event) {
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




  // Maps

  // Populate selectables_map
  $(document, context).on('selectables_data_fetched', function() {
    // console.log('On: selectables_data_fetched');
    // console.log('selectables_data: ', selectables_data);

    Drupal.edit_selected.populate_selectables_map(); // re-populates the selectables_map array

    if (page_has_map) {
      add_observations_to_map();
    }
  });

  $('.horizontal-tab-button a').on('click', function( event, ui ) {
    // console.log('map: ', map);
    if (page_has_map) {
      var map = Drupal.casa_map_mgt.get_map();
      map.updateSize();
    }
  });





  // Save changed node information
  edit_form.find('form').submit(function( event ) {
    event.preventDefault();
    // console.log('edit form submitted.');

    var node_serialized_raw = $( this ).serializeArray();
    console.log('node_serialized_raw: ', node_serialized_raw);
    var fields_raw = Drupal.casa_node_mgt.convert_form_to_node(node_serialized_raw);
    console.log('fields_raw: ', fields_raw);
    var fields_altered = remove_unaltered_node_fields(fields_raw);
    console.log('fields_altered: ', fields_altered);

    if ($.isEmptyObject(fields_altered)) {
      toastr.warning('Nothing to save'); // @todo add an 'undo' button
      return false;
    }

    // var node = Drupal.casa_node_mgt.normalise_node(fields_altered);
    var fields = Drupal.casa_node_mgt.simplify_node_fields(fields_altered, settings);
    // console.log('fields: ', fields);

    var node = fields;

    // Manage fields that need special formatting for the API
    node = reformat_fields_for_API(node);

    // console.log('node: ', node);

    var nids = Drupal.selection.get_selected_nids();

    if (Drupal.edit_selected.is_page('observation_info')) {
      // node['type'] = "observation";
      var type = "observation";
      Drupal.es_api_interactions.update_nodes(node, type, nids, context);
    }
    else if (Drupal.edit_selected.is_page('picture_info')
      || Drupal.edit_selected.is_page('upload')) {
      var type = "picture";
      Drupal.es_api_interactions.update_nodes(node, type, nids, context);
    }
  });



  // Save a new identification

  var save_id_btn = identify_form.find('input[type="submit"][value="Save"]', context);
  save_id_btn.on('click', function(event){
    event.preventDefault();

    // Re-fetch the form (might have been changed by AJAX)
    identify_form = $('.identify_form_wrapper'); // Does NOT use context
    // console.log('identify_form: ', identify_form);

    var identification_nid = Drupal.es_api_interactions
      .save_identification_from_form(identify_form, context); // Uses AJAX
  });



  // Save a new interaction
  var save_intrn_btn = interaction_form.find('.form-actions input[type="submit"][value="Save"]', context);
  save_intrn_btn.on('click', function(event){
    event.preventDefault();

    // Re-fetch the form (might have been changed by AJAX)
    interaction_form =  $('.interaction_form_wrapper'); // Does NOT use context
    // console.log('identify_form: ', identify_form);

    var interaction = Drupal.es_api_interactions
      .save_interaction_from_form(interaction_form, context);
  });





  // Forms

  // Manage 'Number specimens' form submission using AJAX
  $('#number-specimens form', context).submit(function() {
    var form = $(this);
    manage_form_number_specimens(form);

    // Prevent submitting again.
    return false;
  });

  // Manage 'Add blank observations' form submission using AJAX
  $('#create-blank-observations form', context).submit(function() {
    var form = $(this);
    manage_form_add_blank_obs(form);

    // Prevent submitting again.
    return false;
  });
}



function reformat_fields_for_API(node) {
  if (node['description']) {
    node['description'] = {value: node['description']};
  }

  if (node['location']) {
    var coords = node['location'].split(', ');
    node['location'] = {
      longitude: coords[0],
      latitude:coords[1]
    };
  }

  if (node['dateTaken']) {
    // Convert from 'dd/mm/yyyy' format to unix timestamp format
    var date_parts = node['dateTaken'].split('/');
    var dateString = [date_parts[2], date_parts[1], date_parts[0]].join('-');
    // console.log('dateString: ', dateString);
    node['dateTaken'] = Date.parse(dateString) / 1000;
  }

  if (node['dateObserved']) {
    // Convert from 'dd/mm/yyyy' format to unix timestamp format
    var date_parts = node['dateObserved'].split('/');
    var dateString = [date_parts[2], date_parts[1], date_parts[0]].join('-');
    // console.log('dateString: ', dateString);
    node['dateObserved'] = Date.parse(dateString) / 1000;
  }
  return node;
}



function add_observations_to_map() {
  // console.log("Called: add_observations_to_map()");

  // Map; add all observation's data

  if (! page_has_map) {
    return null;
  }

  map_layer_all_locations = Drupal.casa_map_mgt.create_vector_layer();
  // console.log('map_layer_all_locations: ', map_layer_all_locations.getSource().getFeatures());

  Drupal.casa_map_mgt.add_layer(map_layer_all_locations);

  // console.log('selectables_data: ', selectables_data);
  $.each(selectables_data, function( index, selectable ) {
    add_observation_to_map(selectable, standard_feature_style);
  });
  // console.log('map_layer_all_locations features: ', map_layer_all_locations.getSource().getFeatures());

  if (map_layer_all_locations.getSource().getFeatures().length == 0) {
    // console.log('Are no features.');
    return null;
  }

  Drupal.casa_map_mgt.center_map(map_layer_all_locations);

  // console.log("End: add_observations_to_map()");
}



function add_observation_to_map(selectable_data, style) {
  // console.log('selectable_data: ', selectable_data);

  var field_name = 'location';

  var selectable_prop_has_val = selectable_data.attributes[field_name] != null
    && selectable_data.attributes[field_name] != '';

  if (! selectable_prop_has_val) {
    return null;
  }

  var coordinates = selectable_data.attributes[field_name];
  // console.log('coordinates: ', coordinates);

  // feature = Drupal.casa_map_mgt.create_feature_from_JSON(feature_data);
  feature = Drupal.casa_map_mgt.create_point_feature_from_lon_lat(
    parseFloat(coordinates.longitude),
    parseFloat(coordinates.latitude));
  // console.log('feature coords: ', feature.getGeometry().getCoordinates());

  feature.setStyle(style);

  // Give it a nid property
  feature['nid'] = selectable_data.id;

  // Add the collection location as a layer to the map
  map_layer_all_locations.getSource().addFeature(feature);
}














function set_up_dialogs(context) {
  // console.log('Called: set_up_dialogs()');

  // Transform the edit form into a dialog
  edit_form.dialog({
    modal: true,
    autoOpen: false,
    resizable: false,
    width: 800,
    title: 'Edit observations',
    open: function( event, ui ) {
      $(document).trigger('edit_form_dialog-created');
    },
    close: dialog_close_handler
  });

  // Transform the identify form into a dialog
  identify_form.dialog({
    modal: true,
    autoOpen: false,
    resizable: false,
    width: 800,
    title: 'Identify observations',
    close: dialog_close_handler
  });

  // Transform the interaction form into a dialog
  interaction_form.dialog({
    modal: true,
    autoOpen: false,
    resizable: false,
    width: 800,
    title: 'Add interaction',
    close: dialog_close_handler
  });
}


function dialog_close_handler() {
  fields_altered_names = [];
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

  var num_selected = Drupal.selection.get_selected_nids().length;
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
  fields_altered_names.push(target.attr('name'));
  // console.log('fields_altered_names: ', fields_altered_names);
}



function remove_unaltered_node_fields(node) {
  // console.log('node: ', node);
  // console.log('fields_altered_names: ', fields_altered_names);

  $.each( node, function( key, field ) {
    // console.log('key: ', key);

    var is_altered = $.inArray(key, fields_altered_names) != -1;
    // console.log('is_altered: ', is_altered);

    var is_checkboxes = key.split('[')[0] === 'field_tags';
    // console.log(key + ' is_checkboxes: ', is_checkboxes);

    // If is description field and only one selected, don't delete
    // if (key == 'body[und][0][value]' && Drupal.selection.get_selected_selectables().length == 1) {}

    if ((! is_altered) && (! is_checkboxes)) {
      delete node[key];
    }

  });
  // console.log("node: ", node);
  return node;
}


/**
 * Takes a string representation of a lat-lon location and turns it into lon-lat coordinates.
 * Eg. ["13, 17"] returns [17, 13].
 */
function parse_location(raw_field_value) {
  if (typeof raw_field_value == 'undefined' || ! raw_field_value instanceof Array) {
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
  if (typeof point == 'undefined' || ! point instanceof ol.geom.Point) {
    return null;
  }
  var feature = new ol.Feature({geometry: point});
  var source = new ol.source.Vector({features: [feature]});
  var layer = new ol.layer.Vector({source: source});
  layer.mn = 'observation_location';
  return layer;
}




function rotate_selected(button) {
    // console.log('called: rotate_selected()');
    var toastr_info = toastr.info('Rotating pictures…'); // @todo add an 'undo' button

    var url = Drupal.settings.basePath + 'ajax/images/rotate';
    var selecteds_nids = Drupal.selection.get_selected_nids();
    var rotation_params = {
      'nids': selecteds_nids.join( "|" ),
      'degrees': '90'
    };

    // If counter-clockwise
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
        // document.location.reload();

        rotate_picture_elements(selecteds_nids, rotation_params['degrees']);

      } else {
        toastr.error('Sorry; there was a problem rotating the pictures.');
        // console.log( "In rotate_result.done(), data: ", data );
      }
      // console.log('data: ', data);
    });
}



function rotate_picture_elements(nids, degrees) {
  // console.log('nids: ', nids);
  // console.log('degrees: ', degrees);
  $.each(nids, function(index, nid) {
    var selectable = Drupal.edit_selected.get_selectable_from_nid(nid);
    var image = selectable.find('[class*="field"] img');
    var current_rotation = image.attr('data-rotated');
    current_rotation = typeof current_rotation == 'undefined'
      ? current_rotation = 0
      : current_rotation.replace('deg', '');
    var new_rotation = parseInt(current_rotation) + parseInt(degrees);
    image.attr('data-rotated', new_rotation + 'deg');
  });
}




function manage_form_number_specimens(form) {
  // console.log('form.serialize(): ', form.serialize());
  // var are_selecteds = Drupal.selection.are_selecteds();
  // console.log('are_selecteds: ', are_selecteds);

  // Disable buttons if there are no selections
  if (! Drupal.selection.are_selecteds()) {
    toastr.error('You need to select an observation.');
    return false;
  }

  var request_params = {
    // url: form.attr('action'),
    url: Drupal.casa_core.get_site_url() + 'ajax/number_specimens',
    type: form.attr('method'),
    data: form.serialize()
  };

  var toastr_info = toastr.info('Numbering observations…'); // @todo add an 'undo' button

  // Send jq xhr request.
  var jqxhr = $.ajax(request_params);

  jqxhr.error(function(data) {
    toastr.error('Sorry; there was a problem numbering the observations.');
    console.log( "In ajax.error(), data: ", data );
  });

  jqxhr.success(function(data) {
    toastr.success('Observations have been numbered successfully. Reloading in 3 seconds…');
    var reload_timeout = window.setTimeout(function(){
      document.location.reload();
    }, 3000);
  });

  jqxhr.always(function( data ) {
    toastr_info.remove();
  });
}




function manage_form_add_blank_obs(form) {
  // console.log('form.serialize(): ', form.serialize());

  form.find('#collection-id').val(Drupal.casa_core.get_collection_nid());
  // console.log('form.serialize: ', form.serialize());

  var toastr_info = toastr.info('Adding picture-less observations…'); // @todo add an 'undo' button

  var request_params = {
    // url: form.attr('action'),
    url: Drupal.casa_core.get_site_url() + 'ajax/observations/create-blank',
    type: form.attr('method'),
    data: form.serialize(),
  };

  // Send jq xhr request.
  var jqxhr = $.ajax(request_params);

  jqxhr.error(function(data) {
    toastr.error('Sorry; there was a problem adding picture-less observations.');
  });

  jqxhr.success(function(data) {
    toastr.success('Picture-less observations have been created successfully. Reloading in 3 seconds…');
    var reload_timeout = window.setTimeout(function(){
      document.location.reload();
    }, 3000);
  });

  jqxhr.always(function( data ) {
    toastr_info.remove();
  });
}




// function set_up_field_progress(context) {
//   // console.log('Called: set_up_field_progress()');
//   var fields_count = 10;

//   for (var i = 0; i < fields_count; i++) {
//     $('.progress-container', context).append('<div></div>');
//   };

//   var fields_active = 3;

//   for (var i = 0; i < fields_active; i++) {
//     $('.progress-container > div:nth-of-type(' + (i + 1) + ')', context).addClass('active');
//   };
// }



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
  // console.log('identifications_data: ', identifications_data);

  var field_name = button.attr('value');
  // console.log('field_name: ', field_name);

  // @todo Validate: Check that selectables data has been fetched (using AJAX).

  // Make sure .field-data elements are empty, and no .selectables are 'matched'.
  selectables.find('.field-data').html('');
  selectables.attr('data-is-match', 'false');

  var fields_with_data_count = 0; // How many selectables have data for this field.

  // console.log('field_name: ', field_name);
  if (field_name == 'no_fields') {
    button.addClass('active');
    field_shown = field_name;
  }
  else {
    // console.log('selectables_data: ', selectables_data);

    // For each selectable
    // console.log('selectables_map: ', selectables_map);
    $.each(selectables_data, function( index, selectable_data ) {
      // console.log( index, ": ", selectable_data );

      // console.log('selectable_data.attributes[field_name]: ',
      //   selectable_data.attributes[field_name]);

      var nid = selectable_data.id;

      var selectable_prop_has_val =
        selectable_data.attributes[field_name] != null
        && selectable_data.attributes[field_name] != '';

      var field_data = '';



      // 'List' fields
      var list_fields = {
        beauty: 'field_beauty',
        usefulness: 'field_usefulness'
      };

      var is_list_field = Object.keys(list_fields).indexOf(field_name) > -1;
      if (is_list_field) {
        // console.log('selectable_data: ', selectable_data);

        var codes = selectable_data.attributes[field_name];
        // console.log('codes: ', codes);

        if (codes) {
          $.each(codes, function(index, code) {
            field_data += settings_of_setup['node_info']['fields_info']
              [list_fields[field_name]]['allowed_values'][code];
          });
        }
        // console.log('field_data: ', field_data);
      }



      // 'Taxonomy term reference' fields
      var t_ref_fields = {
        subject: 'field_subject',
        tags: 'field_tags',
        locality: 'field_locality'
      };

      var is_t_ref_field = Object.keys(t_ref_fields).indexOf(field_name) > -1;
      if (is_t_ref_field) {
        // console.log('selectable_data: ', selectable_data);

        var tids = selectable_data.attributes[field_name];
        // console.log('tids: ', tids);

        if (tids) {
          $.each(tids, function(index, tid) {
            field_data += settings_of_setup['node_info']['fields_info']
              [t_ref_fields[field_name]]['terms'][tid];
          });
        }
        // console.log('field_data: ', field_data);
      }



      else if (field_name == 'identifications') {
        // console.log('identifications_data: ', identifications_data);
        var identifications_indexes = identifications_map[parseInt(nid)];

        if (typeof identifications_indexes != 'undefined') {

          identifications_indexes.forEach(function(identifications_index, index) {
            if (index != 0) {
              field_data += ', ';
            }
            var identification = identifications_data[identifications_index];
            var certainty_label = settings_of_setup['node_info']['fields_info']
              ['field_certainty']['allowed_values']
              [identification.attributes.certainty];

            field_data
              += identification.attributes.label
              + " (" + certainty_label + ')';
          });
        }
      }



      else if (field_name == 'interactions') {
        // console.log('interactions_data: ', interactions_data);
        var interactions_indexes = interactions_map[parseInt(nid)];

        if (typeof interactions_indexes != 'undefined') {

          interactions_indexes.forEach(function(interaction_index, index) {
            if (index != 0) {
              field_data += ', ';
            }
            var interaction = interactions_data[interaction_index];
            field_data
              += interaction.attributes.label;
          });
        }
      }



      // Most ordinary fields
      else if (selectable_prop_has_val) {
        // console.log('selectable_data: ', selectable_data);

        field_data = selectable_data.attributes[field_name];
        // console.log('field_data: ', field_data);

        // If it's not a string, turn it into a string
        if (typeof field_data != 'string') {
          field_data = JSON.stringify(field_data);
        }
        // console.log('field_data: ', field_data);
      }



      // If there is a value
      if (field_data && field_data != '') {
        // console.log('field_data: ', field_data);

        fields_with_data_count++;

        var selectable = Drupal.edit_selected.get_selectable_from_nid(nid);
        selectable.attr('data-is-match', 'true');
        selectable.find('.field-data').append(field_data);
      }

    });

    // selectables.find('.field-data').append('data');

    field_shown = field_name;
  }

  if (fields_with_data_count == 0 && field_name != 'no_fields') {
    toastr.info('None of the selectables have a value for this field.');
  }

  // console.log('field_shown: ' + field_shown);
  return field_shown;
}



function set_up_keypress_mgmt(context) {

  $(document, context).bind('keydown', 'e',         handle_keypress_edit);

  if (Drupal.edit_selected.is_page('picture_info')
    || Drupal.edit_selected.is_page('upload')) {
    Drupal.casabio.add_keypress_info(
      "<tr><td><strong>left</strong> : </td><td>Previous picture</td></tr>"
      + "<tr><td><strong>right</strong> : </td><td>Next picture</td></tr>"
      + "<tr><td><strong>x</strong> : </td><td>Select picture</td></tr>"
      + "<tr><td><strong>c</strong> : </td><td>Un-select all pictures</td></tr>"
      + "<tr><td><strong>e</strong> : </td><td>Edit selected pictures</td></tr>"
    );
  }

  if (Drupal.edit_selected.is_page('observation_info')) {
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
  edit_form.dialog('open');
}

function handle_keypress_identify() {
  identify_form.dialog('open');
}

// Not needed; jQuery ui Dialogs close with 'esc' automatically.
// function handle_keypress_close_dialog() {
//   Drupal.casa_core.close_dialogs();
// }


})(jQuery, Drupal, this, this.document);
