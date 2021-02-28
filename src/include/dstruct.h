/*
 * dstruct.h
 *
 *  Created on: Feb 28, 2021
 *      Author: iskandar
 */

#ifndef INCLUDE_DSTRUCT_H_
#define INCLUDE_DSTRUCT_H_


typedef struct entry_{
		char *key;
		char *value;
		struct entry_ *pnext;
} _entry;

typedef struct {

	_entry *pentry;
	int size;

} _list;





#endif /* INCLUDE_DSTRUCT_H_ */
