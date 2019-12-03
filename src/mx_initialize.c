#include "header.h"

static _Bool parse_line(char *line, char **word1, char **word2, int  *word3);
static _Bool is_valid_word(char *s);
static void  print_error_in_line(int i, t_App *app, char *word1, char *word2);
static void free_words(char *word1, char *word2);

void mx_initialize(t_App *app, char **lines_file) {
    for (int i = 1; lines_file[i] != NULL; i++) {
        char *word1 = NULL;
        char *word2 = NULL;
        int word3 = -1;

        if (app->k != 0 && app->k <= i)
                mx_printerr(LINE_ERROR_SLASH , app);   
        if (parse_line(lines_file[i],&word1,&word2,&word3)) {
            int i = 0;
            int j = 0;
            mx_guide(word1,word2,app);
            // mx_push_element_in_island(word1,app);
            // mx_push_element_in_island(word2,app);
            mx_guide_index(i,j,word1,word2);
            //Написать функцию !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //i = mx_search_index_island(word1,app);
            //j = mx_search_index_island(word2,app);
            mx_push_am(app,&word3,i,j);
        }
        else 
            print_error_in_line(i,app,word1,word2);
        free_words(word1,word2);
    }
    if (app->k != 0)
        mx_printerr(LINE_ERROR_SLASH, app);
}

static _Bool parse_line(char *line, char **word1, char **word2, int  *word3) {
    char *number = NULL;
    int index_dash = mx_get_char_index(line, '-');
    int index_coma = mx_get_char_index(line, ',');
    int len = mx_strlen(line);

    if (index_coma == -1 && index_dash == -1 
        && len == 0 && index_dash > index_coma) {
        return false;
    }
    *word1 = mx_strndup(line,index_dash);
    *word2 = mx_strndup(line + index_dash + 1, index_coma - index_dash - 1);
    number = mx_strndup(line + index_coma + 1, len - index_coma - 1);
    if (!is_valid_word(*word1) || !is_valid_word(*word2))
        return false;
    *word3 = mx_atoi(number);
    if (*word3 == -1 || *word3 == 0)
        return false;
    free(number);
    return true;
}

static _Bool is_valid_word(char *s) {
    if (mx_strlen(s) == 0)
        return false;
    for (int i = 0; s[i] != '\0'; i++){
        if (!mx_isalpha(s[i]))
            return false;
    }
    return true;
}

static void free_words(char *word1, char *word2) {
    free(word1);
    free(word2);
}
static void  print_error_in_line(int i, t_App *app, char *word1, char *word2) {
    free(word1);
    free(word2);
    app->invalid_line_number = i + 1;
    mx_printerr(LINE_ISNT_VALID,app);
}
