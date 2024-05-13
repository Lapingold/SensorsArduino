#include "baseSensor.h"
#include <Arduino.h>

#include <Arduino_APDS9960.h>

class APDSensor : public BaseSensor
{
private:

        int r, g ,b ,a;
        uint16_t colors[4];
        uint8_t gestures;
        uint32_t last_gesture_update;
        int proximity;

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
