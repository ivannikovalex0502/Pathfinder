#include "libmx.h"

int mx_atoi(char *s) {   // TODO: do it
    int res = 0;
    if(!mx_isdigit(*s)) return -1;

    while (mx_isdigit(*s)) {   
        res = 10 * res + (*s) - '0';
        s++;
    }
    return res;
}

