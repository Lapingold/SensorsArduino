#include "baseSensor.h"
#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT_U.h>
#include <DHT.h>


class DHTSensor : public BaseSensor
{
private:
    float temperature, humidity;
    DHT dht;

public:
    DHTSensor():dht(0,0)
    {
        temperature = 0;
        humidity = 0;
    }

    void setUpDHT(byte pin);
    void readDHT();
    void printData() override;
    void collectData(dataPack_t &dataPack) override;

};
