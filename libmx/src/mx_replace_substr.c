#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace)
{
     if(!str || !sub || !replace)
         return NULL;

    int len = mx_strlen(str);
    
    int sub_len = mx_strlen(sub);

    int rep_len = mx_strlen(replace);

    int count_words = mx_count_substr(str, sub);

    char *str_new = mx_strnew(len - (sub_len * count_words) + (rep_len * count_words));

    while (*str)
    {
        if(mx_strncmp(str, sub, sub_len) == 0)
        {
            mx_strcpy(str_new, replace);
            str_new += rep_len;
            str += sub_len;
            continue;
        }
        *str_new = *str;
        str++;
        str_new++;
    }
    str_new -= len - (sub_len * count_words) + (rep_len * count_words);
    return str_new;
}

