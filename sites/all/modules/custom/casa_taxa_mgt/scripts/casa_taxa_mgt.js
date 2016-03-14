/**
 * @file
 * A JavaScript file for…
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

// Happens only once
$( document ).ready(function() {
});

// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.casa_taxa_mgt = {
  attach: function(context, settings) {
    // console.log('Called: Drupal.behaviors.casa_taxa_mgt.attach()');

        $( '.expand[data-ajax]', context ).on('click', function(event) {
            expand_taxonomy_branch($( this ));
        });

  }
};



/**
 * 
 */
function expand_taxonomy_branch(button) {
    var toastr_info = toastr.info('Expanding…'); // @todo add an 'undo' button
    console.log('toastr_info: ', toastr_info);
    var has_children = button.parents('li').attr('data-has-children') == 'true';

    if (!has_children) {
        var url = button.attr( 'data-ajax' );
        var target = button.parent().siblings( '.children' );

        var jqxhr = $.get(url);

        jqxhr.fail(function( data ) {
            toastr_info.remove();
            toastr.error('Sorry, there was a problem loading the taxonomy children.');
            console.log( "In jqxhr.fail(), data: ", data );
        });

        jqxhr.done(function( data ) {
            // console.log('data: ', data);
            toastr_info.remove();

            var result = data['result'];

            // If the GET was a success.
            if (result == "success") {
                target.append(data['content']);
                // toastr.success('Taxonomy children loaded.'); // Not needed; it's obvious when it's successful
                Drupal.attachBehaviors(target);
            }
            // If there was a problem with the GET.
            else {
                toastr.error('Sorry, there was a problem loading the taxonomy children.');
                console.log( "In jqxhr.done(), data: ", data );
            }
        });


        button.html('-');
        button.parent().parent().attr('data-has-children', 'true');
    }
    else {
        var children_container = button.parent().siblings( '.children' );
        children_container.empty();
        button.html('+');
        button.parent().parent().attr('data-has-children', 'false');
    }
}



})(jQuery, Drupal, this, this.document);