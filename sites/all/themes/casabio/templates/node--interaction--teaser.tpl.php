<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<article data-nid="<?php print $node->nid; ?>" class="node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?> data-type="<?php print $type; ?>" data-view-mode="<?php print $view_mode; ?>" data-nid="<?php print $node->nid; ?>" data-title="<?php print $node->title; ?>">

  <?php if (isset($pretitle)): ?>
    <!-- <p class="pretitle subtle"><?php print $pretitle; ?></p> -->
  <?php endif; ?>

  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
    <header>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php if ($display_submitted): ?>
        <p class="submitted">
          <?php print $user_picture; ?>
          <?php print $submitted; ?>
        </p>
      <?php endif; ?>

      <?php if ($unpublished): ?>
        <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['picture_object']);
  ?>

  <div class="col-container">
    <section class="first">
      <?php print render($content['picture_subject']); ?>
    </section>
    <section class="middle">
      <?php print render($content); ?>
    </section>
    <section class="last">
      <?php print render($content['picture_object']); ?>
    </section>
  </div>

  <?php /*print render($content['links']);*/ ?>

</article>
