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
    size_t parser = 0;
    bool res = true;

    if (comment_is_present(line))
        cmd = delete_comment(line);
    else
        cmd = ml_strdup(line);
    arr_cmd = ml_str_tok(cmd, " \t,");
    free(cmd);
    res = line_is_label(arr_cmd[parser]);
    if (res && !arr_cmd[parser + 1]) {
        ml_destroy_str_array(arr_cmd);
        return (true);
    } else if (res && arr_cmd[parser + 1])
        parser++;
    res = verify_cmd_and_args(&arr_cmd[parser], labels);
    ml_destroy_str_array(arr_cmd);
    return (res);
}

int check_cmd_validity(compiler_t *info)
{
    for (size_t i = 2; info->f_lines[i]; i++){
        if (!cmd_is_valid(info->f_lines[i], info->labels))
            return (84);
    }
    return (0);
}
