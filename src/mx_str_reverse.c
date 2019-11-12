#include "libmx.h"

void mx_str_reverse(char *s)
{
     int len = 0;
     if(!s)
          return;
          
     len = mx_strlen(s) - 1;
     if(*s)
     {
         for(int i = 0; i < len; i++)
         {
              mx_swap_char(&s[i],&s[len--]);
         }
     }
}

