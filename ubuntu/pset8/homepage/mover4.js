document.getElementById("q").addEventListener("mouseover", fn, once = false);
                        document.getElementById("q").addEventListener("mouseout", fnone, once = false);
                        var y;
                        function fnone() {
                            // document.getElementById("q").parentNode.offsetWidth=y ;
                            // var km = String(y)+'px' ;

                            // event.currentTarget.parentNode.clientWidth = y ;
                            // var k = 123;
                            // var z = 32123 ;
                            document.getElementById("q").parentNode.className = "  mt-4 mb-3 marty  mar";

                        }

                        function fn() {
                            y = document.getElementById("q").parentNode.clientWidth;
                            document.getElementById("q").parentNode.className = "mart   mt-4 mb-3 mar";
                           document.getElementById("q").children[0].children[1].className = "opaci scaler bg-danger textstyle"


                        }
