#include "libmx.h"

static _Bool parse_line(char *line, char **word1, char **word2, int  *word3);
static _Bool is_valid_word(char *s);
static void init_matrix_A(t_App *app);
static void push_element_in_city(char *elem, t_App *app);

void mx_check_text_file(t_App *app,  char *str)
{
    app->parsed_lines_array = mx_strsplit(str,'\n');
    char **lines_file = app->parsed_lines_array;
    
    app->SIZE = mx_atoi(lines_file[0]);
    if(app->SIZE == -1){
        mx_printerr(INVALID_FIRS_LINE,app);
    }
    mx_city_malloc(app);
    init_matrix_A(app);

    for(int i = 1; lines_file[i] != NULL; i++)
    {
        char *word1 = NULL;
        char *word2 = NULL;
        int word3 = -1;

        // if(lines_file[i] == NULL)
        // {
        //     mx_printerr(INVALID_N_ISLAND,app);
        // }
        if(parse_line(lines_file[i],&word1,&word2,&word3))
        {
            // TODO   занесити word1 and word2 в масив !!!!!
            push_element_in_city(word1,app);
            push_element_in_city(word2,app);
            // TODO заполнить matrix_a

        }
        else
        {
            free(word1);
            free(word2);
            app->invalid_line_number = i + 1; // Разобрать как вывести эту ошибку!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            mx_printerr(LINE_ISNT_VALID,app); 
        }
        free(word1);
        free(word2);
    }
    // if(lines_file[app->SIZE + 1] != NULL)
    //     mx_printerr(INVALID_N_ISLAND,app);
}

static _Bool parse_line(char *line, char **word1, char **word2, int  *word3)
{
    int index_dash = mx_get_char_index(line,'-');
    int index_coma = mx_get_char_index(line,',');
    int len = mx_strlen(line);
    if(index_coma == -1 || index_dash == -1 || len == 0 || index_dash > index_coma)
        return false;

    *word1 = mx_strndup(line,index_dash);
    *word2 = mx_strndup(line + index_dash + 1, index_coma - index_dash - 1);
    char *number = strndup(line + index_coma + 1, len - index_coma - 1);
     if(!is_valid_word(*word1) || !is_valid_word(*word2))
    {
        return false;
    }
    // printf("%s\n",*word1);
    // printf("%s\n",*word2);

    *word3 = mx_atoi(number);
    if(*word3 == -1)
    {
        return false;
    }
    free(number);
    return true;
}

static _Bool is_valid_word(char *s)
{
    if(mx_strlen(s) == 0)
        return false;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(!mx_isalpha(s[i]))
            return false;
    }
    return true;
}

static void init_matrix_A(t_App *app)
{
    app->A_M = malloc(app->SIZE * app->SIZE * sizeof(int));

    for(int i = 1; i < app->SIZE; i++)
    {
        for(int j = 0; j < app->SIZE; j++)
        {
            if(i == j)
            {
                app->A_M[i * app->SIZE + j] = 0;
            }
            else
                app->A_M[i * app->SIZE + j] = 1000000000;
        }
    }
}

static void push_element_in_city(char *elem, t_App *app)
{
    char **island = app->city;
    int i;

    for(i = 0; i < app->SIZE; i++)
    {
        if(island[i] == NULL)
            break;

        if(mx_strcmp(island[i], elem) == 0)
            return;
    }

    if(i < app->SIZE)
        island[i] = mx_strdup(elem);

    else
        mx_printerr(INVALID_N_ISLAND, app);    
}

