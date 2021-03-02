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

	_config *c = init_config("../conf/sbs.conf");
    c->pf_get_config(c, "log");



	return EXIT_SUCCESS;
}
