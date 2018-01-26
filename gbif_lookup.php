<?php
  // $url = 'http://api.gbif.org/v1/species?name=Euphorbia+burgeri';
  $url = 'http://gbif.org/';
  print 'URL: ' . $url . '<br>';

  // $response = var_dump(http_get($url), [], $response);
  $curl = curl_init($url);
  $result = curl_exec($curl);
  print_r($result);

  if(! $result){
    die('Error: "' . curl_error($curl) . '" - Code: ' . curl_errno($curl));
  }
?>