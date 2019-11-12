#include "libmx.h"

int mx_count_int(int num)
{
     int len = 0;
     if(num < 0)
         len++;
         
     while(num > 0 || -num > 0 || num == -2147483648)
     {
         num /= 10;
         len++;
     }
     return len;
}

