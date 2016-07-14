/**
 * @file
 * A JavaScript file for…
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

var map;

// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.contribute = {
  attach: function(context, settings) {

  }/*,
  weight: 6*/
};



Drupal.contribute = {

  get_collection_nid: function() {
    var path = window.location.pathname;
    var path_parts = path.split('/');
    var nid = path_parts[path_parts.length - 1];
    // console.log( "collection: ", collection );
    return nid;
  },



  build_selectable_element: function(node, bundle, row_index, settings) {
    var main_picture_src = node['attributes']['image']['formats']['medium_square'];
    var colorbox_href = node['attributes']['image']['formats']['very_large'];
    var colorbox_rel = node['attributes']['collection']

    // console.log('node: ', node);
    var new_selectable = $('<article data-nid="' + node['id'] + '" '
      + 'class="' + bundle + ' selectable views-row-' + row_index + '"></article>')
      .appendTo('.selectables > ul');

    new_selectable.append([
      '<div class="field image">',
      '  <img src="' + main_picture_src + '">',
      '</div>',
      '<div class="selectable-target"></div>',
      '<span class="field-data"></span>',
      '<div class="property-nid">' + node['id'] + '</div>'
    ].join("\n"));

    if (bundle == 'picture') {
      // Enable colorbox trigger
      var colorbox_trigger = $('<a href="' + colorbox_href + '" class="colorbox" '
        + 'rel="'+ colorbox_rel + '">' + 'lightbox</a>')
        .colorbox();
      new_selectable.append(colorbox_trigger);
    }

    // Attach listeners to the new element
    Drupal.selection.add_selection_listeners(new_selectable, settings);

    return new_selectable;
  }

};


})(jQuery, Drupal, this, this.document);
