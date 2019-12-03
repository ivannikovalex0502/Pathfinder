#include "header.h"

static void restore_paths_from_to(t_App *app, int i, int j);
static void init_lists(t_stack  **res, t_App *app, int i, int j);

void mx_restore_paths(t_App *app) {
    for (int i = 0; i < app->SIZE; i++) {
        for (int j = i + 1; j < app->SIZE; j++) {
            restore_paths_from_to(app,i,j);
        }
    }
}

static void restore_paths_from_to(t_App *app, int i, int j) {
    t_stack *res =  NULL;

    init_lists(&res,app,i,j);
    mx_restore(app,res);
    free(res->path);
    free(res);
}

static void init_lists(t_stack  **res, t_App *app, int i, int j) {
    *res = malloc(sizeof(t_stack));
    if ((*res) == NULL) 
        exit(1);
    (*res)->max_size = app->SIZE;
    (*res)->path = malloc((*res)->max_size * sizeof(int) + 1);
    (*res)->path[0] = i;
    (*res)->path[1] = j;
    (*res)->size = 1;
}

