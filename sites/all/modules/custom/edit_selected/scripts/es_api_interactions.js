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
 * Drupal.es_api_interactions
 *  .fetch_token()
 *  .get_token()
 *  .fetch_selectables_data()
 *  .save_identification_from_form()
 *  .save_interaction_from_form()
 *  .update_observations()
 *  .update_nodes()
 *
 * get_collection_nid()
 *
 * create_identification_from_form()
 * create_identification_obj()
 * create_add_interaction_obj()
 * save_add_interaction()
 */

// var page_is_setup = false;

var security_token =      '';

// var api_url = site_url + 'api/v1.0'; // using Services module
var api_url;


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.es_api_interactions = {
  attach: function(context, settings) {
    api_url = settings.basePath + settings.API_path;
    // console.log('api_url: ', api_url);

    // if (! page_is_setup) {

    //   page_is_setup = true;
    // }

    // // Change toastr global options
    // toastr.options = {
    //   "showDuration": "800"
    // }
  }
}


Drupal.es_api_interactions = {

  fetch_token: function(show_message) {
    // console.log('fetch_token()');
    if (typeof show_message === 'undefined') {
      show_message = true;
    }

    // console.log('toastr.options: ', toastr.options);
    if (show_message) {
      var toastr_info = toastr.info('Fetching token…'); // @todo add an 'undo' button
    }

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
      $(document).trigger('token_fetched');
    });

    jqxhr.always(function( data ) {
      if (show_message) {
        toastr_info.remove();
      }
    });
  },


  get_token: function() {
    return security_token;
  },



  // =============================================================================
  //                                              Local functions

  fetch_selectables_data: function(show_message) {
    if (typeof show_message === 'undefined') {
      show_message = true;
    }

    if (show_message) {
      var toastr_info = toastr.info('Loading…'); // @todo add an 'undo' button
    }

    var collection_nid = get_collection_nid();

    var url;
    if (Drupal.edit_selected.is_page('observation_info')) {
      // var url = api_url + '/collections/' + collection_nid + '/observations';
      var url = api_url + '/v0.1/observations?'
        + 'filter[collection]=' + collection_nid
        + 'range=1000';
    }
    else if (Drupal.edit_selected.is_page('picture_info') ||
      Drupal.edit_selected.is_page('upload')) {
      // var url = api_url + '/collections/' + collection_nid + '/pictures';
      var url = api_url + '/v0.1/pictures?'
        + 'filter[collection]=' + collection_nid
        + 'range=1000';
    }
    else {
      throw 'current_page not recognised in ' + 'Drupal.es_api_interactions.fetch_selectables_data().';
    }

    // var jqxhr = $.get(url);
    var request_params = {
      type: "GET",
      contentType: "application/json",
      url: url
    }
    var jqxhr = $.ajax(request_params);

    jqxhr.fail(function( data ) {
      toastr.error('Sorry, there was a problem loading the observations.');
      console.log( "In fetch_selectables_data() jqxhr.fail(), data: ", data );
    });

    jqxhr.done(function( data ) {
      // console.log( "In jqxhr.done(), data: ", data );
      // toastr.success('selectables_data loaded successfully.'); // Not needed.
      Drupal.edit_selected.set_selectables_data(data.data);
      $(document).trigger('selectables_data_fetched');



      // Create the elements (rather than using view)

      // $.each(Drupal.edit_selected.get_selectables_data(), function(index, selectable_data) {
      //   console.log('index: ', index);

      //   var new_selectable = Drupal.contribute.build_selectable_element(
      //     selectable_data, 'observation', index, settings);

      //   Drupal.edit_selected.selectables_append(new_selectable);
      //   Drupal.edit_selected.add_selection_listeners(new_selectable, settings);

      // });



    });

    jqxhr.always(function( data ) {
      if (show_message) {
        toastr_info.remove();
      }
    });
  },



  // =============================================================================
  //                                              Local functions

  fetch_identifications_data: function(show_message) {
    if (typeof show_message === 'undefined') {
      show_message = true;
    }

    var collection_nid = get_collection_nid();

    var url = Drupal.casa_core.get_site_url() + 'ajax/identifications/by_collection/' + collection_nid;

    // var jqxhr = $.get(url);
    var request_params = {
      type: "GET",
      contentType: "application/json",
      url: url
    }

    if (show_message) {
      var toastr_info = toastr.info('Loading…'); // @todo add an 'undo' button
    }

    var jqxhr = $.ajax(request_params);

    jqxhr.fail(function( data ) {
      toastr.error('Sorry, there was a problem loading the identifications.');
      console.log( "In fetch_identifications_data() jqxhr.fail(), data: ", data );
    });

    jqxhr.done(function( data ) {
      // console.log( "In jqxhr.done(), data: ", data );
      // toastr.success('selectables_data loaded successfully.'); // Not needed.
      Drupal.edit_selected.set_identifications_data(data.data);
      // console.log('data.data: ', data.data);
      Drupal.edit_selected.populate_identifications_map();
      // console.log('data.data: ', data.data);

      $(document).trigger('identifications_data_fetched');
    });

    jqxhr.always(function( data ) {
      if (show_message) {
        toastr_info.remove();
      }
    });
  },



  fetch_interactions_data: function(show_message) {
    if (typeof show_message === 'undefined') {
      show_message = true;
    }

    var collection_nid = get_collection_nid();

    var url = Drupal.casa_core.get_site_url() + 'ajax/interactions/by_collection/' + collection_nid;

    // var jqxhr = $.get(url);
    var request_params = {
      type: "GET",
      contentType: "application/json",
      url: url
    }

    if (show_message) {
      var toastr_info = toastr.info('Loading…'); // @todo add an 'undo' button
    }

    var jqxhr = $.ajax(request_params);

    jqxhr.fail(function( data ) {
      toastr.error('Sorry, there was a problem loading the interactions.');
      console.log( "In fetch_interactions_data() jqxhr.fail(), data: ", data );
    });

    jqxhr.done(function( data ) {
      // console.log( "In jqxhr.done(), data: ", data );
      // toastr.success('selectables_data loaded successfully.'); // Not needed.
      Drupal.edit_selected.set_interactions_data(data.data);
      // console.log('data.data: ', data.data);
      Drupal.edit_selected.populate_interactions_map();
      // console.log('data.data: ', data.data);

      $(document).trigger('interactions_data_fetched');
    });

    jqxhr.always(function( data ) {
      if (show_message) {
        toastr_info.remove();
      }
    });
  },



  save_identification_from_form: function(form, context) {

    var identification = create_identification_from_form(form);
    // console.log('identification: ', identification);

    if (Object.keys(identification).length == 0) {
      throw 'Interaction is empty in ' + 'Drupal.es_api_interactions.save_identification_from_form().';
    }

    var observation_nid = Drupal.selection.get_selected_nids()[0]; // Used below when save is successful.
    var identification_nid = null;

    var url = Drupal.casa_core.get_api_resource_url('identification');

    var request_params = {
      type: "POST",

      contentType: "application/json",
      data: JSON.stringify(identification, null, 2),
      headers: {
        "access_token": Drupal.es_api_interactions.get_token()
        // Session id header is not specified, because it's automatically added by browser (it's a cookie).
      },
      url: url
    }
    var toastr_info = toastr.info('Saving…'); // @todo add an 'undo' button
    var jqxhr = $.ajax(request_params);

    jqxhr.fail(function( data ) {
      toastr.error('Sorry, there was a problem saving the identification.');
      console.log( "In jqxhr.fail(), data: ", data );
    });

    jqxhr.done(function( data ) {
      // console.log( "In jqxhr.done(), data: ", data );
      toastr.success('identification saved successfully.');

      // Update selectables_data with new identification
      identification_nid = data['nid'];

      // Record returned identification
      Drupal.edit_selected.identifications_data_append(data.data[0]);
      Drupal.edit_selected.populate_identifications_map();

      Drupal.edit_selected.refresh_current_field_indicator(context);
    });

    jqxhr.always(function( data ) {
      toastr_info.remove();
    });

    return identification_nid;
  },


  /**
   * Creates an interaction object for sending as JSON to the API.
   */
  save_interaction_from_form: function(form, context) {

    var taxon_values = Drupal.casa_core.get_values_from_ref_view(form);
    var taxon_tid = taxon_values[0];
    // console.log('taxon_tid: ', taxon_tid);
    var taxon_name = taxon_values[1];
    // console.log('taxon_name: ', taxon_name);

    if (!taxon_tid) {
      toastr.warning('You need to select a taxon before saving.');
      return null;
    }

    var title = '';

    var certainty = form.find("[name^='field_certainty']").val();

    var interaction_activity = form.find("[name^='field_interaction_activity']").val();

    var body = form.find("[name^='body']").val();
    // console.log('body: ', body);

    var params = create_add_interaction_obj(title, body, interaction_activity, taxon_tid, certainty);
    // console.log('interaction: ', interaction);

    var observation_nid = Drupal.selection.get_selected_nids()[0]; // Will always be only one when submitting.

    save_add_interaction(params, observation_nid, context);

    return interaction;
  },



  /**
   * @returns true if successful, false otherwise.
   */
  update_nodes: function(node_data, type, nids, context, attempt_num) {
    // console.log('node_data: ', node_data);
    // console.log('nids: ', nids);

    if (! node_data || Object.keys(node_data).length == 0) {
      throw 'Parameter node_data is empty in ' + 'Drupal.es_api_interactions.update_nodes().';
    }
    if (typeof attempt_num === 'undefined') {
      attempt_num = 1;
    }

    var toastr_info = toastr.info('Saving…'); // @todo add an 'undo' button
    var jqxhrs = [];
    var all_successful = true;
    var request_group_id = 0; // Not used yet...
    var nids_failed = [];

    nids.forEach(function(nid, index){
      var is_last = index == nids.length - 1;
      // console.log('is_last: ', is_last);
      var jqxhr;

      // DEVELOPMENT - for testing only
      // @todo #remove this.
      if (nid == '62630') {
        nid = 'breaker';
      }

      jqxhr = Drupal.es_api_interactions.update_node(node_data, type, nid);
      jqxhrs.push(jqxhr);

      jqxhr.fail(function( data ) {
        console.log( "In jqxhr.fail(), data: ", data );
        all_successful = false;
        nids_failed.push(nid);
      });

      jqxhr.done(function( data ) {
        // console.log( "In jqxhr.done(), data: ", data );

        // Update node in selectables_data with saved node info
        Drupal.edit_selected.set_selectable(nid, data.data);

        Drupal.edit_selected.update_feature(nid); // Map feature

        Drupal.edit_selected.refresh_current_field_indicator(context);

        Drupal.edit_selected.set_loads_finished([nid]);
      });

      if (is_last) {
        jqxhr.always(function( data ) {
          toastr_info.remove();

          if (all_successful) {
            toastr.success(type + 's updated successfully.');
          }
          else {
            manage_muli_save_failures(node_data, type, nids_failed, context, attempt_num);
          }
        });
      }

    });

  },


  /**
   * @returns true if successful, false otherwise.
   */
  update_node: function(data_object, type, nid) {

    var method = "PATCH";
    var data = JSON.stringify(data_object, null, 2);
    var url = Drupal.casa_core.get_api_resource_url(type) + '/' + nid;

    var settings = {
      type: method,
      contentType: "application/json",
      data: data,
      headers: {
        "access_token": Drupal.es_api_interactions.get_token()
        // Session id header is not specified, because it's automatically added by browser (it's a cookie).
      },
      url: url
    }
    var jqxhr = $.ajax(settings);
    return jqxhr;
  },





  /**
   * @returns true if successful, false otherwise.
   */
  delete_nodes: function(type, nids, context) {
    // console.log('nids: ', nids);

    var toastr_info = toastr.info('Deleting…'); // @todo add an 'undo' button
    // var jqxhrs = [];
    var all_successful = true;
    var request_group_id = 0; // Not used yet...

    nids.forEach(function(nid, index){
      var is_last = index == nids.length - 1;
      // console.log('is_last: ', is_last);

      var jqxhr = Drupal.es_api_interactions.delete_node(type, nid);
      // jqxhrs.push(jqxhr);

      jqxhr.fail(function( data ) {
        console.log( "In jqxhr.fail(), data: ", data );
        all_successful = false;
      });

      jqxhr.done(function( data ) {
        // console.log( "In jqxhr.done(), data: ", data );

        // Update selectables_data with saved node info
        // Drupal.edit_selected.set_selectable(nid, data.data);

        // Drupal.edit_selected.update_feature(nid);
      });

      if (is_last) {
        jqxhr.always(function( data ) {
          if (all_successful) {
            toastr_info.remove();
            toastr.success(type + 's updated deleted.');

            var selecteds = Drupal.selection.get_selected_selectables();
            // console.log('selecteds: ', selecteds);

            $.each( selecteds, function() {
              $(this).remove();
            });
          }
          else {
            toastr_info.remove();
            toastr.error('Sorry, there was a problem deleting the nodes.');
          }
        });
      }


    });

  },


  /**
   * @returns true if successful, false otherwise.
   */
  delete_node: function(type, nid) {

    var method = "DELETE";
    var data = '';
    var url = Drupal.casa_core.get_api_resource_url(type) + '/' + nid;

    var settings = {
      type: method,
      contentType: "application/json",
      data: data,
      headers: {
        "access_token": Drupal.es_api_interactions.get_token()
        // Session id header is not specified, because it's automatically added by browser (it's a cookie).
      },
      url: url
    }
    var jqxhr = $.ajax(settings);
    return jqxhr;
  }

};



