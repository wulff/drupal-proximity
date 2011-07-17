<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function mapadelic_demo_taxonomy_default_vocabularies() {
  return array(
    'mapadelic_demo_store_type' => array(
      'name' => 'Store type',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '1',
      'tags' => '0',
      'module' => 'features_mapadelic_demo_store_type',
      'weight' => '0',
      'nodes' => array(
        'mapadelic_demo_store' => 'mapadelic_demo_store',
      ),
    ),
  );
}
