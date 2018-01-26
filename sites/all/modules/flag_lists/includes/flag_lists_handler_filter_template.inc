<?php
/**
 * @file flag_lists_handler_filter_template.inc
 * Filter by list template
 */
class flag_lists_handler_filter_template extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('List templates');
      $this->value_options = array();
      $templates = flag_lists_get_templates();
      if (empty($templates)) {
         drupal_set_message(
           t('No templates found, create a flag lists <a href="@url">template</a>',
           array('@url' => url('/admin/structure/flags/lists/template') )),
           'info');
      }
      else if ($templates['0'] === FALSE) {
         drupal_set_message(
           t('No enabled template found, enable the built in flag lists <a href="@url">template</a>',
           array('@url' => url('/admin/structure/flags/manage/fl_template') )),
           'warning');
      }
      else {
        foreach ($templates as $template) {
          $options[$template->name] = $template->name;
        }
        $this->value_options = $options;
      }
    }
    return $this->value_options;
  }
}
