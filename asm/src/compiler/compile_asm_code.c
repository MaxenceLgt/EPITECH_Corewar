/*
** EPITECH PROJECT, 2023
** compile_asm_file
** File description:
** compile_asm_file
*/

#include "asm_head.h"

int compile_asm_code(char *file)
{
    if (manage_errors(file) == 84)
        return (84);
    return (0);
}
