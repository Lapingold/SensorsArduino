#include <Arduino.h>
#include "DHTSensor.h"
#include "APDSensor.h"
#include <Adafruit_APDS9960.h>


//DHTSensor dhtSensor;
APDSensor apdSensor;

void setup()
{
  Serial.begin(9600);
  //dhtSensor.setUpDHT(2); 
   if (!APDS.begin())
   {
    Serial.println("Error failed to innitialize APDSensor."); 
   }
   APDS.enableProximity(true);
   APDS.enableGesture(true);
   APDS.enableProximity(true);
}

void loop()
{
  /*dhtSensor.readDHT(2);
  dhtSensor.collectData();*/

  apdSensor.readAPDS();
  apdSensor.collectData();

  delay(1000);
}

