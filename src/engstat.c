//
// Created by iskandar on 3/10/21.
//

#include "engstat.h"

_engstat *init_engstat(){
    _engstat *iengstat = new(1, struct engstat_);
    iengstat->pf_get_current = &current;
    iengstat->pf_get_voltage = &voltage;
    return iengstat;
}
void destruct_engstat(_engstat *apengstat){

    apengstat->pf_get_voltage = NULL;
    apengstat->pf_get_current = NULL;
    free(apengstat);
}

float current(void){

    int value = analogRead(A0);
    float voltage = value * 5.0 / 255;
    float current = (voltage - 2.5) / 0.066;
    return current;
}

float voltage(void){
    int value = analogRead(A0);
    return value * 5.0 / 255;
}
