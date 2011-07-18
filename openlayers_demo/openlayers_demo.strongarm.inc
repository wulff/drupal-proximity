<?php

/**
 * Implementation of hook_strongarm().
 */
function openlayers_demo_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_openlayers_demo_store';
  $strongarm->value = 0;
  $export['comment_anonymous_openlayers_demo_store'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_openlayers_demo_store';
  $strongarm->value = '3';
  $export['comment_controls_openlayers_demo_store'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_openlayers_demo_store';
  $strongarm->value = '4';
  $export['comment_default_mode_openlayers_demo_store'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_openlayers_demo_store';
  $strongarm->value = '1';
  $export['comment_default_order_openlayers_demo_store'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_openlayers_demo_store';
  $strongarm->value = '50';
  $export['comment_default_per_page_openlayers_demo_store'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_openlayers_demo_store';
  $strongarm->value = '0';
  $export['comment_form_location_openlayers_demo_store'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_openlayers_demo_store';
  $strongarm->value = '0';
  $export['comment_openlayers_demo_store'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_openlayers_demo_store';
  $strongarm->value = '1';
  $export['comment_preview_openlayers_demo_store'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_openlayers_demo_store';
  $strongarm->value = '1';
  $export['comment_subject_field_openlayers_demo_store'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_openlayers_demo_store';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-2',
    'revision_information' => '1',
    'author' => '0',
    'options' => '2',
    'comment_settings' => '3',
    'menu' => '-1',
    'taxonomy' => '-4',
  );
  $export['content_extra_weights_openlayers_demo_store'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_openlayers_demo_store';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_openlayers_demo_store'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openlayers_default_preset';
  $strongarm->value = 'openlayers_demo_node';
  $export['openlayers_default_preset'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openlayers_proximity_unit';
  $strongarm->value = 'km';
  $export['openlayers_proximity_unit'] = $strongarm;

  return $export;
}
