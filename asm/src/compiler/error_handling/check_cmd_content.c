/*
** EPITECH PROJECT, 2023
** check_cmd_content
** File description:
** check_cmd_content
*/

#include "asm_head.h"
#include "define_head.h"

static bool is_existing_cmd(char *cmd)
{
    for (size_t i = 0; op_tab[i].mnemonique != 0; i++)
        if (ml_strcmp(op_tab[i].mnemonique, cmd) == 0)
            return (true);
    return (false);
}

static bool is_valid_arg(UNUSED char *cmd, UNUSED char **labels,
UNUSED op_t info, UNUSED size_t pos)
{
    return (true);
}

bool verify_cmd_and_args(char **cmd, char **labels)
{
    size_t tab_parser = 0;

    if (!is_existing_cmd(cmd[0]))
        return (false);
    for (; ml_strcmp(op_tab[tab_parser].mnemonique, cmd[0]); tab_parser++);
    if ((int)(ml_count_array_size(CONST cmd) - 1) !=
    op_tab[tab_parser].nbr_args)
        return (false);
    for (size_t i = 1; cmd[i]; i++)
        if (!is_valid_arg(cmd[i], labels, op_tab[tab_parser], i))
            return (false);
    return (true);
}
