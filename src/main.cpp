#include <Arduino.h>
#include <Wire.h>

const byte sdaPin = 7;
const byte sclPin = 6;

void sendData(){
  uint8_t data = 0;
  for(int i = 0; i < 8; i++)
    data |= ( digitalRead( i + 2 ) << i );
  
  Wire.write((byte) data);
}

void setup()
{

  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial){}
  Serial.println("Serial set up");
  
  Wire.begin(1);
  for(int i = 0; i < 8; i++)
    pinMode( i + 2 ,INPUT);
  
  Wire.onRequest(sendData);

}



void loop() { }