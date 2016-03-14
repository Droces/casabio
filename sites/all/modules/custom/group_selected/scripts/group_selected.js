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

// The groups arrays store the groups of 'pictures'
// The indexes refer to the 'result numbers' of the elements within the view content (for easy JQuery retrieval)

// var selecteds_indexes = []; // View row numbers of the 
var groups_indexes =  []; // View row numbers of the 
var groups_nums =     [];
var group_keys_pointer = 0; // Is incremented each time a group is added
var saved_nids =    [];
var save_pictures_into_observations_url;



// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.group_selected = {
  attach: function(context, settings) {

    save_pictures_into_observations_url = Drupal.settings.basePath + 'ajax/collections/%/group_pictures_into_observations';

    alter_page(context);

    display_groups();
    auto_sort();

    set_up_keypress_mgmt(context);

    $('.selectable', context).on('selection:select', function(event) {
      adjust_buttons();
    });
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



/* CONTENTS
  alter_page
  display_groups
  auto_sort

  group
  get_group
  are_grouped_selecteds
  all_grouped_are_selecteds
  ungroup_selected
  ungroup
  ungroup_all
  save_groups
  adjust_buttons

  set_up_keypress_mgmt
  handle_keypress_group
  handle_keypress_ungroup
 */





function alter_page(context) {
  var toolbar = $('[role="toolbar"][aria-label*="primary"]', context);

  $( '#auto-group', context ).click( function(event) {
    trigger_auto_group();
  });

  $( '#ungroup_all', context ).click( function(event) {
    ungroup_all();
  });

  $( '#group', context ).click( function() {
    group(true);
  });
  $( '#ungroup', context ).click( function() {
    ungroup_selected();
  });
  $( '#group_individuals', context ).click( function() {
    group_individuals();
  });

  $( '#save', context ).click( function() {
    save_groups();
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
    var group_nid = $(this).find(".views-field-nid-group .field-content" ).html();

    // First, selects all consecutive pictures that should be part of a group.
    // Then, at the end of those consecutive pictures, groups the selected pictures.
    // Then begins again for a new group.

    // If this selectable is should be part of a group
    if (group_nid) {
      // console.log("group_nid: ", group_nid);
      var index = Drupal.selection.get_index($(this));
      // console.log("index: ", index);
      var nid = $(this).find(".views-field-nid-group .field-content" ).html();

      // If this is the first
      if (this_group_nid == null) {
        this_group_nid = group_nid;
      }
      // If this is the start of a new group
      if (group_nid != this_group_nid) {
        group(false);
        this_group_nid = group_nid;
      }
      Drupal.selection.selecteds_indexes_push( index );
    }
  });
  if (this_group_nid != null) { // For just the last group
    group(false);
  }
}



/**
 * In development. Sorts selectables by their date field values.
 */
function auto_sort() {
  var elements = $('.selectables ul.content > *');
  // console.log('items.length: ', items.length);
  elements.each(function(index, el) {
    var element = $(this);
    var date;
    if (element.is('li')) {
      date = element.find( ".views-field-created .field-content" ).html();
    }
    else if (element.is('ul')) {
      date = element.find( "li:first-of-type .views-field-created .field-content" ).html();
    }
    // console.log('date: ', date);
  });
}



/**
 * Sends an AJAX request to the Auto Group module to auto-group the collection.
 */
function trigger_auto_group() {
  var toastr_info = toastr.info('Auto-grouping pictures…'); // @todo add an 'undo' button
  var url = Drupal.settings.basePath 
    + 'auto_group_pictures'
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
 * Also deselects all elements. Also notifies the user.
 */
function group (show_message) {
  // console.log("Called: group()");

  show_message = ( show_message === undefined ) ? true : show_message;
  selecteds_indexes = Drupal.selection.get_selecteds_indexes();

  // Unselect all elements that are already in a group
  for (var i = selecteds_indexes.length - 1; i >= 0; i--) {
    var index = selecteds_indexes[i];
    var element = Drupal.selection.get_selectable( index );

    if (get_group(element).length > 0) { // If in a group
      Drupal.selection.deselect(index);
      Drupal.selection.selecteds_indexes_remove(index);
    }
  };
  // console.log('length: ', selecteds_indexes.length);

  if (selecteds_indexes.length > 0) {

    var first_selected = Drupal.selection.get_selectable( selecteds_indexes[0] );
    var element_before = first_selected.prev();

    var new_group = $( '<ul id="group-' + group_keys_pointer + '" class="group"></ul>' );
    // console.log("new_group", new_group);

    // Insert new group
    if ( element_before.length > 0 ) {
      new_group.insertAfter( element_before );
    }
    else {
      new_group.prependTo( first_selected.parent() );
    }

    // Move selected elements to the new group
    $.each( selecteds_indexes, function( key, index ) {
      var element = Drupal.selection.get_selectable( index );

      // If this element is not in a group
      if (get_group(element).length == 0) {
        element.detach().appendTo(new_group);
      }
    });

    // Add the elements' indexes to the groups array
    groups_indexes.push( selecteds_indexes );
    // console.log( "groups_indexes: ", groups_indexes);
    // console.log( "group_keys_pointer: ", group_keys_pointer);
    groups_nums.push( group_keys_pointer );

    group_keys_pointer ++;

    if (show_message) {
      toastr.success('Pictures grouped.'); // @todo add an 'undo' button
    }
  }

  Drupal.selection.deselect_all();
  // sort_all(); @todo create this function
  // Each item and group should be given 'data-date-created="yyyy-mm-dd"' attribute;
  // items should be sorted by this;
  // see http://stackoverflow.com/questions/14160498/sort-element-by-numerical-value-of-data-attribute.

  adjust_buttons();
}



/**
 * @returns jQuery object
 *   The group that the node is in
 */
function get_group(element) {
  return element.parent( '.group' );
}



/**
 * Determines whether any of the selecteds are in a group.
 */
function are_grouped_selecteds() {
  var are_grouped_selecteds = false;
  $.each( Drupal.selection.get_selecteds_indexes(), function( key, index ) {
    var element = get_selectable( index );

    if (get_group(element).length > 0) {
      are_grouped_selecteds = true;
      return false; // breaks out of $.each() loop
    }
  });
  if (are_grouped_selecteds) {
    return true;
  }
  else {
    return false;
  }
}



/**
 * Determines whether all of the selecteds are in groups.
 */
function all_grouped_are_selecteds() {
  var all_grouped_are_selecteds = true;
  $.each( Drupal.selection.get_selecteds_indexes(), function( key, index ) {
    var element = get_selectable( index );

    if (get_group(element).length <= 0) {
      all_grouped_are_selecteds = false;
      return false; // breaks out of $.each() loop
    }
  });
  if (all_grouped_are_selecteds) {
    return true;
  }
  else {
    return false;
  }
}



/**
 * 
 */
function ungroup_selected() {

  $.each( Drupal.selection.get_selecteds_indexes(), function (key, index) {
    var group_id = Drupal.selection.get_selectable(index).parent( '.group' ).attr( 'id' );
    // console.log("group_id: ", group_id);
    if (group_id !== undefined) {
      var group_num = parseInt(group_id.substring(group_id.search('-') + 1), 10);
      // console.log("group_num: ", group_num);
      ungroup(group_num, false);
    }
  });

  toastr.success('Pictures un-grouped.')
}



/**
 * Removes a group, moves its elements back into the main list, and optionally shows a message.
 * 
 * @param int group_num
 *   If group_num is a negative number, will ungroup the last group
 * @param boolean message
 *   Whether a message popup should be displayed
 */
function ungroup(group_num, message) {
  // console.log( "group_num: ", group_num );

  // Set defauls for parameters
  message = ( message === undefined ) ? false : message;

  // Validation
  // Ensure that the number is valid
  if( ! $.inArray(group_num, groups_indexes) ) {
    return;
  }

  // If negative, Set number for last group
  if( group_num < 0 ) {
    group_num = groups_indexes.length - 1;
  }

  var group_obj = $ ( '.view-content .content #group-' + group_num );

  var group_indexes = groups_indexes[groups_nums.indexOf( group_num )];

  var element_before = group_obj.prev();
  // console.log( "group_num: ", group_num );
  // console.log( "element_before length: ", element_before.length );

  // Move elements of group back to the original group
  $.each( group_indexes, function( key, index ) {
    var element = Drupal.selection.get_selectable( index );
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
  // groups_indexes.splice( $.inArray( group_num, groups_nums), 1 );

  if( message ) {
    toastr.success('Pictures un-grouped.');
  }

  Drupal.selection.deselect_all();

  adjust_buttons();
}



/**
 * Calls ungroup() for all groups.
 */
function ungroup_all() {

  $.each( groups_nums, function( key, group_num ) {
    // console.log("group_num: ", group_num);
    ungroup( group_num, false ); // Can just use index '0' because the array has been shortened each time
  }); 
  groups_indexes = [];
  groups_nums = [];

  // console.log( "groups_nums, after ungroup: ", groups_nums);
  // console.log( "groups_indexes, after ungroup: ", groups_indexes);
  toastr.success('All pictures un-grouped.');
}



function group_individuals() {
  Drupal.selection.deselect_all();

  var indiv_selectables = $(".selectable").not(".group .selectable");
  
  indiv_selectables.each(function( index, selectable ) {
    var index = Drupal.selection.get_index($(selectable));
    Drupal.selection.selecteds_indexes_push( index );
    
    group(false);
  });
  toastr.success('All individual pictures grouped.');
}



/**
 * Sends all groups to be saved as observations using an HTTP POST.
 */
function save_groups() {
  // console.log( "groups_indexes: ", groups_indexes);
  var toastr_info = toastr.info('Saving picture groups…'); // @todo add an 'undo' button

  var groups_nids = get_groups_nids();
  // console.log( "groups_nids: ", groups_nids);

  var collection_nid = Drupal.casa_core.get_collection_nid();
  var url = save_pictures_into_observations_url.replace('%', collection_nid);
  // console.log( "url: ", url );

  // console.log('groups_nids just before saving: ', groups_nids);
  // console.log('collection_nid just before saving: ', Drupal.casa_core.get_collection_nid());
  var posting;
  posting = $.post(url, {
      "groupings": groups_nids
    }
  );

  posting.fail(function( data ) {
    toastr_info.remove();
    toastr.error('Sorry; there was a problem saving the pictures.');
    console.log( "In posting.fail(), data: ", data);
    console.log( "In posting.fail(), data['responseText']: ", data['responseText']);
  });

  posting.done(function( data ) {
    toastr_info.remove();

    var result = data['result'];
    // console.log( "Result: ", result );

    if (result == "success") {
      toastr.success('All pictures saved successfully.');
      // console.log( "data: ", data);
    } else {
      toastr.error('Sorry; there was a problem saving the pictures.');
      console.log( "In posting.done(), data: ", data);
    }
  
    // window.location.href = Drupal.settings.basePath + 'node/104';
  });
}



/**
 * Creates an array of grouped pictures nids. 
 * Iterates through the groups_indexes array and creates a matching array where indexes are instead nids.
 */
function get_groups_nids() {
  // An array of 'observation' arrays.
  // Each observation array is an array of picture nids
  var groups_nids = [];

  var groups = $('.selectables .group');
  groups.each(function( group_index, group ) {
    // Each group becomes an observation

    var selectables = $(group).find('.selectable');
    groups_nids[group_index] = [];

    selectables.each(function( selectable_index, selectable ) {
      // Each selectable is a picture that will be referenced by the new observation

      // Determine the picture's node ID
      var nid = parseInt($(selectable).find( ".views-field-nid .field-content" ).html(), 10);
      
      groups_nids[group_index].push(nid);
    });
  });

  return groups_nids;
}



/**
 * Enables and disables the buttons according to selections and groups.
 */
function adjust_buttons() {

  var are_selecteds = Drupal.selection.get_selecteds_indexes().length;
  var are_groups = groups_indexes.length;

  if( are_selecteds ) {
    $( '#group' ).attr('disabled', false);
  } else {
    $( '#group' ).attr('disabled', true);
  }

  if( are_groups ) {
    $( '#ungroup_all' ).attr('disabled', false);
    $( '#save' ).attr('disabled', false);
  } else {
    $( '#ungroup_all' ).attr('disabled', true);
    $( '#save' ).attr('disabled', true);
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
  group(true);
}

function handle_keypress_ungroup() {
  ungroup_selected();
}


})(jQuery, Drupal, this, this.document);