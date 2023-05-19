/*
** EPITECH PROJECT, 2023
** label_management
** File description:
** label_management
*/

#include <stdlib.h>
#include "asm_head.h"

bool cmd_call_label(char *cmd)
{
    if (!cmd)
        return (false);
    for (size_t i = 0; cmd[i] != '\0'; i++)
        if (cmd[i] == LABEL_CHAR)
            return (true);
    return (false);
}

static char *get_label(char *cmd)
{
    size_t parser = 0;
    char *name = NULL;

    for (; cmd[parser] != LABEL_CHAR; parser++);
    name = ml_strdup(&cmd[parser + 1]);
    return (name);
}

bool is_existant_label(char *cmd, char **labels)
{
    char *label = get_label(cmd);
    bool ret_val = false;

    for (size_t i = 0; labels[i]; i++)
        if (ml_strcmp(label, labels[i]) == 0)
            ret_val = true;
    free(label);
    return (ret_val);
}
