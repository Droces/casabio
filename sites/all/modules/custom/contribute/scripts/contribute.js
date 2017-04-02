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
var current_page;

var map;

// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.contribute = {
  attach: function(context, settings) {
    // console.log('context: ', context);
    // console.log('settings: ', settings);

    if (! page_is_setup) {
      current_page = settings.contribute.current_page;

      page_is_setup = true;
    }

  },
  weight: 3
};



Drupal.contribute = {

  is_page: function(page) {
    if (typeof current_page == 'undefined') {
      throw "In Drupal.contribute.is_page(), current_page is undefined";
    }
    return current_page == page;
  },

  get_collection_nid: function() {
    var nid;

    if (Drupal.contribute.is_page('upload')) {
      return Drupal.casa_upload.get_collection_to_use();
    }
  
    var path = window.location.pathname;
    var path_parts = path.split('/');
    var nid = path_parts[path_parts.length - 1];
    // console.log( "collection: ", collection );
    return nid;
  },



  /**
   * @param node
   *   node object as returned by API.
   */
  build_selectable_element: function(node, bundle, row_index, settings) {
    // console.log('Called: build_selectable_element');
    // console.log('node: ', node);
    
    var main_picture_src = node['attributes']['image']['formats']['medium_square'];

    var lightbox_href = node['attributes']['image']['formats']['very_large'];
    var lightbox_rel = node['attributes']['collection'];
    var title = node['attributes']['label'];

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
      // Enable lightbox trigger
      var lightbox_trigger = $('<a href="' + lightbox_href + '" data-lightbox="no-group" '
        + 'rel="'+ lightbox_rel + '" data-title="' + title + '">' + 'Expand</a>');
      new_selectable.append(lightbox_trigger);

      // <a href="url" data-lightbox="no-group" data-title="Acacia caffra_0.jpg">Expand</a>
    }

    // Attach listeners to the new element
    Drupal.selection.add_selection_listeners(new_selectable, settings);

    return new_selectable;
  }

};


})(jQuery, Drupal, this, this.document);
