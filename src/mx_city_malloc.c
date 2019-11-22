#include "libmx.h"

static void init_matrix_A(t_App *app);

void mx_city_malloc(t_App *app)
{
    app->city = malloc(app->SIZE * sizeof(char *) + 1);
    if(app->city == NULL){
        exit(1);
    }
    for(int i = 0; i < app->SIZE + 1; i++)
        app->city[i] = NULL;

     init_matrix_A(app);
}

static void init_matrix_A(t_App *app)
{
    app->A_M = malloc(app->SIZE * app->SIZE * sizeof(int));

    for(int i = 1; i < app->SIZE; i++)
    {
        for(int j = 0; j < app->SIZE; j++)
        {
            if(i == j)
            {
                app->A_M[i * app->SIZE + j] = 0;
            }
            else
                app->A_M[i * app->SIZE + j] = 1000000000;
        }
    }
}

