# Mapadelic

TODO: Mapadelic is a set of modules...

## Download software

To perform proximity searches with the Mapadelic modules, you will need to install the following contrib modules:

* CCK
* GMap
* Location
* Views
* Views attach

If you have access to Drush Make, you can use the following make file to install all the required software:

	; core
	core = 6.x
	api = 2
	projects[] = drupal
	; contrib
	projects[cck][subdir] = contrib
	projects[gmap][subdir] = contrib
	projects[location][subdir] = contrib
	projects[views][subdir] = contrib
	projects[views_attach][subdir] = contrib

When you have downloaded the software and run the Drupal installer, you are ready to configure your site. (Performing the basic Drupal installation tasks is not covered by this guide.)

## Enable modules

Enable the following modules:

* CCK: Content
* CCK: Location CCK
* Location: GMap
* Location: Location
* Views: Views
* Views: Views attach
* Views: Views UI

If drush is available, you can use the following command to enable all modules at once:

	drush -y en content location_cck gmap location views \
	  views_attach views_ui

## Basic configuration

### GMap

Go to the following URL to get your Google Maps API key:

	http://code.google.com/apis/maps/signup.html

When you have your key, go to Administer › Site configuration > GMap and enter it. When you have entered the key you should see a preview map in the "Default map settings" fieldset. (MAYBE: for now we'll just increase the size of the map to 640x360 pixels and leave the ...) We'll leave the rest of the settings as they are for now.

### Location

Go to Administer > Settings > Location to configure the Location modules. Change the default country if you are not in the United Stated, and check the box labeled "Use a Google Map to set latitude and longitude". This will make it possible for users to enter locations by clicking on a map.

Next, go to the "Geocoding options" tab and select "Town (city, village) level accuracy" as the default geocoding accuracy. On the same tab, enable the Google geocoding service for your contry. Save settings and click "Configure parameters" to configure the Google geocoding service for your country. Make sure the country-specific accuracy setting matches the global accuracy setting.

## Create a content type

We will be building a store locator, so let's get started by creating a new content type. Go to Administer > Content management > Content types > Add content type. We'll call it "Store" and make a few changes to the default settings (renaming the title and body fields, and disabling comments).

When the content type has been created, click on the "Manage fields" link on the content type overview to add a location field. We'll call the new field "Store location" and give it the field name "field_mapadelic_demo_store_location". Select "Location" as the field type and click "Save" to add the field to the Store content type.

Before the field is ready for use, we have to modify its global settings. We'll mark the field as required and modify the default country.

## Create a taxonomy

Our imaginary pet store chain has different sizes of stores: Megamarts and regular stores. We'll use a taxonomy to handle this information. Go to Administer › Content management > Taxonomy > Add vocabulary and add a vocabulary named "Store type" associated with the new Store content type. Make the vocabulary required. Next, click on "Add terms" and add the two terms "Regular" and "Megamart" to the vocabulary. If you click on the "List" tab you should see the two terms.

## Create some content

Now we are ready to add some stores to the site. Go to Create content > Store and add your first store. There's a bug in the current version of the Location modules which means that you have to choose the country manually or write a bit of code to handle that. You can use the snippet along the following pattern to set the default country to Denmark:

	$form[field_name][0]['country']['#default_value'] = 'dk';
	$form[field_name][0]['country']['#value'] = 'dk';

When you save the node you'll notice that the default node display doesn't include a map. To fix that, go to Administer › Content management > Content types and edit the Store content type. Click on the "Display fields" tab and select "Address with map" as the full node display for the Store location field.

If you want to prevent specific fields from being displayed, you must edit the Store location field and select which fields to disable in the "Display settings" section. This is useful if you don't want to display the exact coordinates of the node or if you want to hide some of the address information.

## Create a view

Go to Administer > Site building > Views to create a view for doing the actual proximity search. Name the view mapadelic_demo_store_locator and give it a brief description. Select the view type "Node" and click "Next" to create the view.

Change the view style to "GMap" and click the gear icon to edit its style options. Select "Location.module" as the data source. Use the "Marker / fallback marker to use" widget to select which marker to use on the map.

Set "Items to display" to zero to make sure that all stores will be shown on the map when no filters are applied.

Next, add the following fields to the view:

* Node: Title
* Location: Street
* Location: Postal Code
* Location: City

All the fields added to the view will be displayed in the popup that appears when a user clicks on one of the markers on the map. To make the popup look as clean as possible, you should use an empty label for all of fields.

Make sure that the fields appear in the same order in the view as they do in the list above.

If you want to display the postal code and the city on one line, you can click the gear icon next to the row style and tell Views to display them inline separated by a space.

When you add the title field, you should check the box labeled "Link this field to its node" to make it possible for users to click on the name of a store to be taken to the page for that store.

If you want to display additional information such as map links, you can use the "Location: Address" field instead of the street field. It contains all the data known to the Location module.

Finally, we'll add a page display to the view, so we can make it available at a specific URL. Add the display and assign it the path "mapadelic_demo". This will make the view available at the following URL

	http://example.com/mapadelic_demo

When you go to this URL you'll see a nice map showing all of the stores in the database. When you click on one of the markers you will see a nicely formatted address and a link to the store node.

## Filtering

Now let's make the map more useful by adding a couple of filters. We'll add a taxonomy filter to make it easy to get an overview of all regular shops or all megamarts, and a proximity filter to make it easy to find stores nearby.

First, add a "Taxonomy: Term" filter to the view (choose the "taxonomy term ID" version). Make the selection type "Dropdown" and click "Update" to configure the filter settings. Keep the default settings but click "Expose" to make this filter appear above the view on the store locator page. Change the label for the exposed filter to "Type" and click "Update" to add the filter to the view. If you go to the store locator pages you will be able to filter the stores by type.

To make it possible to search by proximity, add a "Location: Distance / Proximity" filter to the view, configure it to use circular proximity and set the origin to "Static Latitude / Longitude". Set the distance fairly high and expose the filter. Change the label of the exposed field to "Postal code".

## Add some code to make proximity searches work

To make proximity searches work, we have to add a bit of code. Refer to the mapadelic_demo.module file distributed with this guide. This section describes what happens in the different parts of the code.

* **Line 3:** Include the code necessary for Features to work
* **Line 5-6:** Set up a default unit and distance
* **Line 13-42:** Adds an address and distance field to the exposed form
* **Line 14:** Gets the current view object and
* **Line 18-30:** Adds the location and distance fields
* **Line 33:** Modifies the title of the taxonomy select widget
* **Line 36-37:** Modifies the weights of existing form elements
* **Line 40:** Attaches a theme function to the form
* **Line 47-67:** Handles geocoding of the address entered by the user
* **Line 50:** Determines the radius to use for the search
* **Line 53:** Determines the coordinates to use as the center for the search
* **Line 56-65:** Modifies the distance/proximity views filter
* **Line 72-95:** Determines whether the proximity search yielded any results. If no stores were found, it redirects to the default view and displays a brief error message.
* **Line 100-106:** Registers a custom theme function
* **Line 114-135:** Determines the coordinates to use for the search
* **Line 119-123:** Tries to use the default geocoder to determine the coordinates from the address entered by the user
* **Line 127-131:** Gets the default coordinates from the GMap settings if the user hasn't entered an address
* **Line 140-149:** Returns and array of distances for use in the distance widget
* **Line 157-177:** A custom theme function which adds a bit of CSS and renders all the necessary form elements with minimal markup

## Niceties

To make the map automatically zoom to fit all markers, go to Administer › Site configuration > GMap and mark the "autozoom" checkbox in the "Map Behavior flags" fieldset.