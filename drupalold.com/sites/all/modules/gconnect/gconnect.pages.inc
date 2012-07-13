<?php
/*
 * @file:
 *
 *
 */
function git_callback() {
  global $base_url;
  $continue = sprintf('http://%s', $_SERVER['HTTP_HOST'] . request_uri());
  $continue = str_replace('&amp;', '&', $continue);
  $response = @file_get_contents('php://input');

  $result = git_verify($continue, $response);

  $profile = array();
  if (!empty($result)) {
    $profile['identifier'] = $result['identifier'];
    $profile['email'] = $result['verifiedEmail'];
    $profile['displayname'] = $result['displayName'];
    $profile['status'] = "ok";
    if (!empty($result['firstName'])) {
      $profile['firstName'] = $result['firstName'];
    }
    elseif (!empty($result['displayName'])) {
      $profile['firstName'] = $result['displayName'];
    }
    if (!empty($result['lastName'])) {
      $profile['lastName'] = $result['lastName'];
    }
    elseif (!empty($result['displayName'])) {
      $profile['lastName'] = $result['displayName'];
    }
  }

  // Redirect the user to the create account page.
  $_SESSION['gconnect'] = $profile;
  $url = $base_url . "/?q=git/auth/handler";
  //var_dump($_SESSION['gconnect']);
  $html = '<script type="text/javascript">';
  if (!empty($url)) {
    $html .= "window.opener.location='$url';";
  }
  $html .= 'window.close();</script>';
  return $html;
}

/**
 * Sends request to the identity toolkit API endpoint to verify the IDP response.
 *
 * @param string $url The URL which is requested by the IDP.
 * @param string $postBody The post body which is posted by the IDP.
 * @return mixed: parsed raw user identity object from authentication server's HTTP response.
 */
function git_verify($url, $postbody) {
  $request = array();
  $request['method'] = 'identitytoolkit.relyingparty.verifyAssertion';
  $request['apiVersion'] = 'v1';
  $request['params'] = array();
  $request['params']['requestUri'] = $url;
  $request['params']['postBody'] = $postbody;

  $response = git_post($request);

  if (!empty($response['result'])) {
    return $response['result'];
  }
  return NULL;
}

/**
 * Sends post HTTP request to the remote url using curl module.
 *
 * @param string $postData the post body of this request.
 * @return mixed Data parsed from the HTTP response,
 *         NULL if the HTTP response code is not 200.
 */
function git_post($postdata) {
  $ch = curl_init();
  curl_setopt_array($ch, array(
      CURLOPT_URL => 'https://www.googleapis.com/rpc?key=' . variable_get('gconnect_developer_key', ''),
      CURLOPT_RETURNTRANSFER => 1,
      CURLOPT_HTTPHEADER => array('Content-Type: application/json'),
      CURLOPT_POSTFIELDS => json_encode($postdata),
      CURLOPT_SSL_VERIFYPEER => FALSE,
      CURLOPT_SSL_VERIFYHOST => FALSE));

  $response = curl_exec($ch);
  var_dump($response);
  $http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
  curl_close($ch);
  if ($http_code == '200' && !empty($response)) {
    return json_decode($response, TRUE);
  }
  else {
    return NULL;
  }
}

function git_auth_handler() {
  global $user;
  if ($_SESSION['gconnect']['status'] != 'ok') {
    drupal_set_message(t('We were unable to complete your request.'), 'error');
    watchdog('gconnect', 'Failed to obtain a 3rd party identifier for user ID %id: auth_info() returned error: %err', array('%id' => $user->uid, '%err' => "Cannot able to connect to google !"), WATCHDOG_ERROR);
    drupal_goto("node");
  }
  $gconnect_id = $_SESSION['gconnect']['identifier'];
    
  // Check allowed domain names.
  $allowed_domains = variable_get('gconnect_allowed_domains', '');
  $is_domains_blocked = variable_get('gconnect_block_domains', '');
  if (!empty($allowed_domains)) {
    $allowed_domains = preg_split('/\r\n|\r|\n/', $allowed_domains);
    if (count($allowed_domains)) {
      list($userName, $mailDomain) = split("@", $_SESSION['gconnect']['email']);
      if ($is_domains_blocked) {
        if ((in_array($mailDomain, $allowed_domains))) {
         drupal_set_message(t('User with email domain @domain is restrictred to use this site.', array('@domain' => $mailDomain)), 'error');
          drupal_goto();  
        }
      }
      else {  
        if (!(in_array($mailDomain, $allowed_domains))) {
         drupal_set_message(t('User with email domain @domain is restrictred to use this site.', array('@domain' => $mailDomain)), 'error');
          drupal_goto();  
        }
      }  
    }
  } 
  
  $provider_title = "gmail";
  $uid = db_result(db_query("SELECT uid FROM {users} where mail = '%s'", $_SESSION['gconnect']['email']));
  if ($uid) {
    $account = user_load($uid);

    // Is this a registered user?
    if (isset($account->uid)) {
      if (!variable_get('user_email_verification', TRUE) ||
          $account->login) {
        // IF settings do not require email verification
        // OR
        // it's not the first login for the user (which means the email has
        // already been verified)
        // OR
        // they are using an email the ID provider has already verified
        //
        // then we can skip the email verification process
        user_external_login($account);
        drupal_set_message("You are now logged in.");
      }
      else {
        drupal_set_message(t('You must validate your email address for this account before logging in with it.'), 'error');
      }
      drupal_goto();
    }
  }
  else {
    if (variable_get('user_register', 1)) {
      $form_state['values'] = array();
      $form_state['values']['op'] = t('Create new account');
      drupal_execute('user_register', $form_state);
          // See if the user was successfully registered.
      if (!empty($form_state['user'])) {
        $account = array(
          'user' => $user,
          'id' => $gconnect_id,
          'provider_machinename' => "gmail",
          'provider_title' => "Google",
        );
        // Nothing more to do.
        drupal_goto();
      }
      // get the error messages and clear the messages queue
      $messages = drupal_get_messages('error');

      if (empty($form_state['values']['mail'])) {
        // If the identity provider did not provide an email address, ask
        // the user to complete (and submit) the form manually instead of
        // showing the error messages about the missing values generated by
        // FAPI.
        drupal_set_message(t('Although we have verified your account, gmail did not provide us with your e-mail address.  Please enter one below to complete your registration.  (If you\'ve previously registered with us, please <a href="@login">log in</a> and add your gmail account under "Linked accounts.")', array('@login' => url('user/login'))), 'warning');
      }
      else {
        drupal_set_message(t('Although we have verified your account, registration using the information provided by gmail failed due to the reasons listed below. Please complete the registration by filling out the form below. (If you\'ve previously registered with us, please <a href="@login">log in</a> and add your gmail account under "Linked accounts.")', array('@login' => url('user/login'))), 'warning');
        // Append form validation errors below the above warning.
        foreach ($messages['error'] as $message) {
          drupal_set_message(check_plain($message), 'error');
        }
      }  // End of else
    } // End of check user register allowed
    else {
      drupal_set_message("New Registrations are not allowed !!", 'error');
      drupal_goto();
    }
  }  // End of new account else
}
