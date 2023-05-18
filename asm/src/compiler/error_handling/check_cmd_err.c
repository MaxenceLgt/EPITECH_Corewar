/*
** EPITECH PROJECT, 2023
** check_cmd_validity
** File description:
** check_cmd_validity
*/

#include "asm_head.h"

static bool cmd_is_valid(UNUSED char *line, UNUSED char **labels)
{
    return (true);
}

int check_cmd_validity(compiler_t *info)
{
    for (size_t i = 2; info->f_lines[i]; i++){
        if (!cmd_is_valid(info->f_lines[i], info->labels))
            return (84);
    }
    return (0);
}
