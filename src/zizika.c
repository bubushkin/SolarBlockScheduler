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

    system("pwd");
	_config *c = init_config("../conf/sbs.conf");

    char **buffer = split("log=/var/log/sbs.log", '=');
    printf("%s", buffer[1]);




	return EXIT_SUCCESS;
}
