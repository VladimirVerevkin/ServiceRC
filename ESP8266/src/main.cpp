//#include <Arduino.h>
#include "main.h"

/* Установите здесь свои SSID и пароль */
//const char* ssid = "Keenetic-6621";  // SSID
//const char* password = "DL4x4fBh"; // пароль

/* Установка SSID и пароль сети в AP(Access Point) режиме - точка доступа*/
const char* ssidAP = "ServiceRC";  // SSID
const char* passwordAP = "123456789"; // пароль

/* Настройки IP адреса */
IPAddress local_ip(192,168,4,22);
IPAddress gateway(192,168,4,22);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

void handle_OnConnect();
void handle_settings();
void handle_send();
void handle_reset();
void handle_NotFound();

void setup() {
  // put your setup code here, to run once:
  uint8_t timeconnect=0; //переменная для счета попыток подключения
  Serial.begin(115200);
  delay(500);
  
  // инициализация доступа к памяти для хранения данных(эн-память)
  initEEPROM();
  String ssid = readEEPROM(addressIDwifi);
  String password = readEEPROM(addressPASwifi);
  
  Serial.println("Connecting to ");
  Serial.println(ssid);
  
   // подключиться к локальной wifi сети (в режиме API - )
  WiFi.begin(ssid, password);
  
  // проверить, подключился ли wi-fi модуль к wi-fi сети, если нет создаем сеть для настройки
  while ((WiFi.status() != WL_CONNECTED) && (timeconnect<=20)) 
  {
    delay(1000);
    timeconnect += 1;
    Serial.print(".");
  }
  if (timeconnect > 20){
    Serial.println("\nWiFi not connected!");
    Serial.println("Access Point mode:");
    Serial.println("WiFi: ServiceRC password: 123456789");
    WiFi.mode(WIFI_AP); 
    WiFi.softAP(ssidAP, passwordAP);
    WiFi.softAPConfig(local_ip, gateway, subnet);
    delay(100);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
  }
  else{
    Serial.println("WiFi connected..!");
    Serial.print("Got IP: ");  
    Serial.println(WiFi.localIP());
  }

  server.on("/", handle_OnConnect);
  //server.on("/send", handle_send);
  server.on("/settings", handle_settings);
  server.on("/reset", handle_reset);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // put your main code here, to run repeatedly:
    server.handleClient(); 
}

void handle_OnConnect(){
  server.send(200,"text/html", websettings);
  //server.send(200,"text/html", webpageCode);
}

void handle_settings()
{
  String wpwd=server.arg("pwd");
  String wid=server.arg("ssid");
  if((wid != "") && (wpwd != "")){
    writeEEPROM(addressPASwifi, wpwd);
    writeEEPROM(addressIDwifi, wid);
    Serial.println("settings.");
  }
  server.send(200,"text/html", websettings);
}

void handle_reset(){
  Serial.println("reset");
  server.send(200,"text/html", webreset);
}

void handle_NotFound()
{
  server.send(404, "text/plain", "Not found");
}