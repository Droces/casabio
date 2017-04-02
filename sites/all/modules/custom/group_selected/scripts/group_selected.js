/**
 * @file
 * A JavaScript file for…

  Requirements: a view with results having classes of '.selectable' and '.groupable'.

  The grouping functions are all managed asynchonously, using the website's API
  to update groups when possible.

  In other words, each action taken by the user (eg. add to pictures to a group)
  will show the result of that action immediately (pictures will be shown as
  grouped). The save_groups() function is then called to sync these updates
  with the server, so that the website's saved data matches what the user is
  seeing.

 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {



/**
 * CONTENTS
 *
 * - variable declarations
      
      // Finds all matching identifications by user, keeps only one.
      filter_identifications_to_one($node);
      // dpm('Finished filter_identifications_to_one()'); -
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
 * filter_groups_to_unsaved()
 * update_temp_ids()
 * adjust_buttons()
 *
 * set_up_keypress_mgmt()
 * handle_keypress_group()
 * handle_keypress_ungroup()
 */

var page_is_setup = false;

const SAVED_STATUS_NEW =      'new'; // Not yet saved.
const SAVED_STATUS_ALTERED =  'altered'; // Saved, but changed since.

// const SAVED_STATUS_UNSAVED =  'unsaved'; // Has changes, needs save request.
const SAVED_STATUS_SAVING =   'being_saved'; // Save request has been made; waiting for response.
const SAVED_STATUS_SAVED =    'saved'; // Saved and not changed.

// An array of representations of groups (which are saved as observations)
// In format {id: observation.id, status: SAVED_STATUS_SAVED, pictures: []}
// The last property, pictures, is an array of picture nids in that group
var groups =          [];

var selectables,
    groupables,
    group_elements;

// Maps group's id to its position in the groups array
// Makes it easy to retrieve a specfic group by its nid
var groups_map =      {}; // Nothing to do with location and geographic maps

var temp_ids =        [];
var save_groups_url;



// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.group_selected = {
  attach: function(context, settings) {
    // console.log('context: ', context);
    // console.log('settings: ', settings);

    // Assignments

    // The following assignments do not use the context, because all matching 
    // elements on entire page should be selected.

    selectables = $('.selectable');
    groupables = $('.groupable');
    group_elements = $('.group');
    // var toolbar = $('[role="toolbar"][aria-label*="primary"]');
    save_groups_url = Drupal.settings.basePath + 'ajax/collections/%/group_pictures';

    // Functions that should only happen once per page load
    if (! page_is_setup) {

      // Fetches

      fetch_groups();

      alter_page(context);

      set_up_keypress_mgmt();
      
      add_page_listeners(context);
    }

    // @todo Functions that should be re-written to be able to run on every attachBehaviors().
    if (! page_is_setup) {

      add_listeners(context);

      display_groups();

      page_is_setup = true;

      // Drupal.attachBehaviors('body'); // For testing only
    }

  },
  weight: 5
};


// // Used like: $("#notAnElement").exists();
// $.fn.exists = function () {
//   return this.length !== 0;
// }



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
  groups_map = {};

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

function fetch_groups(success_callbacks, always_callbacks) {
  var toastr_info = toastr.info('Loading…'); // @todo add an 'undo' button
  var collection_nid = Drupal.contribute.get_collection_nid();
  // console.log('collection_nid: ', collection_nid);

  var url = Drupal.casa_core.get_api_url() + '/v0.1/observations?filter[collection]=' + collection_nid;
  // console.log('url: ', url);

  var jqxhr = $.get(url);

  jqxhr.fail(function( data ) {
    if(jqxhr.readyState < 4)  {
      // toastr.warning('Request was not completed.');
    }
    else {
      toastr.error('Sorry, there was a problem loading the observations.');
      console.log( "In fetch_selectables_data() jqxhr.fail(), data: ", data );
    }
  });

  jqxhr.done(function( data ) {
    // console.log( "In jqxhr.done(), data: ", data );

    // toastr.success('selectables_data loaded successfully.'); // Not needed.
    var observations = data.data;
    // console.log('observations fetched: ', observations);
    parse_groups(observations);
    // console.log('groups after fetch: ', groups);

    $(document).trigger('groups_fetched');
  });

  jqxhr.always(function( data ) {
    toastr_info.remove();
    Drupal.casa_utilities.invoke_callbacks(always_callbacks);
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
      is_new: null,
      pictures: observation.attributes.picturesInObservation
    };
  });
  // console.log('groups: ', groups);

  sort_groups_array();
  populate_groups_map();
}



