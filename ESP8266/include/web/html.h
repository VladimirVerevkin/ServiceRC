// web
const char webpageCode[]=
R"=====(
<!DOCTYPE html>
<html>
<!--------------------------- C S S -------------------------------->
<head>
    <meta charset="utf-8" />
    <title>LED Control</title>
    <style>
        html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}
        body{margin-top: 50px;} 
        h1 {color: #444444;margin: 50px auto 30px;} 
        h3 {color: #444444;margin-bottom: 5px;}
        .range-volt { width: 300px; margin-bottom: 30px; margin-top: 30px}
        .button {display: block; width: 160px; background-color:#1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}
        .button-on {background-color: #1abc9c;}
        .button-on:active {background-color: #16a085;}
        .button-off {background-color: #34495e;}
        .button-off:active {background-color: #2c3e50;}
        p{font-size: 16px;color: #888;margin-bottom: 5px;}
    </style>
</head>
<!--------------------------- H T M L ------------------------------>
<body>
<form name="control">
    <h1> Нагрузка подсветки ТВ </h1>
    <h3> Текущие значения  </h3>
    <p> Напряжение: <output name="volt">450</output> В _ _ Ток: <output name="curent">550</output> А</p>
    <h3>Настройка напряжения</h3>
    <p>(напряжение для тока 300мА)</p>
    <output font-size:18px; id="text-setvolt">140</output> В<br>
    <input type="range" id="id-range-setvolt" class="range-volt" oninput="rangeInput()" min="1" max="6" value="6" />
    <button id="id-btnOnOff" class="button button-off" onclick="OnOff()">Выкл.</button>
    <p>--------------------------------</p>
    <a href="/settings">...настройка сети wifi...</a>
</form>
<!--------------------------- JavaScript --------------------------->
<script>
    var setVolt = document.getElementById("id-range-setvolt");
    var textVolt = document.getElementById("text-setvolt");
    var btnOnOff = document.getElementById("id-btnOnOff");
    
    function rangeInput(){
        if(btnOnOff.textContent === "Выкл."){
            switch(parseInt(setVolt.value)){
                case 1: textVolt.textContent = "40"; break;
                case 2: textVolt.textContent = "60"; break;
                case 3: textVolt.textContent = "80"; break;
                case 4: textVolt.textContent = "100"; break;
                case 5: textVolt.textContent = "120"; break;
                case 6: textVolt.textContent = "140"; break;
            }
        }
        else{
            switch(parseInt(textVolt.textContent)){
                case 40: setVolt.value =  1; break;
                case 60: setVolt.value =  2; break;
                case 80: setVolt.value =  3; break;
                case 100: setVolt.value = 4; break;
                case 120: setVolt.value = 5; break;
                case 140: setVolt.value = 6; break;
            }
        }
        console.log("range="+setVolt.value);
    }
   
    function OnOff(){
        event.preventDefault();
        if(btnOnOff.textContent === "Выкл."){
            btnOnOff.textContent = "Вкл.";
            btnOnOff.style.background = "#1abc9c";
            fetch('/send?' + new URLSearchParams({ volt: setVolt.value }))
        }
        else{
            btnOnOff.textContent = "Выкл.";
            btnOnOff.style.background = "#34495e";
            fetch('/send?' + new URLSearchParams({ volt: 0 }))
        }
        console.log("btnOnOff");
    }
</script>
</body>
</html>

)=====";