/**
 * @file
 * A JavaScript file for…
 */


// Immediately-invoked function expression (IIFE, aka. An "anonymous closure")
// Makes this JavaScript compatible with libraries other than jQuery
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
 *  .get_selectables_from_nids()
 *  .set_identifications_data()
 *  .identifications_data_append()
 *  .refresh_current_field_indicator()
 *  // .get_selectable_field_value()
 *
 * misc_page_set_up()
 * add_listeners()
 *
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



var page_is_setup = false,
    settings_of_setup,
    page_setup_loadings = [],
    page_setup_loadings_message,
    page_content_type;

var edit_form,
    identify_form,
    interaction_form,
    toolbar;

// var current_page;
var page_has_map;

var map_layer_all_locations,
    standard_feature_style,
    selected_feature_style;

var fields_altered_names = [];

var selectables = {}; // jQuery objects

var selectables_data = []; // Data returned from API requests
var selectables_map = {}; // Maps selectable's nid: its position in the selectables_data array

var identifications_data = [];
var identifications_map = {}; // Maps selectable's nid: list of positions of identifications of it
// In the form of {nid: [0, 1, 3]}

var interactions_data = [];
var interactions_map = {}; // Maps selectable's nid: list of positions of interactions of it ?
// In the form of {nid: [0, 1, 3]} ?


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.edit_selected = {
  attach: function(context, settings) {
    // console.log('context: ', context);
    // console.log('settings: ', settings);
    
    if (! page_is_setup) {
      // console.log('edit_selected_behaviors');

      define_variables(context, settings);

      page_setup_loadings_message = toastr.info('Page setup loading…', null, {
        'timeOut': '-1'
      });

      // fetch_selectables_data
      if (Drupal.contribute.is_page('upload')) {
        page_content_type = 'picture';
      }
      else if (Drupal.contribute.is_page('picture_info')) {
        page_content_type = 'picture';
        // console.log('Calling fetch_selectables_data()');
        page_setup_loadings.push('fetch_selectables_data');
        Drupal.es_api_interactions.fetch_selectables_data(null, 'picture', false,
          [[Drupal.edit_selected.refresh_current_field_indicator, this, []]]);
      }
      if (Drupal.contribute.is_page('observation_info')) {
        page_content_type = 'observation';
        page_setup_loadings.push('fetch_selectables_data');
        Drupal.es_api_interactions.fetch_selectables_data(null, 'observation', false,
          [[Drupal.edit_selected.refresh_current_field_indicator, this, []]]);

        page_setup_loadings.push('fetch_identifications_data');
        Drupal.es_api_interactions.fetch_identifications_data(false);

        page_setup_loadings.push('fetch_interactions_data');
        Drupal.es_api_interactions.fetch_interactions_data(false);
      }

      // console.log('fetch_token()');
      page_setup_loadings.push('fetch_token');
      Drupal.es_api_interactions.fetch_token(false);


      // Page setup

      misc_page_set_up(context, settings);

      adjust_buttons(context);

      // set_up_field_progress(context);

      set_up_keypress_mgmt(context);

      add_listeners(context, settings);

      // If there are identifications, show 'Auto-identify' dialog
      var are_identifications = false;
      if (! are_identifications) {
        $('[data-display="#auto-identify-dialog"]').trigger('click');
      }

      // When clicking on a checkbox, remove 'mixed' indications on all other checkboxes of that field
      $('input[type="checkbox"]').change(function() {
        // console.log('$(this): ', $(this));
        $(this).parents('[class*="form-field-name"]').find('input')
          .prop("indeterminate", false)
          .attr('data-values-status', '' );
      });


      // After setup (non-destructive)

      page_is_setup = true;
    }

  },
  weight: 7
};


