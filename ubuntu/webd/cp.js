document.getElementById("afd").addEventListener("click",trigger) ;
function trigger()
{
  debugger ;
  var x  = document.getElementsByClassName("hello")[0].childNodes[1].firstChild.nodeValue;
  alert(x) ;
}

