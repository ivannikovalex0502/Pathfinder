#include "libmx.h"

char *mx_itoa(int number) {
    int count = 0;
    int len = 0;
    char *itog = NULL;

    if (number == -2147483648){
        char *n = mx_strdup("-2147483648");
        return n;
    }
    else if (number == 0){
        return mx_strdup("0");
    }
    len = mx_count_int(number);
    itog = mx_strnew(len);
    if (number < 0){
        itog[0] = '-';
        count++;
        number *= -1;
    }
    for (int i = len - 1; i >= count; i--){
        itog[i] = (number % 10) + '0';
        number /= 10;
    }
    return itog;
}

