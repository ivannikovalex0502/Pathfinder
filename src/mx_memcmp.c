#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *st1 = (unsigned char *)s1;
    unsigned char *st2 = (unsigned char *)s2;

    size_t i = 0;

    if(st1 == st2 || n == 0)
        return 0;
     
    while(i < n)
    {
        if(st1[i] != st2[i])
        {
             return ((int) st1[i] - st2[i]); 
        }
        i++;
    }
    return 0;
}

