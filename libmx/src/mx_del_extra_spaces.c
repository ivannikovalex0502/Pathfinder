#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *dur = mx_strnew(mx_strlen(str));
    int k = 0;
    char *itog = NULL;

    if (str == NULL)
          return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
         if (mx_isspace(str[i]) && !mx_isspace(str[i - 1])) {
              dur[k] = ' ';
              k++;
          }
         else if (!mx_isspace(str[i])) {
              dur[k] = str[i];
              k++;
         }
    }
    itog = mx_strtrim(dur);
    mx_strdel(&dur);
    return itog;
}

