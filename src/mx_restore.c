#include "libmx.h"

static void into_stack(t_list *res, int elem);
static void pop_front_stack(t_list *res);

void restore(t_App *app, t_list *res)
{
    if(res->path[res->size] == res->path[0]){
        print_path(app,res);
        return;
    }
    else{

        for(int next = 0; next < app->SIZE; next++){
            if(find_next(app,res,next)){
                //написать три функции
                into_stack(res,next);

                mx_restore(app,res);

                pop_front_stack(res);
            }
        }   

    }
}

static void into_stack(t_list *res, int elem)
{
    if(res->size < res-> max_size)
    {
        res->size++;
        res->path[res->size] = elem;
    }
}

static void pop_front_stack(t_list *res)
{
    if(res->size > 1){
        res->size--;
        return res->path[res->size + 1];
     }
     return res->path[1];
}

