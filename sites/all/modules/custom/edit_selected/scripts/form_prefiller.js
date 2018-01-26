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
 * Drupal.form_prefiller
 *  .clear_form()
 *  .prefill_form()
 *
 * // get_field_property()
 * get_field_values()
 * set_field_value()
 * clear_field_value()
 * onlyUnique()
 */


Drupal.form_prefiller = {


  /**
   * Clears one field, so that it has no value.
   */
  clear_form: function(form) {

    // // Clear the map
    // if (typeof map_layer_selected_location !== 'undefined') {
    //   map_layer_selected_location.getSource().clear();
    // }

    var form_fields = form.find('input, textarea, select');

    // For each field in the block, find matching view result field, and use it's value
    $.each(form_fields, function( index, field ) {
      // console.log('field: ', field);
      if ($(field).attr('type') == 'text' && $(field).attr('data-default-value')) {
        // console.log('default value: ', $(field).attr('data-default-value'));
        $(field).val($(field).attr('data-default-value'));
      }
      else {
        Drupal.form_prefiller.clear_form_field(field);
      }
    });
  },

  clear_form_field: function(field) {
    if ($(field).attr('type') == 'submit'
      || $(field).attr('type') == 'hidden') { // @todo Include disabled (used for auto-complete)
      return null;
    }

    $(field).filter( "input:not([type='checkbox'])" ).val('');
    $(field).filter( 'input[type="checkbox"]' ).prop('checked', false);
    // field.find( "input[type='checkbox'], input[type='radio']" ).prop('checked', false);
    $(field).filter( "textarea" ).val('');
    $(field).filter( 'select option' ).prop('selected', false);
  },

  /**
   * For all selected nodes, fill their aggregated values into the edit form.
   *
   * If their values differ, sets the associated field's message to indicate mixed values.
   */
  prefill_form: function(form, selectables_data, settings) {
    // console.log("Called: prefill_form(), settings: ", settings);
    // console.log('selectables_data: ', selectables_data);

    if (Object.keys(selectables_data).length == 0) {
      var error_message = 'Array selectables_data is empty.';
      toastr.error(error_message);
      throw error_message;
    }

    var form_fields = form.find('input, textarea, select');
    // console.log('form_fields: ', form_fields);

    // For each field in the block, find matching view result field, and use it's value
    $.each(form_fields, function( index, field ) {
      Drupal.form_prefiller.prefill_form_field($(field), selectables_data, settings);
    });
  },

  /**
   * For all selected nodes, fill their aggregated values into the edit form.
   *
   * If their values differ, sets the associated field's message to indicate mixed values.
   */
  prefill_form_field: function(field, selectables_data, settings) {
    // console.log('field: ', field);

    if (field.attr('type') == 'submit') {
      return null;
    }

    // Determine field name

    var field_name = field.attr('name');

    if (typeof field_name == 'undefined') {
      return null;
    }

    var reg_expr = /\[/; // Split a string by '[' or by '][' or by ']'
    var field_name = field_name.split(reg_expr)[0]; // Keep only the first part
    // console.log('field_name: ', field_name);

    // Convert Drupal field name to API equivalent
    if (Drupal.contribute.is_page('observation_info')) {
      field_name = settings.API.observations_field_names_map[field_name];
    }
    else if (Drupal.contribute.is_page('picture_info')
      || Drupal.contribute.is_page('upload')) {
      field_name = settings.API.pictures_field_names_map[field_name];
    }
    // console.log('field_name: ', field_name);


    field_values = get_field_values(field_name, selectables_data, settings);
    // console.log('field_values gotten: ', field_values);

    // Use the values

    // If the selected nodes have at least one value for this field
    if (! field_values.length > 0 ) {
      return null;
    }

    field_values_mixed = field_values.filter( onlyUnique ).length > 1  ? true : false; //selecteds_indexes.length
    // console.log(field_name + ' field_values_mixed: ', field_values_mixed);

    // For mixed-values fields, display a message to notify the user
    if( field_values_mixed ) {
      // console.log('field_values mixed: ', field_values);

      field.filter('select, textarea')
        .val(null)
        .attr('data-values-status', "mixed" );

      $.each(field_values, function(index, value) {
        // console.log('value: ', value);
        field.filter('[type="checkbox"][value="' + value[0] + '"]')
          .prop("indeterminate", true)
          .attr('data-values-status', "mixed" );
      });
    }

    // For single-value fields, set the form item's value to the field value
    else {
      field.attr( 'data-values-status', "" );

      // Map
      if (field.attr('name').indexOf('field_locality') > -1) {
        // Drupal.es_maps.set_field_value(value);
        Drupal.edit_selected.set_selectable_feature_as_selected();
      }

      set_field_value(field, field_values[0]);
    }
  }

};





/**
 * Creates and array of field values from all selected nodes.
 */
function get_field_values(field_name, selectables_data, settings) {
  // console.log('get_field_values()');
  // console.log('field_name: ', field_name);
  // console.log('selectables_data: ', selectables_data);

  var field_values = [];
  var selectables_map = Drupal.edit_selected.get_selectables_map();

  // $.each( Drupal.selection.get_selecteds_indexes(), function( key, index ) {
  $.each( Drupal.selection.get_selected_nids(), function( index, nid ) {
    // console.log('nid: ', nid);

    // from selectables_data

    var selectable_data = selectables_data[selectables_map[nid]];
    // console.log('selectable_data: ', selectable_data);

    if (typeof selectable_data.attributes[field_name] != undefined) {
      var field_value = selectable_data.attributes[field_name];
      // console.log('field_value: ', field_value);

      field_value = field_value == null ? '' : field_value; // If null, change to ''

      field_values.push( field_value );
    }

  });

  // console.log('field_values: ', field_values);
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
 */
function set_field_value(field, values) {
  // console.log('field in:', field);
  // console.log('values in:', values);

  if (Array.isArray(values)) {
    // Checkboxes - can have multiple values
    $.each(values, function(index, value) {
      // console.log('value: ', value);

      // Select, multiple
      if (field.is( "select" )) {
        field.val(values);
      }

      var checkbox_selector = "input[type='checkbox'][name*='" + value + "']";
      if (field.is( checkbox_selector )) {
        field.prop('checked', true);
      }
    });
  }
  else {

    // If field has a default value but no value provided, leave it as is
    var default_value = field.attr('data-default-value');
    if (default_value && ! values) {
      return null;
    }

    // Text field, Textarea, Select (dropdown)
    field.filter( "input:not([type='checkbox']), textarea" ).val(values);

    // Select, single (dropdown) - can have only one value
    if (field.is( "select" )) {
      field.val(values);
    }

    // Radios
    var radio = "input[type='radio'][value='" + values[0] + "']";
    field.filter(radio).prop('checked', true);
  }
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
 * Used by array.filter().
 * Checks if the given value is the first occurring.
 * If not, it must be a duplicate, and function will return false.
 */
function onlyUnique(value, index, self) {
  return self.indexOf(value) === index;
}


})(jQuery, Drupal, this, this.document);
