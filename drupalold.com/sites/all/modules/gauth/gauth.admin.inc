<?php

/**
 * General settings configuration form.
 */
function gauth_settings_form() {
  $form = array();

  $form['gauth_manage_api_access_text'] = array(
    '#type' => 'markup',
    '#value' => '<p>' . t('For more information on the consumer key and secret, see <a href="@url">Managing the OAuth key and secret</a>', array('@url' => 'http://www.google.com/support/a/bin/answer.py?hl=en&answer=162105')) . '</p>',
  );

  $form['gauth_oauth_server'] = array(
    '#type' => 'textfield',
    '#title' => t('Google OAuth server'),
    '#default_value' => variable_get('gauth_oauth_server', 'https://www.google.com/accounts'),
    '#required' => TRUE,
  );

  $form['gauth_consumer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Auth Consumer Key'),
    '#default_value' => variable_get('gauth_consumer_key', ''),
    '#required' => TRUE,
  );

  $form['gauth_consumer_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Auth Consumer Secret'),
    '#default_value' => variable_get('gauth_consumer_secret', ''),
    '#required' => TRUE,
  );

  $form['gauth_two_legged_oauth'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable 2-legged oauth'),
    '#default_value' => variable_get('gauth_two_legged_oauth', FALSE),
  );

  $form['gauth_hd'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Apps domain'),
    '#description' => t('If authenticating against a Google Apps account, enter the hosted domain name, e.g. <em>example.com</em>'),
    '#default_value' => variable_get('gauth_hd', ''),
  );

  $form['gauth_scopes'] = array(
    '#type' => 'textfield',
    '#title' => t('Application scopes'),
    '#description' => t('A space separated list of Google Apps service scopes, e.g. <em>http://www.google.com/calendar/feeds/</em>. For the full list, see the <a href="@url">API documentation</a> ', array('@url' => 'http://code.google.com/apis/gdata/faq.html#AuthScopes')),
    '#default_value' => variable_get('gauth_scopes', ''),
  );

  $form['gauth_app_display_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Application display name'),
    '#default_value' => variable_get('gauth_app_display_name', ''),
  );

  return system_settings_form($form);
}

