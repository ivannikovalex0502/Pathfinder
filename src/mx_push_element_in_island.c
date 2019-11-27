#include "header.h"

void mx_push_element_in_island(char *elem, t_App *app)
{
    char **island = app->city;
    int i;

    for(i = 0; i < app->SIZE; i++)
    {
        if(island[i] == NULL)
            break;

        if(mx_strcmp(island[i], elem) == 0)
            return;
    }
    if(i < app->SIZE)
        island[i] = mx_strdup(elem);

    else
        mx_printerr(INVALID_N_ISLAND, app);    
}

