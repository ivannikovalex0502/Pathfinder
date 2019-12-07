#include "libmx.h"

char *mx_file_to_str(const char *file) {
    char buf[1];
    int len = 1;
    int fd2 = 0;
    char *result = NULL;
    int fd = open(file, O_RDONLY);

    if (fd < 0) {
        close(fd);
            return NULL;
     }
    if (read(fd, buf, 1) < 0)
        return NULL;

     while (read(fd,buf,1))
        len++;
     close(fd);
    if (fd < 0) 
        return NULL;
    result = mx_strnew(len);
    fd2 = open(file, O_RDONLY);
    if (fd < 0) 
        return NULL;
    for (int i = 0; read(fd2,buf,1); i++)
        result[i] = *buf;
    close(fd2);
    if (fd < 0) 
        return NULL;
    return result;
}

