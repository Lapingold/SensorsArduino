#include <Arduino.h>

class BaseSensor {

private:

typedef struct _dataPack{
    float humidityData;
    float tempratureData;
    int colorData;
    int gestureData;
    unsigned char proximityData;
} dataPack;

public:

// read sensor
virtual void collectData();
// print data
virtual void printData();
// save data in a object
virtual char* sendData();
};