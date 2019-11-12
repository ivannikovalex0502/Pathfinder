#include "libmx.h"

int mx_sqrt(int x)
{
    int sol = 0;
    
    if( x == 1)
        return 1;
 
    while((sol * sol) < x){
        sol++;
        if(sol > 46340)
        {
            return 0;
        }
    }

    if((sol * sol) != x)
         sol = 0;
    return (sol);
}

