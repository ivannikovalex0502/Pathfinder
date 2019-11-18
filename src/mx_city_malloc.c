#include "libmx.h"

void mx_city_malloc(t_App *app)
{
    app->city = malloc(app->SIZE * sizeof(char *) + 1);
    if(app->city == NULL){
        exit(1);
    }
    for(int i = 0; i < app->SIZE + 1; i++)
        app->city[i] = NULL;

    // for(int j = 0; j < app->SIZE; j++)
    // {
    //     printf("%s\n",app->city[j]);
    // }
}

