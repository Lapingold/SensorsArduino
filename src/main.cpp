#include <Arduino.h>
#include "DHTSensor.h"
#include "APDSensor.h"

//DHTSensor dhtSensor;
APDSensor apdSensor;

void setup()
{
  Serial.begin(115200);
  //dhtSensor.setUpDHT(2);
  apdSensor.setUpAPDS();
  
}

void loop()
{
  /*dhtSensor.readDHT(2);
  dhtSensor.collectData();*/

  apdSensor.readAPDS();
  apdSensor.printData();

  delay(1000);
}

