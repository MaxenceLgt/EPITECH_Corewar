/*
** EPITECH PROJECT, 2022
** my_putstr_count
** File description:
** my_putstr_count
*/

#include "display_pf_head.h"

void display_str_pf(char const *str, size_t *count)
{
    size_t len = strlen_pf(str);

    write(1, str, len);
    (*count) += len;
}
