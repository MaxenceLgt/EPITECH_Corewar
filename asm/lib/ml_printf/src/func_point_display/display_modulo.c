/*
** EPITECH PROJECT, 2023
** display_modulo
** File description:
** display_modulo
*/

#include <stdarg.h>
#include "display_pf_head.h"

int display_modulo(va_list list, size_t *count)
{
    (void)list;
    display_char_pf('%', count);
    return (1);
}
