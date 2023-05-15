/*
** EPITECH PROJECT, 2023
** ml_dup_array
** File description:
** ml_dup_array
*/

#include "ml_array_h.h"
#include "ml_str_h.h"
#include <stdlib.h>

char **ml_dup_array(const char **array)
{
    size_t size = ml_count_array_size(array);
    char **dup_array = ml_create_str_array(size);
    size_t parser = 0;

    if (!dup_array)
        return (NULL);
    for (; array[parser]; parser++)
        dup_array[parser] = ml_strdup(array[parser]);
    dup_array[parser] = NULL;
    return (dup_array);
}
