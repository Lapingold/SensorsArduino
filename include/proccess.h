#include "baseSensor.h"
#include <Arduino.h>

class Proccess: public BaseSensor{
    private:
    char* proccessDataToSend[6];

    public:
    void printData() override;          // Debug
    void collectData() override;
    void proccessData();
    void setDataString(char** values, float reading, byte index, uint16_t minTreshold, uint16_t maxThreshold);
};