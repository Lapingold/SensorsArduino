#include "baseSensor.h"
#include <Arduino.h>

class Proccess: public BaseSensor{
    private:
    char proccessDataToSend[];

    public:
    void printData() override;          // Debug
    void collectData() override;
    char proccessData(); 

};