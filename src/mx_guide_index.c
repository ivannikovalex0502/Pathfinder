#include "header.h"

void mx_guide_index(int i, int j, char *word1, char *word2)
{
    t_App *app = malloc(sizeof(t_App));
    i = mx_search_index_island(word1,app);
    j = mx_search_index_island(word2,app);
}
