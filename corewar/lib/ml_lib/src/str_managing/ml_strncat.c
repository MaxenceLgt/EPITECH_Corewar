/*
** EPITECH PROJECT, 2022
** ml_strncat
** File description:
** ml_strncat
*/

#include "ml_str_h.h"

void ml_strncat(char **dest, char const *src, size_t nb)
{
    size_t i = 0;
    size_t dest_max = ml_strlen((*dest));

    if (nb > ml_strlen(src))
        ml_strcat(dest, src);
    else
        for (; i != nb; i++)
            (*dest)[dest_max + i] = src[i];
    (*dest)[dest_max + i] = '\0';
}
