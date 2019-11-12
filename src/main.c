#include "libmx.h"

int main(int argc, char *argv[])
{
    t_App *app = malloc(sizeof(t_App));
 
    if(argc != 2)
    {
        mx_printerr(INVALID_ARGV,app);
    }
    char *str = mx_file_to_str(argv[1]);

    if (str == NULL) {
         mx_printerr(FILE_DOES_EX, app);
    }
    if (mx_strlen(str) <= 0) {
         mx_printerr(FILE_IS_EMTY, app);
    }
    printf("%c\n",str[0]);
    app->file_name = argv[1];
    mx_check_text_file(app,str);
}

