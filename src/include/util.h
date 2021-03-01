/*
 * util.h
 *
 *  Created on: Feb 28, 2021
 *      Author: iskandar
 */

#ifndef INCLUDE_UTIL_H_
#define INCLUDE_UTIL_H_

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1024

#ifdef __LINUX__
    #include <error.h>
#endif

#define new(X, Y) (Y *)calloc(X, sizeof(Y))

#ifdef __APPLE__
    #define eeprint(X) fprintf(stderr, "%s, %d, %s\n", __FILE__, __LINE__, X); exit(EXIT_FAILURE);
#elif __LINUX__
    #define eeprint(X) error(0x1, EXIT_FAILURE, "%s, %d, %s\n",__FILE__, __LINE__, X)
#endif
#endif /* INCLUDE_UTIL_H_ */
