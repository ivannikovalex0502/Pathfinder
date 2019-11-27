 #include "libmx.h"
 
void *mx_realloc(void *ptr, size_t size)
{
    if(!ptr && size)
        return malloc(size);
        
    if(size == 0 && ptr)
    {
        free(ptr);
        return NULL;
    }
      
    size_t len = mx_strlen(ptr);
    void *p;

    if(len > size)
    {
        p = malloc(len);
        if(!p)
            return NULL;
        p = mx_memmove(p,ptr,len);
      }
      else{
        p = malloc(size);
        if(!p)
            return NULL;
        p = mx_memmove(p,ptr,size);   
      }
      return p;
  }

