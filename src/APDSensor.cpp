#include <Arduino_APDS9960.h>
#include "APDSensor.h"

/*APDS9960 APDSensor::setUpAPDS()
{
    APDS9960 sensor;
    return 
}*/


void APDSensor::readAPDS()
{
  
   
   //APDS.begin();
   if (APDS.colorAvailable())
   {
   APDS.readColor(r, g, b, a);
   colors[0] = r;
   colors[1] = g;
   colors[2] = b;
   colors[3] = a;
   }

   if (APDS.gestureAvailable())
   {
     gestures = APDS.readGesture();
   }

   if (APDS.proximityAvailable())
   {
     proximity = APDS.readProximity();
   }

   printData();

   APDS.end();
}

void APDSensor::printData()
{
    Serial.print("R = ");
    Serial.print(r);
    Serial.println("G = ");
    Serial.print(g);
    Serial.print("B = ");
    Serial.print(b);
    Serial.print("A = ");
    Serial.print(a);
    Serial.println("Gesture = ");
    Serial.print(gestures);
    Serial.println("Proximity = ");
    Serial.print(proximity);
}

void APDSensor::collectData() {
    for (size_t i = 0; i < sizeof(colors)/sizeof(uint16_t); i++)
    {
      dataPack.colorData[i] = colors[i];
    }

    dataPack.gestureData=gestures;
    dataPack.proximityData=proximity;

    Serial.println("Data is collected in the data pack");
}
