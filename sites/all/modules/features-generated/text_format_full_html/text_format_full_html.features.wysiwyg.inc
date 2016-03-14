<?php
/**
 * @file
 * text_format_full_html.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function text_format_full_html_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: full_html
  $profiles['full_html'] = array(
    'format' => 'full_html',
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
          'justifyleft' => 1,
          'justifycenter' => 1,
          'bullist' => 1,
          'numlist' => 1,
          'link' => 1,
          'unlink' => 1,
          'image' => 1,
          'formatselect' => 1,
          'blockquote' => 1,
          'code' => 1,
          'hr' => 1,
          'removeformat' => 1,
        ),
        'paste' => array(
          'pastetext' => 1,
          'pasteword' => 1,
        ),
        'table' => array(
          'tablecontrols' => 1,
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
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 0,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 0,
      'remove_linebreaks' => 0,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 1,
      'block_formats' => 'p,h2,h3,h4',
      'css_setting' => 'theme',
      'css_path' => '',
      'css_classes' => '',
      'buttonorder' => 'formatselect,bold,italic,justifyleft,justifycenter,bullist,numlist,link,linkit,unlink,image,media,blockquote,hr,pastetext,pasteword,removeformat,tablecontrols,code',
    ),
    'rdf_mapping' => array(),
  );

  return $profiles;
}
