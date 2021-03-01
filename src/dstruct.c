/*
 * dstruct.c
 *
 *  Created on: Feb 28, 2021
 *      Author: iskandar
 */

#include "include/dstruct.h"
#include "include/util.h"

_list *init_list(){

	_list *ilist = new(0x1, _list);
	if(ilist == NULL){
		eeprint("Malloc failed");
	}

	ilist->pf_add = &add_entry;
	ilist->pf_remove = &remove_entry;
	ilist->pf_get = &get;
	ilist->pf_init_entry = &init_entry;

	return ilist;
}

void destruct_list(_list *);

_entry *init_entry(char *apkey, char *apval){

    _entry *ietr = new(0x1, _entry);
	if(ietr == NULL){
		eeprint("Malloc failed");
	}

	ietr->key = new(0x1, char);
	if(ietr->key == NULL){
		eeprint("Malloc failed");
	}

	ietr->value = new(0x1, char);
	if(ietr->value == NULL){
		eeprint("Malloc failed");
	}
	if(strncpy(ietr->key, apkey, strlen(apkey)) == NULL){
		eeprint("Unable to generate config entry");
	}

	if(strncpy(ietr->value, apval, strlen(apval)) == NULL){
		eeprint("Unable to generate config entry");
	}
	return ietr;
}

void add_entry(struct list_ *aplist, _entry *apentry){

	if(aplist->pentry == NULL){
		aplist->pentry = apentry;
	} else{
		_entry *paux = aplist->pentry;
		while(paux->pnext != NULL){
			paux = paux->pnext;
		}
		paux->pnext = apentry;
	}
	aplist->size++;
}


void remove_entry(struct list_ *aplist, char *apkey){

}
_entry *get(_entry *apentry, char *apkey){

}