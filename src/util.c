//
// Created by Iskandar Askarov on 3/1/21.
//

#include "include/util.h"

void split(char *apline, char delim, char **buffer){

    int idx = 0, xdx = 0;
    char c = 0xF;
    short found = 0;

//    if((buffer[0] = new(128, char)) == NULL){
//        eeprint("Malloc failed");
//    }
//    if((buffer[1] = new(128, char)) == NULL){
//        eeprint("Malloc failed");
//    }

    while(c != NULL){
        c = apline[idx++];
        if(c == delim){
            for(int i = 0; i < idx - 1; i++){
                buffer[0][i] = apline[i];
            }
            found = 1;
            continue;
        }
        if(found){
            if(c != '\n')
                buffer[1][xdx++] = c;
            else break;
        }
    }
}
