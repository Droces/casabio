/**
 * @file
 * A JavaScript file for…
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
   */
  convert_form_to_node: function(form) {
    var node = {};
    var node_serialized = form.serializeArray();
    // console.log("node_serialized: ", node_serialized);
    
    // Just for testing - remove later.
    $.each(node_serialized, function (index, property) {
      node[property.name] = property.value;
    });
    // console.log("node: ", node);
    var node = {};
    
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

        // "field_name[und][0][value] = 1" needs to become "field_name = {und: [{value: 1}]}"
        var field_object = convert_field_to_object(field);

        if (field.name == "field_location") {
          if (field_has_value) {
            // Combine [dataType] and [geom] in field.value
          }
          else {
            field.value = {und:[{
              geom: "",
              dataType: "WKT"
            }]};
          }
          node[field.name] = field.value;
        }
        // All other fields
        else if (field_has_value) {
          node[field.name] = field.value;
        }
      }
    });
    // console.log("node: ", node);

    return node;
  }
}



/* Private functions
 * 
   convert_field_to_object()  // Called by Drupal.casa_node_mgt.convert_form_to_node()
   parts_to_object()          // Called by Drupal.casa_node_mgt.convert_form_to_node()
 */


/**
 * Converts (eg.) "{name: field_name[und][0][value], value: 1}" to "{name: field_name, value: {und: [{value: 1}]} }"
 */
function convert_field_to_object(field) {
  // console.log("field: ", field);
  var new_field = {};

  var reg_expr = /\[|\]\[|\]/; // Split a string by '[' or by '][' or by ']'
  var name_parts = field.name.split(reg_expr);
  // console.log("name_parts: ", name_parts);

  // Remove the last part if it's == ""
  var index_of_last = name_parts.length - 1;
  if (name_parts[index_of_last] == "") {
    name_parts.splice(index_of_last, 1);
  }

  // Now we have (eg.) name_parts = ["field_name", "und", "0", "value"]

  field.name = name_parts.splice(0, 1)[0]; // Pulls the first element out of the array
  field.value = parts_to_object(name_parts, field.value);
  // console.log("field: ", field);

  return new_field;
}



/**
 * A recursive function. Starts with (eg.) ["und", "0", "value"]
 * @note This does not work for multi-value fields! eg. ["und", "3"...
 * @todo Make this work for multi-value fields.
 */
function parts_to_object(parts, field_value) {
  // console.log("parts: ", parts);

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