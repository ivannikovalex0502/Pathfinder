#include "header.h"

static void init_dist_matrix(t_App *app);
static void algoritm_Floyd(t_App *app);
static void make_cost_matrix(t_App *app);
void mx_restore_paths(t_App *app);

void mx_make_paths(t_App *app) {
    make_cost_matrix(app);
    mx_restore_paths(app);
}

static void make_cost_matrix(t_App *app) {
    init_dist_matrix(app);
    algoritm_Floyd(app);
}

static void init_dist_matrix(t_App *app) {
    app->dist_M = malloc(app->SIZE * app->SIZE * sizeof(int));
    for (int i = 0; i < app->SIZE; i++) {
        for (int j = 0; j < app->SIZE; j++) {
            app->dist_M[i * app->SIZE + j] = app->A_M[i * app->SIZE + j];
        }
    }
}

static void algoritm_Floyd(t_App *app) {
    int size = app->SIZE;
    int *dist = app->dist_M;

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int ik = i * size + k;
                int kj = k * size + j;
                int ij = i * size + j;

                if (dist[ik] + dist[kj] < dist[ij])
                    dist[ij] = dist[ik] + dist[kj];
            }
        }
    }
} 

