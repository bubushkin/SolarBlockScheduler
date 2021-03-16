/*
 * config.c
 *
 *  Created on: Feb 25, 2021
 *      Author: iskandar
 */

#include "config.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util.h"

_config * init_config(char *apath){

	_config *iconfig = new(0x1, _config);
	if(iconfig == NULL){
		eeprint("Malloc failed");
		exit(EXIT_FAILURE);
	}

	if((iconfig->fp = fopen(apath, "r")) == NULL){
		destruct_config(iconfig);
		eeprint("Can't open config file for reading");
		exit(EXIT_FAILURE);
	}

	iconfig->ientries = init_list();

	iconfig->pf_get_config = &get_config;
	iconfig->pf_parse_entries = &parse_entries;
	iconfig->pf_parse_entries(iconfig);

	return iconfig;
}

void parse_entries(struct config_ *apconfig){

	char line[MAXLEN] = {0};
	char *buffer[2];
	while(fgets(line, MAXLEN, apconfig->fp)){
		buffer[0] = new(128, char);
		buffer[1] = new(128, char);
		split(line, '=', buffer);
        _entry *p = apconfig->ientries->pf_init_entry(buffer[0], buffer[1]);
        apconfig->ientries->pf_add(apconfig->ientries, p);
        free(buffer[0]);
        free(buffer[1]);
	}

}

void destruct_config(_config *apconfig){

	if(fclose(apconfig->fp) != 0x0){
        free(apconfig);
		eeprint("Unable to close config file");
	}

	destruct_list(apconfig->ientries);
	apconfig->pf_init_entry = NULL;
	apconfig->pf_parse_entries = NULL;
	apconfig->pf_get_config = NULL;
	free(apconfig);
}

char *get_config(struct config_ *apconfig, char *apkey){

	_entry *paux = apconfig->ientries->pentry;
	while(paux != NULL){
		if(strcmp(paux->key, apkey) == 0){
			return paux->value;
		}
		paux = paux->pnext;
	}
	return NULL;
}