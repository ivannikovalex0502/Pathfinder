#include "libmx.h"

int mx_count_words(const char *str, char c)
{
    char *s = (char*)str;
    int words = 0;

    if (str == NULL) return -1;
    if (*str == '\0') return 0;

    while(*s)
    {
        if(*s != c)
            words++;

        while(*s && *s != c)
            s++;
        while(*s && *s == c)
            s++;
     }
     return words;
}

