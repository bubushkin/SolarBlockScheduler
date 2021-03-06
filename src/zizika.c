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
#include "include/logger.h"

int main(void) {

	system("pwd");
	_config *c = init_config("conf/sbs.conf");

    char *path = c->pf_get_config(c, "log");

    _logger *log = init_logger(path);

    log->fp_debug(log, "This is debug");
    log->fp_error(log, "This is error");
    log->fp_info(log, "This is info");
    log->fp_warning(log, "This is warning");

    destruct_logger(log);



	return EXIT_SUCCESS;
}

