#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub)
{
    int i = 0;
    int index = 0;

    if(str == NULL || sub == NULL)
        return -2;
    if(!*str)
        return 0;

    while(str[i] != '\0')
    {
        if(mx_strncmp(str,sub,mx_strlen(sub)) == 0)
            return index;
        index++;
        str++;
    }
    return -1;
}

