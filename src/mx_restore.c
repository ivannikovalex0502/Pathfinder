#include "header.h"

static void into_stack(t_lists *res, int elem);
static int pop_front_stack(t_lists *res);
static _Bool is_short_path(t_App *app, t_lists *res,int next);

void mx_restore(t_App *app, t_lists *res)
{
    if(res->path[res->size] == res->path[0]){
        mx_print_short_path(app,res);
        return;
    }
    else{

        for(int next = 0; next < app->SIZE; next++){
            if(is_short_path(app,res,next)){
                //написать три функции
                into_stack(res,next);

                mx_restore(app,res);

                pop_front_stack(res);
            }
        }   
    }
}

static _Bool is_short_path(t_App *app, t_lists *res,int next)
{
     int j = res->path[res->size];
     int i = res->path[0];

     int *matrix_A = app->A_M;
     int *matrix_D = app->dist_M;
     int size = app->SIZE;

     if(j != next){
        if(matrix_D[i * size + j] -  matrix_A[j * size + next] == matrix_D[i * size + next]){
            return true;
        }
     }
     return false;
}

static void into_stack(t_lists *res, int elem)
{
    if(res->size < res->max_size)
    {
        res->size++;
        res->path[res->size] = elem;
    }
}

static int pop_front_stack(t_lists *res)
{
    if(res->size > 1){
        res->size--;
        return res->path[res->size + 1];
     }
     return res->path[1];
}

