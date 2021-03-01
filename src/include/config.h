/*
 * config.h
 *
 *  Created on: Feb 25, 2021
 *      Author: iskandar
 */

#ifndef INCLUDE_CONFIG_H_
#define INCLUDE_CONFIG_H_
#include <stdio.h>
#include "dstruct.h"
#include "util.h"

typedef struct config_{

	FILE *fp;
	_list *ientries;

	char *(*pf_get_config)(struct config_ *, char *);
	void (*pf_init_entry)();
	void (*pf_parse_entries)(struct config_ *);

} _config;

_config * init_config(char *);
void destruct_config(_config *);
char *get_config(struct config_ *, char *);
char **split(char *, char);

void parse_entries(struct config_ *);

#endif /* INCLUDE_CONFIG_H_ */
