<?php
/**
 * @file
 * image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: medium_square.
  $styles['medium_square'] = array(
    'label' => 'Medium, square (220 × 220)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 220,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: thumbnail_square.
  $styles['thumbnail_square'] = array(
    'label' => 'Thumbnail, square (100 × 100)',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tiny.
  $styles['tiny'] = array(
    'label' => 'Tiny (24 × 24)',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 24,
          'height' => 24,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: very_large.
  $styles['very_large'] = array(
    'label' => 'Very large (800 × 800)',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => 800,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: very_large_cropped.
  $styles['very_large_cropped'] = array(
    'label' => 'Very large, cropped (700 × 700)',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 700,
          'height' => 700,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
