<?php
/**
 * @file
 * text_format_filtered_html.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function text_format_filtered_html_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: filtered_html
  $profiles['filtered_html'] = array(
    'format' => 'filtered_html',
    'editor' => 'tinymce',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 0,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'underline' => 1,
          'strikethrough' => 1,
          'bullist' => 1,
          'numlist' => 1,
          'link' => 1,
          'unlink' => 1,
          'image' => 1,
          'formatselect' => 1,
          'hr' => 1,
          'removeformat' => 1,
        ),
        'paste' => array(
          'pastetext' => 1,
          'pasteword' => 1,
        ),
        'linkit' => array(
          'linkit' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'none',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 1,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 1,
      'block_formats' => 'p,h2,h3,h4',
      'css_setting' => 'theme',
      'css_path' => '',
      'css_classes' => '',
      'buttonorder' => 'formatselect,bold,italic,underline,strikethrough,bullist,numlist,link,linkit,unlink,image,media,hr,removeformat,pastetext,pasteword',
    ),
    'rdf_mapping' => array(),
  );

  return $profiles;
}
