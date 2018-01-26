/**
 * @file
 *
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {



/**
 * CONTENTS
 *
 * - variable declarations -
 *
 * Drupal.behaviors.casa_map_mgt
 *  .attach()
 *
 * Drupal.casa_map_mgt
 *   .get_map()
 *   .get_ol_maps()
 *   .create_feature_from_JSON()
 *   .create_vector_layer()
 *   .add_feature_to_vector_layer()
 *   .add_layer()
 *   .get_feature_from_settings()
 *   .remove_interaction()
 *   .center_map()
 *   .create_style()
 *   
 *   .make_map_source()
 *   .make_map_tile_layer()
 *
 * add_collection_to_map()
 *
 * create_feature_geometry()
 * transform_geometry_to_4326()
 * transform_geometry_from_4326()
 */


var page_is_setup = false;

var map_container;
var map;
var map_tile_layer;
var map_vector_layer;
var draw_source;
var popup;

// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.casa_map_mgt = {
  attach: function(context, settings) {
    // console.log('context: ', context);
    // console.log('settings: ', settings);

    if (! page_is_setup) {
      // console.log('Page being set up...');
      // Drupal.casa_utilities.start_timer('casa_map_mgt');

      // Listener: When a tab is clicked, updateSize of any maps within it.
      $('.horizontal-tab-button a', context).on('click', function( event, ui ) {
        // console.log("heard: horizontal-tab-button clicked");

        if (typeof(Drupal.openlayers) !== 'undefined') {
          map = Drupal.casa_map_mgt.get_ol_maps(settings);
          // console.log('map: ', map);
          map.updateSize();
        }
        // else {
        //   throw "casa_map_mgt.js: " + "Drupal.openlayers is undefined.";
        // }
      });

      Drupal.casa_map_mgt.transform_placeholders_to_maps(context, settings);

      $('#views-exposed-form-browse-observations-map-feed', context).submit(function() {
        var form_values = $(this).serializeArray();
        // console.log('form_values: ', form_values);
        var url = $(this).attr('action');
        var method = $(this).attr('method');

        var data = {};

        $.each(form_values, function(key, value) {
          data[value.name] = value.value;
        });
        // console.log('data: ', data);

        var results = Drupal.casa_map_mgt.query_view_w_filters(url, data, method, settings);
        return false;
      });

      set_up_keypress_mgmt(context);

      // Drupal.casa_utilities.end_timer('casa_map_mgt');
      page_is_setup = true;
    }

  },
  weight: 2
};


