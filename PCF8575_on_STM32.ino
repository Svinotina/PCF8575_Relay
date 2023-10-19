#include "Arduino.h"
#include "PCF8575.h"  // https://github.com/xreef/PCF8575_library

// Set i2c address
PCF8575 pcf8575(0x20);

void setup()
{
  Serial.begin(9600);

  // Set pinMode to OUTPUT
  for(int i=0;i<16;i++) {
    pcf8575.pinMode(i, OUTPUT);
  }
  for(int i=0;i<16;i++) {
	  pcf8575.digitalWrite(i, HIGH);
  }

  pcf8575.begin();
}

void loop()
{
  static int pin = 0;
  pcf8575.digitalWrite(pin, LOW);
  delay(1000);
  // pcf8575.digitalWrite(pin, HIGH);
  // delay(1000);
  pin++;
  if (pin > 15) pin = 0;
}