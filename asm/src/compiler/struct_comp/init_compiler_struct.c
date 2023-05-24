/*
** EPITECH PROJECT, 2023
** init_compiler_struct
** File description:
** init_compiler_struct
*/

#include <stdlib.h>
#include "asm_head.h"

static char *get_output_file(const char *file)
{
    char *output = output = malloc(sizeof(char) * (ml_strlen(file) + 2));

    if (!output)
        return (NULL);
    ml_strncpy(&output, file, ml_strlen(file) - 1);
    ml_strcat(&output, "cor");
    return (output);
}

compiler_t *init_compiler(const char *file)
{
    compiler_t *info = malloc(sizeof(compiler_t));
    char *buffer = ml_get_file_content(file);

    if (!info || !buffer)
        return (NULL);
    info->f_out = get_output_file(file);
    info->f_lines = convert_file_content(buffer);
    info->labels = get_labels(info->f_lines);
    if (info->labels && ml_strcmp(info->labels[0], "Invalid label") == 0) {
        free(buffer);
        destroy_comp_struct(info);
        exit(84);
    }
    free(buffer);
    return (info);
}
