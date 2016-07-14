/**
 * @file
 * A JavaScript file for…

  Requirements: a view with results having classes of '.selectable' and '.groupable'
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
 * Drupal.group_selected
 *  .get_collection_nid()
 *
 * populate_groups_map()
 * fetch_groups()
 * parse_groups()
 * alter_page()
 * add_listeners()
 * display_groups()
 *
 * call_auto_group()
 * group()
 * get_group()
 * add_temp_id()
 * ungroup_selected()
 * ungroup()
 * ungroup_all()
 * group_individuals()
 * save_groups()
 * filter_groups_to_new()
 * update_temp_ids()
 * adjust_buttons()
 *
 * set_up_keypress_mgmt()
 * handle_keypress_group()
 * handle_keypress_ungroup()
 */



const SAVED_STATUS_SAVED =    'saved';
const SAVED_STATUS_ALTERED =  'altered';
const SAVED_STATUS_SAVING =   'being_saved';
const SAVED_STATUS_NEW =      'new';

// An array of representations of groups (which are saved as observations)
// In format {id: observation.id, status: SAVED_STATUS_SAVED, pictures: []}
// The last property, pictures, is an array of picture nids in that group
var groups =          [];

// Maps group's id: its position in the groups array
// Makes it easy to retrieve a specfic group by its nid
var groups_map =      {}; // Nothing to do with location and geographic maps

var temp_ids =        [];
var save_groups_url;



// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.group_selected = {
  attach: function(context, settings) {

    fetch_groups();
    populate_groups_map();

    save_groups_url = Drupal.settings.basePath + 'ajax/collections/%/group_pictures';

    alter_page(context);

    add_listeners(context);

    display_groups();

    set_up_keypress_mgmt(context);

  },
  weight: 5
};



Drupal.group_selected = {

  get_collection_nid: function() {
    var path = window.location.pathname;
    var path_parts = path.split('/');
    var nid = path_parts[path_parts.length - 1];
    // console.log( "collection: ", collection );
    return nid;
  }

};




function populate_groups_map() {
  // Populate selectables_map
  $.each(groups, function( index, group ) {
    var id = group.id;
    // console.log('nid: ', nid);
    groups_map[id] = index;
  });
  // console.log('selectables_map: ', selectables_map);
}



// =============================================================================
//                                              Local functions

function fetch_groups() {
  var toastr_info = toastr.info('Loading…'); // @todo add an 'undo' button
  var collection_nid = Drupal.contribute.get_collection_nid();
  // console.log('collection_nid: ', collection_nid);

  var url = Drupal.casa_core.get_api_url() + '/v0.1/observations?filter[collection]=' + collection_nid;
  // console.log('url: ', url);

  var jqxhr = $.get(url);

  jqxhr.fail(function( data ) {
    toastr.error('Sorry, there was a problem loading the observations.');
    console.log( "In fetch_selectables_data() jqxhr.fail(), data: ", data );
  });

  jqxhr.done(function( data ) {
    // console.log( "In jqxhr.done(), data: ", data );

    // toastr.success('selectables_data loaded successfully.'); // Not needed.
    var observations = data.data;
    // console.log('observations fetched: ', observations);
    parse_groups(observations);
    // console.log('groups after fetch: ', groups);
    populate_groups_map();
    // console.log('groups_map after fetch: ', groups_map);

    $(document).trigger('groups_fetched');
  });

  jqxhr.always(function( data ) {
    toastr_info.remove();
  });
}



/**
 * Converts fetched observation data into groups, saves in groups.
 */
function parse_groups(observations) {
  // console.log('observations: ', observations);

  $.each( observations, function( index, observation ) {
    groups[index] = {
      id: observation.id,
      status: SAVED_STATUS_SAVED,
      pictures: observation.attributes.picturesInObservation
    };
  });
  // console.log('groups: ', groups);
}



function alter_page(context) {
  var toolbar = $('[role="toolbar"][aria-label*="primary"]', context);

  $( '#auto-group', context ).click( function(event) {
    call_auto_group();
  });

  $( '#ungroup_all', context ).click( function(event) {
    ungroup_all();
  });

  $( '#group', context ).click( function() {
    group(null, SAVED_STATUS_NEW, false);
    save_groups(groups, true);
  });
  $( '#ungroup', context ).click( function() {
    ungroup_selected();
  });
  $( '#group_individuals', context ).click( function() {
    group_individuals();
  });
}



