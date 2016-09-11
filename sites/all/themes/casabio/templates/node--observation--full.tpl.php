<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */

  // dpm($content, 'content');
  // throw new Exception("Error Processing Request", 1);


?>
<article data-nid="<?php print $node->nid; ?>" class="node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>

  <div class="col-container">
    <div class="col-1-2">
      <?php
        print render($content['field_pictures_observation'][0]);
        unset($content['field_pictures_observation'][0]);
      ?>
      <div class="others">
        <?php
          print render($content['field_pictures_observation']);
        ?>
      </div>
      <?php
        print render($content['field_location']);
      ?>
    </div>
    <div class="col-2-2">
      <section class="field-group">
        <?php

          if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
            <header>
              <?php print render($title_prefix); ?>
              <?php if ($page && $title): ?>
                <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
              <?php endif; ?>
              <?php print render($title_suffix); ?>
              <p class="subtle">Observation</p>


              <?php if ($unpublished): ?>
                <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
              <?php endif; ?>
            </header>
          <?php endif;

          if ($display_submitted): ?>
            <p class="submitted">
              <?php print $user_picture; ?>
              <?php print $submitted; ?>
            </p>
          <?php endif;
        ?>
      </section>
      <section class="field-group">
        <h2>Basic Info</h2>

        <?php
          // Hide fields that shouldn't be displayed with the rest of $content
          hide($content['comments']);
          hide($content['links']);

          hide($content['identifications_view']);
          hide($content['interactions_view']);
          hide($content['new_identification_form']);
          hide($content['comments']);
        ?>

        <?php print render($content); ?>

      </section>
      <section class="field-group">
        <h2>Identifications</h2>
        <?php
          print render($content['identifications_view']);
          print render($content['new_identification_form']);
        ?>
      </section>
      <section class="field-group">
        <h2>Interactions</h2>
        <?php
          print render($content['interactions_view']);
          // print render($content['add_interaction_form']);
        ?>
      </section>
      <section class="field-group">
        <h2>Comments</h2>
        <?php print render($content['comments']); ?>
      </section>

    </div>
  </div>

</article>
