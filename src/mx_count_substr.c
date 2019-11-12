#include "libmx.h"

int mx_count_substr(const char *str, const char *sub)
{
    int index = 0;
    int i = 0;

    if(str == NULL || sub == NULL )
        return -1;
    
    if(str == '\0' || sub == '\0')
        return -1;

    while(str[i] != '\0')
    {
        if(mx_strncmp(str,sub,mx_strlen(sub)) == 0)
            index++;
        str++;
    }
    return index;
}