Drupal.casa_map_mgt = {


  get_map: function(settings) {
    if (typeof(map) === 'undefined') {
      Drupal.casa_map_mgt.setup_map(settings);
    }
    return map;

    // Has has OL module map
    // else if (typeof(Drupal.openlayers) !== 'undefined') {
    //   return get_ol_maps(settings);
    // }
  },



  /*
   * Gets all maps created by the OpenLayers module;
   * Assumes there's only 1 map on the page...
   * @todo change this (and calling functions) to support multiple
   */
  get_ol_maps: function(settings) {

    if (typeof(Drupal.openlayers) === 'undefined') {
      throw 'Drupal.openlayers is not defined' + ', in Drupal.casa_map_mgt.refresh_maps()';
    }

    var map;
    var map_instances = Drupal.openlayers.instances;
    // console.log('map_instances: ', map_instances);

    $.each(map_instances, function(map_id, map_instance) {
      map = map_instance.map;
    });

    return map;
  },



  setup_map: function(settings) {
    var map_field = $('.form-field-name-field-location');
    // console.log('map_field.length: ', map_field.length);
    if (map_field.length > 0) {
      map = Drupal.map_widget_maker.make_widget_map(settings);
      // console.log('map: ', map);
    }
    else {
      throw "casa_map_mgt.js: " + "There is no textarea for the map";
    }
  },



  /**
   * Converts map containers that contain location data into OpenLayers maps.
   */
  transform_placeholders_to_maps: function(context, settings) {

    $('[data-transform="to-map"]', context).once('to-map').each(function(index, el) {

      map_container = $(this);
      map_container.removeClass('hidden');

      // // Get map container attributes
      // var attributes = map_container[0].attributes;
      // $.each(attributes, function (name, value) {
      //   console.log('name: ', name);
      //   console.log('value: ', value);
      // });

      var source_url = map_container.attr('data-source-url');
      // console.log('source_url: ', source_url);
      if (source_url) {
        source_url = settings.basePath + source_url;
        // console.log('source_url: ', source_url);

        filters = [];

        Drupal.casa_map_mgt.query_view_w_filters(source_url, filters, 'GET', settings);
      }
      else {
        // console.log('map_container.html(): ', map_container.html());
        var features_json = map_container.html();
        var features_data = $.parseJSON(features_json).features;
        Drupal.casa_map_mgt.add_features_to_map(map_container, features_data, settings);
      }
    });
  },


  query_view_w_filters: function(url, filters, method, settings) {
    // console.log('filters: ', filters);
    // console.log('method: ', method);

    url = settings.basePath + '/data/observations/qds';

    var query_str = '';
    if (method.toUpperCase() == 'GET') {
      query_str += '?';
      $.each(filters, function(key, value) {
        // console.log('key: ', key);
        query_str += key + '=' + value + '&';
      });
      filters = [];
    }

    var toastr_info = toastr.info('Fetching locations…', null, {
      'timeOut': '-1'
    }); // @todo add an 'undo' button

    var jqxhr = $.ajax({
      type: method,
      url: url + query_str,
      data: filters,
      // success: success,
      // dataType: dataType
    })
      .done(function(data) {
        // console.log("data: ", data);
        Drupal.casa_map_mgt.add_features_to_map(map_container, data, settings);
      })
      .fail(function() {
        alert("Sorry, could not fetch map data from: " + source_url);
      })
      .always(function() {
        toastr_info.remove();
      });
  },



  add_features_to_map: function(map_container, features_data, settings) {
    // console.log('features_data: ', features_data);

    var tile_layer = Drupal.casa_map_mgt.make_map_tile_layer('Bing');
    // console.log('tile_layer: ', tile_layer);

    var projection = tile_layer.getSource().getProjection();
    // console.log('projection: ', projection);

    var map_element = map_container[0];
    // console.log('map_element: ', map_element);
    // console.log('map_element: ', map_element);

    map_container.html('');

    var vector_source = new ol.source.Vector();
    var vector_layer = new ol.layer.Vector({
      source: vector_source
    });

    // Add location features
    var features = create_features_from_geojson(features_data, projection);
    // console.log('features: ', features);


    $.each(features, function(index, feature) {
      vector_source.addFeature(feature);
    });
    // console.log('vector_source.getFeatures(): ', vector_source.getFeatures());

    var gbif_key = map_container.attr('data-gbif-key');
    var tile_layer2 = null;
    if (gbif_key) {
      // console.log('gbif_key: ', gbif_key);
      tile_layer2 = Drupal.casa_map_mgt.make_map_tile_layer('gbif', [gbif_key]);
    }

    // Create the OpenLayers map.
    var map = new ol.Map({
      target: map_element,

      layers: [tile_layer],

      view: new ol.View({
        center: ol.proj.fromLonLat([0, 0]),
        zoom: 3
      })
    });
    if (vector_layer){
      map.addLayer(vector_layer);
    }
    if (tile_layer2) {
      map.addLayer(tile_layer2);
    }
    // console.log('map: ', map);

    // map.getView().setZoom(3);
    
    var popup_text = $('<div class="dialog popup white">test</div>');
    popup = new ol.Overlay({
      element: popup_text[0],
      positioning: 'bottom-center',
      offset: [0, -5]
    });
    map.addOverlay(popup);

    map.on('click', function(event){
      // console.log('event: ', event);
      var features = map.getFeaturesAtPixel(event.pixel);
      // console.log('features: ', features);

      if (! features) {
        popup.setPosition();
      }

      var names = [];
      var i = 0;
      $.each(features, function(key, feature) {
        // // Limit to 10
        // if (i == 10) {
        //   names.push('...');
        // }
        // i ++;
        // if (i >= 10) {
        //   return;
        // }

        // console.log('feature: ', feature);
        // console.log('feature.getProperties(): ', feature.getProperties());
        var url = settings.basePath + 'node/' + feature.getProperties().properties.id;
        // names.push(feature.getProperties().properties.picture);
        names.push('<a href="' + url + '" target="_blank">' + feature.getId() + '</a>');
      });
      // console.log('observations: ', names.join(', '));
      popup.setPosition(event.coordinate);
      popup_text.html('<div>' + names.join(', ') + '</div>');
    });

    var features_extent = vector_layer.getSource().getExtent();
    // console.log('features_extent: ', features_extent);
    map.getView().fit(features_extent);
    map.getView().setMaxZoom(19);

    // If features were found
    if (features.length > 0) {
      // Zoom to and center on vector layer.
      // map.getView().fit(vector_layer.getSource().getExtent(), map.getSize());
    }
    else {
      map.getView().setZoom(1);
    }
  },



  /*
   * Create a vector layer from JSON data.
   *
   * @param map
   *   OpenLayers map object
   * @param feature_data
   *   Feature's location data in geofield JSON format
   */
  create_feature_from_JSON: function(feature_data) {
    // console.log('feature_data: ', feature_data);

    // var map_tile_layer = new ol.layer.Tile({
    //   // source: new ol.source.MapQuest({layer: 'sat'})
    //   source: new ol.source.OSM({})
    // });

    // Convert "LINESTRING (20.41…)" to "20.41…"
    var indexStart = feature_data.geom.indexOf('(') + 1;
    var indexEnd = feature_data.geom.indexOf(')');
    var coordinates_string = feature_data.geom.substring(indexStart, indexEnd);
    // console.log('coordinates_string: ', coordinates_string);


    var featureGeometry = create_feature_geometry(coordinates_string, feature_data.geo_type);
    // console.log('featureGeometry: ', featureGeometry);

    var tile_layer_projection = map_tile_layer.getSource().getProjection();
    // console.log('tile_layer_projection: ', tile_layer_projection);

    // Transform this to match the projection of the map tile layer that will be used
    featureGeometry.transform(
      new ol.proj.Projection({code: "EPSG:4326"}), // source: EPSG:4326 (WGS84 geographic coordinates)
      tile_layer_projection // destination: EPSG:3857 (Web or Spherical Mercator, as used for example by Bing Maps or OpenStreetMap)
    );
    // console.log('featureGeometry coords after transform: ', featureGeometry.getCoordinates());


    var feature = new ol.Feature({
      geometry: featureGeometry,
      name: 'My ___'
    });

    return feature;
  },



  /*
   * Create a vector layer from JSON data.
   */
  create_point_feature_from_lon_lat: function(lon, lat) {

    var geometry = new ol.geom.Point(
      [lon, lat]
    );
    // console.log('geometry coords: ', geometry.getCoordinates());

    var projection = map_tile_layer.getSource().getProjection();
    // console.log('projection: ', projection);

    // Transform from coordinates (EPSG:4326) to metres (EPSG:3857)

    // Transform this to match the projection of the map tile layer that will be used
    geometry.transform(
      new ol.proj.Projection({code: "EPSG:4326"}), // source: EPSG:4326 (WGS84 geographic coordinates)
      projection // destination: EPSG:3857 (Web or Spherical Mercator, as used for example by Bing Maps or OpenStreetMap)
    );
    // console.log('geometry coords after transform: ', geometry.getCoordinates());


    var feature = new ol.Feature({
      geometry: geometry,
      name: 'My point'
    });

    return feature;
  },



  create_vector_layer: function() {
    return new ol.layer.Vector({
      source: new ol.source.Vector()
    });
  },



  add_feature_to_vector_layer: function(feature) {
    // console.log('features: ', map_vector_layer.getSource().getFeatures());
    map_vector_layer.getSource().addFeature(feature);
    // console.log('features: ', map_vector_layer.getSource().getFeatures());
  },



  add_layer: function(layer) {
    map.addLayer(layer);
  },





  get_feature_from_settings: function(settings) {
    // Fetch the current collection's location data.
    var feature_location_string = settings.edit_selected.collection_location;
    // Convert the location data into JSON.
    var feature_location = $.parseJSON(feature_location_string);
    return feature_location;
  },



  get_map_tile_layer: function() {
    return map_tile_layer;
  },

  set_map_tile_layer: function(map_tile_layer_in) {
    map_tile_layer = map_tile_layer_in;
  },


  center_map: function(layer) {
    // console.log('layer: ', layer);
    var maxZoom = 19; // Max for Bing AerialWithLabels tile layer

    if (typeof layer !== 'undefined') {
      // Zoom map to the layer's extent
      var extent = layer.getSource().getExtent();
      // console.log('extent: ', extent);
      map.getView().fit(extent, map.getSize(), {
        maxZoom: maxZoom
      });
    }
    else {
      // Zoom map to the own map_vector_layer's extent
      var extent = map_vector_layer.getSource().getExtent();
      // console.log('extent: ', extent);
      map.getView().fit(extent, map.getSize(), {
        maxZoom: maxZoom
      });
    }
  },



  create_style: function(geo_type, radius, fill_colour, stroke_colour) {

    // switch (geo_type) {
    //   case 'linestring':
    //     //
    //     break;
    //   case 'point':
    //     break;
    //   default:
    //     break;
    // }

    if (typeof radius == undefined) {
      radius = 5;
    }

    if (typeof fill_colour == undefined) {
      fill_colour = 'red'; // 'white';
    }

    if (typeof stroke_colour == undefined) {
      stroke_colour = 'red'; // '#bada55';
    }

    // Circle
    var style = new ol.style.Style({
      image: new ol.style.Circle({
        radius: radius,
        fill: new ol.style.Fill({color: fill_colour}),
        stroke: new ol.style.Stroke({color: stroke_colour, width: 1})
      })
    });

    return style;
  },



  /**
   * Transforms a feature from a layer's projection to EPSG:4326.
   */
  transform_geometry_to_4326: function(feature, layer) {

    if (typeof layer === 'undefined') {
      layer = map_tile_layer;
    }

    var current_projection = layer.getSource().getProjection();
    // console.log('new_projection: ', new_projection);
    var new_projection = new ol.proj.Projection({code: "EPSG:4326"});

    feature.getGeometry().transform(current_projection, new_projection);
  },



  /**
   * Transforms a feature from EPSG:4326 to a layer's projection.
   */
  transform_geometry_from_4326: function(feature, layer) {

    if (typeof layer === 'undefined') {
      layer = map_tile_layer;
    }

    var current_projection = new ol.proj.Projection({code: "EPSG:4326"});
    var new_projection = layer.getSource().getProjection();
    // console.log('new_projection: ', new_projection);

    feature.getGeometry().transform(current_projection, new_projection);
  },


  make_map_source: function(type, parameters) {
    // console.log('type: ', type);
    switch (type) {
      case 'OSM':
        // MapQuest Open Street Maps
        return new ol.source.MapQuest({layer: 'osm'});
        break;

      case 'Bing':
        // BingMaps

        // TYPES ________________________________
        // Aerial             Aerial
        // AerialWithLabels   Aerial with labels
        // Road               Road
        // collinsBart        Collins Bart
        // ordnanceSurvey     Ordnance Survey

        return new ol.source.BingMaps({
          imagerySet: 'AerialWithLabels', // EPSG:3857
          key: 'Alv8UVrw4GpMxdqDyfVK8js_wa56fdUPFhZF7eUPSTiPVsry3kdyIQcr-U5upHIN'
        });
        break;

      case 'gbif':
        // return new ol.source.TileImage({
        //   tileUrlFunction: function(coordinate) {
        //     var map_url = 'http://api.gbif.org/v1/map/density/tile'
        //       + '?x=' + coordinate[0]
        //       + '&y=' + coordinate[1]
        //       + '&z=' + coordinate[2]
        //       + '&type=' + 'TAXON'
        //       + '&key=' + '3152198'
        //       + '&resolution=' + '2'
        //       // + '&palette=' + 'yellows_reds'
        //     ;
        //     console.log('map_url: ', map_url);
        //     return map_url;
        //   }
        // });
        return new ol.source.XYZ({
          url: 'http://api.gbif.org/v1/map/density/tile?x={x}&y={y}&z={z}'
            + '&type=' + 'TAXON'
            + '&key=' + parameters[0]
            + '&resolution=' + '2'
            // + '&palette=' + 'yellows_reds'
        });

      default:
        break;
    }
  },

  make_map_tile_layer: function(source_type, parameters) {
    var tile_source = Drupal.casa_map_mgt.make_map_source(source_type, parameters);
    // console.log('tile_source.getProjection(): ', tile_source.getProjection());

    var map_tile_layer = new ol.layer.Tile({
      source: tile_source
    });
    return map_tile_layer;
  }

};

