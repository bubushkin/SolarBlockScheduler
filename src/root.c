//
// Created by iskandar on 3/10/21.
//

#include "root.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <pcf8591.h>

_root * init_root(void){

    _root *iroot = new(0x1, struct root_);
    if(iroot == NULL){
        eeprint("Memory allocation failed");
    }
    return iroot;
}

void destruct_root(_root *aproot){
    aproot->fd = NULL;
    aproot->current_charge = 0x0;
    aproot->current_rn = NULL;
    free(aproot);
}

int detectI2C(_config *apconfig, _root *aproot){
    int i2caddr = (int)strtol(apconfig->pf_get_config(apconfig, "i2caddr"), NULL, 0);
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
