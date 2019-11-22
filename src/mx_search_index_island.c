#include "libmx.h"

int search_index_island(char *elem, t_App *app)
{
    for(int i = 0; i < app->SIZE; i++)
    {
        if(mx_strcmp(app->city[i],elem) == 0)
            return i;
    }
    return -1;
}

