#include "libmx.h"

char *mx_strndup(const char *s1, size_t n)
{
    size_t len = 0;
    char *dup;
    size_t i = 0;
    
    if(!*s1 || n <= 0)
        return NULL;

    len = mx_strlen(s1);

    if(len >= n)
        dup = mx_strnew(n);
    else
        dup = mx_strnew(len);

    while(i < n && s1[i] != '\0')
    {
         dup[i] = s1[i];
         i++;
    }
    dup[i] = '\0'; 
    return dup;
}

