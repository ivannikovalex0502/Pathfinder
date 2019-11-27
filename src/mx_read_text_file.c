#include "header.h"

char *mx_read_text_file(int argc, char *argv[],t_App *app)
{
     argc = 2;
     app->file_name = argv[1];
     int fd = open(argv[1],O_RDONLY);
     if (fd < 0)
     {
          close(fd);
          mx_printerr(FILE_DOES_EX, app);
     }
     close(fd);

     app->file_to_str = mx_file_to_str(argv[1]);
     char *str = app->file_to_str;

     if (mx_strlen(str) == 0){
         mx_printerr(FILE_IS_EMTY, app);
     }
     return str;
}

