<?php

function d7_preprocess(&$variables,$hook){
  //static $i;
//  kpr($i .' '.$hook);
  //kpr($hook);
  //$i++;
}
function d7_preprocess_page(&$variables){
  //kpr("hello");
  print "santosh kosgi" ;
  $slogans = array(
    t("life is good"),
    t("chase your dreams"),
    t("live happily"),
    t("make india a better place"),
    t("success is mantra"),
    t("a place to live a chance to grow"),
    t("sri chaitanya jr college")
    );
  $variables['site_slogan'] = $slogans[array_rand($slogans)] ;


  //adding variables
  if($variables['logged_in']){
    $variables['footer_message'] = t("welcome @username, This is an f theme",array(@username => $variables['user']->name ) );
  }
  else {
    $variables['footer_message'] = t("This is an f theme ." );
  }
  kpr($variables);
}
