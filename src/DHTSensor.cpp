#include "DHTSensor.h"

#define DHT_SENSOR_TYPE DHT11

void DHTSensor::setUpDHT(byte pin)
{ 
    DHT dhtTemp(pin, DHT_SENSOR_TYPE);
    dht = dhtTemp;
}

void DHTSensor::readDHT()
{
    dht.begin();

    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    printData();
}

void DHTSensor::printData()
{
    Serial.println();
    Serial.print("Temperature: \t");
    Serial.println(temperature);
    Serial.print("Humidity: \t");
    Serial.print(humidity);
    Serial.println();
}

void DHTSensor::collectData() {
    dataPack.tempratureData = temperature;
    dataPack.humidityData = humidity;
    Serial.println("Data is collected in the data pack");
}