/*
 * util.h
 *
 *  Created on: Feb 28, 2021
 *      Author: iskandar
 */

#ifndef INCLUDE_UTIL_H_
#define INCLUDE_UTIL_H_

#include <stdlib.h>
#include <error.h>

#define MAXLEN 1024

#define eeprint(X) error(0x1, EXIT_FAILURE, "%s, %d, %s\n",__FILE__, __LINE__, X)



#endif /* INCLUDE_UTIL_H_ */
