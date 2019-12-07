#include "header.h"

static void into_stack(t_stack *res, int elem);
static int pop_front_stack(t_stack *res);
static _Bool is_short_path(t_App *app, t_stack *res,int next);
static int get_from_stack(t_stack *res);

void mx_restore(t_App *app, t_stack *res) {
    if (get_from_stack(res) == res->path[0]) {
        mx_print_short_path(app,res);
        return;
    }
    else {
        for (int next = 0; next < app->SIZE; next++) {
            if (is_short_path(app, res, next)) {
                into_stack(res, next);
                mx_restore(app, res);
                pop_front_stack(res);
            }
        }
    }
}

static _Bool is_short_path(t_App *app, t_stack *res, int next) {
    int k;
    int i = res->path[0];
    int *m_A = app->A_M;
    int *m_D = app->dist_M;
    int size = app->SIZE;

    k = get_from_stack(res);
    if (k != next) {
        if (m_D[i * size + k] - m_A[k * size + next] == m_D[i * size + next])
            return true;
    }
    return false;
}

static int get_from_stack(t_stack *res) {
    return res->path[res->size];
}

static void into_stack(t_stack *res, int elem) {
    if (res->size < res->max_size) {
        res->size++;
        res->path[res->size] = elem;
    }
}

static int pop_front_stack(t_stack *res) {
    if (res->size > 1) {
        res->size--;
        return res->path[res->size + 1];
    }
    return res->path[1];
}

