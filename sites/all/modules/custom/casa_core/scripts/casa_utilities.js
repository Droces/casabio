/**
 * @file
 * JavaScript snippets needed by CasaBio that aren't specific to Drupal
 */

/**
 * CONTENTS
 *
 *  .toObject()
 *  .get_url_parameter_value()
 *  .add_message_from_js()
 *  .get_loader_markup()
 *  .start_timer()
 *  .end_timer()
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


var timers = {};


Drupal.casa_utilities = {

  /**
   * Converts an array to an object.
   */
  toObject: function(array) {
    var array_as_object = {};
    for (var i = 0; i < array.length; ++i)
      array_as_object[i] = array[i];
    return array_as_object;
  },



  get_url_parameter_value: function(param) {
    var sPageURL = decodeURIComponent(window.location.search.substring(1)),
      sURLVariables = sPageURL.split('&'),
      parameter_name,
      i;
    // console.log('sPageURL: ', sPageURL);

    for (i = 0; i < sURLVariables.length; i++) {
      parameter_name = sURLVariables[i].split('=');

      if (parameter_name[0] === param) {
        return parameter_name[1] === undefined ? true : parameter_name[1];
      }
    }
  },



  /**
   * Displays a message in the message area. Useful for JS AJAX errors.
   *
   * Note that the close buttons can be activated by calling:
   * @code
   * Drupal.behaviors.casabio.attach($('.message-container')[0], settings);
   * @endcode
   *
   * @param type
   *   The type of message. Options: 'status', 'warning', 'error'.
   */
  add_message_from_js: function(message_text, type) {
    var container = $('.message-container');
    var remove_button = '<button class="right" data-action="remove">×</button>';
    switch (type) {
      case 'status':
        container.append(
          '<div class="messages status"><h2 class="element-invisible">Status message</h2>'
          + remove_button
          + message_text + '</div>');
        break;

      case 'warning':
        container.append(
          '<div class="messages warning"><h2 class="element-invisible">Warning message</h2>'
          + remove_button
          + message_text + '</div>');
        break;

      case 'error':
      default:
        container.append(
          '<div class="messages error"><h2 class="element-invisible">Error message</h2>'
          + remove_button
          + message_text + '</div>');
        break;
    }
  },


  get_loader_markup: function() {
    var markup =
    '<div class="loader" id="floatingCirclesG">' +
    '  <div class="f_circleG" id="frotateG_01"></div>' +
    '  <div class="f_circleG" id="frotateG_02"></div>' +
    '  <div class="f_circleG" id="frotateG_03"></div>' +
    '  <div class="f_circleG" id="frotateG_04"></div>' +
    '  <div class="f_circleG" id="frotateG_05"></div>' +
    '  <div class="f_circleG" id="frotateG_06"></div>' +
    '  <div class="f_circleG" id="frotateG_07"></div>' +
    '  <div class="f_circleG" id="frotateG_08"></div>' +
    '</div>';
    return markup;
  },


  start_timer: function(name) {
    if (typeof name !== 'string') {
      throw "Param 'name' is not a string.";
    }
    if (typeof timers[name] !== 'undefined') {
      // Timer already started
      return false;
    }
    else {
      timers[name] = new Date();
      return true;
    }
  },


  end_timer: function(name) {
    if (typeof name !== 'string') {
      throw "Param 'name' not a string.";
    }
    if (typeof timers[name] === 'undefined') {
      throw "Timer '" + name + "' needs to be a valid timer name.";
    }
    else {
      var end = new Date();
      var duration = end.getTime() - timers[name].getTime();
      console.log("Timer " + name + " duration: " + duration + "msec");
      delete(timers[name]);
    }
  },


  /**
   * Invokes functions provided in an array. Often used by delayed fuctions
   * like .done() and .always() which rely on HTTP requests.
   *
   * @param callbacks
   *   An array of arrays, in the form [[function, thisobject, [args...]], ...]
   */
  invoke_callbacks(callbacks) {
    // If callback functions were provided, invoke them.
    if (typeof callbacks !== 'undefined') {
      // console.log('callbacks: ', success_callbacks, always_callbacks);
      $.each(callbacks, function(key, callback_info) {
        // console.log('callback_info: ', callback_info);
        // console.log('this[1]: ', this[1]);

        // If callback's "this" object wasn't provided, provide a default
        this[1] = typeof this[1] === 'undefined' ? this : this[1];
        // If callback's parameters weren't provided, provide a default of an empty array
        this[2] = typeof this[2] === 'undefined' ? [] : this[2];

        // var this_obj = (typeof callback_info[2] === 'undefined') ? this : callback_info[2];
        this[3] = this[0].apply(this[1], this[2]);
      });
    }
    return callbacks;
  }


};


})(jQuery, Drupal, this, this.document);


