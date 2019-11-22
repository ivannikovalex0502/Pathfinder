#ifndef LIBMX_H
#define LIBMX_H


#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <wchar.h>
#include <malloc/malloc.h>

typedef struct  s_list {
    void  *data;
    struct s_list *next;
}         t_list;

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
void push_element_in_island(char *elem, t_App *app);

void mx_printchar(char c);
void mx_print_strarr(char **arr, const char *delim);
void mx_printint(int n);
void mx_print_unicode(wchar_t c);
void mx_city_malloc(t_App *app);
void mx_printstr(const char *s);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
char *mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
void mx_check_text_file(t_App *app,  char *str);
char *mx_itoa(int number);
void mx_foreach(int *arr, int size, void (*f)(int));
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);
int mx_quick_sort(char **arr, int left, int right);
int mx_strlen(const char *s);
void mx_swap_char(char *s1, char *s2);
void mx_str_reverse(char *s);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_count_int(int num);
int mx_get_char_index(const char *str, char c);
int search_index_island(char *elem, t_App *app);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_read_text_file(int argc, char *argv[],t_App *app);
int mx_atoi(char *s);
_Bool mx_isspace(char c);
_Bool mx_isdigit(int c);
_Bool mx_isalpha(int c);
int mx_strcmp(const char *s1, const char *s2);
int mx_strncmp(const char *s1, const char *s2, int len);
char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_strstr(const char *haystack, const char *needle);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str,char c);
 char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
void mx_print_error(const char *s);
void mx_printerr(t_errors errors, t_App *app);
char **mx_strsplit(const char *s, char c);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_file_to_str(const char *file);
int mx_read_line(char **lineptr, int buf_size, char delim, const int fd);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);
void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);
t_list  *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);
int mx_list_size(t_list *list);
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));

#endif

