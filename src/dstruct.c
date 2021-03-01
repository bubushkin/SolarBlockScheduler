/*
 * dstruct.c
 *
 *  Created on: Feb 28, 2021
 *      Author: iskandar
 */

#include "include/dstruct.h"
#include "include/util.h"

_list *init_list(){

	_list *ilist = (_list *)malloc(sizeof(_list));
	if(ilist == NULL){
		eeprint("Malloc failed");
		exit(EXIT_FAILURE);
	}
	memset(ilist, 0, sizeof(_list));

	ilist->pf_add = &add_entry;
	ilist->pf_remove = &remove_entry;
	ilist->pf_get = &get;
	ilist->pf_init_entry = &init_entry;

	return ilist;
}

void destruct_list(_list *);

_entry *init_entry(char *apkey, char *apval){

	_entry *ietr = (_entry *) calloc(0x1, sizeof(_entry));
	if(ietr == NULL){
		eeprint("Malloc failed");
		exit(EXIT_FAILURE);
	}

	ietr->key = (char *) calloc(0x1, strlen(apkey));
	if(ietr->key == NULL){
		eeprint("Malloc failed");

		exit(EXIT_FAILURE);
	}

	ietr->value = (char *) calloc(0x1, strlen(apval));
	if(ietr->value == NULL){
		eeprint("Malloc failed");
		exit(EXIT_FAILURE);
	}
	if(strncpy(ietr->key, apkey, strlen(apkey)) == NULL){
		eeprint("Unable to generate config entry");
		exit(EXIT_FAILURE);
	}

	if(strncpy(ietr->value, apval, strlen(apval)) == NULL){
		eeprint("Unable to generate config entry");
		exit(EXIT_FAILURE);
	}
	return ietr;
}

void add_entry(struct list_ *aplist, _entry *apentry){


	if(aplist->pentry == NULL){
		aplist->pentry = apentry;
	} else{
		_entry *paux = aplist->pentry->pnext;
		while(paux != NULL){
			paux = paux->pnext;
		}
		paux = apentry;
	}
}


void remove_entry(struct list_ *aplist, char *apkey){

}
_entry *get(_entry *apentry, char *apkey){

}
