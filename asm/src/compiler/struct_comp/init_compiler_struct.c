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
    char *output = NULL;
    size_t count = 0;

    for (; file[count] != '.' && file[count] != '\0'; count++);
    if (file[count] == '\0')
        return (NULL);
    count++;
    output = malloc(sizeof(char) * count + 4);
    if (!output)
        return (NULL);
    output[0] = '\0';
    ml_strncat(&output, file, count);
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
    ml_printf("%s\n", info->f_out);
    ml_display_str_array(info->f_lines);
    ml_display_str_array(info->labels);
    free(buffer);
    return (info);
}
