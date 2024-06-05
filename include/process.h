#include "baseSensor.h"
#include <Arduino.h>

class Process: public BaseSensor{
    private:
    char* processDataToSend[6];

    public:
    void printData() override;          // Debug
    void collectData(dataPack_t &dataPack) override;
    void processData();
    void setDataString(char** values, float reading, byte index, uint16_t minThreshold, uint16_t maxThreshold);
};