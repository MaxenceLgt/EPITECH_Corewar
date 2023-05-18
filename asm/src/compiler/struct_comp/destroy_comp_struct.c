/*
** EPITECH PROJECT, 2023
** destroy_comp_struct
** File description:
** destroy_comp_struct
*/

#include <stdlib.h>
#include "asm_head.h"

void destroy_comp_struct(compiler_t *info)
{
    if (!info)
        return;
    if (info->f_lines)
        ml_destroy_str_array(info->f_lines);
    if (info->f_out)
        free(info->f_out);
    if (info->labels)
        ml_destroy_str_array(info->labels);
    free(info);
}
