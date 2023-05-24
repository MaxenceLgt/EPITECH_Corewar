/*
** EPITECH PROJECT, 2023
** get_labels
** File description:
** get_labels
*/

#include <stdlib.h>
#include "asm_head.h"
#include "define_head.h"

static void set_invalid_label(char ***label)
{
    ml_destroy_str_array((*label));
    (*label) = NULL;
    (*label) = ml_add_str_to_array((*label), "Invalid label");
}

bool line_is_label(char *line)
{
    char **line_array = ml_str_tok(line, "\t ");
    size_t last_pos = 0;
    bool return_val = false;

    if (!line_array || !line_array[0])
        return (return_val);
    last_pos = ml_strlen(line_array[0]);
    if (line_array[0][last_pos - 1] == ':')
        return_val = true;
    ml_destroy_str_array(line_array);
    return (return_val);
}

static bool label_is_in_lst(char **lst, char *label)
{
    if (!label)
        return (true);
    if (!lst)
        return (false);
    for (size_t i = 0; lst[i]; i++)
        if (ml_strcmp(label, lst[i]) == 0)
            return (true);
    return (false);
}

static char *get_label_name(char *line)
{
    char **line_array = ml_str_tok(line, "\t ");
    char *name = NULL;
    size_t last_pos = 0;

    if (!line_array || !line_array[0])
        return (NULL);
    last_pos = ml_strlen(line_array[0]);
    name = ml_strndup(line_array[0], last_pos - 1);
    for (size_t i = 0; name[i] != '\0'; i++) {
        if (!CHAR_IS_ALNUM(name[i]) && name[i] != '_') {
            free(name);
            name = NULL;
            break;
        }
    }
    ml_destroy_str_array(line_array);
    return (name);
}

char **get_labels(char **lines)
{
    char **label = NULL;
    char *label_name = NULL;

    for (size_t i = 0; lines && lines[i]; i++) {
        if (!line_is_label(lines[i]))
            continue;
        label_name = get_label_name(lines[i]);
        if (label_is_in_lst(label, label_name)) {
            free(label_name);
            set_invalid_label(&label);
            break;
        } else {
            label = ml_add_str_to_array(label, label_name);
            free(label_name);
        }
        label_name = NULL;
    }
    return (label);
}
