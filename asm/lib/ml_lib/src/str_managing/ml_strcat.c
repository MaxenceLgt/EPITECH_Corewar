/*
** EPITECH PROJECT, 2022
** ml_strcat
** File description:
** ml_strcat
*/

#include "ml_str_h.h"

void ml_strcat(char **dest, char const *src)
{
    size_t i = 0;
    size_t dest_max = ml_strlen((*dest));
    size_t srclen = ml_strlen(src);

    for (; i != srclen; i++)
        (*dest)[dest_max + i] = src[i];
    (*dest)[dest_max + i] = '\0';
}
