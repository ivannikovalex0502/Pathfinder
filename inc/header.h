#ifndef HEADER_H
#define HEADER_H


#include "libmx.h"

typedef enum f_errors {
    INVALID_ARGV,
    FILE_DOES_EX,
    FILE_IS_EMTY,
    INVALID_FIRS_LINE,
    INVALID_N_ISLAND,
    LINE_ISNT_VALID
} t_errors;


typedef struct s_APP {
    int SIZE;
    char **city;
    int *A_M;
    int *dist_M;
    int invalid_line_number;
    char *file_name;
    char *file_to_str;
    char **parsed_lines_array;

} t_App;

typedef struct {
    int *path;
    int size;
    int max_size;
} t_lists; 

void mx_make_paths(t_App *app);
void mx_push_element_in_island(char *elem, t_App *app);
void mx_print_short_path(t_App *app, t_lists *res);
void mx_free_all(t_App *app);
void mx_restore(t_App *app, t_lists *res);
void mx_print_error(const char *s);
void mx_printerr(t_errors errors, t_App *app);
void mx_city_malloc(t_App *app);
void mx_check_text_file(t_App *app,  char *str);
void mx_restore_paths(t_App *app);
//void
int mx_search_index_island(char *elem, t_App *app);
int mx_atoi(char *s);
//int
char *mx_read_text_file(int argc, char *argv[],t_App *app);
//char
_Bool mx_isdigit(int c);
_Bool mx_isalpha(int c);
//_Bool
#endif

