<?php
/**
 * @file
 * gmiw_content_type_basic_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gmiw_content_type_basic_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function gmiw_content_type_basic_page_node_info() {
  $items = array(
    'basic_page' => array(
      'name' => t('Basic Page'),
      'base' => 'node_content',
      'description' => t('Use this <em>basic page</em> if you want any content on the site really. I don\'t plan to make any more.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
