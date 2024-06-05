#include "process.h"

void Process::printData()
{
  // Humidity
  Serial.print("humidity: ");
  Serial.print(processDataToSend[0]);
  Serial.print("\n");

  // Temperature
  Serial.print("temperature: ");
  Serial.print(processDataToSend[1]);
  Serial.print("\n");

  // Proximity
  Serial.print("proximity: ");
  Serial.print(processDataToSend[2]);
  Serial.print("\n");

  // Ambient
  Serial.print("ambient: ");
  Serial.print(processDataToSend[3]);
  Serial.print("\n");

  // Colour
  Serial.print("color: ");
  Serial.print(processDataToSend[4]);
  Serial.print("\n");

  // Gesture
  Serial.print("gesture: ");
  Serial.print(processDataToSend[5]);
  Serial.print("\n");
}

void Process::collectData(dataPack_t &dataPack)
{

  static char *humidityConversion[] = {"Dry", "Moist", "Wet"};
  static char *temperatureConversion[] = {"Cold", "Average Temperture", "Hot Temperature"};
  static char *colorConversion[] = {"Red", "Green", "Blue"};
  static char *ambientConversion[] = {"Dark", "Neutral Ambience", "Light"};
  static char *gestureConversion[] = {"None", "Up", "Down", "Left", "Right"};
  static char *proximityConversion[] = {"Close", "Middle distance", "Furthest"};

  setDataString(humidityConversion, dataPack.humidityData, 0, 40, 60);
  setDataString(temperatureConversion, dataPack.tempratureData, 1, 18, 23);
  setDataString(proximityConversion, dataPack.proximityData, 2, 75, 150);
  setDataString(ambientConversion, dataPack.colorData[3], 3, 200, 1200);

  if (dataPack.colorData[0] > dataPack.colorData[1] &&
      dataPack.colorData[0] > dataPack.colorData[2])
  {
    processDataToSend[4] = colorConversion[0];
  }
  else if (dataPack.colorData[1] > dataPack.colorData[0] &&
           dataPack.colorData[1] > dataPack.colorData[2])
  {
    processDataToSend[4] = colorConversion[1];
  }
  else
  {
    processDataToSend[4] = colorConversion[2];
  }

  processDataToSend[5] = gestureConversion[dataPack.gestureData + 1];
}

void Process::setDataString(char **values, float reading, byte index,
                            uint16_t minThreshold, uint16_t maxThreshold)
{
  if (reading < minThreshold)
  {
    processDataToSend[index] = values[0];
  }
  else if (reading >= minThreshold && reading <= maxThreshold)
  {
    processDataToSend[index] = values[1];
  }
  else if (reading > maxThreshold)
  {
    processDataToSend[index] = values[2];
  }
}
