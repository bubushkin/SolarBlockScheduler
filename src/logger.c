//
// Created by Iskandar Askarov on 3/2/21.
//

#include "include/logger.h"

_logger *init_logger(char *apath){
    _logger *ilogger = new(0x1, _logger);
    if(ilogger == NULL){
        eeprint("Malloc failed");
    }
    if(apath == NULL){
        eeprint("Log path is empty. Please set it up.");
    }
    if((ilogger->fp = fopen(apath, "a"))==NULL){
        eeprint("Unable to open log file for writing..");
    }
    ilogger->fp_info = &info;
    ilogger->fp_error = &serror;
    ilogger->fp_warning = &warning;
    ilogger->fp_debug = &debug;

    return ilogger;
}

void destruct_logger(_logger *apconfig){
    fclose(apconfig->fp);
    apconfig->fp_info = NULL;
    apconfig->fp_error = NULL;
    apconfig->fp_warning = NULL;
    apconfig->fp_debug = NULL;
    apconfig->fp_gettime = NULL;
    free(apconfig);
}
void serror(struct logger_ *aplogger, char *log){
    char strtime[18];
    gettime(strtime);
    fprintf(aplogger->fp, "%s:[ERROR]:%s\n", strtime, log);
}

void info(struct logger_ *aplogger, char *log){
    char strtime[18];
    gettime(strtime);
    fprintf(aplogger->fp, "%s:[INFO]:%s\n", strtime, log);
}

void warning(struct logger_ *aplogger, char *log){
    char strtime[18];
    gettime(strtime);
    fprintf(aplogger->fp, "%s:[WARNING]:%s\n", strtime, log);
}

void debug(struct logger_ *aplogger, char *log){
    char strtime[18];
    gettime(strtime);
    fprintf(aplogger->fp, "%s:[DEBUG]:%s\n", strtime, log);
}
