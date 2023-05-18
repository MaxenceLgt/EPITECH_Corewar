/*
** EPITECH PROJECT, 2023
** convert_file_content
** File description:
** convert_file_content
*/

#include <stdlib.h>
#include "asm_head.h"
#include "define_head.h"

static bool is_empty_string(const char *str)
{

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == COMMENT_CHAR)
            break;
        if (!CHAR_IS(str[i], " \t"))
            return (false);
    }
    return (true);
}

static void delete_str_from_tab(char ***tab, size_t pos)
{
    for (; (*tab)[pos] && (*tab)[pos + 1]; pos++){
        free((*tab)[pos]);
        (*tab)[pos] = ml_strdup((*tab)[pos + 1]);
    }
    (*tab)[pos] = NULL;
}

char **convert_file_content(char *buffer)
{
    char **arr_buffer = ml_str_tok(buffer, "\n");
    size_t i = 0;

    if (!arr_buffer)
        return (NULL);
    while (arr_buffer[i]) {
        if (is_empty_string(arr_buffer[i]))
            delete_str_from_tab(&arr_buffer, i);
        else
            i++;
    }
    return (arr_buffer);
}
