/*
** EPITECH PROJECT, 2023
** transcribe_label
** File description:
** transcribe_label
*/

#include "asm_head.h"

static void count_bytes(size_t pos_lab, size_t my_pos, char **lines,
int fd_out)
{
    u_int16_t res = 0;

    for (size_t i = my_pos - 1; i >= pos_lab; i--)
        res -= calculate_size_cmd(lines[i]);
    if (res != 0) {
        change_endians(&res, sizeof(u_int16_t));
        write(fd_out, &res, 2);
        return;
    }
    for (size_t i = my_pos; i < pos_lab; i++)
        res += calculate_size_cmd(lines[i]);
    change_endians(&res, sizeof(u_int16_t));
    write(fd_out, &res, 2);
}

void transcribe_label(compiler_t *info, size_t pos, char *name)
{
    char **temp = NULL;
    size_t name_l = ml_strlen(name);

    for (size_t i = pos; i >= 2; i--) {
        temp = ml_str_tok(info->f_lines[i], " \t,");
        if (ml_strncmp(temp[0], name, name_l) == 0 && temp[0][name_l] == ':') {
            ml_destroy_str_array(temp);
            return (count_bytes(i, pos, info->f_lines, info->fd_out));
        }
        ml_destroy_str_array(temp);
    }
    for (size_t i = pos; info->f_lines[i]; i++) {
        temp = ml_str_tok(info->f_lines[i], " \t,");
        if (ml_strncmp(temp[0], name, name_l) == 0 && temp[0][name_l] == ':') {
            ml_destroy_str_array(temp);
            return (count_bytes(i, pos, info->f_lines, info->fd_out));
        }
        ml_destroy_str_array(temp);
    }
}
