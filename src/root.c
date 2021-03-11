//
// Created by iskandar on 3/10/21.
//

#include "root.h"

_root * init_root(void){

    _root *iroot = new(0x1, struct root_);
    if(iroot == NULL){
        eeprint("Memory allocation failed");
    }
    return iroot;
}

int detectI2C(_config *apconfig, _root *aproot){
    int i2caddr = atoi(apconfig->pf_get_config("i2caddr"));
    aproot->fd = wiringPiI2CSetup(i2caddr);
    if(aproot->fd < 0){
        eeprint("I2C address error");
    } else{
        if(wiringPiI2CWrite(aproot->fd, 0x0) < 0x0){
            eeprint("No device found at given address");
        }
    }
    return 1;
}