function add_listeners(context) {

  $('.selectable', context).on('selection:select', function(event) {
    adjust_buttons();
  });

  // $(document, context).on('groups_fetched', function() {
  // });

  $(document, context).on('selecteds_grouped', function(event) {
    save_groups(groups, true);
  });
}



/**
 * Finds all selectables that are in observations, and groups them.
 * This works if the selectables are already sorted by their observations.
 */
function display_groups() {
  var selectables = $( ".selectable" );
  // var groups = [];
  var this_group_nid = null;

  selectables.each(function(index, el) {
    var group_nid = $(this).find(".field.nid-observation .field-content" ).html();

    // First, selects all consecutive pictures that should be part of a group.
    // Then, at the end of those consecutive pictures, groups the selected pictures.
    // Then begins again for a new group.

    // If this selectable is should be part of a group
    if (group_nid) {
      // console.log("group_nid: ", group_nid);
      var index = Drupal.selection.get_index($(this));
      // console.log("index: ", index);
      var nid = $(this).find(".field.nid-observation .field-content" ).html();

      // If this is the first
      if (this_group_nid == null) {
        this_group_nid = group_nid;
      }
      // If this is the start of a new group
      if (group_nid != this_group_nid) {
        group(this_group_nid, SAVED_STATUS_SAVED, false);
        this_group_nid = group_nid;
      }
      Drupal.selection.selecteds_indexes_push( index );
    }
  });
  if (this_group_nid != null) { // For just the last group
    group(this_group_nid, SAVED_STATUS_SAVED, false);
  }
}



/**
 * Sends an AJAX request to the Auto Group module to auto-group the collection.
 */
function call_auto_group() {
  var toastr_info = toastr.info('Auto-grouping pictures…'); // @todo add an 'undo' button
  var url = Drupal.settings.basePath
    + 'ajax/pictures/auto_group'
    + '/' + Drupal.casa_core.get_collection_nid()
    + '/' + $('#auto-group-num').val();
  // console.log( "url: ", url );

  var posting = $.post(url);
  // console.log( "posting: ", posting );

  posting.fail(function( data ) {
    toastr_info.remove();
    toastr.error('Sorry; there was a problem auto-grouping the pictures.');
    console.log( "Response: ", data);
  });

  posting.done(function( data ) {
    // console.log( "Called: posting.done()");

    var result = data['result'];
    // console.log( "Result: " + result );

    if (result == "success") {
      toastr_info.remove();
      toastr.success('Pictures have been auto-grouped successfully. Reloading in 3 seconds…');
      var reload_timeout = window.setTimeout(function(){
        document.location.reload();
      }, 3000);
    } else {
      toastr_info.remove();
      toastr.error('Sorry; there was a problem auto-grouping the pictures.');
      console.log( "Response: ", data);
    }

    // window.location.href = Drupal.settings.basePath + 'node/104';
  });
  posting.fail(function( data ) {
    toastr.error('Sorry; there was a problem auto-grouping the pictures.');
  })
}



/**
 * Creates a group, and moves all selected elements into it.
 *
 * Deselects all elements. Can display a message to the user. Does not call save_groups().
 *
 * @param group_nid
 *   The nid of the group's observation, if already saved. If null, a temporary id will be created.
 *
 * @param saved_status
 *   Whether the group already exists (has been saved), is altered, or is new.
 *
 * @param show_message
 *   Whether a message should be displayed to the user to indicate the grouping success.
 *   Generally this should be false, because a message is shown as groups are being saved.
 */
