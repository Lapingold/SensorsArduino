#include "DHTSensor.h"

#define DHTTYPE DHT11
#define DHT_SENSOR_TYPE DHT11

DHT DHTSensor::setUpDHT(byte pin)
{
    static const int DHT_SENSOR_PIN = pin;
    DHT dht(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
    return dht;
}

void DHTSensor::readDHT(byte pin)
{
    DHT dht = setUpDHT(pin);
    dht.begin();

    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    printData();
}

void DHTSensor::printData()
{
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("Humidity: ");
    Serial.println(humidity);
}

void DHTSensor::collectData() {
    dataPack.tempratureData = temperature;
    dataPack.humidityData = humidity;
    Serial.println("Data is collected in the data pack");
}