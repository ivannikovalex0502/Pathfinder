#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
    unsigned char *s = (unsigned char *)src;
    unsigned char *d = (unsigned char *)dst;
    unsigned char ch = (unsigned char)c;

    size_t i = 0;

    if(n == 0)
       return NULL;
    
    while(i <  n)
    {
        d[i] = s[i];
        if((unsigned char)s[i] == (unsigned char)ch)
            return (d + i + 1);
        i++;
    }
    return NULL;
 }

