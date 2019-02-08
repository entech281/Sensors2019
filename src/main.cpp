#include <Arduino.h>

#include "Adafruit_MCP23017.h"
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

/*const byte LED_PIN_OUT = ;
const byte LED_PIN_IN = ;
*/
Adafruit_MCP23017 port_expander;

void setup()
{


  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial)
  {
  }
  
  Serial.println("Serial set up");

  port_expander.begin(0);
  Wire.begin();
  Serial.println("IO Expander Initialized");

  port_expander.pinMode(0, INPUT);
  port_expander.pinMode(1, INPUT);
  port_expander.pinMode(2, INPUT);
  port_expander.pinMode(3, INPUT);

  pinMode(2, OUTPUT);
  Serial.println("IO Expander Pins Set");
  //port_expander.pullUp(0, HIGH);
}

void loop()
{
  uint16_t bits = port_expander.readGPIOAB();
  uint16_t indexRight = 0 ;
  for(indexRight = 0; indexRight <= 16; ++indexRight){
     if(!( bits << indexRight )){
       break;
     }
  }
  indexRight --;
  int indexLeft;
  for(indexLeft = 0; indexLeft <= 16; ++indexLeft){
     if(!( bits >> indexLeft )){
       break;
     }
  }
  indexLeft ++;
  indexLeft = indexLeft - 16;

  int offset_from_robot = ( indexRight + indexLeft ) / 2 * DISTANCE_BETWEEN_SENSORS - SENSOR_AREA_WIDTH / 2;
  //Wire.beginTransmission(RIO_I2C_PORT);
  //Wire.write(offset_from_robot);
  //Wire.endTransmission();
  Serial.println(offset_from_robot);

}
