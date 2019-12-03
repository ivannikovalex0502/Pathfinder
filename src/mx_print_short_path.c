#include "header.h"

static char *get_name_by_id(int i, t_App *app);
static void print_path(t_App *app, t_stack *res);
static void print_route(t_App *app, t_stack *res);
static void print_distance(t_App *app, t_stack *res);

void mx_print_short_path(t_App *app, t_stack *res) {
    mx_print_line();
    mx_printstr("\n");
    print_path(app, res);
    print_route(app, res);
    print_distance(app, res);
    mx_print_line();
    mx_printstr("\n");

}

static char *get_name_by_id(int i, t_App *app) {
    return app->city[i];
}

static void print_path(t_App *app, t_stack *res) {
    mx_printstr("Path: ");
    mx_printstr(get_name_by_id (res->path[0], app));
    mx_printstr(" -> ");
    mx_printstr(get_name_by_id(res->path[1], app));
    mx_printstr("\n");
}

static void print_route(t_App *app, t_stack *res) {
    mx_printstr("Route: ");
    for (int i = res->size; i >= 2; i--) {
        mx_printstr(get_name_by_id(res->path[i], app));
        mx_printstr(" -> ");
    }
    mx_printstr(get_name_by_id(res->path[1], app));
    mx_printstr("\n");
}

static void print_distance(t_App *app, t_stack *res) {
    int total_dist = 0;
    int dist = 0;

    mx_printstr("Distance: ");
    for (int i = res->size - 1; i >= 2; i--) {
        dist = app->A_M[res->path[i] * app->SIZE + res->path[i + 1]];
        total_dist += app->A_M[res->path[i] * app->SIZE + res->path[i + 1]];
        mx_printint(app->A_M[res->path[i] * app->SIZE + res->path[i + 1]]);
        mx_printstr(" + ");
    }
    if (total_dist != 0) {
        dist = app->A_M[res->path[2] * app->SIZE + res->path[1]];
        total_dist += dist;
        mx_printint(dist);
        mx_printstr(" = ");
    }
    else
       total_dist = app->A_M[res->path[2] * app->SIZE + res->path[1]];
    mx_printint(total_dist);
    mx_printstr("\n");
}