function alter_page(context) {

  // Add attributes to groupables

  groupables.each(function() {
    // Find date added
    var group_date_added = $(this).find('.views-field-created .field-content').html();
    // Add date as attribute
    $(this).attr('data-date-added', group_date_added);
    // Find date taken
    var group_date_taken = $(this).find('.views-field-field-date-taken .date-display-single').html();
    // Add date as attribute
    $(this).attr('data-date-taken', group_date_taken);
  });

  // Add listeners to buttons

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

  var dialog = Drupal.theme('group_individuals_dialog');
  dialog.appendTo('body');
}

/**
 * Creates a dialog used to alert of ungrouped pictures when moving to next phase.
 */
Drupal.theme.group_individuals_dialog = function () {
  var dialog = $( '<div id="group-individuals-dialog" class="dialog">'
    + 'Some of your pictures are not grouped. Pictures need to be grouped to be shown as observations on the next page. Would you like to all pictures that arent part of a group to be grouped?'
    + '</div>' );
  return dialog;
};



function add_page_listeners(context) {

  $(document).on('selection:deselect_all', function(event) {
    adjust_buttons();
  });

  // $(document, context).on('groups_fetched', function() {
  // });

  $(document).on('selecteds_grouped', function(event) {
    save_groups(groups, true);
  });

  $(document).on('groups_saved', function(event) {
    // update_saved_groups();
  });

  

  // When the 'Next' button is clicked
  $('#block-contribute-steps a[rel="next"]', context).on('click', function(event) {
    var link = $(this);
    // console.log('clicked');


    if (! link.hasClass('no-dialog')) {
      var do_click = display_message_ungrouped_individuals(link);
      return do_click;
    }
  });
}



function add_listeners(context) {

  selectables.on('selection:select', function(event) {
    adjust_buttons();
  });
}



function display_message_ungrouped_individuals(next_link) {
  var num_ungrouped = 0;
  selectables.each(function() {
    if (get_group($(this)).length == 0) {
      num_ungrouped ++;
    }
  });
  // console.log('num_ungrouped', num_ungrouped);
  if (num_ungrouped == 0) {
    return true;
  }

  // Display dialog asking if individual pictures should be grouped.
  $( "#group-individuals-dialog" ).dialog({
    dialogClass: "no-close",
    width: 500,
    title: 'Group individual pictures?',
    modal: true,
    buttons: [
      {
        text: "Don't group",
        click: function() {
          next_link.addClass('no-dialog');
          next_link[0].click();
        }
      },
      {
        text: "Cancel",
        click: function() {
          $( this ).dialog( "close" );
        }
      },
      {
        text: "Group individuals",
        class: "primary",
        click: function() {
          next_link.addClass('no-dialog');

          $(document).on('groups_saved', function(event) {
            next_link[0].click();
          });

          group_individuals();
        }
      }
    ]
  });
  return false;
}



/**
 * Finds all selectables that are in observations, and groups them.
 * This works if the selectables are already sorted by their observations.
 */
