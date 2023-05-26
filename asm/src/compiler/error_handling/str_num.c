/*
** EPITECH PROJECT, 2023
** str_num
** File description:
** str_num
*/

#include "asm_head.h"

bool str_num(char *str)
{
    size_t i = 0;

    if (str[i] == '-')
        i++;
    for (; str[i] != '\0'; i++)
        if (!CHAR_IS_NUM(str[i]))
            return (false);
    return (true);
}