// @todo delete this in favour of the version in contribute.js
function get_collection_nid() {
  var nid;

  if (Drupal.edit_selected.is_page('upload')) {
    return Drupal.casa_upload.get_collection_to_use();
  }

  var path = window.location.pathname;
  var path_parts = path.split('/');
  nid = path_parts[path_parts.length - 1];
  // console.log( "collection: ", collection );
  return nid;
}



/**
 * Creates an identification object for sending as JSON to the API.
 */
function create_identification_from_form(form) {

  var taxon_values = Drupal.casa_core.get_values_from_ref_view(form);
  // console.log('taxon_values: ', taxon_values);
  var taxon_tid = taxon_values[0];
  var taxon_name = taxon_values[1];

  if (!taxon_tid) {
    toastr.warning('You need to select a taxon before saving.');
    return null;
  }

  var observation_nid = Drupal.selection.get_selected_nids()[0]; // Will always be only one when submitting.
  // console.log('observation_nid: ', observation_nid);
  var observation_name = Drupal.edit_selected.get_selectable_data(observation_nid)
    ['attributes']['label'];
  // var observation_reference = observation_name + " (" + observation_nid + ")";
  // console.log('observation_reference: ', observation_reference);

  var language = 'und';

  var title = taxon_name;
  var certainty = form.find("#edit-field-certainty-und").val();

  var identification = create_identification_obj(title, observation_nid, taxon_tid, certainty);
  // console.log('identification: ', identification);

  return identification;
}



