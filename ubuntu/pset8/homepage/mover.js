 document.getElementById("qwer").addEventListener("mouseover", fn, once = false);
                        document.getElementById("qwer").addEventListener("mouseout", fnone, once = false);
                        var y;
                        function fnone() {
                            // document.getElementById("qwer").parentNode.offsetWidth=y ;
                            // var km = String(y)+'px' ;

                            // event.currentTarget.parentNode.clientWidth = y ;
                            // var k = 123;
                            // var z = 32123 ;
                            document.getElementById("qwer").parentNode.className = "  mt-4 mb-3 marty  mar";

                        }

                        function fn() {
                            y = document.getElementById("qwer").parentNode.clientWidth;
                            document.getElementById("qwer").parentNode.className = "mart  mt-4 mb-3 mar";
                           document.getElementById("qwer").children[0].children[1].className = "opaci scaler bg-danger textstyle"


                        }
