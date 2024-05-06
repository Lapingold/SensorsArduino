#include "baseSensor.h"
#include <Arduino.h>



class APDSensor : public BaseSensor
{
private:

        uint16_t r;
        uint16_t g;
        uint16_t b;
        uint16_t a;
        uint16_t colors[4];
        int gestures;
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

    class APDS9960 setUpAPDS();
    void readAPDS();
    void printData() override;
    void collectData() override;

    
};
