#ifndef BASESENSOR_H
#define BASESENSOR_H
#include <Arduino.h>
class BaseSensor
{

public:
    struct dataPack_t
    {
        float humidityData = 0;
        float tempratureData = 0;
        uint16_t colorData[4] = {0, 0, 0, 0};
        int8_t gestureData = 0;
        int proximityData = 0;
    };


    // read sensor
    virtual void collectData(dataPack_t &dataPack) = 0;
    // print data
    virtual void printData() = 0;
    // save data in a object
    // virtual char *sendData();
};

#endif /* BASESENSOR_H */