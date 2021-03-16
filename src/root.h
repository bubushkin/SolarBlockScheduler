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
#include "config.h"

#define GREEN_RN 0xA
#define YELLOW_RN 0xB
#define RED_RN 0xC
#define BLACK_RN 0xD
#define BASE 120

typedef struct root_{
    int fd;
	int current_rn;
	double current_charge;


} _root;

_root * init_root(void);

void global_init(_config *, _root *);

int detectI2C(_config *, _root *);

#endif /* INCLUDE_ROOT_H_ */
