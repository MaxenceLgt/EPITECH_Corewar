/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "ml_str_h.h"

char *ml_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (ml_strlen(src) + 1));
    size_t i = 0;

    if (!str)
        return (NULL);
    for (; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}

char *ml_strndup(char const *src, size_t size)
{
    char *str = NULL;
    size_t i = 0;

    if (ml_strlen(src) <= size)
        return (ml_strdup(src));
    str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return (NULL);
    for (; i != size; i++)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}
