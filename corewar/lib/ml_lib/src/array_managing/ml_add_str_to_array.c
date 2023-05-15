/*
** EPITECH PROJECT, 2023
** ml_add_str_to_array
** File description:
** ml_add_str_to_array
*/

#include "ml_array_h.h"
#include "ml_str_h.h"
#include <stdlib.h>

char **ml_add_str_to_array(char **array, const char *str)
{
    size_t size = ml_count_array_size((const char **)array);
    char **n_array = ml_create_str_array(size + 1);

    if (!n_array)
        return (NULL);
    if (array){
        n_array = ml_copy_array(n_array, (const char **)array);
        ml_destroy_str_array(array);
    }
    n_array[size] = ml_strdup(str);
    n_array[size + 1] = NULL;
    return (n_array);
}
