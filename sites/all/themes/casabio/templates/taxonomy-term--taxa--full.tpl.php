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


  <div class="col-container">
    <div class="col-1-2">
      <?php
        print render($content['field_representative_picture']);
        print render($content['field_pictures']);
        print render($content['pictures_of_taxon']);
        print render($content['field_range']);
        print render($content['locations']);
      ?>
    </div>
    <div class="col-2-2">

      <?php if (!$page): ?>
        <h2><a href="<?php print $term_url; ?>"><?php print $term_name; ?></a></h2>
      <?php endif; ?>

      <?php if (isset($content['field_taxon_rank'])): ?>
        <p class="subtle"><?php print render ($content['field_taxon_rank']); ?></p>
      <?php endif; ?>

      <div class="content" role="presentation">
        <?php print render($content); ?>
      </div>
    </div>
  </div>

</div>
