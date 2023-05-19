/*
** EPITECH PROJECT, 2023
** check_cmd_content
** File description:
** check_cmd_content
*/

#include "asm_head.h"
#include "define_head.h"

static bool str_is_num(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (!CHAR_IS_NUM(str[i]))
            return (false);
    return (true);
}

static bool is_existing_cmd(char *cmd)
{
    for (size_t i = 0; op_tab[i].mnemonique != 0; i++)
        if (ml_strcmp(op_tab[i].mnemonique, cmd) == 0)
            return (true);
    return (false);
}

int get_type(char *cmd)
{
    if (cmd[0] == DIRECT_CHAR)
        return (T_DIR);
    else if (cmd[0] == 'r')
        return (T_REG);
    return (T_IND);
}

static bool is_valid_arg(char *cmd, char **labels, op_t info, size_t pos)
{
    int type = 0;
    if (!cmd)
        return (false);
    type = get_type(cmd);
    if (!(type & info.type[pos]))
        return (false);
    if (type == T_REG && (!str_is_num(&cmd[1]) || ml_atoi(&cmd[1]) >
    REG_NUMBER))
        return (false);
    if (cmd_call_label(cmd) && !is_existant_label(cmd, labels))
        return (false);
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
        if (!is_valid_arg(cmd[i], labels, op_tab[tab_parser], i - 1))
            return (false);
    return (true);
}
