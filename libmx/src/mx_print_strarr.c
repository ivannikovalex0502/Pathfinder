#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim)
{
    int i = 0;
    if(*arr != NULL && delim != NULL && arr != NULL)
    {    
        for(i = 0; arr[i] != NULL; i++) 
        {
            if(arr[i + 1])
            {
                mx_printstr(arr[i]);
                mx_printstr(delim);
            }
        }
      mx_printstr(arr[i - 1]);        
      mx_printchar('\n');
    }
}

