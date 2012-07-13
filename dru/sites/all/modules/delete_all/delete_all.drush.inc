<?php

/**
 * @file
 * delete all Drush command
 */

/**
 * Implementation of hook_drush_command().
 */
function delete_all_drush_command() {
  $items = array();
  $items['delete-all'] = array(
    'callback' => 'delete_all_drush_delete',
    'description' => 'Delete all nodes of a specific content type',
    'options' => array(
      'roles' => 'pick roles',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_drush_help().
 */
function delete_all_drush_help($section) {
  switch ($section) {
    case 'drush:delete-all':
	return dt("Delete all nodes of a specific content type.");
  }
}

/**
 * Drush callback to delete content
 */
function delete_all_drush_delete() {
  $types = func_get_args();
  if ($types) {
    if (in_array('users', $types)) {
      if (!$types[1] && drush_get_option('roles')) {
        $choices = user_roles();
        $role = drush_choice($choices, dt("Choose a role to delete."));
        if ($role == 0) {
          return;
        }
      }
      else {
        $role = $types[1];
        if(strpos($role,',')) {
          $role = explode(',', $role);
        }
      }
      print "Deleted " . delete_all_users_delete($role) . " users\n";
    }
    else {
      print "Deleted " . _delete_all_normal(FALSE, $types) . " nodes\n";
    }
  }
  else {
    print "Content types and number of nodes:\n";
    // This should be refactored back into delete_all_content
    $result = db_query("SELECT type, COUNT(*) AS num FROM {node} GROUP BY type");
    $count = array();
    foreach ($result as $record) {
	  $count[$record->type] = $record->num;
    }
    foreach (node_type_get_types() as $type => $info) {
	  print $info->type .' '. ($count[$type] + 0) . "\n";
    }
  }
}
