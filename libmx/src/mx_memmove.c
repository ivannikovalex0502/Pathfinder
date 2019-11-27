#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len)
{
    unsigned char temp[len];

    mx_memcpy(temp,src,len);
    mx_memcpy(dst,temp,len);
   
    return dst;
}

