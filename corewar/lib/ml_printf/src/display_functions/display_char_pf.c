/*
** EPITECH PROJECT, 2022
** display_char_pf
** File description:
** display_char_pf
*/

#include <unistd.h>

void display_char_pf(const char c, size_t *count)
{
    write(1, &c, 1);
    (*count) += 1;
}
