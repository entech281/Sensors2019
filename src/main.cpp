#include <Arduino.h>

//#include "Adafruit_MCP23017.h"
#include <Wire.h>

#define SCL_PIN 6
#define SDA_PIN 7
#define SCL_PORT PORTD
#define SDA_PORT PORTC


#include <SoftI2CMaster.h>

const byte sdaPin = 7;
const byte sclPin = 6;


#define DISTANCE_BETWEEN_SENSORS 2
#define SENSOR_AREA_WIDTH        4
#define RIO_I2C_PORT             8




void sendData(){
  Wire.write((byte) 1);
}

void setup()
{


  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial)
  {
  }
  
  Serial.println("Serial set up");

  
  Wire.begin(1);

  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);

  Wire.onRequest(sendData);
}



void loop()
{
  Serial.print("Value:");
  
  digitalRead(8);
  digitalRead(9);
  digitalRead(10);
  digitalRead(11);



  Serial.println(1);
  
  
  
  delay(100);

}