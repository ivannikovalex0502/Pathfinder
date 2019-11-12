#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr)
{
    unsigned long tmp = nbr;
    int len = 0;
    char *memory;

    if(nbr != 0){
        while(tmp > 0)
        {
            tmp /= 16;
            len++;
        }
        
        memory = mx_strnew(len);

        for(; nbr > 0; nbr /= 16, len--)
        {
            if(nbr % 16 >= 0 && nbr % 16 <= 9)
            memory[len - 1] = nbr % 16 + '0';
            else if(nbr % 16 >= 10 && nbr % 16 <= 15)
            memory[len - 1] = nbr % 16 + 'a' - 10; 
        }
    }
    else{
        memory = malloc(2);
        memory[0] = '0';
        memory[1] = '\0';
    }
    return memory;
}

