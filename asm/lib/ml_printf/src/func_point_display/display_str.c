/*
** EPITECH PROJECT, 2023
** display_str
** File description:
** display_str
*/

#include <stdarg.h>
#include "display_pf_head.h"

int display_str(va_list list, size_t *count)
{
    char *str = va_arg(list, char *);

    display_str_pf(str, count);
    return (1);
}
