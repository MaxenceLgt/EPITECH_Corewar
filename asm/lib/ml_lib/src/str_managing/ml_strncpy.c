/*
** EPITECH PROJECT, 2022
** ml_strncpy
** File description:
** ml_strncpy
*/

#include "ml_str_h.h"

void ml_strncpy(char **dest ,char const *src, size_t n)
{
    size_t count = 0;

    if (ml_strlen(src) <= n){
        ml_strcpy(dest, src);
    } else {
        for (;count != n; count++)
            (*dest)[count] = src[count];
        (*dest)[count] = '\0';
    }
}
