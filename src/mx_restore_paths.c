#include "libmx.h"

static void restore_paths_from_to(t_App *app, int i, int j);
static void init_lists(t_lists  **res, t_App *app, int i, int j);

void mx_restore_paths(t_App *app)
{
    for(int i = 0; i < app->SIZE; i++)
    {
        for(int j = i + 1; j < app->SIZE; j++)
        {
            restore_paths_from_to(app,i,j);
        }
    }
}

static void restore_paths_from_to(t_App *app, int i, int j)
{
    t_lists *res =  NULL;

    init_lists(&res,app,i,j);
}

static void init_lists(t_lists  **res, t_App *app, int i, int j)
{
    return true;
}


