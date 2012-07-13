google.load('identitytoolkit', '1.0', {packages: ['importer']});

googleapis.setDeveloperKey(Drupal.settings.gconnect.devkey);

jQuery(function(){    
  var myIdps = Drupal.settings.gconnect.idps;
  window.google.identitytoolkit.easyrp.config.continueUrl = Drupal.settings.gconnect.baseUrl+'/?q=git/callback';
  window.google.identitytoolkit.easyrp.config.setConfig({
    idps: myIdps
  });
  var form = jQuery('#user-register');
  form.append('<input type="button" value="Sign Up Using Google"' +
      'class="gconnect-button" onclick="startImport();">');
  var form = jQuery('#user-login');
  form.append('<input type="button" value="Sign In Using Google"' +
      'class="gconnect-button" onclick="startImport();">');
  var form = jQuery('#user-login-form');
  form.append('<input type="button" value="Sign In Using Google"' +
      'class="gconnect-button" onclick="startImport();">');
    
});

function startImport() {
  google.identitytoolkit.easyrp.AttributeImporter.start(null, function(){});
  $(".widget-link").hide();
}

function handleResult(userInfo) {
  // not needed since the assertion is passed via _SESSION.
}