function isOdd(num) { return num % 2;}



/**
 * @param crs
 *   ol.proj.Projection object for the coordinate reference system that the new 
 *   features should use. eg. ol.proj.Projection({code: "EPSG:3857"})
 */
function create_features_from_geojson(features_data, crs) {
  // console.log('features_data: ', features_data);
  var features = [];

  if (features_data.type == 'FeatureCollection') {
    features_data = features_data.features;
  }

  $.each(features_data, function(index, feature_data) {
    // console.log('index: ', index);
    // console.log('feature_data: ', feature_data);

    var feature = create_feature_from_geometry(feature_data);

    // Transform the feature's projection.
    feature.getGeometry().transform(
      new ol.proj.Projection({code: "EPSG:4326"}), // source: EPSG:4326 (WGS84 geographic coordinates)
      crs // destination: EPSG:3857 (Web or Spherical Mercator, as used for example by Bing Maps or OpenStreetMap)
    );

    // FOR TESTING
    // feature = new ol.Feature({
    //   geometry: new ol.geom.Point([10,10])
    // });

    // Style it according to it's geometry type.
    var style;

    // console.log('type: ', feature.getGeometry().getType());
    if (feature.getGeometry().getType() == 'Point') {
      style = new ol.style.Style({
        // Small red dot
        image: new ol.style.Circle({
          radius: 5,
          fill: new ol.style.Fill({color: 'red'}),
        })
      });
    }
    // Polygon (representing a QDS)
    else if (feature.getGeometry().getType() == 'Polygon') {
      // Set the feature's style (based on its count).
      var count = parseInt(feature_data.properties.count);
      var colour = get_qds_count_colour(count);
      style = create_qds_style(colour);
    }
    feature.setStyle(style);

    features.push(feature);
  });

  return features;
}



