<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function openlayers_demo_taxonomy_default_vocabularies() {
  return array(
    'openlayers_demo_store_type' => array(
      'name' => 'Store type',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '1',
      'tags' => '0',
      'module' => 'features_openlayers_demo_store_type',
      'weight' => '0',
      'nodes' => array(
        'openlayers_demo_store' => 'openlayers_demo_store',
      ),
    ),
  );
}
