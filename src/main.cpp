#include <Arduino.h>
#include "DHTSensor.h"
#include "APDSensor.h"
#include "process.h"

DHTSensor dhtSensor;
APDSensor apdSensor;
Process process;
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
    process.collectData(dataPack);
    process.printData();
    // apdSensor.printData();
    // Serial.println("-----------------");
    start = now;
  }

  apdSensor.readAPDS();
}
