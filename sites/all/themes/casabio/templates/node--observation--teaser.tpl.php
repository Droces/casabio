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

  <!-- <a href="<?php print $node_url; ?>" class="block"></a> -->
  <?php print render($content['node_block_link']); ?>

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
  ?>
  <div class="col-container">
    <section class="show">
      <?php
        print render($content['field_pictures_observation'][0]);
        unset($content['field_pictures_observation'][0]);
      ?>
      <!-- <div class="others">
        <?php
          print render($content['field_pictures_observation']);
        ?>
      </div> -->
    </section>
    <section class="tell">

      <?php if (isset($pretitle)): ?>
        <p class="pretitle subtle"><?php print $pretitle; ?></p>
      <?php endif; ?>

      <?php

        // Title isn't useful
        if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
          <header>
            <?php print render($title_prefix); ?>
            <?php if (!$page && $title): ?>
              <h3<?php print $title_attributes; ?>><?php print $title; ?></h3>
            <?php endif; ?>
            <?php print render($title_suffix); ?>


            <?php if ($unpublished): ?>
              <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
            <?php endif; ?>
          </header>
        <?php endif;

        // Submitted info isn't as useful as custom author fields…
        /*if ($display_submitted): ?>
          <p class="submitted">
            <?php print $user_picture; ?>
            <?php print $submitted; ?>
          </p>
        <?php endif;*/
      ?>

      <?php
        print render($content);
      ?>

      <?php /*print render($content['links']);*/ ?>

      <?php /*print render($content['comments']);*/ ?>
    </section>
  </div>

</article>
