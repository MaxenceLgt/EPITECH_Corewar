/*
** EPITECH PROJECT, 2023
** calculate_prog_size
** File description:
** calculate_prog_size
*/

#include "asm_head.h"

static int calculate_size_cmd(char *cmd)
{
    return (0);
}

int calculate_prog_size(char **prog)
{
    int result = 0;

    if (!prog)
        return (0);
    for (size_t i = 0; prog[i]; i++)
        result += calculate_size_cmd(prog[i]);
    return (result);
}
