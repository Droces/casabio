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
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
  ?>
  <div class="col-container">
    <div class="col-1-2">
      <?php
        print render($content['field_main_image']);
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
              <p class="subtle">Collection</p>


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
        <?php
          print render($content);
        ?>
      </section>
    </div>
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>
