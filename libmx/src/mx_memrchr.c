#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n)
{
    unsigned char *str = (unsigned char *)s;
    
    unsigned char search = (unsigned char)c;

    size_t i = 0;
    size_t len = mx_strlen(s);
    
    while( i <= n)
    {
        if(str[len] == search)
        {
             return (&str[len]);
        }
        len--;
        i++;
    }
    return NULL;
}