/**
 * @param geometry
 *   A GeoJSON geometry object.
 */
function create_feature_from_geometry(feature_data) {
  // console.log('feature_data', feature_data);
  var geometry = feature_data.geometry;
  var feature_geometry;

  // Point
  if (geometry.type == 'Point') {
    var feature_geometry = new ol.geom.Point([
      parseFloat(geometry.coordinates[0]),
      parseFloat(geometry.coordinates[1])
    ]);
  }
  // Polygon (representing a QDS)
  else if (geometry.type == 'Polygon') {
    var feature_geometry = new ol.geom.Polygon([[
      [parseFloat(geometry.coordinates[0][0][0]),
       parseFloat(geometry.coordinates[0][0][1])],
      [parseFloat(geometry.coordinates[0][1][0]),
       parseFloat(geometry.coordinates[0][1][1])],
      [parseFloat(geometry.coordinates[0][2][0]),
       parseFloat(geometry.coordinates[0][2][1])],
      [parseFloat(geometry.coordinates[0][3][0]),
       parseFloat(geometry.coordinates[0][3][1])]
    ]]);
    // console.log('polygon: ', polygon);
  }

  var feature = new ol.Feature({
    geometry: feature_geometry,
    properties: feature_data.properties
  });

  if (feature_data.properties.name) {
    feature.setId(feature_data.properties.name);
  }
  else {
    feature.setId('Unnamed');
  }

  // feature.on('click', function(){
  //   alert(this.getId());
  // }, feature);

  // console.log('feature: ', feature);
  return feature;
}



