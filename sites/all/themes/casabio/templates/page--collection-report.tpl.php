<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<nav>
  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">Home</a>
</nav>

<main role="main">
  <?php print render($page['content']); ?>
</main>
