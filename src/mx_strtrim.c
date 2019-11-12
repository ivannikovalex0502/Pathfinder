#include "libmx.h"

char *mx_strtrim(const char *str)
{
    if(str == NULL)
        return NULL;
        
    int first = 0;
       
    int last = mx_strlen(str) - 1;
    int len ;

    while(mx_isspace(str[first])){
        first++;
    }

    while(mx_isspace(str[last]))
        last--;

    len = last - (first - 1);

    for (int i = 0; i < first; i++) {
        str++;
    }
    return mx_strndup(str, len);
}       

