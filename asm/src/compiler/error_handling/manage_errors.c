/*
** EPITECH PROJECT, 2023
** manage_errors
** File description:
** manage_errors
*/

#include "asm_head.h"

int manage_errors(const char *file)
{
    if (!file_is_readable(file))
        return (84);
    return (0);
}
