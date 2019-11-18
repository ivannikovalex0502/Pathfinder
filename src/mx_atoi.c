#include "libmx.h"

int mx_atoi(char *s) {   // TODO: do it
    // int res = 0;
    // if(!mx_isdigit(*s)) return -1;

    // while (mx_isdigit(*s)) {   
    //     res = 10 * res + (*s) - '0';
    //     s++;
    // }
    // if(res == 0)
    //     res = -1;
    // return res;

   // TODO: do it
    int res = 0;
    while (*s != '\0') {
        if (!mx_isdigit(*s)) return -1;
        res = 10 * res + (*s) - '0';
        s++;
    }
    if(!s)
        return -1;
    if(res == 0)
        res = -1;
    return res;
}

