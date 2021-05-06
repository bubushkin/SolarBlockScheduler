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
#include "src/engstat.h"

int main(void) {

	_config *c = init_config("../conf/sbs.conf");

    char *logfile = c->pf_get_config(c, "log");
//    _root *root = init_root();
//    global_init(c, root);
//
//    _engstat *engstat = init_engstat();
//    float current = engstat->pf_get_current();
//    float voltage = engstat->pf_get_voltage();

    _logger *log = init_logger(logfile);

    destruct_logger(log);
//destruct_config(c);

	return EXIT_SUCCESS;
}

