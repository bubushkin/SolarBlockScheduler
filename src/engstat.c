//
// Created by iskandar on 3/10/21.
//

#include "engstat.h"


int detectI2C(int address){
    _fd = wiringPiI2CSetup(address);
    if(_fd < 0){
        printf("Error address: 0x%x \n", address);
        return 0;
    } else{
        if(wiringPiI2CWrite(_fd, 0x0) < 0x0){
            printf("No device found at address 0x%x\n", address);
            return 0;
        } else{
            printf("Found device at address 0x%x\n", address);
            return 1;
        }
    }
}

if(detectI2C(0x48)){
wiringPiSetup();
pcf8591Setup(BASE,0x48);
while(1)
{
int value = analogRead(A0);
float voltage = value * 5.0 / 255;
float current = (voltage - 2.5) / 0.066;
printf("AOUT: %d VOLTAGE: %f CURRENT: %f\n",value, voltage, current);
delay(500);
}
}