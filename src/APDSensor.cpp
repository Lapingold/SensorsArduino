#include <Arduino_APDS9960.h>
#include "APDSensor.h"

void APDSensor::setUpAPDS()
{
  if (!APDS.begin())
  {
    Serial.println("Failed to initialize device, please check your wiring.");
  }
  else
  {
    Serial.println("Device initialized!");
  }

  gestures = GESTURE_NONE;
  last_gesture_update = 0;
}

void APDSensor::readAPDS()
{
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
    int currentGestures = APDS.readGesture();
    if (currentGestures != GESTURE_NONE)
    {
      gestures = currentGestures;

      last_gesture_update = millis();
    }
  }
  if (millis() - last_gesture_update > 1000) {
    gestures = GESTURE_NONE;
  }

  if (APDS.proximityAvailable())
  {
    proximity = APDS.readProximity();
  }
}

void APDSensor::printData()
{
  Serial.print("Time gone by (ms) ");
  Serial.println(millis());

  Serial.print("R: ");
  Serial.print(r);
  Serial.print(" G: ");
  Serial.print(g);
  Serial.print(" B: ");
  Serial.print(b);
  Serial.print(" A: ");
  Serial.println(a);
  Serial.print("Latest gesture change (");
  Serial.print(millis() - last_gesture_update);
  Serial.print("ms ago) was ");

  if (gestures == GESTURE_UP)
    Serial.println("UP");
  else if (gestures == GESTURE_DOWN)
    Serial.println("DOWN");
  else if (gestures == GESTURE_LEFT)
    Serial.println("LEFT");
  else if (gestures == GESTURE_RIGHT)
    Serial.println("RIGHT");
  else
    Serial.println("NONE");

  Serial.print("Proximity: \t");
  Serial.print(proximity);
}

void APDSensor::collectData(dataPack_t &dataPack)
{
  for (size_t i = 0; i < sizeof(colors) / sizeof(uint16_t); i++)
  {
    dataPack.colorData[i] = colors[i];
  }

  dataPack.gestureData = gestures;
  dataPack.proximityData = proximity;
}
