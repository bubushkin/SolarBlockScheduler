//
// Created by iskandar on 3/16/21.
//

#ifndef IZIBU_PCF8591_H
#define IZIBU_PCF8591_H


typedef struct pcf8591_{
    volatile int aval;
    int (*pf_analog_read)(void);
    int (*pf_analog_write)(void);

} _pcf8591;

_pcf8591 *init_acd();
void destruct_acd(_pcf8591 *);

#endif //IZIBU_PCF8591_H
