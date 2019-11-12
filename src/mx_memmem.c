#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len)
{
    unsigned char *b = (unsigned char *)big;
    unsigned char *l = (unsigned char *)little;

    size_t i = 0;
  
    if(big_len < little_len || !big_len || !little_len)
        return NULL;

    if(little_len == 1)
         return mx_memchr(big,(int ) *l, big_len);
    
    while(i < big_len - little_len + 1)
    {
         if(!mx_memcmp(b,l,little_len))
         {
             return (void *)b;
         }
         b++;
         i++;
    }
    return NULL;
}

