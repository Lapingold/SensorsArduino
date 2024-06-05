#include "proccess.h"

void Proccess::printData()
{
  // prompt
  Serial.print("prompt: ");

  // Humidity
  Serial.print(proccessDataToSend[0]);
  Serial.print(",");

  // Temperature
  Serial.print(proccessDataToSend[1]);
  Serial.print(",");

  // Proximity
  Serial.print(proccessDataToSend[2]);
  Serial.print(",");

  // Ambient
  Serial.print(proccessDataToSend[3]);
  Serial.print(",");

  // Colour
  Serial.print(proccessDataToSend[4]);
  Serial.print("\n");

  // Gesture
  Serial.print("gesture: ");
  Serial.print(proccessDataToSend[5]);
  Serial.print("\n");
}

void Proccess::collectData(dataPack_t &dataPack)
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
    proccessDataToSend[4] = colorConversion[0];
  }
  else if (dataPack.colorData[1] > dataPack.colorData[0] &&
           dataPack.colorData[1] > dataPack.colorData[2])
  {
    proccessDataToSend[4] = colorConversion[1];
  }
  else
  {
    proccessDataToSend[4] = colorConversion[2];
  }

  proccessDataToSend[5] = gestureConversion[dataPack.gestureData + 1];
}

void Proccess::setDataString(char **values, float reading, byte index,
                             uint16_t minThreshold, uint16_t maxThreshold)
{
  if (reading < minTreshold)
  {
    proccessDataToSend[index] = values[0];
  }
  else if (reading >= minTreshold && reading <= maxThreshold)
  {
    proccessDataToSend[index] = values[1];
  }
  else if (reading > maxThreshold)
  {
    proccessDataToSend[index] = values[2];
  }
}
