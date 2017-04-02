/**
 * @file
 * A JavaScript file for…
 */

/**
 * CONTENTS
 * 
 * Drupal.casa_node_mgt.
 *   convert_form_to_node()
 *   normalise_node()
 *   simplify_node_fields()
 * 
 * normalise_field()
 * denormalise_field_value()
 * parts_to_object()
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


// // To understand behaviors, see https://drupal.org/node/756722#behaviors
// Drupal.behaviors.casa_node_mgt = {
//   attach: function(context, settings) {
//     //
//   }
// };


Drupal.casa_node_mgt = {

  /**
   * Creates a API-ready node object from a form jQuery object.
   *
   * Converts [0: {name: "field_year[und][0][value]", value: "2016"}]
   * to {field_year[und][0][value]: "2016"}
   */
  convert_form_to_node: function(node_serialized) {
    var node = {};
    // console.log("node_serialized: ", node_serialized);

    // Just for testing - remove later.
    $.each(node_serialized, function (index, property) {
      node[property.name] = property.value;
    });
    // console.log("node: ", node);
    var node = {};

    // Loop through fields
    $.each(node_serialized, function (index, field) {
      // Known form properties that are not part of the node's properties or fields.
      var props_to_ignore = [
        "changed",
        "form_build_id",
        "form_id",
        "form_token",
        "prefill",
        "edit_selected_nids",
        "edit_selected_altered_fields"
      ];

      // If the field should not be ignored
      if ($.inArray(field.name, props_to_ignore) == -1) {
        var field_has_value = field.value;

        // Save the field value to node
        if (field_has_value) {
          // node[field.name] = field.value;



          // If a multi-value field (like a multi-select / check-boxes field)
          if (typeof node[field.name] !== 'undefined') {
            // If it's already an array
            if (typeof node[field.name] === 'object') {
              node[field.name].push(field.value);
            }
            else {
              node[field.name] = [node[field.name], field.value];
            }
            // console.log('node[field.name]: ', node[field.name]);
          }

          else {
            node[field.name] = field.value;
          }




        }
      }
    });
    // console.log("node: ", node);

    return node;
  },


  /**
   * Converts {field_year[und][0][value]: "2016"}
   * to {field_year: {und: [{value: "2016"}]}
   */
  normalise_node: function(node) {
    var node_output = {};

    $.each(node, function (index, field) {
      var field_has_value = field.value;

      var field_object = normalise_field(index, field);
      // console.log('field_object: ', field_object);

      if (field_object.name == "field_location") {
        if (field_has_value) {
          // Combine [dataType] and [geom] in field.value
        }
        else {
          field.value = {und:[{
            geom: "",
            dataType: "WKT"
          }]};
        }
        node_output[field_object.name] = field_object.value;
      }
      // All other fields
      else {
        node_output[field_object.name] = field_object.value;
      }
    });

    // console.log('node_output: ', node_output);
    return node_output;
  },


  /**
   * Alternative to normalise_node().
   * Converts {field_year[und][0][value]: "2016"}
   * to {year: "2016"}
   */
  simplify_node_fields: function(node, settings) {
    var node_output = {};

    $.each(node, function (field_name, value) {
      // console.log('field_name: ', field_name);
      // console.log('value: ', value);

      var reg_expr = /\[/; // Split a string by '[' or by '][' or by ']'
      var field_name = field_name.split(reg_expr)[0]; // Keep only the first part
      // console.log('field_name: ', field_name);

      // Determine the correct field name (for API)
      // @todo fix: For pictures only!
      if (Drupal.contribute.is_page('observation_info')) {
        field_name = settings.API.observations_field_names_map[field_name];
      }
      else if (Drupal.contribute.is_page('picture_info')
        || Drupal.contribute.is_page('upload')) {
        field_name = settings.API.pictures_field_names_map[field_name];
      }
      // console.log('field_name: ', field_name);

      // If a multi-value field (like a multi-select / check-boxes field)
      if (typeof node_output[field_name] !== 'undefined') {
        // If it's already an array
        if (typeof node_output[field_name] === 'object') {
          node_output[field_name].push(value);
        }
        else {
          node_output[field_name] = [node_output[field_name], value];
        }
        // console.log('node_output[field_name]: ', node_output[field_name]);
      }

      else {
        node_output[field_name] = value;
      }
    });

    // console.log('node_output: ', node_output);
    return node_output;
  }
}



/* Private functions
 *
   normalise_field()  // Called by Drupal.casa_node_mgt.convert_form_to_node()
   parts_to_object()          // Called by Drupal.casa_node_mgt.convert_form_to_node()
 */


/**
 * Converts (eg.) "field_name[und][0][value], 1" to "{name: field_name, value: {und: [{value: 1}]} }"
 */
function normalise_field(field_name, field_value) {
  // console.log('field_name: ', field_name);
  // console.log('field_value: ', field_value);
  var field_output = {};

  var reg_expr = /\[|\]\[|\]/; // Split a string by '[' or by '][' or by ']'
  var name_parts = field_name.split(reg_expr);
  // console.log("name_parts: ", name_parts);

  // Remove the last part if it's == ""
  var index_of_last = name_parts.length - 1;
  if (name_parts[index_of_last] == "") {
    name_parts.splice(index_of_last, 1);
  }

  // Now we have (eg.) name_parts = ["field_name", "und", "0", "value"]

  field_output['name'] = name_parts.splice(0, 1)[0]; // Pulls the first element out of the array
  field_output['value'] = parts_to_object(name_parts, field_value);
  // console.log('field_output: ', field_output);

  return field_output;
}


/**
 * Converts (eg.) "{und: [{value: 1}]} }" to "1"
 */
function denormalise_field_value(field_value) {
  // console.log('field_value: ', field_value);

  // $.each(field_value, function(index, value) {});
  return field_value;
}



/**
 * Recursively builds a normalised object for a field's value.
 *
 * Converts (eg.) "["und", "0", "value"], 1" to "{und: [{value: 1}]} }"
 * @note This does not work for multi-value fields! eg. ["und", "3"...
 * @todo Make this work for multi-value fields.
 */
function parts_to_object(parts, field_value) {
  // console.log('parts: ', parts);
  // console.log('field_value: ', field_value);

  var part = parts.splice(0, 1)[0];
  var part_as_int = parseInt(part, 10);
  var value; // What to return within an array or object

  // If this is the last part, or is a 'blank' array
  if (parts.length == 0) {
    value = field_value;
  }
  else {
    value = parts_to_object(parts, field_value); // Call function recursively with rest of parts
  }
  // console.log("value: ", value);

  // If part is not an integer, needs to return an object
  if (isNaN(part_as_int)) {
    var return_val = {};
    return_val[part] = value;
    return return_val;
  }
  // If part is an integer, needs to return an array
  else {
    return [value];
  }

}



})(jQuery, Drupal, this, this.document);
