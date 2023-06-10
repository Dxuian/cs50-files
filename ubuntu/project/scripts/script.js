//1 is button on shorts off 
//0 is button off shorts on 
if (typeof browser == "undefined") {
    browser = chrome;
}
var k2;
// document.addEventListener("DOMContentLoaded", check);
async function check(passer){
    if (typeof browser == "undefined") {
        browser = chrome;
    }
    var k1 = browser.runtime.sendMessage('check');
    k2 = await k1;
    k2 = Number(k2);
    console.log(k2);
    if (k2===1 && passer==undefined) {
        document.getElementById("turner").checked = "true";
        
    }
    else if (passer==undefined) {
        document.getElementById("turner").removeAttribute("checked");
    }
    return k2; 
}
check() ; 

document.getElementById("actualtoggle").addEventListener("click", changeto);
async function changeto() {
    if (typeof browser == "undefined") {
        browser = chrome;
    }
    passer= "cram" ; 
    k2  = await check(passer) ; 
    if (k2 == 1) {
        sender = 0;

        var x = document.getElementById("switcher").className;
        document.getElementById("switcher").className = document.getElementById("switcheron").className;
        document.getElementById("switcheron").className = x;
    }
    else {
        sender = 1; 
        var x = document.getElementById("switcheron").className;
        document.getElementById("switcheron").className = document.getElementById("switcher").className;
        document.getElementById("switcher").className = x;
    }
    var findtab = await browser.tabs.query({ active: true, currentWindow: true, url: "https://www.youtube.com/*" })
    if (findtab.length != 0) {
        var after = await browser.tabs.sendMessage(findtab[0].id, "changetype");
        var kay = after;
        if (kay == "made changes") {
            var ca = await browser.runtime.sendMessage("change");
            console.log(ca);
        }
        else {

        }

    }


}






































// async function curr()
// {
//     var findtab = await browser.tabs.query({active:true,currentWindow:true,url:"https://www.youtube.com/*"}) ;
//     if(findtab.length!=0)
//     {
//         var after = await browser.tabs.sendMessage(findtab[0].id,"orginal") ;
//         var kay =  after ;
//     }
// }