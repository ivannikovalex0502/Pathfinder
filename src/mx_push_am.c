#include "header.h"

void mx_push_am(t_App *app, int *word3, int i, int j)
{
    app->A_M[i * app->SIZE + j] = *word3;
    app->A_M[j * app->SIZE + i] = *word3; 
}

