#include "proccess.h"

void Proccess::printData()
{
  // Serial.print("This is proccessDataToSend: ");
  for (size_t i = 0; i < 6; i++)
  {
    if (i == 5)
    {
      Serial.print("\n");
      Serial.print("gesture: ");
      Serial.println(proccessDataToSend[i]);
    }
    else if (i == 4)
    {
      Serial.print(proccessDataToSend[i]);
    }
    else if (i == 0)
    {
      Serial.print("prompt: ");
      Serial.print(proccessDataToSend[i]);
      Serial.print(",");
    }
    else
    {
      Serial.print(proccessDataToSend[i]);
      Serial.print(",");
    }
  }
}

void Proccess::collectData(dataPack_t &dataPack)
{

  static char *humidityConversion[] = {"Low Humidity", "Humid", "High Humidity"};
  static char *temperatureConversion[] = {"Cold", "Average Temperture", "Hot Temperature"};
  static char *colorConversion[] = {"Red", "Green", "Blue"};
  static char *ambientConversion[] = {"Dark", "Neutral Ambience", "Light"};
  static char *gestureConversion[] = {"None", "Up", "Down", "Left", "Right"};
  static char *proximityConversion[] = {"Close", "Middle distance", "Furthest"};

  setDataString(humidityConversion, dataPack.humidityData, 0, 40, 60);
  setDataString(temperatureConversion, dataPack.tempratureData, 1, 18, 23);
  setDataString(proximityConversion, dataPack.proximityData, 2, 75, 150);
  setDataString(ambientConversion, dataPack.colorData[3], 3, 200, 1200);

  if (dataPack.colorData[0] > dataPack.colorData[1] && dataPack.colorData[0] > dataPack.colorData[2])
  {
    proccessDataToSend[4] = colorConversion[0];
  }
  else if (dataPack.colorData[1] > dataPack.colorData[0] && dataPack.colorData[1] > dataPack.colorData[2])
  {
    proccessDataToSend[4] = colorConversion[1];
  }
  else
  {
    proccessDataToSend[4] = colorConversion[2];
  }

  proccessDataToSend[5] = gestureConversion[dataPack.gestureData + 1];
}

void Proccess::setDataString(char **values, float reading, byte index, uint16_t minTreshold, uint16_t maxThreshold)
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
