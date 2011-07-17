<?php

/**
 * Implementation of hook_content_default_fields().
 */
function mapadelic_demo_content_default_fields() {
  $fields = array();

  // Exported field: field_mapadelic_demo_location
  $fields['mapadelic_demo_store-field_mapadelic_demo_location'] = array(
    'field_name' => 'field_mapadelic_demo_location',
    'type_name' => 'mapadelic_demo_store',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'all',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'location',
    'required' => '1',
    'multiple' => '0',
    'module' => 'location_cck',
    'active' => '1',
    'location_settings' => array(
      'form' => array(
        'fields' => array(
          'name' => array(
            'collect' => '0',
            'default' => '',
            'weight' => '2',
          ),
          'street' => array(
            'collect' => '1',
            'default' => '',
            'weight' => '4',
          ),
          'additional' => array(
            'collect' => '0',
            'default' => '',
            'weight' => '6',
          ),
          'city' => array(
            'collect' => '1',
            'default' => '',
            'weight' => '8',
          ),
          'province' => array(
            'collect' => '0',
            'default' => '',
            'weight' => '10',
          ),
          'postal_code' => array(
            'collect' => '1',
            'default' => '',
            'weight' => '12',
          ),
          'country' => array(
            'collect' => '1',
            'default' => 'dk',
            'weight' => '14',
          ),
          'locpick' => array(
            'collect' => '1',
            'weight' => '20',
          ),
        ),
      ),
      'display' => array(
        'hide' => array(
          'name' => 'name',
          'additional' => 'additional',
          'country' => 'country',
          'province_name' => 'province_name',
          'country_name' => 'country_name',
          'coords' => 'coords',
          'street' => 0,
          'city' => 0,
          'province' => 0,
          'postal_code' => 0,
          'locpick' => 0,
          'map_link' => 0,
        ),
      ),
    ),
    'gmap_macro' => '[gmap ]',
    'gmap_marker' => 'alt small red',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'street' => '',
          'city' => '',
          'postal_code' => '',
          'country' => 'dk',
          'locpick' => array(
            'user_latitude' => '',
            'user_longitude' => '',
          ),
          'cck_preview_in_progress' => TRUE,
          'location_settings' => array(
            'form' => array(
              'fields' => array(
                'name' => array(
                  'default' => '',
                  'collect' => '0',
                  'weight' => '2',
                ),
                'street' => array(
                  'default' => '',
                  'collect' => '1',
                  'weight' => '4',
                ),
                'additional' => array(
                  'default' => '',
                  'collect' => '0',
                  'weight' => '6',
                ),
                'city' => array(
                  'default' => '',
                  'collect' => '1',
                  'weight' => '8',
                ),
                'province' => array(
                  'default' => '',
                  'collect' => '0',
                  'weight' => '10',
                ),
                'postal_code' => array(
                  'default' => '',
                  'collect' => '1',
                  'weight' => '12',
                ),
                'country' => array(
                  'default' => 'dk',
                  'collect' => '1',
                  'weight' => '14',
                ),
                'locpick' => array(
                  'default' => array(
                    'user_latitude' => '',
                    'user_longitude' => '',
                  ),
                  'collect' => '1',
                  'weight' => '20',
                  'nodiff' => TRUE,
                ),
                'cck_preview_in_progress' => array(
                  'default' => TRUE,
                ),
                'location_settings' => array(
                  'default' => array(
                    'form' => array(
                      'fields' => array(
                        'lid' => array(
                          'default' => FALSE,
                        ),
                        'name' => array(
                          'default' => '',
                          'collect' => 1,
                          'weight' => 2,
                        ),
                        'street' => array(
                          'default' => '',
                          'collect' => 1,
                          'weight' => 4,
                        ),
                        'additional' => array(
                          'default' => '',
                          'collect' => 1,
                          'weight' => 6,
                        ),
                        'city' => array(
                          'default' => '',
                          'collect' => 0,
                          'weight' => 8,
                        ),
                        'province' => array(
                          'default' => '',
                          'collect' => 0,
                          'weight' => 10,
                        ),
                        'postal_code' => array(
                          'default' => '',
                          'collect' => 0,
                          'weight' => 12,
                        ),
                        'country' => array(
                          'default' => 'dk',
                          'collect' => 1,
                          'weight' => 14,
                        ),
                        'locpick' => array(
                          'default' => FALSE,
                          'collect' => 1,
                          'weight' => 20,
                          'nodiff' => TRUE,
                        ),
                        'latitude' => array(
                          'default' => 0,
                        ),
                        'longitude' => array(
                          'default' => 0,
                        ),
                        'source' => array(
                          'default' => 0,
                        ),
                        'is_primary' => array(
                          'default' => 0,
                        ),
                        'delete_location' => array(
                          'default' => FALSE,
                          'nodiff' => TRUE,
                        ),
                      ),
                    ),
                  ),
                ),
                'lid' => array(
                  'default' => FALSE,
                ),
                'latitude' => array(
                  'default' => 0,
                ),
                'longitude' => array(
                  'default' => 0,
                ),
                'source' => array(
                  'default' => 0,
                ),
                'is_primary' => array(
                  'default' => 0,
                ),
                'delete_location' => array(
                  'default' => FALSE,
                  'nodiff' => TRUE,
                ),
              ),
            ),
            'display' => array(
              'hide' => array(
                'name' => 0,
                'street' => 0,
                'additional' => 0,
                'city' => 0,
                'province' => 0,
                'postal_code' => 0,
                'country' => 0,
                'locpick' => 0,
                'province_name' => 0,
                'country_name' => 0,
                'map_link' => 0,
                'coords' => 0,
              ),
            ),
          ),
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Store location',
      'weight' => '-3',
      'description' => '',
      'type' => 'location',
      'module' => 'location_cck',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Store location');

  return $fields;
}
