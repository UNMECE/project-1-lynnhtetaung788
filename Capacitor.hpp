#ifndef _CAPACITOR_HPP_
#define _CAPACITOR_HPP_

struct capacitor {
    long double *time;       //time array
    long double *voltage;    //voltage array
    long double *current;    //current array
    long double c;           //capacitance value
};

#endif