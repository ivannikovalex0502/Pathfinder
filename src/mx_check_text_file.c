#include "header.h"

void mx_check_text_file(t_App *app, char *str) {
    char **lines_file = NULL;

    app->parsed_lines_array = mx_strsplit(str, '\n'); 
    lines_file = app->parsed_lines_array;
    app->SIZE = mx_atoi(lines_file[0]);
    if (app->SIZE > 9999)
        mx_printerr(INVALID_N_ISLAND, app);
    if (app->SIZE  == 0 && lines_file[1] == NULL)
        exit(0);
    if (app->SIZE  == 0 && lines_file[1])
        mx_printerr(INVALID_N_ISLAND, app);
    if (app->SIZE == -1)
        mx_printerr(INVALID_FIRS_LINE, app);
    mx_city_malloc(app);
    mx_initialize(app,lines_file);
    if (app->city[app->SIZE - 1] == NULL)
        mx_printerr(INVALID_N_ISLAND, app);
}