function create_identification_obj(title, observation, taxon_tid, certainty) {
  // return {
  //   "title": title,
  //   "status": true,
  //   "type": "identification",
  //   "field_certainty": {
  //     "und": certainty
  //   },
  //   "field_observation": {
  //     "und": [
  //       {"target_id": observation}
  //     ]
  //   },
  //   "field_identified_species": {
  //     "und": [
  //       {"tid": taxon_tid}
  //     ]
  //   }
  // };

  return {
    "label": title,
    // "status": true,
    // "type": "identification",
    "certainty": certainty,
    "observation": observation,
    "identifiedSpecies": taxon_tid
  };
}


function create_add_interaction_obj(title, body, interaction_activity, taxon_tid, certainty) {
  // return {
  //   "title": title,
  //   "status": true,
  //   "type": "interaction",
  //   "body": {
  //     "und": [
  //       {
  //         "value": body,
  //         "format": "filtered_html"}
  //     ]
  //   },
  //   "field_interaction_activity": {
  //     "und": [
  //       {"target_id": interaction_activity}
  //     ]
  //   },
  //   "field_identified_species": {
  //     "und": [
  //       {"tid": taxon_tid}
  //     ]
  //   },
  //   "field_certainty": {
  //     "und": [
  //       {"value": certainty}
  //     ]
  //   }
  // };

  return {
    "label": title,
    // "status": true,
    // "type": "identification",
    "body": body,
    "interactionActivity": interaction_activity,
    "identifiedSpecies": taxon_tid,
    "certainty": certainty
  };
}


