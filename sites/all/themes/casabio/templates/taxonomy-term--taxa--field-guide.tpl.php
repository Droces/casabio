<?php
/**
 * @file
 * Default theme implementation to display a term.
 */
?>

<?php /*dpm($term);*/ ?>

<div id="taxonomy-term-<?php print $term->tid; ?>" class="<?php print $classes . " view-mode-" . $view_mode; ?>" data-vocabulary="<?php print $term->vocabulary_machine_name; ?>" data-view-mode="<?php print $view_mode; ?>">

  <?php if (isset($content['term_block_link'])): ?>
    <?php print render($content['term_block_link']); ?>
  <?php endif; ?>


  <header class="term">
    <!-- Prefix: Rank -->
    <?php if (isset($content['field_taxon_rank'])) {
      print '<span class="prefix">' . render($content['field_taxon_rank']) . '</span>';
    } ?>

    <!-- Title -->
    <a href="<?php print $term_url; ?>">
      <h2 class="<?php print $title_class; ?>">
        <?php print $term_name; ?>
      </h2>
    </a>

    <!-- Suffix: Common names -->
    <?php if (isset($content['field_common_names'])) {
      print '<span class="suffix">' . render($content['field_common_names'][0]) . '</span>';
    } ?>
    <?php /*print render($content['field_taxon_rank']);*/ ?>
    
    <?php if (isset($content['field_vulnerability'])): ?>
      <?php print render($content['field_vulnerability']); ?>
    <?php endif; ?>
    
    <?php hide($content['field_num_children']);
      if (isset($content['field_num_children'])):
        if ($num_children > 0): ?>
      <?php print render($content['field_num_children']) . ' ' . $children_suffix; ?>
    <?php endif; endif; ?>
  </header>


  <section class="show">
    <?php if (isset($content['field_representative_picture'])): ?>
      <?php print render($content['field_representative_picture']); ?>
    <?php endif; ?>

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
