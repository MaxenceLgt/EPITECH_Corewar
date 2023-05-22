/*
** EPITECH PROJECT, 2023
** calculate_prog_size
** File description:
** calculate_prog_size
*/

#include "asm_head.h"

bool codingbyte_is_present(char *cmd)
{
    if (ml_strcmp(cmd, "live") == 0 || ml_strcmp(cmd, "fork") == 0 ||
    ml_strcmp(cmd, "lfork") == 0 || ml_strcmp(cmd, "zjmp") == 0)
        return (false);
    return (true);
}

static int count_size_cmd(char **cmd)
{
    int result = 1;

    if (is_in_index_lst(cmd[0]))
        return (manage_index_arg(cmd) + result);
    for (size_t i = 1; cmd[i]; i++){
        if (cmd[i][0] == DIRECT_CHAR) {
            result += DIR_SIZE;
            continue;
        } if (cmd[i][0] == 'r') {
            result += 1;
            continue;
        } result += IND_SIZE;
    }
    if (codingbyte_is_present(cmd[0]))
        result += 1;
    return (result);
}

int calculate_size_cmd(char *cmd)
{
    int size_line = 0;
    size_t parser = 0;
    char **cmd_arr = ml_str_tok(cmd, " \t,");

    if (!cmd_arr)
        return (size_line);
    if (line_is_label(cmd_arr[parser]) && !cmd_arr[parser + 1])
        return (size_line);
    if (line_is_label(cmd_arr[parser]))
        parser++;
    size_line = count_size_cmd(&cmd_arr[parser]);
    return (size_line);
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
