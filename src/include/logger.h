//
// Created by Iskandar Askarov on 3/2/21.
//

#ifndef ZIZIKA_LOGGER_H
#define ZIZIKA_LOGGER_H
#include "util.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct logger_ {

    FILE *fp;
    void(*fp_info)(struct logger_ *, char *);
    void(*fp_error)(struct logger_ *, char *);
    void(*fp_warning)(struct logger_ *, char *);
    void(*fp_debug)(struct logger_ *, char *);
    char *(*fp_gettime)(struct logger_ *);

} _logger;

_logger * init_logger(char *);
void destruct_logger(_logger *);

void error(struct logger_ *, char *);
void info(struct logger_ *, char *);
void warning(struct logger_ *, char *);
void debug(struct logger_ *, char *);
char *gettime(struct logger_ *);

#endif //ZIZIKA_LOGGER_H
