#include "header.h"

static void line_invlid(t_App *app);
static void file_is_emty(t_App *app);
static void file_not_exit(t_App *app);
static void line_error_slash(t_App *app);

void mx_printerr(t_errors errors, t_App *app) {
    if (errors == INVALID_ARGV)
        mx_print_error("usage: ./pathfinder [filename]");
    else if (errors == FILE_DOES_EX)
        file_not_exit(app);
    else if (errors == FILE_IS_EMTY)
        file_is_emty(app);
    else if (errors == INVALID_FIRS_LINE)
        mx_print_error("error: line 1 is not valid");
    else if (errors == INVALID_N_ISLAND)
        mx_print_error("error: invalid number of islands");
    else if (errors == LINE_ISNT_VALID)
        line_invlid(app);
    else if (errors == LINE_ERROR_SLASH)
        line_error_slash(app);
    mx_print_error("\n");
    exit(1);
}

static void line_invlid(t_App *app) {
    char *number_line = NULL;

    mx_print_error(" error: line ");
    number_line = mx_itoa(app->invalid_line_number);
    mx_print_error(number_line);
    free(number_line);
    number_line = NULL;
    mx_print_error(" is not valid");
}

static void file_is_emty(t_App *app) {
    mx_print_error("error: file ");
    mx_print_error(app->file_name);
    mx_print_error(" is empty");
}

static void file_not_exit(t_App *app) {
    mx_print_error("error: file ");
    mx_print_error(app->file_name);
    mx_print_error(" does not exist");
}

static void line_error_slash(t_App *app) {
    char *number_line = NULL;

    mx_print_error("error: line ");
    number_line = mx_itoa(app->k);
    mx_print_error(number_line);
    free(number_line);
    number_line = NULL;
    mx_print_error(" is not valid");
}
