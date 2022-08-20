#include "nvmemory.h"
// инициализация эн-памяти
void initEEPROM()
{
  EEPROM.begin(512);
}
// запись в эн-память стоки
void writeEEPROM(uint16 address, String data)
{
  // преобразовать String в массив char
  uint8_t datalength;
  datalength = data.length()+1;
  char chardata[datalength];
  data.toCharArray(chardata, datalength); //string to char[]
  EEPROM.put(address, datalength);  //запись в память - байт-длина строки!!
  for(uint8_t i=0;i<datalength;i++)
  {
    EEPROM.put(address+1+i, chardata[i]);  // записать в ячейку памяти addressIDwifi+i значение chardata[i]
  }
  EEPROM.commit();
}
// чтение строки из эн-памяти
String readEEPROM(uint16 address)
{
  String strdata;
  uint8_t strlenght;
  strlenght = EEPROM.read(address); //чтение - длина строки
  char data[strlenght];
  for(uint8_t i=0;i<strlenght;i++)
  {
    data[i]=EEPROM.read(address+1+i);
  }
  strdata = data; //char[] to str
  return strdata;
}