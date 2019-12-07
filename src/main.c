#include "header.h"

int main(int argc, char *argv[]) {
    char *str = NULL;
    t_App *app = malloc(sizeof(t_App));

    if (argc != 2)
        mx_printerr(INVALID_ARGV, app);
    str = mx_read_text_file(argv, app);
    mx_check_text_file(app, str);
    mx_make_paths(app);
    mx_free_all(app);
    return 0;
}

