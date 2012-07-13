CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation


INTRODUCTION
------------

Author:
* Anil Sagar (anil614sagar)

This module allows users to login / register on a Drupal website through the Google Identity Toolkit API http://code.google.com/apis/identitytoolkit/ – using their Gmail login and password.

INSTALLATION
------------

1. Copy the gconnect directory to your sites/SITENAME/modules directory
   or sites/all/modules directory.

2. Enable the module at Administer >> Site building >> Modules.

3. Visit Administer > Site Configuration > Google Connect Settings to configure the Google Developer Key.

4. Install jquery update module.

5. Update the jquery version to 1.4.2 using this patch here. http://drupal.org/node/775924#comment-2987316

6. That's it. :) Visit user/login or user/register page to see Google Connect Buttons.