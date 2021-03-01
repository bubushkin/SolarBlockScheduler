/*
 * config.c
 *
 *  Created on: Feb 25, 2021
 *      Author: iskandar
 */


#include "include/config.h"
#include <stdlib.h>
#include <stdio.h>

_config * init_config(char *apath){

	_config *iconfig = (_config *)calloc(0x1, sizeof(_config));
	if(iconfig == NULL){
		eeprint("Malloc failed");
		exit(EXIT_FAILURE);
	}

	if((iconfig->fp = fopen(apath, "r")) == NULL){
		destruct_config(iconfig);
		eeprint("Can't open config file for reading");
		exit(EXIT_FAILURE);
	}

	iconfig->pentries = init_list();
	_entry *p = iconfig->pentries->pf_init_entry("log", "/etc/log/sbs.log");

	iconfig->pentries->pf_add(iconfig->pentries, p);

	iconfig->pf_get_config = &get_config;
	return iconfig;
}

_entry * parse_entries(struct config_ *apconfig){

	char line[MAXLEN] = {0};
	while(fgets(line, MAXLEN, apconfig->fp)){

	}
}

void destruct_config(_config *apconfig){

	if(fclose(apconfig->fp) != 0x0){
		eeprint("Unable to close config file");
		exit(EXIT_FAILURE);
		free(apconfig);
	}

	free(apconfig);

}

char *get_config(struct config_ *apconfig, char *apkey){

	_entry *paux = apconfig->pentries->pentry;
	while(paux != NULL){
		if(strcmp(paux->key, apkey)){
			return paux->value;
		}
		paux = paux->pnext;
	}
	return NULL;
}

