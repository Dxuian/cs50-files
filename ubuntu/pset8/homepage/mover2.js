 document.getElementById("qwe").addEventListener("mouseover", fn, once = false);
                        document.getElementById("qwe").addEventListener("mouseout", fnone, once = false);
                        var y;
                        function fnone() {
                            // document.getElementById("qwer").parentNode.offsetWidth=y ;
                            // var km = String(y)+'px' ;

                            // event.currentTarget.parentNode.clientWidth = y ;
                            // var k = 123;
                            // var z = 32123 ;
                            document.getElementById("qwe").parentNode.className = " mt-4 mb-3 marty  mar";

                        }

                        function fn() {
                            y = document.getElementById("qwe").parentNode.clientWidth;
                            document.getElementById("qwe").parentNode.className = "mart  mt-4 mb-3 mar";
                            document.getElementById("qwe").children[0].children[1].className = "opaci scaler bg-danger textstyle"


                        }
