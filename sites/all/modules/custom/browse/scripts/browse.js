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

var collections_disabled_options = [
	'new',
	'unidentified',
	'all',

	'map',
	'list',
];

// Happens only once
$( document ).ready(function() {
});

// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.browse = {
  attach: function(context, settings) {
  	// alert('context: ' + context);

    if (! page_is_setup) {

			// $( '#browse-chooser-form [value="collections"]', context ).change( function(event) {
			// 	manage_change( $( this ));
			// });
			$( '#browse-chooser-form [name="entity"]', context ).change( function(event) {
				manage_change( $( this ));
			});

      page_is_setup = true;
		}

  }
};


function manage_change (target) {
	var value = target.prop('value');
	console.log('value: ' + value);

	$.each(collections_disabled_options, function(index, val) {
		if (value == "collections") {
			$( '[value="' + val + '"]' ).prop('checked', false);
			$( '[value="' + val + '"]' ).attr('disabled', 'true');
		}
		else {
			$( '[value="' + val + '"]' ).attr('disabled', null);
			$( '[value="' + val + '"]' ).prop('checked', false);
		}
	});

}


})(jQuery, Drupal, this, this.document);
