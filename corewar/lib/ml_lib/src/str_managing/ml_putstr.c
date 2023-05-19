/*
** EPITECH PROJECT, 2022
** ml_putstr
** File description:
** ml_putstr
*/

#include "ml_str_h.h"
#include <unistd.h>

void ml_putstr(char const *str)
{
    write(1, str, ml_strlen(str));
}

void ml_putstr_error(char const *str)
{
    write(2, str, ml_strlen(str));
}
