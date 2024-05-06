#ifndef BASESENSOR_H
#define BASESENSOR_H
#include <Arduino.h>
class BaseSensor
{

protected:
    struct _dataPack
    {
        float humidityData = 0;
        float tempratureData = 0;
        uint16_t colorData[4] = {0, 0, 0, 0};
        uint8_t gestureData = 0;
        int proximityData = 0;
    } dataPack;

public:
    // read sensor
    virtual void collectData();
    // print data
    virtual void printData();
    // save data in a object
    // virtual char *sendData();
};

#endif /* BASESENSOR_H */