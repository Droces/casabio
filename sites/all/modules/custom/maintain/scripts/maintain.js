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


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.maintain = {
  attach: function(context, settings) {

    set_up_listeners();

    if (! page_is_setup) {

      page_is_setup = true;
    }


  }/*,
  weight: 1*/
};


function set_up_listeners() {
  // In the taxon edit form, in the 'Choose a representative picture' fieldset,
  // When a picture is clicked on
  $('.representative_picture_chooser article[data-type="picture"]').click(function(event) {
    event.preventDefault();
    // console.log('.representative_picture_chooser picture clicked');

    var nid = $(this).attr('data-nid');
    // console.log('nid: ', nid);
    var title = $(this).attr('data-title');
    // console.log('title: ', title);

    var representative_picture_field = $('#taxonomy-form-term [name^="field_representative_picture"]');
    // console.log("representative_picture_field.val(): ", representative_picture_field.val());

    // Set the value of 'field_representative_picture' field
    representative_picture_field.val(title + ' (' + nid + ')');
  });


  // In the taxon edit form, in the 'Choose pictures' fieldset,
  // When a picture is clicked on
  $('.pictures_chooser article[data-type="picture"]').click(function(event) {
    event.preventDefault();
    // console.log('.pictures_chooser picture clicked');
    
    var nid = $(this).attr('data-nid');
    // console.log('nid: ', nid);
    var title = $(this).attr('data-title');
    // console.log('title: ', title);

    var representative_picture_field = $('#taxonomy-form-term input[type="radio"]:checked')
      .siblings('.form-item')
      .children('[name^="field_pictures"]');
    // console.log("representative_picture_field.val(): ", representative_picture_field.val());

    // Set the value of 'field_representative_picture' field
    representative_picture_field.val(title + ' (' + nid + ')');
  });
}


})(jQuery, Drupal, this, this.document);