function group(group_nid, saved_status, show_message) {
  // console.log("Called: group()");

  // -----------------------------------------------------------------
  // Manage parameters

  show_message = ( show_message == 'undefined' ) ? true : show_message;
  var selecteds_indexes = Drupal.selection.get_selecteds_indexes();
  // console.log('selecteds_indexes: ', selecteds_indexes);

  if (group_nid == null) {
    group_nid = add_temp_id();
  }

  // // -----------------------------------------------------------------
  // // Unselect all elements that are already in a group

  // for (var i = selecteds_indexes.length - 1; i >= 0; i--) {
  //   var index = selecteds_indexes[i];
  //   var element = Drupal.selection.get_selectable( index );

  //   if (get_group(element).length > 0) { // If in a group
  //     Drupal.selection.deselect(index);
  //     Drupal.selection.selecteds_indexes_remove(index);
  //   }
  // };
  // // console.log('length: ', selecteds_indexes.length);

  // // If there isn't at least one selected, exit
  // if (!selecteds_indexes.length > 0) {
  //   return null;
  // }

  // -----------------------------------------------------------------
  // Find the first group if any of the selected are in a group already

  var group = find_first_group(selecteds_indexes);
  // console.log('group: ', group);

  // -----------------------------------------------------------------
  // Insert new group if no group already

  if (typeof group == 'undefined') {
    var first_selected = Drupal.selection.get_selectable( selecteds_indexes[0] );
    var element_before = first_selected.prev();

    group = $( '<ul id="' + group_nid + '" class="group"></ul>' );
    // console.log("group", group);

    if ( element_before.length > 0 ) {
      group.insertAfter( element_before );
    }
    else {
      group.prependTo( first_selected.parent() );
    }
  }
  else {
    // Notify save function that this is an altered group, not a new one
    saved_status = SAVED_STATUS_ALTERED;
  }

  // -----------------------------------------------------------------
  // Move selected elements to the new group

  $.each( selecteds_indexes, function( key, index ) {
    var element = Drupal.selection.get_selectable( index );

    // If this element is not in a group
    if (get_group(element).length == 0) {
      element.detach().appendTo(group);
    }
    // If this element is in a group, but not in the first / new group
    else if ((element).length > 0 && (! get_group(element).is(group))) {
      merge_groups(group, get_group(element));
    }
  });

  // -----------------------------------------------------------------
  // Add group to groups array

  if (saved_status == SAVED_STATUS_NEW) {
    var selected_nids = Drupal.selection.get_selected_nids();
    groups.push({
      id: group_nid,
      status: saved_status,
      pictures: selected_nids
    });
    // console.log('groups: ', groups);
    populate_groups_map();
  }

  // -----------------------------------------------------------------
  // Show message and finish up

  if (show_message) {
    toastr.success('Pictures grouped.'); // @todo add an 'undo' button

    $(document).trigger('selecteds_grouped');
  }

  Drupal.selection.deselect_all();

  // sort_all(); @todo create this function
  // Each item and group should be given 'data-date-created="yyyy-mm-dd"' attribute;
  // items should be sorted by this;

  adjust_buttons();

}


/**
 * Finds the first group containing one of the selecteds provided.
 *
 * @returns jQuery object
 */
function find_first_group(selecteds_indexes) {
  var group;

  $.each( selecteds_indexes, function( key, index ) {
    var element = Drupal.selection.get_selectable( index );

    // If no group has been found yet, and this element is in a group
    if ((typeof group == 'undefined') && (get_group(element).length > 0)) {
      group = get_group(element);
    }
  });

  return group;
}



/**
 * @returns jQuery object
 *   The group that the node is in
 */
function get_group(element) {
  return element.parent( '.group' );
}


/**
 * Adds all elements from one group to another.
 * Sets the second group to empty, to be removed on save.
 * Does not save the groups.
 * Parameters should both be jQuery objects.
 */
function merge_groups(remaining_group_obj, removing_group_obj) {
  // console.log('Called: merge_groups()');

  $.each( removing_group_obj.children(), function( key, index ) {
    var element = $(this);
    element.detach().appendTo(remaining_group_obj);
  });

  // Prepare the groups for saving

  var remaining_group_id = remaining_group_obj.attr( 'id' );
  // console.log( 'remaining_group_id: ', remaining_group_id );
  var removing_group_id = removing_group_obj.attr( 'id' );
  // console.log( 'removing_group_id: ', removing_group_id );

  remaining_group = groups[groups_map[remaining_group_id]];
  removing_group = groups[groups_map[removing_group_id]];

  remaining_group.status = SAVED_STATUS_ALTERED;
  remaining_group.pictures =
    remaining_group.pictures.concat(removing_group.pictures); // merged

  removing_group.status = SAVED_STATUS_ALTERED;
  removing_group.pictures = [];

  removing_group_obj.remove();
}



function add_temp_id() {
  var temp_id;
  if (temp_ids.length == 0) {
    temp_id = 0;
  }
  else {
    temp_id = temp_ids[temp_ids.length - 1] + 1; // Increment last temp id
  }
  temp_ids.push(temp_id);
  return temp_id;
}



