#include <Adafruit_APDS9960.h>
#include "APDSensor.h"
#include <SPI.h>

void APDSensor::setUpAPDS()
{
  if (!APDS.begin())
  {
    Serial.println("failed to initialize device! Please check your wiring.");
  }
  else
  {
    Serial.println("Device initialized!");
  }

  Serial.println("Enabling sensors");
  APDS.enableProximity(true);
  APDS.enableGesture(true);
  APDS.enableColor(true);
}

void APDSensor::readAPDS()
{

  APDS.getColorData(&r, &g, &b, &a);
  colors[0] = r;
  colors[1] = g;
  colors[2] = b;
  colors[3] = a;

  gestures = APDS.readGesture();
  proximity = APDS.readProximity();
}

void APDSensor::printData()
{
  Serial.println("Trying to print data");

  Serial.print("R: ");
  Serial.print(r);
  Serial.println(" G: ");
  Serial.print(g);
  Serial.print(" B: ");
  Serial.print(b);
  Serial.print(" C: ");
  Serial.println(a);
  Serial.println("Gesture = ");
  Serial.print(gestures);
  Serial.println("Proximity = ");
  Serial.print(proximity);
}

void APDSensor::collectData()
{
  for (size_t i = 0; i < sizeof(colors) / sizeof(uint16_t); i++)
  {
    dataPack.colorData[i] = colors[i];
  }

  dataPack.gestureData = gestures;
  dataPack.proximityData = proximity;

  Serial.println("Data is collected in the data pack");
}
