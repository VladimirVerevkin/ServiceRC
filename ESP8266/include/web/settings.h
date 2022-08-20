const char websettings[]=
R"=====(
<!DOCTYPE html>
<html>
<!--------------------------- C S S -------------------------------->
<head>
    <meta charset="utf-8" />
    <title>LED Control Settings</title>
    <style>
        html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}
        body{margin-top: 50px;} 
        h1 {color: #444444;margin: 50px auto 30px;} 
        h3 {color: #444444;margin-bottom: 5px;}
        .range-volt { width: 300px; margin-bottom: 30px; margin-top: 30px}
        .button {display: block;width: 200px;background-color: #1abc9c;border: none;color: white;padding: 20px 20px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}
        .button-on {background-color: #1abc9c;}
        .button-on:active {background-color: #16a085;}
        .button-off {background-color: #34495e;}
        .button-off:active {background-color: #2c3e50;}
        p {font-size: 16px;color: #888; margin-bottom: 20px; margin-top: 20px;} 
    </style>
</head>
<!--------------------------- H T M L ------------------------------>
<body>
<form name="control">
    <h1> Настройка WiFi сети </h1>
    <input type="checkbox" id="checkConnect" onchange="functionCheckConnect()" value="off"><label>Подключиться к существующей Wi-Fi сети</label>
    <p><label>Имя сети: </label><input id="inputSSID" disabled="disabled"></input></p>
    <p><label>Пароль: </label><input id="inputPwd" disabled="disabled"></input></p>
    <p>----------------------------------------------------------------------</p>
    <button id="btnSaveID" class="button button-off" onclick="functionSave()" disabled="disabled">Сохранить</button>
    <a href="/reset">...Перезагрузка...</a>
</form>
<!--------------------------- JavaScript --------------------------->
<script>
    var checkConnect = document.getElementById("checkConnect");
    var inputSSID = document.getElementById("inputSSID");
    var inputPwd = document.getElementById("inputPwd");
    var btnSaveID = document.getElementById("btnSaveID");
    
    function functionCheckConnect(){
        if(checkConnect.value === "off"){
            checkConnect.value = "on";
            inputSSID.removeAttribute("disabled");
            inputPwd.removeAttribute("disabled");
            btnSaveID.removeAttribute("disabled");
            btnSaveID.style.background = "#1abc9c";
        }
        else{
            checkConnect.value = "off";
            inputSSID.setAttribute("disabled", "disabled");
            inputPwd.setAttribute("disabled", "disabled");
            btnSaveID.setAttribute("disabled", "disabled");
            btnSaveID.style.background = "#34495e";
        }
        console.log("functionCheckConnect() "+checkConnect.value);
    }
    function functionSave(){
        fetch('/settings?' + new URLSearchParams({ ssid: inputSSID.value, pwd: inputPwd.value }));
    }
</script>
</body>
</html>
)=====";