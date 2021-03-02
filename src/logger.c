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
    ilogger->fp_error = &error;
    ilogger->fp_warning = &warning;
    ilogger->fp_debug = &debug;
    ilogger->fp_gettime = &gettime;

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
void error(struct logger_ *aplogger, char *log){
    fprintf(aplogger->fp, "%s : ERROR : %s\n", aplogger->fp_gettime(aplogger), log);
}

void info(struct logger_ *aplogger, char *log){
    fprintf(aplogger->fp, "%s : INFO : %s\n", aplogger->fp_gettime(aplogger), log);
}

void warning(struct logger_ *aplogger, char *log){
    fprintf(aplogger->fp, "%s : WARNING : %s\n", aplogger->fp_gettime(aplogger), log);
}

void debug(struct logger_ *aplogger, char *log){
    fprintf(aplogger->fp, "%s : DEBUG : %s\n", aplogger->fp_gettime(aplogger), log);
}

char *gettime(struct logger_ *aplogger){
    char strtime[18];
    time_t rawtime;
    time( &rawtime );
    strftime(strtime, 18, "%Y%m%d %H:%M:%S", localtime(&rawtime));
    return strtime;
}