function display_groups() {
  // var groups = [];
  var this_group_nid = null;

  // Add 'data-group-nid' attribute to each
  selectables.each(function() {
    var group_nid = $(this).find(".field.nid-observation .field-content" ).html();
    $(this).attr('data-group-nid', group_nid);
  });

  // For each selectable that has a group
  selectables.filter('[data-group-nid]').each(function() {
    var this_group_nid = $(this).attr('data-group-nid');
    // console.log('this_group_nid: ', this_group_nid);

    if (this_group_nid == '') {
      return null;
    }

    // Find all those in its group
    var all_in_group = selectables.filter('[data-group-nid="' + this_group_nid + '"]');
    // console.log('all_in_group.length: ', all_in_group.length);

    all_in_group.each(function() {
      var index = Drupal.selection.get_index($(this));
      Drupal.selection.selecteds_indexes_push( index );
    });

    var selecteds = Drupal.selection.get_selected_nids().length;
    // console.log('selecteds: ', selecteds);


    group(this_group_nid, SAVED_STATUS_SAVED, false);

    // Remove the attribute of each in this group to prevent re-grouping
    all_in_group.attr('data-group-nid', '');
  });

  selectables.removeAttr('data-group-nid');



  selectables.each(function(index, el) {
    // var group_nid = $(this).find(".field.nid-observation .field-content" ).html();

    // // First, selects all consecutive pictures that should be part of a group.
    // // Then, at the end of those consecutive pictures, groups the selected pictures.
    // // Then begins again for a new group.

    // If this selectable is should be part of a group
    // if (group_nid) {
    //   // console.log("group_nid: ", group_nid);
    //   var index = Drupal.selection.get_index($(this));
    //   // console.log("index: ", index);
    //   var nid = $(this).find(".field.nid-observation .field-content" ).html();

    //   // If this is the first
    //   if (this_group_nid == null) {
    //     this_group_nid = group_nid;
    //   }
    //   // If this is the start of a new group
    //   if (group_nid != this_group_nid) {
    //     group(this_group_nid, SAVED_STATUS_SAVED, false);
    //     this_group_nid = group_nid;
    //   }
    //   Drupal.selection.selecteds_indexes_push( index );
    // }

  });
  // if (this_group_nid != null) { // For just the last group
  //   group(this_group_nid, SAVED_STATUS_SAVED, false);
  // }
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

  var jqxhr = $.post(url);
  // console.log( "jqxhr: ", jqxhr );

  jqxhr.done(function( data ) {
    // console.log( "Called: jqxhr.done()");

    var result = data['result'];
    // console.log( "Result: " + result );

    if (result == "success") {
      toastr.success('Pictures have been auto-grouped successfully. Reloading in 3 seconds…');
      var reload_timeout = window.setTimeout(function(){
        document.location.reload();
      }, 3000);
    } else {
      toastr.error('Sorry; there was a problem auto-grouping the pictures.');
      console.log( "Response data: ", data);
    }

    // window.location.href = Drupal.settings.basePath + 'node/104';
  });

  jqxhr.fail(function( data ) {
    toastr.error('Sorry; there was a problem auto-grouping the pictures.');
    console.log( 'jqxhr: ', jqxhr);
  });

  jqxhr.always(function( data ) {
    toastr_info.remove();
  });
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
 *   If it is already saved, this function is being called to show it.
 *
 * @param show_message
 *   Whether a message should be displayed to the user to indicate the grouping success.
 *   Generally this should be false, because a message is shown as groups are being saved.
 */
function group(group_nid, saved_status, show_message) {
  // console.log("Called: group()");
  // console.log('saved_status: ', saved_status);

  // -----------------------------------------------------------------
  // Manage parameters

  show_message = ( show_message == 'undefined' ) ? true : show_message;
  var selecteds_indexes = Drupal.selection.get_selecteds_indexes();
  // console.log('selecteds_indexes: ', selecteds_indexes);

  // -----------------------------------------------------------------
  // Find the first group if any of the selected are in a group already

  var group = find_first_selected_group(selecteds_indexes);
  // console.log('group: ', group);

  // -----------------------------------------------------------------
  // Determine nid or create a temporary nid

  if (group_nid == null) {
    if (typeof group !== 'undefined') {
      group_nid = group.attr('id');
    }
    else {
      group_nid = add_temp_id();
    }
  }
  // console.log('group_nid: ', group_nid);

  // -----------------------------------------------------------------
  // Insert new group if no group already

  if (typeof group == 'undefined') {
    group = create_group_element(selecteds_indexes, group_nid);
    saved_status = SAVED_STATUS_NEW;
  }
  else if (saved_status == SAVED_STATUS_NEW) {
    // This is an altered group, not a new one, so update status for save
    saved_status = SAVED_STATUS_ALTERED;
  }
  // console.log('saved_status: ', saved_status);

  move_elements_to_group(selecteds_indexes, group);

  add_selected_to_groups_array(saved_status, group_nid);

  sort_groups_array();

  // -----------------------------------------------------------------
  // Add upload date/time as attribute on group.

  // Sort group's children, because they weren't necessarily added in the
  // correct order.
  sort_groupables(group);

  var group_date_added = group.children().first().find('.views-field-created .field-content').html();
  group.attr('data-date-added', group_date_added);

  var group_date_taken = group.children().first().find('.views-field-field-date-taken .date-display-single').html();
  group.attr('data-date-taken', group_date_taken);

  sort_groupables();

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

  // console.log('groups: ', groups);
}


function create_group_element(selecteds_indexes, group_nid) {
  var first_selected = Drupal.selection.get_selectable( selecteds_indexes[0] );
  var element_before = first_selected.prev();

  var group = $( '<ul id="' + group_nid + '" class="group"></ul>' );
  // console.log("group", group);

  if ( element_before.length > 0 ) {
    // Directly after the group
    group.insertAfter( element_before );
  }
  else {
    // In the group, at the beginning
    group.prependTo( first_selected.parent() );
  }

  return group;
}


/**
 * Finds the first group containing one of the selecteds provided.
 *
 * @returns jQuery object
 */
function find_first_selected_group(selecteds_indexes) {
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


function move_elements_to_group(selecteds_indexes, new_group) {
  // console.log('new_group: ', new_group);

  // console.log('groups: ', groups);
  // console.log('groups_map', groups_map);

  $.each( selecteds_indexes, function( key, index ) {
    var element = Drupal.selection.get_selectable( index );
    var its_group = get_group(element);

    // If this element is not in a group
    if (its_group.length == 0) {
      element.detach().appendTo(new_group);
    }
    // If this element is in a group, but not in the first / new new_group
    else if (its_group.length > 0 && (! its_group.is(new_group))) {
      merge_groups(new_group, its_group);
    }

  });
}



function add_selected_to_groups_array(saved_status, group_nid) {
  // console.log('group_nid: ', group_nid);

  // console.log('groups: ', groups);
  // console.log('groups_map', groups_map);

  var selected_nids = Drupal.selection.get_selected_nids();

  if (saved_status == SAVED_STATUS_NEW || saved_status == SAVED_STATUS_SAVED) {
    // Add new group to groups array

    // console.log('pushing');
    groups.push({
      id: group_nid,
      status: saved_status,
      pictures: selected_nids
    });
    // console.log('groups: ', groups);

    sort_groups_array();
    populate_groups_map();
  }
  else if (saved_status == SAVED_STATUS_ALTERED) {
    // Add the pictures to the existing group in groups array
    var group_pics = $.unique(groups[groups_map[group_nid]].pictures.concat(selected_nids));
    // console.log('group_pics: ', group_pics);
    groups[groups_map[group_nid]].pictures = group_pics;
    groups[groups_map[group_nid]].status = SAVED_STATUS_ALTERED;

    // Since neither the number nor order of groups don't change, don't re-populate map
  }
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
  // console.log( 'removing_group_obj: ', removing_group_obj );

  // console.log( 'groups: ', groups );
  // console.log( 'groups_map: ', groups_map );

  $.each( removing_group_obj.children(), function( key, index ) {
    var element = $(this);
    element.detach().appendTo(remaining_group_obj);
  });

  // Prepare the groups for saving

  var remaining_group_id = remaining_group_obj.attr( 'id' );
  // console.log( 'remaining_group_id: ', remaining_group_id );
  var removing_group_id = removing_group_obj.attr( 'id' );
  // console.log( 'removing_group_id: ', removing_group_id );

  if (typeof remaining_group_id == 'undefined' || typeof removing_group_id == 'undefined')  {
    console.log( "In merge_groups(), remaining_group_id or removing_group_id is undefined.");
    return null;
  }

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
    temp_id = temp_ids.length; // One higher than last temp id
  }
  temp_ids.push(temp_id);
  return temp_id;
}



/**
 * Removes groups of all selecteds, moving their elements back into the main list.
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
 * Removes groups, moving their elements back into the main list, and optionally shows a message.
 *
 * @param int groups_to_process
 *   Array of groups' nids. eg. [567, 568]
 * @param boolean message
 *   Whether a message popup should be displayed
 */
function ungroup(groups_to_process, message) {
  // console.log('groups_to_process: ', groups_to_process );

  message = ( typeof message == 'undefined' ) ? false : message;

  groups_to_process.forEach(function(group_id, index) {
    // console.log( 'group_id: ', group_id );

    var group_obj = $ ( '.group#' + group_id );

    eject_all_from_group(group_obj);

    // -----------------------------------------------------------------
    // Update data in groups_to_process array

    // console.log('groups_map: ', groups_map );
    // console.log('groups: ', groups );
    var group = groups[groups_map[group_id]];

    group.status = SAVED_STATUS_ALTERED;
    group.pictures = [];

    // Swap the item from the nid to the group object (needed for save function.)
    groups_to_process[index] = groups[groups_map[group_id]];
  });

  // console.log( 'groups_to_process: ', groups_to_process );
  save_groups(groups_to_process, true);

  // groups[] = unset();

  // -----------------------------------------------------------------
  // Show message and finish up

  if (message) {
    toastr.success('Pictures un-grouped.');
  }

  sort_groupables();

  Drupal.selection.deselect_all();

  adjust_buttons();

  // console.log('groups after ungroup: ', groups);
}


/**
 * Moves elements out of a group, back to the parent group.
 */
function eject_all_from_group(group_obj) {
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

  if (group_obj.children().length == 0) {
    group_obj.remove();
  }
}



/**
 * Calls ungroup() for all groups.
 */
function ungroup_all() {

  sort_groups_array();
  populate_groups_map();

  // Get all groups' nids
  var groups_to_ungroup = Object.keys(groups_map);

  ungroup( groups_to_ungroup, true ); // Can just use index '0' because the array has been shortened each time
}



/**
 * @param callback
 *   A function to be called once the rest of the function has completed.
 */
function group_individuals(callback) {
  // console.log('callback: ', callback);

  Drupal.selection.deselect_all();

  var indiv_selectables = selectables.not(".group .selectable");

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
function save_groups(groups_in, message, success_callbacks, always_callbacks) {
  // console.log('groups_in: ', groups_in);
  // console.log('groups: ', groups);

  // --------------------------------
  // Validate params

  if (typeof groups_in == 'undefined') {
    throw "Parameter `groups_in` is undefined.";
  }
  if (groups_in.length == 0) { // If it was an object: Object.keys(groups_in).length
    return null;
  }
  if (typeof message == 'undefined') {
    message = false;
  }

  // --------------------------------
  // Send request

  if (message) {
    var toastr_info = toastr.info('Saving picture groups…'); // @todo add an 'undo' button
  }

  var collection_nid = Drupal.casa_core.get_collection_nid();
  var url = save_groups_url.replace('%', collection_nid);
  // console.log( "url: ", url );

  groups_in = filter_groups_to_unsaved(groups_in)
  // console.log('Saving groups_in: ', groups_in);

  var ajax_settings = {
    type: "POST",
    contentType: "application/json",
    data: JSON.stringify(Drupal.casa_utilities.toObject(groups_in), null, 2),
    // data: groups_in,
    url: url, // api_url + '/login-token'
  }
  var jqxhr = $.ajax(ajax_settings);

  // Update group.status to indicate 'saving'
  groups_in.forEach(function(group) {
    group.status = SAVED_STATUS_SAVING;
  });

  // --------------------------------
  // Manage responses

  jqxhr.fail(function( data, textStatus, errorThrown ) {
    if(jqxhr.readyState < 4)  {
      // toastr.warning('Saving the pictures was not completed.');
    }
    else {
      toastr.error('Sorry; there was a problem saving the pictures.');
      console.log( "In jqxhr.fail(), data: ", data);
    }

    // @todo Update group.status to indicate 'failed'? To retry?
  });

  jqxhr.done(function( data ) {
    // console.log( "In jqxhr.done(), data: ", data);

    var result = data['result'];

    if (result == "success") {
      if (message) {
        toastr.success('Group saved successfully.');
      }
      // console.log( "data: ", data);
    }
    else {
      toastr.error('Sorry; there was a problem saving the pictures.');
      console.log( "In jqxhr.done(), data: ", data);

      // @todo Update group.status to indicate 'failed'? To retry?
    }

    update_temp_ids(data['new_nodes']);

    update_saved_groups(data['altered_nodes']);

    // console.log('In save_groups(), jqxhr.done(), after all updates');
    // console.log( 'groups: ', groups );
    // console.log( 'groups_map: ', groups_map );

    Drupal.casa_utilities.invoke_callbacks(success_callbacks);

    $(document).trigger('groups_saved');
  });

  jqxhr.always(function( data ) {
    if (message) {
      toastr_info.remove();
    }
    Drupal.casa_utilities.invoke_callbacks(always_callbacks);
  });
}


/**
 * Returns only groups that are new or altered.
 */
function filter_groups_to_unsaved(groups_in) {
  // console.log('groups_in: ', groups_in);
  var groups_output = [];

  groups_in.forEach(function(group) {
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
 * @param nodes_in
 *   Array in the format [{temp_id: 0, id: 345}].
 */
function update_temp_ids(nodes_in) {
  // console.log('nodes_in: ', nodes_in);

  nodes_in.forEach(function (node) {
    // console.log('node: ', node);

    // If this node doesn't have a temp id, skip it
    if (typeof node.temp_id == 'undefined') {
      return null;
    }

    // Change 'id' attribute of group element
    group_elements.filter('#' + node.temp_id).attr('id', node.id);

    // Update data in groups array
    groups[groups_map[node.temp_id]].id = node.id;
    groups[groups_map[node.temp_id]].status = SAVED_STATUS_SAVED;

    // Delete (but not remove) temp_id from temp_ids and groups_map arrays
    delete temp_ids[temp_ids.indexOf(node.temp_id)];
  });

  sort_groups_array();
  populate_groups_map();
}


/**
 * Given an array of saved groups, checks groups array and removes matching empty groups.
 *
 * @nodes_in
 *   An array of group objects, in the format: [{id: '11'}] or [{temp_id: 0, id: 345}].
 */
function update_saved_groups(nodes_in) {
  // console.log('nodes_in: ', nodes_in);
  // console.log('groups before: ', groups);

  $.each(nodes_in, function(index, node) {
    for (var i = groups.length - 1; i >= 0; i--) {
      // console.log('group.pictures.length: ', group.pictures.length);
      if (groups[i].id == node.id) {

        // Remove deleted groups
        if (groups[i].pictures.length == 0) {
          // Remove the group from the groups array
          groups.splice(i, 1);
        }
        else {
          groups[i].status = SAVED_STATUS_SAVED;
        }
      }

    }
  });

  sort_groups_array();
  populate_groups_map();
  // console.log('groups: ', groups);
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



/**
 * @param order (optional)
 *   String indicating the direction of the sort; 'asc', 'desc', or 'rand'
 */
function sort_groupables(container, order) {
  var sort_attrs = ['data-date-added', 'data-date-taken']; // Later ones take preference.

  $.each(sort_attrs, function(index, sort_attr) {
    // var sort_attr = 'data-date-added';
    // var sort_attr = 'data-date-taken';

    if (typeof order === 'undefined') {
      order = 'asc';
    }
    if (typeof container === 'undefined') {
      container = $('.groupables ul.content');
    }

    // Sort all groups and groupables directly inside container
    tinysort(container.children().toArray(), {
      attr: sort_attr,
      order: order
    });

    if (container.is($('.groupables ul.content'))) {
      // Sort all groupables within each group
      group_elements.each(function() {
        tinysort($(this).children('.groupable').toArray(), {
          attr: sort_attr,
          order: order
        });
      });
    }
  });
}



function sort_groups_array() {
  // console.log('groups: ', groups);
  var new_groups = [];

  // Move empty groups to the beginning of the array

  groups.forEach(function callback(group, index, array) {
    // console.log('group: ', group);

    // If the group has no pictures (will be deleted)
    if (! group.pictures) {
      // Add group to beginning
      new_groups.unshift(group);
    }
    else {
      new_groups.push(group);
    }
  }, groups);
  // console.log('new_groups: ', new_groups);
  groups = new_groups;
}



function set_up_keypress_mgmt() {
  Drupal.casabio.add_keypress_info(
    '<tr><td><strong>g</strong> : </td><td>Group selected pictures</td></tr>'
    + '<tr><td><strong>u</strong> : </td><td>Un-group selected pictures</td></tr>');

  $(document).bind('keydown', 'g',         handle_keypress_group);
  $(document).bind('keydown', 'u',         handle_keypress_ungroup);
}

function handle_keypress_group() {
  group(null, SAVED_STATUS_NEW, false);
  save_groups(groups, true);
}

function handle_keypress_ungroup() {
  ungroup_selected();
}


})(jQuery, Drupal, this, this.document);
