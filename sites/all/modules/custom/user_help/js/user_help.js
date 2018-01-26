/**
 * @file
 *   Provides functions that enable the selection of elements on a webpage, which can then be manipulated.
 *
 * HTML elements on the webpage that have a class containing '.selectable'
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


/**
 * CONTENTS
 
  Drupal.behaviors.user_help.attach()
*/


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.user_help = {
  attach: function(context, settings) {
    // console.log('context: ', context);
    // console.log('settings: ', settings);
    // console.log('context: ', $(context));

    var overview_tour = setup_overview_tour();

    $('[href="#tour"]', context).click(function() {
      overview_tour.start();
      return false;
    });

    var cmo_observations_tour = setup_cmo_observations_tour();
    // cmo_observations_tour.start();
  }
  // weight: 3
};

Drupal.user_help = {
  setup_edit_pictures_tour: function() {
    var tour;

    tour = new Shepherd.Tour({
      defaults: {
        classes: 'shepherd-theme-arrows',
        scrollTo: true
      }
    });

    var selector = '.selectable:first-of-type';
    if ($(selector).length) {
      tour.addStep('step-steps', {
        text: "Click on the pictures to select them.",
        attachTo: selector + ' top',
        classes: 'shepherd-theme-arrows first',
        buttons: [
          makeTourButton(tour, 'end', {classes: 'left'}),
          makeTourButton(tour, 'next')
        ]
      });
    }

    var selector = '#show-fields-radios label:first-of-type';
    if ($(selector).length) {
      tour.addStep('step-steps', {
        text: "See picture information by clicking these buttons.",
        attachTo: selector + ' top',
        classes: 'shepherd-theme-arrows last',
        buttons: [
          makeTourButton(tour, 'end', {classes: 'left'}),
          makeTourButton(tour, 'next')
        ]
      });
    }

    return tour;
  }
}


function setup_cmo_observations_tour() {
  var tour;

  tour = new Shepherd.Tour({
    defaults: {
      classes: 'shepherd-theme-arrows',
      scrollTo: true
    }
  });

  var selector = 'ul.steps';
  if ($(selector).length) {
    tour.addStep('step-steps', {
      text: "Contributing observations is the 3-step process",
      attachTo: selector + ' bottom',
      classes: 'shepherd-theme-arrows first last',
      buttons: [
        // makeTourButton(tour, 'end', {classes: 'left'}),
        // makeTourButton(tour, 'next')
      ]
    });
  }

  return tour;
}


function setup_overview_tour() {
  var tour;

  tour = new Shepherd.Tour({
    defaults: {
      classes: 'shepherd-theme-arrows',
      scrollTo: true
    }
  });

  tour.addStep('step-welcome', {
    text: 'CasaBio is all about community-contributed observations of plant and animal specimens.',
    classes: 'shepherd-theme-arrows first',
    buttons: [
      makeTourButton(tour, 'end', {classes: 'left'}),
      makeTourButton(tour, 'next')]
  });

  var selector = '[href$="/contribute/upload"]';
  if ($(selector).length) {
    tour.addStep('step-cmo-observations', {
      text: 'This is where you upload your pictures of plants, animals, etc.',
      attachTo: selector + ' bottom',
      classes: 'shepherd-theme-arrows',
      buttons: [
        makeTourButton(tour, 'end', {classes: 'left'}),
        makeTourButton(tour, 'next')]
    });
  }

  var selector = '[href$="/browse"]';
  if ($(selector).length) {
    tour.addStep('step-explore', {
      text: "Here you will find everyone's pictures, collections, etc.",
      attachTo: selector + ' bottom',
      classes: 'shepherd-theme-arrows',
      buttons: [
        makeTourButton(tour, 'end', {classes: 'left'}),
        makeTourButton(tour, 'back'),
        makeTourButton(tour, 'next')]
    });
  }

  var selector = '[href$="/my/contributions"]';
  if ($(selector).length) {
    tour.addStep('step-my-contributions', {
      text: "All your contributions to CasaBio will live here. Come back here at any time to continue where you left off",
      attachTo: selector + ' bottom',
      classes: 'shepherd-theme-arrows last',
      buttons: [
        makeTourButton(tour, 'back'),
        makeTourButton(tour, 'end')]
    });
  }

  return tour;
}


function makeTourButton(tour, type, options) {
  if (typeof options == 'undefined') {
    options = {};
  }
  var button;
  switch (type) {
    case 'back':
      button = {
        text: 'Back',
        action: tour.back,
        classes: 'back'
      };
      break;
    case 'next':
      button = {
        text: 'Next',
        action: tour.next,
        classes: 'next'
      };
      break;
    case 'end':
      button = {
        text: 'End tour',
        action: tour.cancel,
        classes: 'end'
      };
      break;
  }

  if (typeof options.classes != 'undefined') {
    button.classes += ' ' + options.classes;
  }

  return button;
}


})(jQuery, Drupal, this, this.document);