/**
 * Does what it's named.
 */
function ungroup_selected() {

  var groups_to_ungroup = [];

  $.each( Drupal.selection.get_selected_selectables(), function (key, selectable) {
    var group_id = selectable.parent( '.group' ).attr( 'id' );
    // console.log("group_id: ", group_id);
    if (typeof group_id != 'undefined') {
      // var group_num = parseInt(group_id.substring(group_id.search('-') + 1), 10);
      // console.log("group_num: ", group_num);
      groups_to_ungroup.push(group_id);
    }
  });
  // console.log('groups_to_ungroup: ', groups_to_ungroup);

  ungroup(groups_to_ungroup, false);

  toastr.success('Pictures un-grouped.');
}



/**
 * Removes a group, moves its elements back into the main list, and optionally shows a message.
 *
 * @param int groups_to_process
 *   Array of groups' nids. eg. [567, 568]
 * @param boolean message
 *   Whether a message popup should be displayed
 */
function ungroup(groups_to_process, message) {
  // console.log('groups_to_process: ', groups_to_process );

  // Set defauls for parameters
  populate_groups_map();

  message = ( typeof message == 'undefined' ) ? false : message;

  groups_to_process.forEach(function(group_id, index) {
    // console.log( 'group_id: ', group_id );

    var group_obj = $ ( '.group#' + group_id );

    eject_from_group(group_obj);

    // -----------------------------------------------------------------
    // Update data in groups_to_process array

    // console.log('groups_map: ', groups_map );
    // console.log('groups: ', groups );
    var group = groups[groups_map[group_id]];

    group.status = SAVED_STATUS_ALTERED;
    group.pictures = [];

    // Swap the item from the nid to the group object (needed for save function.
    groups_to_process[index] = groups[groups_map[group_id]];
  });

  // console.log( 'groups_to_process: ', groups_to_process );
  save_groups(groups_to_process, false);

  // groups[] = unset();

  // -----------------------------------------------------------------
  // Show message and finish up

  if (message) {
    toastr.success('Pictures un-grouped.');
  }

  Drupal.selection.deselect_all();

  adjust_buttons();
}


/**
 * Moves elements out of a group, back to the parent group.
 */
function eject_from_group(group_obj) {
  var element_before = group_obj.prev();
  // console.log( element_before: ", element_before );

  // $.each( groups, function( key, group ) {
  group_obj.children().each( function() {
    // var element = Drupal.selection.get_selectable( index );
    var element = $(this);
    // console.log( "element_before length: ", element_before.length );

    // get_selectable(id)

    // alert (element_before.attr("class"));
    element.detach();
    if ( element_before.length > 0 ) {
      element.insertAfter( element_before );
    }
    else {
      element.prependTo( group_obj.parent() );
    }
  });

  group_obj.remove();
}



/**
 * Calls ungroup() for all groups.
 */
function ungroup_all() {

  populate_groups_map();

  // Get all groups' nids
  var groups_to_ungroup = Object.keys(groups_map);

  ungroup( groups_to_ungroup, true ); // Can just use index '0' because the array has been shortened each time
}



function group_individuals() {
  Drupal.selection.deselect_all();

  var indiv_selectables = $(".selectable").not(".group .selectable");

  indiv_selectables.each(function( index, selectable ) {
    var index = Drupal.selection.get_index($(selectable));
    Drupal.selection.selecteds_indexes_push( index );

    group(null, SAVED_STATUS_NEW, false);
  });
  save_groups(groups, true);

  // toastr.success('All individual pictures grouped.');
}



/**
 * Sends all groups to be saved as observations using an HTTP POST.
 *
 * @param groups
 *   A subset of the groups array; an array of 'group' objects.
 */
