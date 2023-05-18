/*
** EPITECH PROJECT, 2023
** check_cmd_validity
** File description:
** check_cmd_validity
*/

#include <stdlib.h>
#include "asm_head.h"

static bool cmd_is_valid(char *line, char **labels)
{
    char *cmd = NULL;
    char **arr_cmd = NULL;
    bool is_label = false;
    size_t parser = 0;

    if (comment_is_present(line))
        cmd = delete_comment(line);
    else
        cmd = ml_strdup(line);
    arr_cmd = ml_str_tok(cmd, " \t,");
    free(cmd);
    is_label = line_is_label(arr_cmd[parser]);
    if (is_label && !arr_cmd[parser + 1])
        return (true);
    else if (is_label && arr_cmd[parser + 1])
        parser++;
    return (verify_cmd_and_args(&arr_cmd[parser], labels));
}

int check_cmd_validity(compiler_t *info)
{
    for (size_t i = 2; info->f_lines[i]; i++){
        if (!cmd_is_valid(info->f_lines[i], info->labels))
            return (84);
    }
    return (0);
}
