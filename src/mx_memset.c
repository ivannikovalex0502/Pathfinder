#include "libmx.h"

void *mx_memset(void *b, int c, size_t len)
{
    unsigned char *a = (unsigned char *)b; 
    unsigned char k = (unsigned char) c;

    size_t i = 0;

    while(i < len)
    {
        a[i] = k;
        i++;
    }
    if(b == NULL)
        return NULL;
    
    return (b);
}

