/*
** EPITECH PROJECT, 2023
** transcribe_body
** File description:
** transcribe_body
*/

#include "asm_head.h"

static char get_cmd_code(char *cmd)
{
    for (size_t i = 0; op_tab[i].mnemonique != 0; i++)
        if (ml_strcmp(op_tab[i].mnemonique, cmd) == 0)
            return (op_tab[i].code);
    return (0);
}

static void transcribe_codingbyte(char **args, compiler_t *info)
{
    UNUSED char test[8] = "00000000";
    u_int8_t res = 0;

    for (size_t i = 0, byte = 0; args[i]; i++, byte += 2) {
        test[byte] = '1';
        test[byte + 1] = '1';
        if (args[i][0] == DIRECT_CHAR)
            test[byte + 1] = '0';
        if (args[i][0] == 'r')
            test[byte] = '0';
    }
    for (size_t i = 0; i < 8; i++) {
        res <<= 1;
        if (test[i] == '1')
            res |= 1;
    }
    write(info->fd_out, &res, 1);
}

static void transcribe_cmd(char **temp, compiler_t *info, size_t pos)
{
    char cmd = get_cmd_code(temp[0]);

    write(info->fd_out, &cmd, 1);
    if (codingbyte_is_present(temp[0]))
        transcribe_codingbyte(&temp[1], info);
    for (size_t i = 1; temp[i]; i++) {
        if (temp[i][0] == 'r') {
            transcribe_register(&temp[i][1], info->fd_out);
            continue;
        }
        if (is_in_index_lst(temp[0])) {
            transcribe_index(temp[i], info, pos);
            continue;
        }
        transcribe_direct_or_ind(temp[i], info, pos);
    }
}

void transcribe_body(char **body, compiler_t *info)
{
    char **temp = NULL;

    if (!body)
        return;
    for (size_t i = 0; body[i]; i++) {
        temp = ml_str_tok(body[i], " ,\t");
        if (line_is_label(temp[0]) && !temp[1]) {
            ml_destroy_str_array(temp);
            continue;
        }
        if (line_is_label(temp[0]))
            transcribe_cmd(&temp[1], info, i + 2);
        else
            transcribe_cmd(temp, info, i + 2);
        ml_destroy_str_array(temp);
    }
}
