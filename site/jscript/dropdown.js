/*bof tab selfDropdown*/

$(function(){
		   $("#navdiv ul:first").addClass("dropdown");
		   $('#navdiv ul li ul').hide();
	$("#navdiv ul li").hover(function(){
	$("ul:first",this).show();
	},function(){
	$("ul:first",this).hide();
	});
	$("ul.dropdown li ul li:has(ul)").find("a:first").prepend(" &laquo; &nbsp;");

});

/*eof tab selfDropdown*/