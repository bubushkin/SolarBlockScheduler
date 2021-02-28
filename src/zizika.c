/*
 ============================================================================
 Name        : zizika.c
 Author      : Iskandar Askarov
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "include/config.h"

int main(void) {

	_config *c = init_config("/tmp/file");
	printf("");

	return EXIT_SUCCESS;
}
