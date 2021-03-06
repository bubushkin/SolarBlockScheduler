/*
 * dstruct.h
 *
 *  Created on: Feb 28, 2021
 *      Author: iskandar
 */

#ifndef INCLUDE_DSTRUCT_H_
#define INCLUDE_DSTRUCT_H_

#include <stdlib.h>
#include <string.h>


typedef struct entry_{
		char *key;
		char *value;
		struct entry_ *pnext;
} _entry;

typedef struct list_{

	_entry *pentry;
	unsigned int size;
	void (*pf_add)(struct list_ *, _entry *);
	_entry *(*pf_init_entry)(char *, char*);

} _list;


_list * init_list();
void destruct_list(_list *);
void add_entry(struct list_ *, _entry *);
void destruct_entries(_entry *);

_entry *get(_entry *, char *);

_entry *init_entry(char *, char *);

#endif /* INCLUDE_DSTRUCT_H_ */
