#include <Arduino.h>

const byte LED_PIN_OUT = 3;
const byte LED_PIN_IN = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN_OUT, OUTPUT);
  pinMode(LED_PIN_IN, INPUT);
}

void loop() {
  digitalWrite(LED_PIN_OUT, !digitalRead(LED_PIN_IN));   // turn the LED on
}