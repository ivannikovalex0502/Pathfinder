#include "libmx.h"

char *mx_read_text_file(int argc, char *argv[],t_App *app)
{
    argc = 1;
    app->file_to_str = mx_file_to_str(argv[1]);
    char *str = app->file_to_str;
    app->file_name = argv[1];

    if (str == NULL) {
         mx_printerr(FILE_DOES_EX, app);
    }
    if (mx_strlen(str) == 0) {
         mx_printerr(FILE_IS_EMTY, app);
    }
    return str;
}

