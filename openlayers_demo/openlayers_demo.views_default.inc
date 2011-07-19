<?php

/**
 * Implementation of hook_views_default_views().
 */
function openlayers_demo_views_default_views() {
  $views = array();

  // Exported view: openlayers_demo_store_locator
  $view = new view;
  $view->name = 'openlayers_demo_store_locator';
  $view->description = 'Store locator';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'field_openlayers_demo_location_openlayers_wkt' => array(
      'label' => 'Store location',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'openlayers_wkt',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_openlayers_demo_location_openlayers_wkt',
      'table' => 'node_data_field_openlayers_demo_location',
      'field' => 'field_openlayers_demo_location_openlayers_wkt',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'title' => array(
      'label' => 'Title',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'body' => array(
      'label' => 'Body',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'body',
      'table' => 'node_revisions',
      'field' => 'body',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'openlayers_demo_store' => 'openlayers_demo_store',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'circle' => array(
      'operator' => '<',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
        'location' => '',
        'node' => '4',
        'unit' => 'km',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_unit' => 0,
        'unit' => 'unit',
        'use_location' => 1,
        'location' => 'location',
        'use_node' => 0,
        'node' => 'node',
        'use_operator' => 0,
        'operator' => 'circle_op',
        'identifier' => 'circle',
        'label' => 'Find a store near you',
        'optional' => 0,
        'single' => 0,
        'remember' => 0,
      ),
      'location_as' => 'location',
      'id' => 'circle',
      'table' => 'openlayers_proximity',
      'field' => 'circle',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'tid' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'tid_op',
        'identifier' => 'tid',
        'label' => 'Type',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'type' => 'select',
      'limit' => TRUE,
      'vid' => '1',
      'id' => 'tid',
      'table' => 'term_node',
      'field' => 'tid',
      'hierarchy' => 0,
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_plugin', 'openlayers_map');
  $handler->override_option('style_options', array(
    'preset' => 'openlayers_demo_proximity',
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'openlayers_demo');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler = $view->new_display('openlayers', 'All stores', 'openlayers_1');
  $handler->override_option('style_plugin', 'openlayers_data');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'data_source' => array(
      'value' => 'openlayers_wkt',
      'other_lat' => 'field_openlayers_demo_location_openlayers_wkt',
      'other_lon' => 'field_openlayers_demo_location_openlayers_wkt',
      'openlayers_wkt' => 'field_openlayers_demo_location_openlayers_wkt',
      'other_top' => 'field_openlayers_demo_location_openlayers_wkt',
      'other_right' => 'field_openlayers_demo_location_openlayers_wkt',
      'other_bottom' => 'field_openlayers_demo_location_openlayers_wkt',
      'other_left' => 'field_openlayers_demo_location_openlayers_wkt',
      'name_field' => 'title',
      'keep_orig_name_field' => 1,
      'description_field' => 'body',
      'keep_orig_desc_field' => 1,
    ),
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('displays', array());

  $views[$view->name] = $view;

  // Exported view: openlayers_demo_stores_nearby
  $view = new view;
  $view->name = 'openlayers_demo_stores_nearby';
  $view->description = 'Stores nearby';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 1,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_fixed' => '',
      'default_argument_user' => 0,
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'openlayers_demo_store' => 0,
        'page' => 0,
        'story' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'openlayers_demo_store' => 'openlayers_demo_store',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'circle' => array(
      'operator' => '<',
      'value' => array(
        'value' => '10',
        'min' => '',
        'max' => '',
        'location' => '',
        'node' => '4',
        'unit' => 'km',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
        'use_unit' => FALSE,
        'unit' => 'unit',
        'use_location' => FALSE,
        'location' => 'location',
        'use_node' => FALSE,
        'node' => 'node',
      ),
      'location_as' => 'node',
      'id' => 'circle',
      'table' => 'openlayers_proximity',
      'field' => 'circle',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Stores nearby');
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_options', array(
    'grouping' => '',
  ));
  $handler = $view->new_display('node_content', 'Node content', 'node_content_1');
  $handler->override_option('types', array(
    'openlayers_demo_store' => 'openlayers_demo_store',
  ));
  $handler->override_option('modes', array(
    '0' => 'full',
  ));
  $handler->override_option('argument_mode', 'nid');
  $handler->override_option('show_title', 1);

  $views[$view->name] = $view;

  return $views;
}
