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

	_config *iconfig = (_config *)malloc(sizeof(_config));
	memset(iconfig, 0, sizeof(_config));
	if(iconfig == NULL){
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	iconfig->pentries = (_list *)malloc(sizeof(_list ));
	if(iconfig->pentries == NULL){
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	if((iconfig->fp = fopen(apath, "r")) == NULL){
		destruct_config(iconfig);
		perror("Can't open config file for reading");
		exit(EXIT_FAILURE);
	}

	iconfig->pget_config = &get_config;
	return iconfig;
}
void destruct_config(_config *apconfig){

	if(fclose(apconfig->fp) != 0x0){
		perror("Unable to close config file");
		exit(EXIT_FAILURE);
		free(apconfig);
	}
	free(apconfig);

}
char *get_config(char *key){


	return NULL;
}

