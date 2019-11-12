#include "libmx.h"

int mx_quicksort(char **arr, int left, int right)
{
    int count = 0;
    if(!arr || !*arr)
        return -1;
    if(left < right){
        int begin = left;
        int end = right;

        char *mid = arr[begin + (end - begin) / 2];
    while(begin <= end)
    {
        while(mx_strlen(arr[begin]) < mx_strlen(mid))
            begin++;
        while(mx_strlen(arr[end]) > mx_strlen(mid))
            end--;

        if(mx_strlen(arr[begin]) != mx_strlen(arr[end]))
        {
            char *tmp = arr[begin];
            arr[begin] = arr[end];
            arr[end] = tmp;
            begin++;
            end--;
            count++;
        } 
    }        
        count +=  mx_quicksort(arr,left,end);
        count += mx_quicksort(arr,begin,right);
    }
    return count;
}

