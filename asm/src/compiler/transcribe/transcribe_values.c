/*
** EPITECH PROJECT, 2023
** transcribe_values
** File description:
** transcribe_values
*/

#include "asm_head.h"

void transcribe_register(char *nb_str, int fd_out)
{
    int int_nb = ml_atoi(nb_str);
    char char_nb = int_nb;

    write(fd_out, &char_nb, 1);
}

void transcribe_direct_or_ind(char *str, int fd_out)
{
    u_int32_t dir = 0;
    u_int16_t ind = 0;

    if (str[0] == DIRECT_CHAR) {
        dir = ml_atoi(&str[1]);
        change_endians(&dir, sizeof(u_int32_t));
        write(fd_out, &dir, sizeof(u_int32_t));
    } else {
        ind = ml_atoi_b(str);
        change_endians(&ind, sizeof(u_int16_t));
        write(fd_out, &ind, sizeof(u_int16_t));
    }
}

void transcribe_index(char *str, int fd_out)
{
    u_int16_t ind = 0;

    if (str[0] == ':' || str[1] == ':')
        return;
    if (str[0] == DIRECT_CHAR)
        ind = ml_atoi_b(&str[1]);
    else
        ind = ml_atoi_b(str);
    change_endians(&ind, sizeof(u_int16_t));
    write(fd_out, &ind, sizeof(u_int16_t));
}