/**
 * @returns true if successful, false otherwise.
 */
function save_add_interaction(params, nid, context) {
  // console.log('params: ', params);

  var url = Drupal.casa_core.get_api_resource_url('interaction');

  var settings = {
    type: "POST",
    contentType: "application/json",
    data: JSON.stringify(params, null, 2),
    headers: {
      "access_token": Drupal.es_api_interactions.get_token()
      // Session id header is not specified, because it's automatically added by browser (it's a cookie).
    },
    url: Drupal.casa_core.get_site_url() + 'ajax/observations/' + nid + '/add_interaction'
  }
  var toastr_info = toastr.info('Saving…'); // @todo add an 'undo' button
  var jqxhr = $.ajax(settings);

  jqxhr.fail(function( data ) {
    toastr.error('Sorry, there was a problem adding the interaction.');
    console.log( "In jqxhr.fail(), data: ", data );
  });

  jqxhr.done(function( data ) {
    // console.log( "In jqxhr.done(), data: ", data );

    toastr.success('Interaction added successfully. The species has been saved '
      + 'as a new observation in your collection.');

    // Update selectables_data

    // // Update selectables_data with saved observation info
    // $.each(nids, function(index, observation_nid) {
    //     // console.log('observation_nid: ', observation_nid);

    //   $.each(observation_data, function(field_name, field_value) {
    //     // console.log('field_name: ', field_name);
    //     // console.log('field_value: ', field_value);

    //     selectables_data[observation_nid][field_name] = field_value;
    //   });
    // });

    // Record returned interaction
    Drupal.edit_selected.interactions_data_append(data.data[0]);
    Drupal.edit_selected.populate_interactions_map();

    Drupal.edit_selected.refresh_current_field_indicator(context);
  });

  jqxhr.always(function( data ) {
    toastr_info.remove();
  });
}


/**
 * Describes the save failure to the user, and re-attempts the save.
 * Should be called when multiple nodes are saved but some fail.
 */
function manage_muli_save_failures(node_data, type, nids_failed, context, attempt_num) {
  // console.log('nids_failed: ', nids_failed);
  // console.log('attempt_num: ', attempt_num);

  if (attempt_num == 1) {
    toastr.error('Sorry, there was a problem updating the nodes. '
      + nids_failed.length + ' nodes did not save successfully. Retrying…');
  }
  else if (attempt_num < 3) {
    toastr.error('In attempt ' + attempt_num + ', '
      + nids_failed.length + ' nodes did not save successfully. Retrying…');
  }

  if (attempt_num < 3) {
    Drupal.es_api_interactions.update_nodes(node_data, type, nids_failed, context, attempt_num + 1);
  }
  else {
    toastr.error('Three unsuccessful attempts were made to save the node. You may try again.');
    Drupal.edit_selected.set_loads_finished(nids_failed);
  }
}


})(jQuery, Drupal, this, this.document);
