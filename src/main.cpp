#include <Arduino.h>
#include "DHTSensor.h"
#include "APDSensor.h"
#include "proccess.h"


DHTSensor dhtSensor;
APDSensor apds;
Proccess proccess;

void setup()
{
  Serial.begin(115200);
  dhtSensor.setUpDHT(2);
  apds.setUpAPDS();
}

void loop()
{
  
  static uint32_t start = millis();
  uint32_t now = millis();

  // Print data once every second
  if (now - start > 1000)
  {
    proccess.printData();
    apds.printData();
    dhtSensor.readDHT(2);
    dhtSensor.collectData();
    proccess.collectData();
    Serial.println("-----------------");
    start = now;
  }

  apds.readAPDS();
}
