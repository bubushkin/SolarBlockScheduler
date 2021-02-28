/*
 * config.h
 *
 *  Created on: Feb 25, 2021
 *      Author: iskandar
 */

#ifndef INCLUDE_CONFIG_H_
#define INCLUDE_CONFIG_H_
#include <stdio.h>
#include "include/dstruct.h"


typedef struct
{

	FILE *fp;
	_list *pentries;

	char *(*pget_config)(char *);
	void (*pinit_entry)();

} _config;

_config * init_config(char *);
void destruct_config(_config *);
char *get_config(char *);

_entry *init_entry();

#endif /* INCLUDE_CONFIG_H_ */

