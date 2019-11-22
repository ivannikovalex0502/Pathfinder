#include "libmx.h"

static _Bool parse_line(char *line, char **word1, char **word2, int  *word3);
static _Bool is_valid_word(char *s);
static void initialize(t_App *app, char **lines_file);

void mx_check_text_file(t_App *app,  char *str)
{
    app->parsed_lines_array = mx_strsplit(str,'\n');
    char **lines_file = app->parsed_lines_array;
    
    app->SIZE = mx_atoi(lines_file[0]);
    if (app->SIZE == -1){
        mx_printerr(INVALID_FIRS_LINE,app);
    }
    mx_city_malloc(app);
    initialize(app,lines_file);

    if(app->city[app->SIZE - 1] == NULL)
        mx_printerr(INVALID_N_ISLAND,app);
}

static void initialize(t_App *app, char **lines_file)
{
    for(int i = 1; lines_file[i] != NULL; i++)
    {
        char *word1 = NULL;
        char *word2 = NULL;
        int word3 = -1;

        if(parse_line(lines_file[i],&word1,&word2,&word3))
        {
            // TODO   занесити word1 and word2 в масив !!!!!
            push_element_in_island(word1,app);
            push_element_in_island(word2,app);
            // TODO заполнить matrix_a
            int i = search_index_island(word1,app);
            int j = search_index_island(word2,app);

            app->A_M[i * app->SIZE + j] = word3;
            app->A_M[j * app->SIZE + i] = word3; // разобраться !!!!!!!!!!!!
        }
        else
        {
            free(word1);
            free(word2);
            app->invalid_line_number = i + 1; 
            mx_printerr(LINE_ISNT_VALID,app); 
        }
        free(word1);
        free(word2);
    }

         //printf("%d\n", app->A_M[0 * app->SIZE + 1]);
        //  printf("1 - %d\n",app->A_M[1]);
        //  printf("2 - %d\n",  app->A_M[1 * app->SIZE + 0]);
                    ////////////////
        //   printf("%d\n",app->A_M[2]);
        //   printf("%d\n",app->A_M[0 * app->SIZE + 2]);
        //             ////////////////
        //   printf("%d\n", app->A_M[1 * app->SIZE + 2]);
        //   printf("%d\n",app->A_M[6]);
                    ////////////////
        // printf("%d\n", app->A_M[2 * app->SIZE + 3]);
        // printf("%d\n",app->A_M[11]);
}

static _Bool parse_line(char *line, char **word1, char **word2, int  *word3)
{
    int index_dash = mx_get_char_index(line,'-');
    int index_coma = mx_get_char_index(line,',');
    int len = mx_strlen(line);
    if(index_coma == -1 
    && index_dash == -1 
    && len == 0 
    && index_dash > index_coma)
        return false;

    *word1 = mx_strndup(line,index_dash);
    *word2 = mx_strndup(line + index_dash + 1, index_coma - index_dash - 1);
    char *number = strndup(line + index_coma + 1, len - index_coma - 1);
     if(!is_valid_word(*word1) || !is_valid_word(*word2)){
        return false;
    }
    
    *word3 = mx_atoi(number);
    if(*word3 == -1){
        return false;
    }
    free(number);
    return true;
}

static _Bool is_valid_word(char *s)
{
    if(mx_strlen(s) == 0)
        return false;
    for(int i = 0; s[i] != '\0'; i++){
        if(!mx_isalpha(s[i]))
            return false;
    }
    return true;
}

