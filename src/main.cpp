#include <Arduino.h>
#include "DHTSensor.h"

DHTSensor dhtSensor;

void setup()
{
  Serial.begin(9600);
  dhtSensor.setUpDHT(2); 
}

void loop()
{
  dhtSensor.readDHT(2);
  dhtSensor.collectData();
  delay(1000);
}