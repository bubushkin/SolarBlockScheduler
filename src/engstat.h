/*
 * engstat.h
 *
 *  Created on: Mar 8, 2021
 *      Author: iskandar
 */

#ifndef INCLUDE_ENGSTAT_H_
#define INCLUDE_ENGSTAT_H_

#include <wiringPiI2C.h>
#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <softPwm.h>
#include <math.h>
#include <wiringPiI2C.h>
#include <ads1115.h>
#include <pcf8591.h>

typedef struct engstat_{

    double (*pf_get_voltage)(void);
    double (*pf_get_current)(void);

} _engstat;

_engstat *init_engstat();
void destruct_engstat(_engstat *);

#endif /* INCLUDE_ENGSTAT_H_ */