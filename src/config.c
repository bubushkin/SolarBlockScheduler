/*
 * config.c
 *
 *  Created on: Feb 25, 2021
 *      Author: iskandar
 */

#include "include/config.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

	iconfig->ientries = init_list();

	iconfig->pf_get_config = &get_config;
	iconfig->pf_parse_entries = &parse_entries;

	return iconfig;
}

char **split(char *apline, char delim){

    int idx = 0, xdx = 0;
    char c = 0xF;
    char *buffer[2];
    short found = 0;

    if((buffer[0] = new(128, char)) == NULL){
        eeprint("Malloc failed");
    }
    if((buffer[1] = new(128, char)) == NULL){
        eeprint("Malloc failed");
    }

    while(c != NULL){
        c = apline[idx++];
        if(c == delim){
            for(int i = 0; i < idx - 1; i++){
                buffer[0][i] = apline[i];
            }
            found = 1;
            continue;
        }
        if(found){
            buffer[1][xdx++] = c;
        }
    }
    return buffer;
}
_entry * parse_entries(struct config_ *apconfig){

	char line[MAXLEN] = {0};

	while(fgets(line, MAXLEN, apconfig->fp)){

	}
//    _entry *p = iconfig->ientries->pf_init_entry("log", "/etc/log/sbs.log");
//
//    iconfig->ientries->pf_add(iconfig->ientries, p);


	return NULL;
}

void destruct_config(_config *apconfig){

	if(fclose(apconfig->fp) != 0x0){
        free(apconfig);
		eeprint("Unable to close config file");
	}
	free(apconfig);

}

char *get_config(struct config_ *apconfig, char *apkey){

	_entry *paux = apconfig->ientries->pentry;
	while(paux != NULL){
		if(strcmp(paux->key, apkey)){
			return paux->value;
		}
		paux = paux->pnext;
	}
	return NULL;
}

