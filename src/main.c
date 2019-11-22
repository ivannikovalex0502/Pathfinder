#include "libmx.h"

int main(int argc, char *argv[])
{
    t_App *app = malloc(sizeof(t_App));
 
    if(argc != 2)
    {
        mx_printerr(INVALID_ARGV,app);
    }

    char *str = mx_read_text_file(argc,argv,app);

    mx_check_text_file(app,str);

    mx_make_paths(app);

    //system("leaks -q ");

    return 0;
}

