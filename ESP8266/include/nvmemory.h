#ifndef NVMEMORY_H_
#define NVMEMORY_H_
//------------------------------------------------
#include <ESP8266WiFi.h>
#include <EEPROM.h>
const uint8_t addressIDwifi = 0;
const uint8_t addressPASwifi = 30;
const uint8_t addressHost = 60;
const uint8_t addressPort = 90;

void initEEPROM(void);
void writeEEPROM(uint16 address, String data);
String readEEPROM(uint16 address);

//------------------------------------------------
#endif /* NVMEMORY_H_ */