function get_qds_count_colour(count) {
  var colour = 'black';

  // Validation.
  // if (typeof count !==

  var categories = {
    1: {
      'min': 0, 'max': 1,
      'colour': [255, 234, 000, 1] // yellow
    },
    2: {
      'min': 1, 'max': 4,
      'colour': [255, 120, 000, 1] // orange
    },
    3: {
      'min': 4, 'max': 10,
      'colour': [255, 000, 000, 1] // red
    },
    4: {
      'min': 10, 'max': 16,
      'colour': [255, 000, 180, 1] // pink
    },
    5: {
      'min': 16, 'max': 1000000, // 100,
      'colour': [195, 000, 255, 1] // purple
    },
  };

  $.each(categories, function(index, category) {
    if(count > category.min && count <= category.max) {
      colour = category.colour; // yellow
    }
  });

  return colour;
}



function create_qds_style(colour) {
  var stroke = new ol.style.Stroke({
    color: colour,
    width: 1
  });
  colour[3] = 0.6;
  var fill = new ol.style.Fill({
    color: colour
  });
  var style = new ol.style.Style({
    fill: fill,
    stroke: stroke
  });

  return style;
}


/**
 * Called by Drupal.casa_map_mgt.make_widget_map()
 */
function add_collection_to_map() {
  map_vector_layer = new ol.layer.Vector({
    source: new ol.source.Vector()
  });
  // console.log('vector_layer: ', vector_layer);

  var feature = Drupal.casa_map_mgt.create_feature_from_JSON(feature_data);

  var style = create_style(feature_data.geo_type);
  feature.setStyle(style);

  Drupal.casa_map_mgt.add_feature_to_vector_layer(feature);

  // Add the collection location as a layer to the map
  map.addLayer(map_vector_layer);

  Drupal.casa_map_mgt.center_map();
}


function create_feature_geometry(coordinates_string, geo_type) {
  // console.log('geo_type: ', geo_type);

  var featureGeometry;

  if (geo_type == 'linestring') {
    // console.log('is linestring');

    var path_points_strings = coordinates_string.split(', ');
    // console.log('path_points_strings: ', path_points_strings);

    var path_points = [];

    $.each(path_points_strings, function(index, val) {
      // console.log('point vals: ', val);
      var vals = val.split(' ');
      path_points.push([parseFloat(vals[0]),parseFloat(vals[1])]);
    });
    // console.log('path_points: ', path_points);

    featureGeometry = new ol.geom.LineString(path_points);
  }

  if (geo_type == 'point') {
    var coords = coordinates_string.split(' ');
    featureGeometry = new ol.geom.Point([parseFloat(coords[0]), parseFloat(coords[1])]);
  }

  return featureGeometry;
}



function set_up_keypress_mgmt(context) {

  $(document, context).bind('keydown', 'esc', function() {
    popup.setPosition();
  });
}



})(jQuery, Drupal, this, this.document);
