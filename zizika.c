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
#include "src/config.h"
#include "src/logger.h"
#include "src/root.h"

int main(void) {

	system("pwd");
	_config *c = init_config("../conf/sbs.conf");

    char *path = c->pf_get_config(c, "log");
    _root *root = init_root();
    global_init(c, root);

    _logger *log = init_logger(path);
    destruct_logger(log);
//destruct_config(c);

	return EXIT_SUCCESS;
}

