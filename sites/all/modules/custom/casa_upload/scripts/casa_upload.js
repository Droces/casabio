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

var collection_to_use = null,
    collection_to_use_title = '',
    choice_block_element,
    api_url,
    row_number_index = 0, // Keeps track of the last selectable added
    milestones = {
      first_picture_uploaded: false,
      next_link_set: false
    },
    failed_files = [],
    pictures_loaded = false;


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.casa_upload = {
  attach: function(context, settings) {
    // console.log('settings: ', settings);

    // console.log('window.location: ', window.location);
    // console.log('window.location.pathname: ', window.location.pathname);

    if (! page_is_setup) {

      api_url = settings.basePath + settings.API_path;

      var collection_nid = Drupal.casa_utilities.get_url_parameter_value('collection');
      // console.log('collection_nid: ', collection_nid);
      if (collection_nid) {
        load_collection_pictures(collection_nid, context, settings);
      }

      set_up_uploader(context, settings);

      choice_block_element = $('.choice-block');

      choice_block_element.find('input, select').change(function() {
        // console.log('changed');
        $('#uploader').attr('aria-enabled', true);
      });

      page_is_setup = true;
    }

  },
  weight: 10
};



Drupal.casa_upload = {
  get_collection_to_use: function() {
    return collection_to_use;
  }
}





function set_up_uploader(context, settings) {

  var PLuploader = $(".plupload-element", context).pluploadQueue();

  $('#collection_choice', context)
    .find('input[type="submit"]').on('click', function () {
      set_collection();
    }); 


  // When files are added to the uploader (could have been dragged in)

  PLuploader.bind('FilesAdded', function(up, files) {

    if (! milestones.first_picture_uploaded) {
      toastr.info('When your pictures have been uploaded, you can edit them below.', null, {
        'timeOut': '-1'
      });
    }

    if (collection_to_use == null) {
      set_collection();

      var collection_nid = Drupal.casa_upload.get_collection_to_use();
      // console.log('collection_nid: ', collection_nid);
      if (collection_nid) {
        load_collection_pictures(collection_nid, context, settings);
      }
    }

    $('#collection_choice', context)
      .attr('aria-collapsed', true)
      .prev().html("Adding to collection: " + collection_to_use_title);


    $('#saved_pics', context)
      .attr('aria-enabled', true);

    // $('.plupload_button.plupload_start').addClass('prominent');
    PLuploader.start();

    $('a[rel="next"]').attr('disabled', false);

    $(document).on('collection_created', function() {
      Drupal.es_api_interactions.fetch_selectables_data(collection_to_use, 'picture', false);

      var url_query = "?collection=" + collection_to_use;
      window.history.pushState({}, "",
        window.location.pathname + url_query
      );
    });

    milestones.first_picture_uploaded = true;
  });


  // As each file has been uploaded

  PLuploader.bind('FileUploaded', function(uploader, file, response) {
    // console.log('uploader: ', uploader);
    // console.log('file: ', file);
    // console.log('response: ', response);

    // console.log('collection_to_use: ', collection_to_use);

    request_body = {
      collection: collection_to_use,
      temp_name: file.id,
      file_name: file.name
    };
    // console.log('request_body: ', request_body);

    save_temp_file(request_body, settings);

  });


  // When upload errors occur

  PLuploader.bind('Error', function(uploader, error) {
    console.log( "error.code: ", error.code);
    console.log( "error.message: ", error.message);
  });
}


/**
 * If there is a 'collection=' parameter in the url, load the pictures of that collection.
 */
