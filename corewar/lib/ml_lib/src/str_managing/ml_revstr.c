/*
** EPITECH PROJECT, 2022
** ml_revstr
** File description:
** ml_revstr
*/

#include "ml_str_h.h"

void ml_revstr(char **str)
{
    size_t max = ml_strlen((*str));
    char tmp = '\0';

    if (max == 0)
        return;
    max--;
    for (size_t i = 0; i < max; i++, max--) {
        tmp = (*str)[i];
        (*str)[i] = (*str)[max];
        (*str)[max] = tmp;
    }
}
