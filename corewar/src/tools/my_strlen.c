/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** strlen
*/

#include "corewar_header.h"

int my_strlen(char const *str)
{
    unsigned int i = 0;

    for (; str[i]; i++);
    return i;
}
