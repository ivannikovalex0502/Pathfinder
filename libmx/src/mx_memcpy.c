#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    unsigned char *sr;
    unsigned char *ds;

    size_t i = 0;

    if(!src && !dst)
        return NULL;

    if(src == dst)
        return dst;
    
    sr = (unsigned char *)src;
    ds = (unsigned char *)dst;
   
    
    while(i < n)
    {
        ds[i] = sr[i];
        i++;
    }
    return ds;
}

