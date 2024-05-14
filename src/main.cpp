#include <Arduino.h>
#include "DHTSensor.h"
#include "APDSensor.h"
#include "proccess.h"


DHTSensor dhtSensor;
APDSensor apdSensor;
Proccess proccess;

void setup()
{
  Serial.begin(115200);
  dhtSensor.setUpDHT(2);
  apdSensor.setUpAPDS();
}

void loop()
{
  
  static uint32_t start = millis();
  uint32_t now = millis();

  // Print data once every second
  if (now - start > 1000)
  {
    proccess.printData();
    apdSensor.printData();
    dhtSensor.readDHT();
    dhtSensor.collectData();
    proccess.collectData();
    Serial.println("-----------------");
    start = now;
  }

  apdSensor.readAPDS();
}
