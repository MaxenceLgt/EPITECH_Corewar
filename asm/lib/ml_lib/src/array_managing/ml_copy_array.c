/*
** EPITECH PROJECT, 2023
** ml_copy_array
** File description:
** ml_copy_array
*/

#include <stdlib.h>
#include "ml_array_h.h"
#include "ml_str_h.h"

char **ml_copy_array(char **array_dest, const char **array_src)
{
    size_t parser = 0;

    if (!array_dest || !array_src)
        return (NULL);
    for (; array_src[parser]; parser++)
        array_dest[parser] = ml_strdup(array_src[parser]);
    array_dest[parser] = NULL;
    return (array_dest);
}
