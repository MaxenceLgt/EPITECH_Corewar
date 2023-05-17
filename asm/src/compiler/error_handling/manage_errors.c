/*
** EPITECH PROJECT, 2023
** manage_errors
** File description:
** manage_errors
*/

#include <stdlib.h>
#include "asm_head.h"

int manage_errors(const char *file)
{
    char *buffer = NULL;
    int exit_value = 0;

    if (!file_is_readable(file))
        return (84);
    buffer = ml_get_file_content(file);
    if (!presence_of_header(buffer))
        exit_value = 84;
    free(buffer);
    return (exit_value);
}
