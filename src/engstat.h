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

void charge_level(float *);

#endif /* INCLUDE_ENGSTAT_H_ */
