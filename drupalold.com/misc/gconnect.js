google.load("identitytoolkit", "1", {packages: ["ac"], language:"en"});

$(function() {
window.google.identitytoolkit.setConfig({
    developerKey: "AIzaSyDViBNgbND7yY9uqGbSwPV-qpnfcoVKqPI",
    companyName: "Faichi",
    callbackUrl: "http://drupalold.com/",
    realm: "",
    userStatusUrl: "drupalold.com/user/",
    loginUrl: "drupalold.com/user/login",
    signupUrl: "http://drupalold.com/user/register",
    homeUrl: "drupalold.com/",
    logoutUrl: "http://drupalold.com/logout",
    idps: ["Gmail"],
    tryFederatedFirst: true,
    useCachedUserStatus: false,
    useContextParam: false
});
$("#navbar").accountChooser();
});

