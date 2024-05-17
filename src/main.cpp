#include <Arduino.h>
#include "DHTSensor.h"
#include "APDSensor.h"
#include "proccess.h"

DHTSensor dhtSensor;
APDSensor apdSensor;
Proccess proccess;
BaseSensor::dataPack_t dataPack;

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

    dhtSensor.collectData(dataPack);
    apdSensor.collectData(dataPack);
    proccess.collectData(dataPack);
    proccess.printData();
    // apdSensor.printData();
    // Serial.println("-----------------");
    start = now;
  }

  apdSensor.readAPDS();
}
