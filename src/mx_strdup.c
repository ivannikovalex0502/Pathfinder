#include "libmx.h"

char *mx_strdup(const char *str)
{
    int len = 0;
    char *dup;
    
    len = mx_strlen(str);

    dup = mx_strnew(len);
    
    mx_strcpy(dup,str);
    
    return dup;
}

