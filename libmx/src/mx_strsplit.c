#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    int count = 0;
    char **arr = NULL;
    int j;
    unsigned int index = 0;

    if (s == NULL)
         return NULL; 
    count = mx_count_words(s,c);
    arr = malloc(sizeof(char *) * (count + 1));
    for ( j = 0; j < count; j++){
        while (*s == c && *s)
            s++;
        index = mx_get_char_index(s,c);
        arr[j] = mx_strndup(s,index);
        s = s + index;
    }
    arr[j] = NULL;
    return arr;
}   

