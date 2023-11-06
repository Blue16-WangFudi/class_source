$(document).ready(function start(){
    var cmpt = " ";  
    var user = " ";  
    var group = [0,0,0,0,0,0,0,0,0]; 
    $("#choose").fadeIn(1000);
    $("#cha").on("click",function a1(){
        $("#choose").fadeOut(1);
        $("#back").fadeOut(1);
        cmpt = "O";
        user = "×";
        pcStep();
    });
    $("#O").on("click",function b1(){
        $("#choose").fadeOut(1);
        $("#back").fadeOut(1);
        cmpt="×";
        user="O";
        pcStep();
    });

    var pcStep = function c1(){
        var step = 0;       
        for(var i in group){
            if(group[i] !== 0){
                step++;
            }
        }
        if(step %2 !== 0){
            return;
        }

        if(step === 0){
            var proStep = [0,2,6,8,4]; 
            var posit = parseInt(Math.random()*5,10);
            group[proStep[posit]] = 1;      
            $("#span-"+(proStep[posit]+1)).html(cmpt);

            judge();
            return;
        }

        if(step === 2){
            if(group[4] === 1){
                var corStep = [0,2,6,8]; 
                for(var t = 0; t<4;t++){
                    if(group[corStep[t]] === 2){
                        var posit1 = 0;
                        if(corStep[t] === 0){
                            posit1 = 8;
                        }else if(corStep[t] === 8){
                            posit1 = 0;
                        }else if(corStep[t] === 2){
                            posit1 = 6;
                        }else if(corStep[t] === 6){
                            posit1 = 2;
                        }
                        posit1 = parseInt(posit);
                        group[posit1] = 1;
                        $("#span-"+(posit1+1)).html(cmpt);
                        judge();
                        return;
                    }
                }
                var posit_g=[0,0]; 
                var posit2 = 0; 
                if(group[1] === 2){
                    posit_g[0] = 0;
                    posit_g[1] = 2;
                }else if(group[3] === 2){
                    posit_g[0] = 0;
                    posit_g[1] = 6;
                }else if(group[5] === 2){
                    posit_g[0] = 2;
                    posit_g[1] = 8;
                }else if(group[7] === 2){
                    posit_g[0] = 6;
                    posit_g[1] = 8;
                }
                posit2 = posit_g[parseInt(Math.random()*2)];
                posit2 = parseInt(posit2);
                group[posit2] = 1;
                $("#span-"+(posit2+1)).html(cmpt);
                judge();
                return;
            }
			else{
                if(group[4] === 0){
                    group[4] = 1;
                    $("#span-5").html(cmpt);
                    judge();
                    return;
                }
                var posit3 = 0;
                if(group[0] === 1){
                    posit3 = 8;
                }else if(group[8] === 1){
                    posit3 = 0;
                }else if(group[2] === 1){
                    posit3 = 6;
                }else if(group[6] === 1){
                    posit3 = 2;
                }
                posit3 = parseInt(posit3);
                group[posit3] = 1;
                $("#span-"+(posit3+1)).html(cmpt);
                judge();
                return;
            }
        }

        var first_arr = checkThree(1,group);
        if(first_arr.length !== 0){
            var posit4 = first_arr[0];
            posit = parseInt(posit);
            group[posit4] = 1;
            $("#span-"+(posit4+1)).html(cmpt);
            judge();
            return;
        }
        var second_arr = checkThree(2,group);
        if(second_arr.length !== 0){
            var posit5 = second_arr[0];
            posit = parseInt(posit5);
            group[posit5] = 1;
            $("#span-"+(posit5+1)).html(cmpt);
            judge();
            return;
        }
        var third_posit = 0;
        var third_max = -1;
        for(var temp in group){
            if(group[temp] === 0){
                if(third_max === -1){
                    third_posit = temp;
                    third_max = 0;
                }
                var ttt = [].concat(group);
                ttt[temp] = 1;
                var temp_arr = checkThree(1,ttt);
                if(temp_arr.length > third_max){
                    third_max = temp_arr.length;
                    third_posit = temp;
                }
            }
        }
        group[third_posit] = 1;
        var wtf = parseInt(third_posit);
        wtf+=1;
        $("#span-"+wtf).html(cmpt);
        judge();
        return;
    };
    var checkThree = function d1(kind,gp){
        var situ = [];
        var allPossible = [[0,1,2],[3,4,5],[6,7,8],[0,3,6],[1,4,7],[2,5,8],[0,4,8],[2,4,6]];
        for(var i in allPossible){
            var x = allPossible[i][0];
            var y = allPossible[i][1];
            var z = allPossible[i][2];
            if((gp[x] === kind && gp[y] === kind && gp[z] === 0) || (gp[x] === 0 && gp[y] === kind && gp[z] === kind) || (gp[x] === kind && gp[y] === 0 && gp[z] === kind)){
                if(gp[x] === 0){
                    situ.push(x);
                    continue;
                }else if(gp[y] === 0){
                    situ.push(y);
                    continue;
                }else if(gp[z] === 0){
                    situ.push(z);
                    continue;
                }
            }
        }
        return situ;
    };
    var result = function e1(state,a,b,c){
        if(state === 1){
            console.log('lose');
            $(".loser").html("失败");

        }else if(state === 2){
            console.log('win');
            $(".loser").html("胜利");

        }else if(state === 3){
            console.log('tie');
            $(".loser").html("平局");

        }
        if(state !== 3){
            $("#tic-"+a).css("background-color","#877f6c");
            $("#tic-"+b).css("background-color","#877f6c");
            $("#tic-"+c).css("background-color","#877f6c");
        }
        setTimeout(function(){
            if(state !== 3){
                $("#tic-"+a).css("background-color","#fff");
                $("#tic-"+b).css("background-color","#fff");
                $("#tic-"+c).css("background-color","#fff");
            }
            $(".loser").fadeIn(400,function(){
                    setTimeout(function(){
                    beginAgain();
                },2000);
            });
        },1500);
    };

    var beginAgain= function f1(){
        for(var yyy = 0; yyy < 9;yyy++){
            group[yyy]=0;
            $("#span-"+(yyy+1)).html("");
        }
        $(".loser").fadeOut(1,function(){
            pcStep();
        });

    }
    var judge = function g1(){
        if(group[0] === group[1] && group[1] === group[2] && group[0]!== 0){
            result(group[0],1,2,3);
        }else if(group[3] === group[4] && group[4] === group[5] && group[3] !== 0){
            result(group[3],4,5,6);
        }else if(group[6] === group[7] && group[7] === group[8] && group[6] !== 0){
            result(group[6],7,8,9);
        }else if(group[0] === group[3] && group[3] === group[6] && group[0] !== 0){
            result(group[0],1,4,7);
        }else if(group[1] === group[4] && group[4] === group[7] && group[1] !== 0){
            result(group[1],2,5,8);
        }else if(group[2] === group[5] && group[5] === group[8] && group[2] !== 0){
            result(group[2],3,6,9);
        }else if(group[0] === group[4] && group[4] === group[8] && group[0] !== 0){
            result(group[0],1,5,9);
        }else if(group[2] === group[4] && group[4] === group[6] && group[2] !== 0){
            result(group[2],3,5,7);
        }else{
            var isTie = true;
            for(var i = 0; i < 9;i++){
                if(group[i] === 0){
                    isTie = false;
                }
            }
            if(isTie){
                result(3,0,0,0);
            }else{
                var step = 0;
                for(var j in group){
                    if(group[j] !== 0){
                        step++;
                    }
                }
                if(step %2 === 0 && step !== 0){
                    pcStep();   
                }
            }
        }
    };
    var initClick = function h1(i){
        $("#tic-"+i).on("click",function(){
            var step = 0;
            for(var j in group){
                if(group[j] !== 0){
                    step++;
                }
            }
            if(step %2 === 0){
                return;
            }


            if(group[i-1] === 0){
                group[i-1] = 2;
                $("#span-"+i).html(user);
                judge();
            }
        });
    };

    for(var i=1;i<=9;i++){
        initClick(i);
    }
});// JavaScript Document