function save_groups(groups, message) {
  // console.log( groups: ", groups);

  if (typeof groups == 'undefined') {
    throw "Parameter `groups` is undefined.";
  }
  if (groups.length == 0) { // If it was an object: Object.keys(groups).length
    return null;
  }
  if (typeof message == 'undefined') {
    message = false;
  }

  if (message) {
    var toastr_info = toastr.info('Saving picture groups…'); // @todo add an 'undo' button
  }

  var collection_nid = Drupal.casa_core.get_collection_nid();
  var url = save_groups_url.replace('%', collection_nid);
  // console.log( "url: ", url );

  groups = filter_groups_to_new(groups)
  // console.log('Saving groups: ', groups);

  var ajax_settings = {
    type: "POST",
    contentType: "application/json",
    data: JSON.stringify(Drupal.casa_core.toObject(groups), null, 2),
    // data: groups,
    url: url, // api_url + '/login-token'
  }
  var jqxhr = $.ajax(ajax_settings);

  jqxhr.fail(function( data ) {
    toastr.error('Sorry; there was a problem saving the pictures.');
    console.log( "In jqxhr.fail(), data: ", data);
    console.log( "In jqxhr.fail(), data['responseText']: ", data['responseText']);
  });

  jqxhr.done(function( data ) {
    // console.log( "In jqxhr.done(), data: ", data);

    var result = data['result'];

    if (result == "success") {
      if (message) {
        toastr.success('Pictures saved successfully.');
      }
      // console.log( "data: ", data);
    }
    else {
      toastr.error('Sorry; there was a problem saving the pictures.');
      console.log( "In jqxhr.done(), data: ", data);
    }

    update_temp_ids(data['new_nodes']);

    $(document).trigger('groups_saved');
  });

  jqxhr.always(function( data ) {
    if (message) {
      toastr_info.remove();
    }
  });
}


/**
 * Returns only groups that are new or altered.
 */
function filter_groups_to_new(groups) {
  // console.log('groups: ', groups);
  var groups_output = [];

  groups.forEach(function(group) {
    // console.log('group.status: ', group.status);
    if (group.status == SAVED_STATUS_NEW || group.status == SAVED_STATUS_ALTERED) {
      groups_output.push(group);
    }
  });

  return groups_output;
}



/**
 * After new observations have been saved, replace their temporary ids with their new nids.
 *
 * @param nids
 *   Array in the format [{temp_id: 0, nid: 345}].
 */
function update_temp_ids(nids) {
  // console.log('nids: ', nids);
  // console.log('groups: ', groups);

  nids.forEach(function (nids_obj) {
    // console.log('nids_obj: ', nids_obj);

    // Change 'id' attribute of group element
    $('.group#' + nids_obj.temp_id).attr('id', nids_obj.nid);

    // Update data in groups array
    groups.forEach(function(group, index) {
      if (group.id == nids_obj.temp_id) {
        group.id = nids_obj.nid;
        group.status = SAVED_STATUS_SAVED;
        // groups[index].id = nids_obj.nid;
        // groups[index].status = SAVED_STATUS_SAVED;
      }
    });

    // Remove temp_id from temp_ids array
    temp_ids.splice(temp_ids.indexOf(nids_obj.temp_id), 1);
  });
  // console.log('groups, after save and update: ', groups);
  // console.log('temp_ids, after update: ', temp_ids);

  populate_groups_map();
}



/**
 * Enables and disables the buttons according to selections and groups.
 */
function adjust_buttons() {

  var are_selecteds = Drupal.selection.get_selecteds_indexes().length;
  var are_groups = groups.length;

  if( are_selecteds ) {
    $( '#group' ).attr('disabled', false);
  } else {
    $( '#group' ).attr('disabled', true);
  }

  if( are_groups ) {
    $( '#ungroup_all' ).attr('disabled', false);
  } else {
    $( '#ungroup_all' ).attr('disabled', true);
  }

  if( are_selecteds && are_groups ) {
    $( '#ungroup' ).attr('disabled', false);
  } else {
    $( '#ungroup' ).attr('disabled', true);
  }
}



function set_up_keypress_mgmt(context) {
  Drupal.casabio.add_keypress_info(
    "<tr><td><strong>g</strong> : </td><td>Group selected pictures</td></tr>"
    + "<tr><td><strong>u</strong> : </td><td>Un-group selected pictures</td></tr>");

  $(document, context).bind('keydown', 'g',         handle_keypress_group);
  $(document, context).bind('keydown', 'u',         handle_keypress_ungroup);
}

function handle_keypress_group() {
  group(null, SAVED_STATUS_NEW, false);
  save_groups(groups, true);
}

function handle_keypress_ungroup() {
  ungroup_selected();
}


})(jQuery, Drupal, this, this.document);
