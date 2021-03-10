/*
 * root.h
 *
 *  Created on: Mar 8, 2021
 *      Author: iskandar
 */

#ifndef INCLUDE_ROOT_H_
#define INCLUDE_ROOT_H_

#include <pthread.h>

#include "runlevel.h"



#define GREEN_RN 0xA
#define YELLOW_RN 0xB
#define RED_RN 0xC
#define BLACK_RN 0xD
#define BASE 120

struct root_{
	int current_rn = 0xFF;
	unsigned float current_charge = 0x0;


};

void spawn_system();
void spawn_user();

void *spawn(void);



#endif /* INCLUDE_ROOT_H_ */
