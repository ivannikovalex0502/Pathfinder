#include "header.h"

void  mx_guide_index(t_App *app, char *word1, char *word2, int *word3) {
    int i = 0;
    int j = 0;

    i = mx_search_index_island(word1,app);
    j = mx_search_index_island(word2,app);
    mx_push_am(app,word3,i,j);
}

