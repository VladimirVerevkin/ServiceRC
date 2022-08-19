//#include <Arduino.h>

#include "main.h"

/* Установика SSID и пароль wifi сети  в режиме АР(Access Point)-точка доступа */
const char* ssidAP = "ServiceRC";  // SSID
const char* passwordAP = "123456789"; // пароль

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(50);
  Serial.println("Start esp");
}

void loop() {
  // put your main code here, to run repeatedly:
}