Drupal.edit_selected = {

  // is_page: function(page) {
  //   return current_page == page;
  // },


  is_page_setup_complete: function() {
    return (page_setup_loadings.length <= 0);
  },


  selectables_append: function(selectable) {
    selectables = selectables.add(selectable);
    // console.log('selectables_append(): selectables.length: ', selectables.length);
  },

  // ===========================================================================
  //                                      selectables_data

  set_selectables_data: function(selectables_data_in) {
    selectables_data = selectables_data_in;
    // console.log('selectables_data: ', selectables_data);

    selectables_data_in.forEach(function(currentValue, index, array) {
      //
    });
  },

  set_selectable: function(nid, selectable) {
    // If nid not provided, just append selectable to the end of the array
    if (typeof nid === 'undefined' || nid == null) {
      var index = selectables_data.push(selectable);
      // console.log('set_selectable(): selectables_data: ', selectables_data);
      populate_selectables_map();
      // selectables_map[nid] = index;
    }
    else {
      var index = Drupal.edit_selected.get_selectables_map()[nid];
      selectables_data[index] = selectable;
    }
    // console.log('set_selectable(): selectables.length: ', selectables.length);
  },

  selectables_data_append: function(selectable) {
    selectables_data.push(selectable);
    // console.log('selectables_data_append(): selectables_data.length: ', selectables_data);
  },

  get_selectables_data: function() {
    return selectables_data;
  },

  get_selectable_data: function(nid) {
    return selectables_data[selectables_map[nid]];
  },

  populate_selectables_map: function() {
    selectables_map = {};

    $.each(selectables_data, function( index, node ) {
      selectables_map[node.id] = index;
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


  /**
   * Returns an array of jQuery objects.
   */
  get_selectables_from_nids: function(nids) {
    selectables_out = [];

    $.each(nids, function(index, nid) {
      selectables_out.push(selectables.find('.property-nid:contains("' + nid + '")')
        .parents('.selectable'));
    });
    return selectables_out;
  },

  // ===========================================================================
  //                                      identifications_data

  set_identifications_data: function(identifications_data_in) {
    identifications_data = identifications_data_in;
  },

  identifications_data_append: function(identification_in) {
    // Check if an identification of this observation with this species already exists
    var matching_id_index = null;

    $.each(identifications_data, function(index, identification) {
      if ((identification_in['attributes']['observation'] == identification['attributes']['observation'])
        && (identification_in['attributes']['identifiedSpecies'] == identification['attributes']['identifiedSpecies'])) {
        // console.log('index: ', index);
        matching_id_index = index
      }
    });

    // If one exists, replace it
    if (matching_id_index) {
      identifications_data[matching_id_index] = identification_in;
    }
    // otherwise add this new identification.
    else {
      identifications_data.push(identification_in);
    }
    // console.log('identifications_data: ', identifications_data);
  },

  /**
   * Remember that the _map object is keyed by the obervations' nids, not the identifications' nids
   */
  populate_identifications_map: function() {
    identifications_map = {};

    $.each(identifications_data, function( index, node ) {
      var nid = node.attributes.observation;
      // console.log('nid: ', nid);

      if (typeof identifications_map[nid] == 'undefined') {
        identifications_map[nid] = [];
      }

      identifications_map[nid].push(index);
      // identifications_map[nid] = index;
    });
    // console.log('identifications_map after population: ', identifications_map);
  },

  // ===========================================================================
  //                                      interactions_data

  set_interactions_data: function(interactions_data_in) {
    interactions_data = interactions_data_in;
  },

  interactions_data_append: function(interaction_in) {
    interactions_data.push(interaction_in);
  },

  /**
   * Remember that the _map object is keyed by the obervations' nids, not the identifications' nids
   */
  populate_interactions_map: function() {
    interactions_map = {};

    $.each(interactions_data, function( index, node ) {
      var nid = node.attributes.observation;
      // console.log('nid: ', nid);

      if (typeof interactions_map[nid] == 'undefined') {
        interactions_map[nid] = [];
      }

      interactions_map[nid].push(index);
      // identifications_map[nid] = index;
    });
    // console.log('interactions_map: ', interactions_map);
  },



  refresh_current_field_indicator: function() {
    // console.log('refresh_current_field_indicator()');
    var field_shown = null;
    var radio_selected = $('#show-fields-radios input[type="radio"]:checked');
    // console.log('radio_selected: ', radio_selected);
    field_shown = show_field_indicators(field_shown, radio_selected);
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
      $('form[action="services/number_specimens"] input[name="nids"]')
        .val(Drupal.selection.get_selected_nids().join(','));

      Drupal.form_prefiller.prefill_form(edit_form, selectables_data, settings);
    });



    $(document).on('selection:select_all', function(event) {

      Drupal.form_prefiller.clear_form(edit_form);
      
      if (page_has_map) {
        Drupal.edit_selected.reset_features_style();
      }

      // Set 'Number Specimens' form's 'nids' (hidden) field
      $('form[action="services/number_specimens"] input[name="nids"]')
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


  /**
   * Makes changes to a map feature (point) representing a node's location.
   */
  update_feature: function(nid) {
    // console.log('nid: ', nid);
    if (! page_has_map) {
      return null;
    }

    var features = map_layer_all_locations.getSource().getFeatures();

    // Get the feature
    var feature;
    $.each(features, function(index, feature_index) {
      // console.log('feature_index: ', feature_index);
      if (feature_index.nid == nid) {
        feature = feature_index;
      }
    });

    // If this nid doesn't yet have a feature on the map, create one for it.
    if (typeof feature == 'undefined') {
      var selectable = Drupal.edit_selected.get_selectable_data(nid);
      add_observation_to_map(selectable, selected_feature_style);
    }

    // Otherwise, alter its longitude and latitude.
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
  },


  set_load_finished: function(nid) {
    // console.log('nid: ', nid);
    var selectable = Drupal.edit_selected.get_selectable_from_nid(nid)
      .find('.loader').remove();
  },

  /**
   * Removes the circular 'loading' indicator image from selectables.
   *
   * @param nids
   *   An array of node ids.
   */
  set_loads_finished: function(nids) {
    // console.log('nid: ', nid);
    $.each(nids, function(index, nid) {
      var selectable = Drupal.edit_selected.get_selectable_from_nid(nid)
        .find('.loader').remove();
    });
  }

};



  /**
   * Sets variables needed by page, called during page load.
   */
function define_variables(context, settings) {
  settings_of_setup = settings;

  // current_page = settings.edit_selected.current_page;
  // console.log('current_page: ', current_page);

  edit_form =         $('.edit_form_wrapper', context);
  identify_form =     $('.identify_form_wrapper', context);
  interaction_form =  $('.interaction_form_wrapper', context);
  toolbar =           $('[role="toolbar"][aria-label*="primary"]', context);

  selectables =       $('.selectable', context);
  // console.log('selectables: ', selectables);

  if (Drupal.contribute.is_page('observation_info')) {
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
}




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

  // // Element to contain the value of the selected field when one of the 'show field' radio buttons is clicked
  selectables.append('<span class="field-data"></span>');
  Drupal.edit_selected.refresh_current_field_indicator();

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

  $('button.rotate', context).on( 'click', function(event) {
    event.preventDefault();
    rotate_selected($(this));
  });

  $('input, textarea, select', context ).on( 'change', function() {
    // console.log('changed');

    // If not a field in a node form, ignore this
    if (! $(this).parents('form').hasClass('node-form')) {
      return null;
    }

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
    field_shown = show_field_indicators(field_shown, $(this));
  });

  $('[data-display="#delete-observations"]').on('click', function () {
    delete_selected_observations(context);
  });

  $('#deidentify').on('click', function(event) {
    event.preventDefault();
    remove_selected_identifications(context);
  });

  $(document).on('dialog_closed', function(event) {
    dialog_close_handler();
  });


  $('[data-trigger="#auto-identify"]').on('click', function () {
    var collection_nid = Drupal.casa_core.get_collection_nid();
    Drupal.es_api_interactions.auto_identify_observations(collection_nid);
  });


  $(document).on('dialog_opened', function(event, element) {
    // console.log('opened, element: ', $(element));
    if ($(element).hasClass('identify_form_wrapper')) {
      $(element).find('.collapsed .fieldset-title').trigger('click');
    }
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

    if (! Drupal.edit_selected.is_page_setup_complete()) {
      toastr.warning('Page setup is not complete yet.'); // @todo add an 'undo' button
      return null;
    }

    // --------------------------------
    // Get altered field values

    var node_serialized_raw = $( this ).serializeArray();
    // console.log('node_serialized_raw: ', node_serialized_raw);
    var fields_raw = Drupal.casa_node_mgt.convert_form_to_node(node_serialized_raw);
    // console.log('fields_raw: ', fields_raw);
    var fields_altered = remove_unaltered_node_fields(fields_raw);
    // console.log('fields_altered: ', fields_altered);

    if ($.isEmptyObject(fields_altered)) {
      toastr.warning('Nothing to save'); // @todo add an 'undo' button
      return null;
    }

    // --------------------------------
    // Convert field values into note object to save

    // var node = Drupal.casa_node_mgt.normalise_node(fields_altered);

    // Convert {field_year[und][0][value]: "2016"} to {year: "2016"}
    var fields = Drupal.casa_node_mgt.simplify_node_fields(fields_altered, settings);
    // console.log('fields: ', fields);

    var node = fields;

    // Manage fields that need special formatting for the API
    node = reformat_fields_for_API(node);
    // console.log('node: ', node);

    // --------------------------------
    // Apply the save to all selected nodes

    var nids = Drupal.selection.get_selected_nids();

    if (Drupal.contribute.is_page('observation_info')) {
      // node['type'] = "observation";
      Drupal.es_api_interactions.update_nodes(node, page_content_type, nids, context);
    }
    else if (Drupal.contribute.is_page('picture_info')
      || Drupal.contribute.is_page('upload')) {
      Drupal.es_api_interactions.update_nodes(node, page_content_type, nids, context);
    }

    // --------------------------------
    // Close dialog, show loading indicators

    // var dialog = $(this).parents('.ui-dialog-content');
    edit_form.dialog('close');

    var loader = Drupal.casa_utilities.get_loader_markup();
    $.each(selectables.filter('.selected'), function (key, selectable) {
      $(this).append(loader);
    });

    Drupal.selection.deselect_all();
  });



  // Save a new identification

  var save_id_btn = identify_form.find('input[type="submit"][value="Save"]', context);
  save_id_btn.on('click', function(event){
    event.preventDefault();

    // Re-fetch the form (might have been changed by AJAX)
    identify_form = $('.identify_form_wrapper'); // Does NOT use context
    // console.log('identify_form: ', identify_form);

    var identification_nid = Drupal.es_api_interactions
      .save_identifications_from_form(identify_form); // Uses AJAX
    
    Drupal.selection.deselect_all();
    Drupal.casa_core.close_dialogs();
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
    
    Drupal.selection.deselect_all();
    Drupal.casa_core.close_dialogs();
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

  // When each 'loading function' of the 'page setup' is completed
  $(document).on('selectables_data_fetched', function() {
    check_page_setup_loadings_done('fetch_selectables_data');
    // console.log('selectables_data: ', selectables_data);
  });
  $(document).on('identifications_data_fetched', function() {
    check_page_setup_loadings_done('fetch_identifications_data');
    // console.log('selectable_data: ', selectable_data);
  });
  $(document).on('interactions_data_fetched', function() {
    check_page_setup_loadings_done('fetch_interactions_data');
    // console.log('selectable_data: ', selectable_data);
  });
  $(document).on('token_fetched', function() {
    check_page_setup_loadings_done('fetch_token');
  });
}


/**
 * When a 'loading function' of the 'page setup' is completed, remove it from
 * the list, and check if all loading functions have completed.
 *
 * @param loading_completed
 *   Name of loading function that has just been completed.
 */
function check_page_setup_loadings_done(loading_completed) {
  page_setup_loadings.splice(page_setup_loadings.indexOf(loading_completed), 1);

  if (Drupal.edit_selected.is_page_setup_complete()) {
    page_setup_loadings_message.remove();
  }
}



function reformat_fields_for_API(node) {
  if (node['description']) {
    // node['description'] = {value: node['description']}; // OLD API
    node['description'] = {
      value: node['description']
    };
  }

  if (node['location']) {
    var coords = node['location'].split(', ');
    node['location'] = {
      longitude: coords[0],
      latitude: coords[1]
    };
    // node['location'] = [coords[0], coords[1]];
    // console.log("node['location']: ", node['location']);
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

  Drupal.casa_map_mgt.get_map(); // Ensures map is defined.

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

  if (! coordinates.longitude || ! coordinates.longitude) {
    // console.log('Observation does not have valid coordinates.');
    return null;
  }

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









function dialog_close_handler() {
  // console.log('Called: dialog_close_handler()');
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
  // Enable buttons if there are any selections
  else if (num_selected >= 1) {
    toolbar.find('button#edit, button#identify').prop( "disabled", false );
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
  console.log('node: ', node);
  // console.log('fields_altered_names: ', fields_altered_names);

  var fields_with_values = Object.keys(node);
  // console.log('fields_with_values: ', fields_with_values);

  $.each( fields_altered_names, function( key, field ) {
    // console.log('field: ', field);

    // If this altered field doesn't exist in the node data
    var is_missing = $.inArray(field, fields_with_values) == -1;
    // console.log('is_missing: ', is_missing);

    if (is_missing) {
      node[field] = "";
    }
  });
  // console.log('node: ', node);

  $.each( node, function( field, value ) {
    // console.log('field: ', field);

    var is_altered = $.inArray(field, fields_altered_names) != -1;
    // console.log('is_altered: ', is_altered);

    var is_checkboxes = field.split('[')[0] === 'field_tags';
    // console.log(field + ' is_checkboxes: ', is_checkboxes);

    // If is description field and only one selected, don't delete
    // if (field == 'body[und][0][value]' && Drupal.selection.get_selected_selectables().length == 1) {}

    if ((! is_altered) && (! is_checkboxes)) {
      delete node[field];
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
  // If counter-clockwise
  var deg = (button.attr('id') == 'rotate-ccw') ? '-90' : '90';
  rotate(deg);
}




function rotate(deg) {
  // console.log('called: rotate_selected()');
  var toastr_info = toastr.info('Rotating pictures…', null, {
    'timeOut': '-1'
  }); // @todo add an 'undo' button

  var url = Drupal.settings.basePath + 'services/images/rotate';
  var selecteds_nids = Drupal.selection.get_selected_nids();
  var rotation_params = {
    'nids': selecteds_nids.join( "|" ),
    'degrees': deg
  };

  var jqxhr = $.post(url, rotation_params, function(data, textStatus, xhr) {
    // console.log('Rotate POST request completed…');
  });

  jqxhr.fail(function( data ) {
    if(jqxhr.readyState < 4)  {
      // toastr.warning('Request was not completed.');
    }
    else {
      toastr_info.remove();
      toastr.error('Sorry; there was a problem rotating the pictures.');
      console.log( "In jqxhr.fail(), Reason: " + data['reason'] );
    }
  });

  jqxhr.done(function( data ) {
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
      // console.log( "In jqxhr.done(), data: ", data );
    }
    // console.log('data: ', data);
  });

  Drupal.selection.deselect_all();
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




function manage_form_number_specimens(form, success_callbacks, always_callbacks) {
  // console.log('form.serialize(): ', form.serialize());
  // var are_selecteds = Drupal.selection.are_selecteds();
  // console.log('are_selecteds: ', are_selecteds);

  // Disable buttons if there are no selections
  if (! Drupal.selection.are_selecteds()) {
    toastr.error('You need to select an observation before numbering specimens.');
    return false;
  }

  var request_params = {
    // url: form.attr('action'),
    url: Drupal.casa_core.get_site_url() + 'services/number_specimens',
    type: form.attr('method'),
    data: form.serialize()
  };

  var toastr_info = toastr.info('Numbering observations…', null, {
    'timeOut': '-1'
  }); // @todo add an 'undo' button

  // Send jq xhr request.
  var jqxhr = $.ajax(request_params);

  jqxhr.error(function(data) {
    toastr.error('Sorry; there was a problem numbering the observations.');
    console.log( "In ajax.error(), data: ", data );
  });

  jqxhr.success(function(data) {

    Drupal.casa_utilities.invoke_callbacks(success_callbacks);
    
    toastr.success('Observations have been numbered successfully. Reloading…');
    // var reload_timeout = window.setTimeout(function(){
    //   document.location.reload();
    // }, 3000);
    document.location.reload();
  });

  jqxhr.always(function( data ) {
    toastr_info.remove();
    Drupal.casa_utilities.invoke_callbacks(always_callbacks);
  });
}




function manage_form_add_blank_obs(form, success_callbacks, always_callbacks) {
  // console.log('form.serialize(): ', form.serialize());

  form.find('#collection-id').val(Drupal.casa_core.get_collection_nid());
  // console.log('form.serialize: ', form.serialize());

  var toastr_info = toastr.info('Adding picture-less observations…', null, {
    'timeOut': '-1'
  }); // @todo add an 'undo' button

  var request_params = {
    // url: form.attr('action'),
    url: Drupal.casa_core.get_site_url() + 'services/observations/create-blank',
    type: form.attr('method'),
    data: form.serialize(),
  };

  // Send jq xhr request.
  var jqxhr = $.ajax(request_params);

  jqxhr.error(function(data) {
    toastr.error('Sorry; there was a problem adding picture-less observations.');
  });

  jqxhr.success(function(data) {

    Drupal.casa_utilities.invoke_callbacks(success_callbacks);

    toastr.success('Picture-less observations have been created successfully. Reloading…');
    // var reload_timeout = window.setTimeout(function(){
    //   document.location.reload();
    // }, 3000);
    document.location.reload();
  });

  jqxhr.always(function( data ) {
    toastr_info.remove();
    Drupal.casa_utilities.invoke_callbacks(always_callbacks);
  });
}




function delete_selected_observations(context) {
  var type = 'observation';
  var nids = Drupal.selection.get_selected_nids();
  Drupal.es_api_interactions.delete_nodes(type, nids, context);
}


function get_identifications_of_observations(nids) {
  var identifications = {};

  $.each(nids, function(index, observation_nid) {

    var identifications_indexes = identifications_map[parseInt(observation_nid)];
    // console.log('identifications_indexes: ', identifications_indexes);

    if (typeof identifications_indexes == 'undefined') {
      return null;
    }
    identifications_indexes.forEach(function(identifications_index, index) {
      var identification = identifications_data[identifications_index];
      identifications[identification.id] = identification;
    });
  });
  return identifications;
}



function remove_selected_identifications(context) {
  var type = 'identification';
  var observations_nids = Drupal.selection.get_selected_nids();

  // Deleselect the observations so they don't get removed after the delete
  Drupal.selection.deselect_all();

  var identifications = get_identifications_of_observations(observations_nids);
  // console.log('identifications: ', identifications);

  Drupal.es_api_interactions.delete_nodes(type, Object.keys(identifications), context);

  // console.log('identifications_data: ', identifications_data);
  $.each(identifications, function(nid, identification) {
    // console.log('nid: ', nid);
    // identifications_data.splice(identifications_map[nid], 1);

    $.each(identifications_data, function(index, identification_data) {
      // console.log('identification_data.id: ', identification_data.id);
      if (nid === identification_data.id) {
        // console.log('index: ', index);
        identifications_data.splice(index, 1);
        return false;
      }
    });
  });
  // console.log('identifications_data: ', identifications_data);
  Drupal.edit_selected.populate_identifications_map();
  Drupal.edit_selected.refresh_current_field_indicator();
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
function show_field_indicators(field_shown, button) {
  // console.log('field_shown: ', field_shown);
  // console.log('button: ', button);
  // console.log('identifications_data: ', identifications_data);

  var toastr_indicators = toastr.info('Loading…');

  var field_name = button.attr('value');
  // console.log('field_name: ', field_name);

  // @todo Validate: Check that selectables data has been fetched (using AJAX).

  // Make sure .field-data elements are empty, and no .selectables are 'matched'.
  selectables.find('.field-data').empty();
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
        // if (typeof settings_of_setup['node_info'] == 'undefined') {
        //   console.log('node')
        // }

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
          var tids_array = [];
          $.each(tids, function(index, tid) {
            tids_array.push(settings_of_setup['node_info']['fields_info']
              [t_ref_fields[field_name]]['terms'][tid]);
          });
          field_data = tids_array.join(',<br>');
        }
        // console.log('field_data: ', field_data);
      }



      else if (field_name == 'identifications') {
        var identifications_indexes = identifications_map[parseInt(nid)];
        // console.log('identifications_indexes: ', identifications_indexes);

        if (typeof identifications_indexes !== 'undefined') {

          identifications_indexes.forEach(function(identifications_index, index) {
            if (index != 0) {
              field_data += '';
            }
            var identification = identifications_data[identifications_index];
            var certainty_label = settings_of_setup['node_info']['fields_info']
              ['field_certainty']['allowed_values']
              [identification.attributes.certainty];

            field_data
              += '<span>' + identification.attributes.label
              + " (" + certainty_label + ')</span>';
          });
        }

        // Better way to do it...
        // @todo implement this
        // var identifications = get_identifications_of_observations([nid]);
      }



      else if (field_name == 'interactions') {
        // console.log('interactions_data: ', interactions_data);
        var interactions_indexes = interactions_map[parseInt(nid)];

        if (typeof interactions_indexes != 'undefined') {

          interactions_indexes.forEach(function(interaction_index, index) {
            if (index != 0) {
              // field_data += ', ';
            }
            var interaction = interactions_data[interaction_index];
            field_data
              += '<span>' + interaction.attributes.label + '</span>';
          });
        }
      }



      // Geofields
      else if (field_name == 'location') {
        // console.log('selectable_data: ', selectable_data);

        field_data = selectable_data.attributes[field_name];

        if (! field_data) {
          return null;
        }
        var decimal_places = 3,
          lon = parseFloat(field_data.longitude),
          lat = parseFloat(field_data.latitude);
        if (! lon && ! lat) {
          return null;
        }
        // console.log('field_data: ', field_data);

        // Displayed latitude first, longitude second (simply by convention)
        field_data = 
          lat.toFixed(decimal_places) + '&deg;N, <br>' +
          lon.toFixed(decimal_places) + '&deg;E';
        // console.log('field_data: ', field_data);
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
        selectable.find('.field-data').html(field_data);
      }

    });

    // selectables.find('.field-data').append('data');

    field_shown = field_name;
  }


  if (fields_with_data_count == 0 && field_name != 'no_fields') {
    toastr.info('None of the ' + page_content_type + ' have a value for "' + field_name + '".');
  }
  
  toastr_indicators.remove();

  // console.log('field_shown: ' + field_shown);
  return field_shown;
}



function set_up_keypress_mgmt(context) {

  $(document, context).bind('keydown', 'e',         handle_keypress_edit);

  if (Drupal.contribute.is_page('picture_info')
    || Drupal.contribute.is_page('upload')) {
    Drupal.casabio.add_keypress_info(
      "<tr><td><strong>left</strong> : </td><td>Previous picture</td></tr>"
      + "<tr><td><strong>right</strong> : </td><td>Next picture</td></tr>"
      + "<tr><td><strong>x</strong> : </td><td>Select picture</td></tr>"
      + "<tr><td><strong>c</strong> : </td><td>Un-select all pictures</td></tr>"
      + "<tr><td><strong>e</strong> : </td><td>Edit selected pictures</td></tr>"
      + "<tr><td><strong>w</strong> : </td><td>Rotatue selected pictures clockwise</td></tr>"
      + "<tr><td><strong>q</strong> : </td><td>Rotatue selected pictures counter-clockwise</td></tr>"
    );
  
    $(document, context).bind('keydown', 'w',         handle_keypress_rotate_cw);
    $(document, context).bind('keydown', 'q',         handle_keypress_rotate_ccw);
  }

  if (Drupal.contribute.is_page('observation_info')) {
    Drupal.casabio.add_keypress_info(
      "<tr><td><strong>left</strong> : </td><td>Previous observation</td></tr>"
      + "<tr><td><strong>right</strong> : </td><td>Next observation</td></tr>"
      + "<tr><td><strong>x</strong> : </td><td>Select observation</td></tr>"
      + "<tr><td><strong>c</strong> : </td><td>Un-select all observations</td></tr>"
      + "<tr><td><strong>e</strong> : </td><td>Edit selected observations</td></tr>"
      + "<tr><td><strong>i</strong> : </td><td>Identify selected observations</td></tr>"
      + "<tr><td><strong>a</strong> : </td><td>Add interaction of selected observations</td></tr>"
    );

    $(document, context).bind('keydown', 'i',         handle_keypress_identify);
    $(document, context).bind('keydown', 'a',         handle_keypress_interaction);
  }

  // $(document, context).bind('keydown', 'esc',       handle_keypress_close_dialog);
}

function handle_keypress_edit() {
  var is_a_selected = selectables.filter('.selected').length > 0;
  // console.log('is_a_selected: ', is_a_selected);
  if (! is_a_selected) {
    toastr.warning('Select at least one ' + page_content_type);
    return null;
  }
  edit_form.dialog('open');
}

function handle_keypress_identify() {
  var is_a_selected = selectables.filter('.selected').length > 0;
  if (! is_a_selected) {
    toastr.warning('Select at least one ' + page_content_type);
    return null;
  }
  identify_form.dialog('open');
}

function handle_keypress_interaction() {
  var is_a_selected = selectables.filter('.selected').length > 0;
  if (is_a_selected) {
    toastr.warning('Select at least one ' + page_content_type);
    return null;
  }
  interaction_form.dialog('open');
}

function handle_keypress_rotate_cw() {
  rotate('90');
}

function handle_keypress_rotate_ccw() {
  rotate('-90');
}

// Not needed; jQuery ui Dialogs close with 'esc' automatically.
// function handle_keypress_close_dialog() {
//   Drupal.casa_core.close_dialogs();
// }


})(jQuery, Drupal, this, this.document);
