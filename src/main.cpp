#include <Arduino.h>
#include "DHTSensor.h"
#include "APDSensor.h"

DHTSensor dhtSensor;
APDSensor apds;

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
    apds.printData();
    dhtSensor.readDHT(2);
    dhtSensor.collectData();
    Serial.println("-----------------");
    start = now;
  }

  apds.readAPDS();
}
