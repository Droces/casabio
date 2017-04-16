<?php
/**
 * @file
 * Default theme implementation to display a term.
 */
?>

<div id="taxonomy-term-<?php print $term->tid; ?>" class="<?php print $classes . " view-mode-" . $view_mode; ?>" data-vocabulary="<?php print $term->vocabulary_machine_name; ?>" data-view-mode="<?php print $view_mode; ?>">

  <?php if (isset($content['term_block_link'])): ?>
    <?php print render($content['term_block_link']); ?>
  <?php endif; ?>

  <div class="col-container outer">

    <section class="show">
      <?php if (isset($content['field_representative_picture'])): ?>
        <?php print render($content['field_representative_picture']); ?>
      <?php endif; ?>
    </section>


    <section class="tell">

      <h2><a href="<?php print $term_url; ?>">
        <!-- Prefix: Rank -->
        <?php if (isset($content['field_taxon_rank'])) {
          print '<span class="prefix">' . render($content['field_taxon_rank']) . '</span>';
        } ?>

        <!-- Title -->
        <?php print $term_name; ?>

        <!-- Suffix: Common names -->
        <?php if (isset($content['field_common_names'])) {
          print '<span class="suffix">(' . render($content['field_common_names'][0]) . ')</span>';
        } ?>
        <?php /*print render($content['field_taxon_rank']);*/ ?>
      </a></h2>

      <div class="col-container">
        <section class="show">

          <?php if (isset($content['field_pictures'])): ?>
            <?php print render($content['field_pictures']); ?>
          <?php endif; ?>

          <?php if (isset($content['field_range'])): ?>
            <?php /*print render($content['field_range']);*/ ?>
            <?php hide($content['field_range']); ?>
          <?php endif; ?>

          <?php if (isset($content['locations'])): ?>
            <?php print render($content['locations']); ?>
          <?php endif; ?>
        </section>

        <section class="tell">

          <div class="content" role="presentation">
            <?php hide($content['field_common_names']); ?>
            <?php print render($content); ?>
          </div>

        </section>
      </div>
    </section>
  </div>
</div>
