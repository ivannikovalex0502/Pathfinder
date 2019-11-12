#include "libmx.h"

_Bool mx_isspace(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' 
        || c == '\v' || c == '\f' || c == '\r')
        return 1;
    return 0; 
}

