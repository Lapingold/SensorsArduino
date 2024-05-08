#include "proccess.h"

void Proccess::printData()
{
  Serial.print("This is proccessDataToSend ");
  Serial.print(proccessDataToSend[0]);
  delay(5000);
}

void Proccess::collectData()
{
  proccessData();
}

char Proccess::proccessData()
{

  static char* humidityConversion[] = {"Low Humidity", "Humid", "High Humidity"};
  static char* temperatureConversion[] = {"Cold", "Average Temperture", "Hot Temperature"};
  static char* colorConversion[] = {"Red", "Green", "Blue",};
  static char* ambientConversion[] = {"Dark", "Neutral Ambience", "Light"};
  static char* gestureConversion[] = {"Left", "Up", "Down", "Right"};
  static char* proximityConversion[] = {"Close", "Middle distance", "Furthest"};

  if (dataPack.humidityData < 40)
  {
    proccessDataToSend[0] = humidityConversion[0];
  }
  else if (dataPack.humidityData >= 40 && dataPack.humidityData <= 60)
  {
    proccessDataToSend[0] = humidityConversion[1];
  }
  else if (dataPack.humidityData > 60)
  {
    proccessDataToSend[0] = humidityConversion[2];
  }
  return 0;
}
