#include <Arduino.h>

class BaseSensor
{

protected:
    struct _dataPack
    {
        float humidityData = 0;
        float tempratureData = 0;
        int colorData = 0;
        int gestureData = 0;
        unsigned char proximityData = 0;
    } dataPack;

public:
    // read sensor
    virtual void collectData();
    // print data
    virtual void printData();
    // save data in a object
    // virtual char *sendData();
};