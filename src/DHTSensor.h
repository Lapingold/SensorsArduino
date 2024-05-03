#include "baseSensor.h"
#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT_U.h>
#include <DHT.h>



class DHTSensor : public BaseSensor
{
private:
    float temperature, humidity;

public:
    DHTSensor()
    {
        temperature = 0;
        humidity = 0;
    }

    class DHT setUpDHT(byte pin);
    void readDHT(byte pin);
    void printData() override;
    void collectData() override;

    
};
