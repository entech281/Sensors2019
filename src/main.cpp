#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_MCP23017.h"

const byte LED_PIN_OUT = 3;
const byte LED_PIN_IN = 2;

Adafruit_MCP23017 mcp;

void setup() {


  mcp.begin();      // use default address 0

  mcp.pinMode(0, INPUT);
  mcp.pullUp(0, HIGH);  // turn on a 100K pullup internally

  pinMode(13, OUTPUT);  // use the p13 LED as debugging


}

void loop() {
  digitalWrite(13, mcp.digitalRead(0));
}
