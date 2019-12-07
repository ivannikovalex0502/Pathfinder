#include "header.h"

static void all_null(t_App *app);
static void check_emty_line(char *str, t_App *app);

char *mx_read_text_file(char *argv[], t_App *app) {
    int fd = 0;
    char *str = NULL;

    all_null(app);
    app->file_name = argv[1];
    fd = open(argv[1],O_RDONLY);
    if (fd < 0) {
        close(fd);
        mx_printerr(FILE_DOES_EX, app);
    }
    close(fd);
    app->file_to_str = mx_file_to_str(argv[1]);
    str = app->file_to_str;
    if (mx_strlen(str) == 0) {
        mx_printerr(FILE_IS_EMTY, app);
    }
    check_emty_line(str,app);
    return str;
}

static void check_emty_line(char *str, t_App *app) {
    int j  = 0;

    if (str[0] == '\n')
         mx_printerr(INVALID_FIRS_LINE,app);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            j++;
        if (str[i] == '\n' && str[i + 1] == '\n') {
            app->k  = j + 1;
            break;
        }
    }
}

static void all_null(t_App *app) {
    app->city = NULL;
    app->A_M = NULL;
    app->dist_M = NULL;
    app->parsed_lines_array = NULL;
    app->file_to_str = NULL;
}