function load_collection_pictures(collection_nid, context, settings) {
  // console.log('collection_nid: ', collection_nid);
  
  // Not PHP!
  // if (! is_valid_eid($collection_nid)) {
  //   throw new InvalidArgumentException("Parameter $collection_nid, " . $collection_nid . ", needs to be a valid NID.", 1);
  // }

  $(document, context)
    .on('selectables_data_fetched', function(event, data) {
    
    if (pictures_loaded) {
      return false;
    }
    // console.log('fetched data: ', data);

    collection_to_use_title = collection_nid; // @todo Fetch title rather.
    $('#collection_choice')
      .attr('aria-collapsed', true)
      .prev().html("Editing collection: " + collection_to_use_title);
    $('#saved_pics')
      .attr('aria-enabled', true);

    $('#uploader').attr('aria-enabled', true);

    $('a[rel="next"]').attr('disabled', false);

    if (! milestones.next_link_set) {
      var next_link = $('a[rel="next"]');
      next_link.attr('href', next_link.attr('href') + collection_nid);
      milestones.next_link_set = true;
    }

    $.each(data.data, function(index, picture) {
      row_number_index++;
      create_picture_element(picture, row_number_index, settings);
    });

    pictures_loaded = true;
  });

  // Drupal.edit_selected??.page_setup_loadings.push('fetch_selectables_data');
  Drupal.es_api_interactions.fetch_selectables_data(collection_nid, 'picture', true);
}



function save_temp_file(request_body, settings, success_callbacks, always_callbacks) {
  var toastr_info = toastr.info('Loading…', null, {
    'timeOut': '-1'
  }); // @todo add an 'undo' button

  var url = Drupal.settings.basePath + 'services/contribute/save-uploaded';

  var request_settings = {
    type: "POST",
    contentType: "application/json",
    data: JSON.stringify(request_body),
    // data: groups,
    url: url, // api_url + '/login-token'
  }
  var jqxhr = $.ajax(request_settings);

  jqxhr.fail(function( data ) {
    if(jqxhr.readyState < 4)  {
      // toastr.warning('Request was not completed.');
    }
    else {
      toastr_info.remove();
      toastr.error('Sorry; there was a problem saving the picture.');
      console.log( "In save_temp_file() jqxhr.fail(), data: ", data);

      Drupal.casa_utilities.add_message_from_js(
        'Picture &lsquo;' + request_body.file_name + '&rsquo; failed to upload.',
        'error');
      console.log( "data['responseText']: ", data['responseText']);

      failed_files.push(request_body.temp_name);
      // console.log('failed_files: ', failed_files);

    }
  });

  jqxhr.done(function( data ) {
    toastr_info.remove();
    // console.log( "In jqxhr.done(), data: ", data);

    row_number_index++;
    create_picture_element(data.data[0], row_number_index, settings);

    Drupal.casa_utilities.invoke_callbacks(success_callbacks);

    // $(document).trigger('temp_file_saved');
  });


  jqxhr.always(function( data ) {
    // Call theme behaviours within context of the message container.
    Drupal.behaviors.casabio.attach($('.message-container')[0], settings);

    // Display which files failed to upload in upload list
    $.each(failed_files, function(index, file) {
      // console.log('file: ', file);
      $('.plupload li#' + file)
        .removeClass('plupload_done')
        .addClass('plupload_failed');
        // .attr('id', file + '-failed');
    });
    
    Drupal.casa_utilities.invoke_callbacks(always_callbacks);
  });
}


/**
 * Creates a picture element from node object returned by API.
 */
function create_picture_element(node, row_number_index, settings) {
  var new_selectable = Drupal.contribute.build_selectable_element(
    node, 'picture', row_number_index, settings);

  // Update selection's selectables array
  Drupal.selection.find_selectables($('.selectables'));

  Drupal.edit_selected.selectables_append(new_selectable);
  Drupal.edit_selected.add_selection_listeners(new_selectable, settings);

  Drupal.edit_selected.selectables_data_append(node);
  Drupal.edit_selected.populate_selectables_map();
}


/**
 * Determins which collection to use - based on either the "Create new colllection"
 * or "Add to existing collection" field - and hides those fields.
 */
