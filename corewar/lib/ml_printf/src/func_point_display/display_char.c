/*
** EPITECH PROJECT, 2023
** display_char
** File description:
** display_char
*/

#include <stdarg.h>
#include "display_pf_head.h"

int display_char(va_list list, size_t *count)
{
    char my_char = va_arg(list, int);

    display_char_pf(my_char, count);
    return (1);
}
