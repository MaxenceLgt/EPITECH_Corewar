/*
** EPITECH PROJECT, 2023
** display_int
** File description:
** display_int
*/

#include <stdarg.h>
#include "display_pf_head.h"

int display_int(va_list list, size_t *count)
{
    int nbr = va_arg(list, int);

    display_int_pf(nbr, count);
    return (1);
}
