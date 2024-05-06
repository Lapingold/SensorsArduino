#include "baseSensor.h"
#include <Arduino.h>

#include <Adafruit_APDS9960.h>

class APDSensor : public BaseSensor
{
private:

        uint16_t r, g ,b ,a;
        uint16_t colors[4];
        uint8_t gestures;
        int proximity;
        Adafruit_APDS9960 APDS;

public:
    APDSensor()
    {
         r = 0;
         g = 0;
         b = 0;
         a = 0;
         colors[0] = 0;
         colors[1] = 0;
         colors[2] = 0;
         colors[3] = 0;
         gestures = 0;
         proximity = 0;
    }

    void setUpAPDS();
    void readAPDS();
    void printData() override;
    void collectData() override;
    
};
