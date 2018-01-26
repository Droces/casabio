<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<?php
  if ((int) $title > 0) {
    $term = taxonomy_term_load($title);
    $term_renderable = taxonomy_term_view($term, 'field_guide');
    $title = drupal_render($term_renderable);
  }
?>

<?php if (!empty($title)): ?>
  <div class="view-grouping-header"><?php print $title; ?></div>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
