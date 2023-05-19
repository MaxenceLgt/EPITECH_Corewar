/*
** EPITECH PROJECT, 2023
** index_management
** File description:
** index_management
*/

#include "asm_head.h"

bool is_in_index_lst(char *cmd)
{
    for (size_t i = 0; index_tab[i].cmd != 0; i++)
        if (ml_strcmp(cmd, index_tab[i].cmd) == 0)
            return (true);
    return (false);
}

int manage_index_arg(char **args)
{
    int result = 0;

    for (size_t parser = 1; args[parser]; parser++) {
        if (args[parser][0] == 'r')
            result += 1;
        else
            result += IND_SIZE;
    }
    if (codingbyte_is_present(args[0]))
        result += 1;
    return (result);
}
