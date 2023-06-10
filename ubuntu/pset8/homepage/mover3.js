document.getElementById("qw").addEventListener("mouseover", fn, once = false);
                        document.getElementById("qw").addEventListener("mouseout", fnone, once = false);
                        var y;
                        function fnone() {
                            // document.getElementById("qw").parentNode.offsetWidth=y ;
                            // var km = String(y)+'px' ;

                            // event.currentTarget.parentNode.clientWidth = y ;
                            // var k = 123;
                            // var z = 32123 ;
                            document.getElementById("qw").parentNode.className = "  mt-4 mb-3 marty  mar";

                        }

                        function fn() {
                            y = document.getElementById("qw").parentNode.clientWidth;
                            document.getElementById("qw").parentNode.className = "mart   mt-4 mb-3 mar";
                           document.getElementById("qw").children[0].children[1].className = "opaci scaler bg-danger textstyle"


                        }
