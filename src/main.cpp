#include <Arduino.h>
#include <Wire.h>

#define SCL_PIN 6
#define SDA_PIN 7
#define SCL_PORT PORTD
#define SDA_PORT PORTC




const byte sdaPin = 7;
const byte sclPin = 6;


#define DISTANCE_BETWEEN_SENSORS 2
#define SENSOR_AREA_WIDTH        4
#define RIO_I2C_PORT             8




void sendData(){
  uint8_t data = 0;
  for(int i = 0; i < 8; i++){
    data |= ( digitalRead( i + 2 ) << i );
  }
  Wire.write((byte) data);
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
  for(int i = 0; i < 8; i++)
    pinMode( i + 2 ,INPUT);
  

  Wire.onRequest(sendData);
}



void loop()
{
  

}