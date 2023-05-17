/*
** EPITECH PROJECT, 2023
** compile_asm_file
** File description:
** compile_asm_file
*/

#include "asm_head.h"

int compile_asm_code(char *file)
{
    compiler_t *info = NULL;

    if (manage_errors(file) == 84)
        return (84);
    info = init_compiler(file);
    return (0);
}
