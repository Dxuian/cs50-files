//1 is button on shorts off 
//0 is button off shorts on 
var browser;

if (typeof browser === "undefined") {
    var browser = chrome;
}
browser.runtime.onMessage.addListener((message, sender, sendResponse) => {
    (async () => {
        if (message == "changetype") {
            var y = browser.storage.local.get("state");
            var x = await y;
            x = x.state;
            if (x == 0) {
                var k = document.querySelectorAll("a[href*='/shorts']")
                for (let card = 0; card < k.length; card++) {
                    try {
                        k[card].parentElement.parentElement.hidden = "true";
                    }
                    catch {
                        k[card].parentElement.hidden = "true";
                    }

                }
            }
            else if (x == 1) {
                var k = document.querySelectorAll("a[href*='/shorts']")
                for (let card = 0; card < k.length; card++) {
                    try {
                        k[card].parentElement.parentElement.removeAttribute('hidden');
                    }
                    catch {
                        k[card].parentElement.removeAttribute('hidden');
                    }
                }

            }
            sendResponse("made changes");
        }
        else if (message = "pager") {
            var y = browser.storage.local.get("state");
            var x = await y;
            x = x.state;
            if (x == 1) {
                if (window.location.href.includes("youtube.com/shorts") == true) {
                    window.history.back();
                }
                var k = document.querySelectorAll("a[href*='/shorts']")
                for (let card = 0; card < k.length; card++) {
                    try {
                        k[card].parentElement.parentElement.hidden = "true";
                    }
                    catch {
                        k[card].parentElement.hidden = "true";
                    }
        
                }
            }
            else if (x == 0) {
                var k = document.querySelectorAll("a[href*='/shorts']")
                for (let card = 0; card < k.length; card++) {
                    try {
                        k[card].parentElement.parentElement.removeAttribute('hidden');
                    }
                    catch {
                        k[card].parentElement.removeAttribute('hidden');
                    }
                }
        
            }
            sendResponse("made changes");
        }

    })();
    return true;
})
