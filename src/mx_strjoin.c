#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2)
{
    int len1 = 0;
    int len2 = 0;
    char *temp;

    if(!s1 && !s2)
        return NULL;
    
    else if(!s2 && s1)
        return mx_strdup(s1);
    else if(s2 && !s1)
        return mx_strdup(s2);
    
    else{
        len1 = mx_strlen(s1);
        len2 = mx_strlen(s2);

        temp = mx_strnew(len1 + len2);

        for(int i = 0; s1[i] != '\0'; i++)
            temp[i] = s1[i];
        for(int j = 0; s2[j] != '\0'; j++,len1++)
            temp[len1] = s2[j];
    }
    return temp;         
} 

