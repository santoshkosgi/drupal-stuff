api = 2
core = "7.14"

;;;;;;
; Fields
;;;;;;
projects[date][version] = 2.5
projects[field_group][version] = 1.1
projects[link][version] = 1.0
projects[options_element][version] = 1.7
projects[references][version] = 2.0
projects[filefield_sources][version] = 1.4

;;;;;;
; Path Tools
;;;;;;
projects[globalredirect][version] = 1.4
projects[pathauto][version] = 1.1
projects[redirect][version] = 1.0-beta4
projects[transliteration][version] = 3.0


;;;;;;
; Sitebuilding tools
;;;;;;
projects[apps][version] = 1.0-beta6
projects[backup_migrate][version] = 2.3
projects[boxes][version] = 1.0
projects[ctools][version] = 1.0
projects[custom_formatters][version] = 2.0
projects[defaultcontent][version] = 1.0-alpha6
; Remove context dependency.
; http://drupal.org/node/1446714
projects[defaultcontent][patch][1446714] = http://drupal.org/files/defaultcontent-1446714-16.patch
projects[ds][version] = 1.5
projects[email_registration][version] = 1.0
projects[entity][version] = 1.0-rc2
projects[entitycache][version] = 1.1
projects[features][version] = 1.0-rc2
projects[features_override][version] = 2.0-alpha1
projects[libraries][version] = 1.0
projects[menu_block][version] = 2.3
projects[panels][version] = 3.2
projects[strongarm][version] = 2.0-rc1
projects[token][version] = 1.1
projects[total_control][version] = 2.3-beta1
projects[views][version] = 3.3
projects[views_bulk_operations][version] = 3.0-rc1

;;;;;;
; Text Editor
;;;;;;
projects[imce][version] = 1.5
projects[imce_wysiwyg][version] = 1.0
;; No D7 release yet
;projects[better_formats][version] = 1.x-dev
projects[insert][version] = 1.1
projects[caption_filter][version] = 1.2
projects[image_resize_filter][version] = 1.13
projects[wysiwyg][version] = 2.1
; Fix path_to_theme()
; http://drupal.org/node/835682
projects[wysiwyg][patch][835682] = http://drupal.org/files/issues/wysiwyg-835682-12.patch
; Fix empty font styles drop down()
; http://drupal.org/node/746524
projects[wysiwyg][patch][746524] = http://drupal.org/files/746524-143-D7.patch
projects[wysiwyg_filter][version] = 1.6-rc2

;;;;;;
; UI Enhancements
;;;;;;
projects[backports][version] = 1.0-alpha1
projects[block_visibility][version] = 1.0-beta2
projects[nodeconnect][version] = 1.0-alpha2
projects[simplified_menu_admin][version] = 1.0-beta2
projects[elements][version] = 1.2
projects[admin_menu][version] = 3.0-rc2
projects[navigation404][version] = 1.0

;;;;;
; Libraries
;;;;;

libraries[tinymce][download][type] = "file"
libraries[tinymce][download][url] = "http://cloud.github.com/downloads/tinymce/tinymce/tinymce_3.4.9.zip"
libraries[tinymce][directory_name] = "tinymce"
libraries[tinymce][destination] = "libraries"

;;;;;;
; Themes
;;;;;;

projects[tao][version] = 3.0-beta4
projects[rubik][version] = 4.0-beta8
projects[omega][version] = 3.1
projects[omega][patch][1343274] = http://drupal.org/files/omega-ie7_0.patch
projects[navin][version] = 1.0-beta2
