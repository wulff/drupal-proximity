# OpenLayers

TODO: Description of OpenLayers...

## Download software

To perform proximity searches with the OpenLayer modules, you will need to install the following contrib modules:

* CCK
* OpenLayers
* OpenLayers Proximity
* Views

If you have access to Drush Make, you can use the following make file to install all the required software:

	; core
	core = 6.x
	api = 2
	projects[] = drupal
	; contrib
	projects[cck][subdir] = contrib
	projects[openlayers][subdir] = contrib
	projects[openlayers_proximity][subdir] = contrib
	projects[views][subdir] = contrib

When you have downloaded the software and run the Drupal installer, you are ready to configure your site. (Performing the basic Drupal installation tasks is not covered by this guide.)

## Enable modules

Enable the following modules:

* CCK: Content
* Chaos tool suite: Chaos tools
* OpenLayers: OpenLayers
* OpenLayers: OpenLayers CCK
* OpenLayers: OpenLayers Proximity
* OpenLayers: OpenLayers UI
* OpenLayers: OpenLayers Views
* Views: Views
* Views: Views UI

If drush is available, you can use the following command to enable all modules at once:

	drush -y en content ctools openlayers openlayers_cck \
	  openlayers_proximity openlayers_ui openlayers_views \
	  views views_ui

## Basic configuration

## Create a content type

We will be building a store locator, so let's get started by creating a new content type. Go to Administer > Content management > Content types > Add content type. We'll call it "Store" and make a few changes to the default settings (renaming the title and body fields, and disabling comments).

When the content type has been created, click on the "Manage fields" link on the content type overview to add a location field. We'll call the new field "Store location" and give it the field name "field_openlayers_demo_store_location". Select "OpenLayers WKT" as the field type and click "Save" to add the field to the Store content type.

Before the field is ready for use, we have to modify its global settings. We'll mark the field as required and configure it to only accept "point" features. While we're on the settings page you should enable "Zoom to layer" as well.

## Create a taxonomy

Our imaginary pet store chain has different sizes of stores: Megamarts and regular stores. We'll use a taxonomy to handle this information. Go to Administer › Content management > Taxonomy > Add vocabulary and add a vocabulary named "Store type" associated with the new Store content type. Make the vocabulary required. Next, click on "Add terms" and add the two terms "Regular" and "Megamart" to the vocabulary. If you click on the "List" tab you should see the two terms.

## Create a preset for entering data

Before we can start adding data, we need to create an OpenLayer preset for use on nodes. Go to Administer > Site building > OpenLayers > Presets > Add. Call the new preset "openlayers_demo_node" and give it the title "Node".

Next, go to the "Center & Bounds" tab and configure the initial map view. If you want to restrict the users to an area of the map, you can shift-drag on the map to set the restricted extent. Remember to check the "Restrict Extent" checkbox.

We'll keep the default settings on the "Behaviors" and "Layers & Styles" tabs, so just click "Save" to create the preset. Go to Administer › Site building > OpenLayers and set the "Node" preset as the default preset. (If you want to disable the layer switcher or disable mousewheel zoom, you can change these and other settings on the "Behaviors" tab.

Head back to the "Manage fields" tab on the store content type and edit the Store location field. Under "Input map preset" select the Node map preset you just created.

## Create some content

Now we are ready to add some stores to the site. Go to Create content > Store and add your first store. To add the location of the store, click the pencil icon in the top right corner and place the store on the map.

## Create a view

Go to Administer > Site building > Views to create a view for doing the actual proximity search. Name the view openlayers_demo_store_locator and give it a brief description. Select the view type "Node" and click "Next" to create the view.

Add the following fields to the default view:

* Node: Title
* Content: Store location

Make sure that the fields appear in the same order in the view as they do in the list above.

When you add the title field, you should check the box labeled "Link this field to its node" to make it possible for users to click on the name of a store to be taken to the page for that store.

Next add a page display and set its URL to "openlayers_demo". Set the display style to "OpenLayers Map". Then, click the little gear icon and choose "Node" as the default map preset.

If you look at the view now, you will see that it is completely empty. In order to show any data on the map, we have to add at least one "OpenLayers Data" display to the view. When you have added the display, set its style to "OpenLayers Data", overriding the default display. Click the gear icon to modify the settings. Set "Map Data Sources" to "OpenLayers WKT" and select the store location field from the "WKT Field" dropdown. Choose Title as the title field and body as the description field.

Now we need to create a new map preset to be able to display the data from the data display. Go to Administer › Site building › OpenLayers > Presets and click add to create a new preset. We'll call the new preset "openlayers_demo_proximity" and set the title to "Proximity". On the "Layers & Styles" tab, enable the openlayers_demo_store_locator layer. Save the preset and return to the store locator view. On the default display click the gear icon next to the style and set "Proximity" as the map preset. 

Go to Administer › Site building › OpenLayers > Proximity search and rebuild the proximity index.

On the default display of the store locator view, add the "Proximity: Great-circle" filter, expose it and check the "Unlock location" checkbox. Uncheck the "Optional" and "Force single" checkboxes. If you want to be able to filter by store type, you can add an exposed "Taxonomy: Term ID" filter as well.

Now you can go to the following URL to test the finished store locator:

	http://example.com/openlayers_demo

TODO: edit map preset to add popups


### Google Maps support

Go to the following URL to get your Google Maps API key:

	http://code.google.com/apis/maps/signup.html

When you have your key, go to Administer › Site building › OpenLayers > Layers > API Keys and enter it.

