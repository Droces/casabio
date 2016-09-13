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

var collection_to_use =   null;
var collection_to_use_title = '';
var choice_block_element;
var api_url
var row_number_index = 0; // Keeps track of the last selectable added


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.casa_upload = {
  attach: function(context, settings) {
    // console.log('settings: ', settings);

    if (! page_is_setup) {

      api_url = settings.basePath + settings.API_path;

      choice_block_element = $('.choice-block');

      choice_block_element.find('input, select').change(function() {
        // console.log('changed');
        $('#uploader').attr('aria-enabled', true);
      });

      var PLuploader = $(".plupload-element", context).pluploadQueue();

      PLuploader.bind('FilesAdded', function(up, files) {
        if (collection_to_use == null) {
          set_collection();
        }

        $('#collection_choice')
          .attr('aria-collapsed', true)
          .prev().html("Adding to collection: " + collection_to_use_title);
        $('#saved_pics')
          .attr('aria-enabled', true);

        $('a[rel="next"]').attr('disabled', false);

        Drupal.es_api_interactions.fetch_selectables_data();
      });

      PLuploader.bind('FileUploaded', function(uploader, file, response) {
        // console.log('uploader: ', uploader);
        // console.log('file: ', file);
        // console.log('response: ', response);

        $request_body = {
          collection: collection_to_use,
          temp_name: file.id,
          file_name: file.name
        };
        // console.log('$request_body: ', $request_body);

        save_temp_file($request_body, settings);

      });


      page_is_setup = true;
    }

  }/*,
  weight: 1*/
};



Drupal.casa_upload = {
  get_collection_to_use: function() {
    return collection_to_use;
  }
}



function save_temp_file($request_body, settings) {
  var toastr_info = toastr.info('Loading…'); // @todo add an 'undo' button

  var url = Drupal.settings.basePath + 'ajax/contribute/save-uploaded';

  var request_settings = {
    type: "POST",
    contentType: "application/json",
    data: JSON.stringify($request_body),
    // data: groups,
    url: url, // api_url + '/login-token'
  }
  var jqxhr = $.ajax(request_settings);

  jqxhr.fail(function( data ) {
    toastr_info.remove();
    toastr.error('Sorry; there was a problem saving the picture.');
    console.log( "In save_temp_file() jqxhr.fail(), data: ", data);
    console.log( "data['responseText']: ", data['responseText']);
  });

  jqxhr.done(function( data ) {
    toastr_info.remove();
    // console.log( "In jqxhr.done(), data: ", data);

    row_number_index++;
    var new_selectable = Drupal.contribute.build_selectable_element(
      data.data[0], 'picture', row_number_index, settings);

    Drupal.selection.find_selectables($('.selectables'));

    Drupal.edit_selected.selectables_append(new_selectable);
    Drupal.edit_selected.add_selection_listeners(new_selectable, settings);

    Drupal.edit_selected.selectables_data_append(data.data[0]);
    // console.log('get_selectables_data(): ', Drupal.edit_selected.get_selectables_data());
    Drupal.edit_selected.populate_selectables_map();
    // console.log('get_selectables_map(): ', Drupal.edit_selected.get_selectables_map());

    // $(document).trigger('groups_saved');
  });
}


function set_collection() {
  var collection_choice =
    choice_block_element.children('[aria-selected]').attr('data-option-id');

  if (collection_choice == 'new') {
    var title = choice_block_element
      .find('[data-option-id="new"] input[type="text"]').val();
    // console.log('title: ', title);
    create_collection(title);
    collection_to_use_title = title;
  }
  else {
    collection_to_use = choice_block_element.children('[aria-selected]')
      .find('select').val();
    // console.log('collection_to_use: ', collection_to_use);
    collection_to_use_title = choice_block_element.children('[aria-selected]')
      .find('option:selected').text();

    var next_link = $('a[rel="next"]');
    next_link.attr('href', next_link.attr('href') + '/' + collection_to_use);
  }
}


function create_collection(title) {
  var toastr_info = toastr.info('Creating collection…'); // @todo add an 'undo' button

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
      "access_token": security_token
      // Session id header is not specified, because it's automatically added by browser (it's a cookie).
    },
    // data: groups,
    url: url, // api_url + '/login-token'
  }
  var jqxhr = $.ajax(request_params);

  jqxhr.fail(function( data ) {
    toastr_info.remove();
    toastr.error('Sorry; there was a problem creating a collection.');
    console.log( "In create_collection() jqxhr.fail(), data: ", data);
    console.log( "data['responseText']: ", data['responseText']);
  });

  jqxhr.done(function( data ) {
    toastr_info.remove();
    // console.log( "In jqxhr.done(), data: ", data);

    // console.log( "n jqxhr.done() success, data: ", data);
    collection_to_use = data['data'][0]['id'];
    // console.log('collection_to_use: ', collection_to_use);

    var next_link = $('a[rel="next"]');
    next_link.attr('href', next_link.attr('href') + '/' + collection_to_use);

    // $(document).trigger('collection created');
  });
}



// Drupal.casa_upload = {};



})(jQuery, Drupal, this, this.document);