function set_collection() {
  // console.log('set_collection()');
  
  var collection_choice =
    choice_block_element.children('[aria-selected]').attr('data-option-id');

  if (collection_choice == 'new') {
    var title = choice_block_element
      .find('[data-option-id="new"] input[type="text"]').val();
    // console.log('title: ', title);
    create_collection(title);
    collection_to_use_title = title;
  }
  // existing
  else {
    collection_to_use = choice_block_element.children('[aria-selected]')
      .find('select').val();
    // console.log('collection_to_use: ', collection_to_use);
    collection_to_use_title = choice_block_element.children('[aria-selected]')
      .find('option:selected').text();


    if (! milestones.next_link_set) {
      var next_link = $('a[rel="next"]');
      next_link.attr('href', next_link.attr('href') + collection_to_use);
      milestones.next_link_set = true;
    }
  }
}


function create_collection(title, success_callbacks, always_callbacks) {
  var toastr_info = toastr.info('Creating collection…', null, {
    'timeOut': '-1'
  }); // @todo add an 'undo' button

  var url = api_url + '/v0.1/collections';
  var security_token = Drupal.es_api_interactions.get_token();
  // console.log('security_token: ', security_token);

  var request_params = {
    type: "POST",
    contentType: "application/json",
    data: JSON.stringify({
      label: title
    }),
    headers: {
      "access-token": security_token
      // Session id header is not specified, because it's automatically added by browser (it's a cookie).
    },
    // data: groups,
    url: url, // api_url + '/login-token'
  }
  var jqxhr = $.ajax(request_params);

  jqxhr.fail(function( data ) {
    if(jqxhr.readyState < 4)  {
      // toastr.warning('Request was not completed.');
    }
    else {
      toastr_info.remove();
      toastr.error('Sorry; there was a problem creating a collection.');
      console.log( "In create_collection() jqxhr.fail(), data: ", data);
      console.log( "data['responseText']: ", data['responseText']);
    }
  });

  jqxhr.done(function( data ) {
    toastr_info.remove();
    // console.log( "In jqxhr.done(), data: ", data);

    // console.log( "n jqxhr.done() success, data: ", data);
    collection_to_use = data['data'][0]['id'];
    // console.log('collection_to_use: ', collection_to_use);

    var next_link = $('a[rel="next"]');
    next_link.attr('href', next_link.attr('href') + collection_to_use);

    Drupal.casa_utilities.invoke_callbacks(success_callbacks);

    $(document).trigger('collection_created');
  });
}



// function get_collection_pictures(settings, success_callbacks, always_callbacks) {
//   var toastr_info = toastr.info('Loading…', null, {
    //   'timeOut': '-1'
    // }); // @todo add an 'undo' button

//   var url = Drupal.settings.basePath + 'services/contribute/save-uploaded';

//   var request_settings = {
//     type: "POST",
//     contentType: "application/json",
//     data: JSON.stringify(request_body),
//     // data: groups,
//     url: url, // api_url + '/login-token'
//   }
//   var jqxhr = $.ajax(request_settings);

//   jqxhr.fail(function( data ) {
//     if(jqxhr.readyState < 4)  {
//       // toastr.warning('Request was not completed.');
//     }
//     else {
//       toastr_info.remove();
//       toastr.error('Sorry; there was a problem fetching the pictures.');
//       console.log( "In get_collection_pictures() jqxhr.fail(), data: ", data);

//       Drupal.casa_utilities.add_message_from_js(data['responseText'], 'error');
//       console.log( "data['responseText']: ", data['responseText']);
//     }
//   });

//   jqxhr.done(function( data ) {
//     toastr_info.remove();
//     console.log( "In jqxhr.done(), data: ", data);

//     // row_number_index++;
//     // create_picture_element(data.data[0], row_number_index, settings);

//     Drupal.casa_utilities.invoke_callbacks(success_callbacks);

//     // $(document).trigger('temp_file_saved');
//   });
// }



// Drupal.casa_upload = {};



})(jQuery, Drupal, this, this.document);
