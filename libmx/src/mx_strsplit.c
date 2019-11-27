#include "libmx.h"

char **mx_strsplit(const char *s, char c)
{
    
     if(s == NULL)
         return NULL;
     
     int count = mx_count_words(s,c);
     char **arr = malloc(sizeof(char *) * (count + 1));
     int j;
     for( j = 0; j < count; j++){
          while(*s == c && *s)
              s++;
          
          unsigned int index = mx_get_char_index(s,c);
          
          arr[j] = mx_strndup(s,index);
          s = s + index;
     }

     arr[j] = NULL;
     return arr;
}   

