#include "libmx.h"

void mx_printerr(t_errors errors, t_App *app)
{
    switch(errors){
        case  INVALID_ARGV:
            mx_print_error("usage: ./pathfinder [filename]");
        break;

        case FILE_DOES_EX:
            mx_print_error("error: file");
            mx_print_error(app->file_name);
            mx_print_error(" doesn't exist");
        break;

        case FILE_IS_EMTY:
            mx_print_error("error: file ");
            mx_print_error(app->file_name);
            mx_print_error(" is empty");
        break;

        case INVALID_FIRS_LINE:
            mx_print_error("error: line 1 isn't valid");
        break;

        case INVALID_N_ISLAND:
            mx_print_error("error: invalid number of islands");
        break;
        case LINE_ISNT_VALID:
            mx_print_error(" error: line");
            mx_printint(app->invalid_line_number);
            mx_print_error(" isn't valid ");
        break;
    }
    mx_printchar('\n');
    exit(-1);
}

