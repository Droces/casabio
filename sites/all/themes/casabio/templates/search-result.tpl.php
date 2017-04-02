<?php

/**
 * @file
 * CasaBio's implementation for displaying a single search result.
 *
 * @see https://api.drupal.org/api/drupal/modules!search!search-result.tpl.php/7
 * @see template_preprocess()
 * @see template_preprocess_search_result()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<li class="<?php print $classes; ?><?php if (isset($result_rendered)) {print ' pre-rendered';} ?>"<?php print $attributes; ?>>

  <?php if (isset($result_rendered)):
    print $result_rendered;
    else: ?>

    <a href="<?php print $url; ?>" role="block"></a>
    
    <?php print render($title_prefix); ?>
    <h3 class="title"<?php print $title_attributes; ?>>
      <a href="<?php print $url; ?>">
        <span class="type"><?php print $type; ?></span>
        <?php print $title; ?>
      </a>
    </h3>
    <?php print render($title_suffix); ?>

    <div class="search-snippet-info">
      <?php if ($snippet): ?>
        <p class="search-snippet"<?php print $content_attributes; ?>><?php print $snippet; ?></p>
      <?php endif; ?>

      <?php if ($info): ?>
        <p class="search-info"><?php print $info; ?></p>
      <?php endif; ?>
    </div>
    
  <?php endif; ?>
</li>
