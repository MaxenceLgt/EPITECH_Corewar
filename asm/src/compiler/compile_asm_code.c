/*
** EPITECH PROJECT, 2023
** compile_asm_file
** File description:
** compile_asm_file
*/

#include <fcntl.h>
#include "asm_head.h"

static int open_file(compiler_t *info)
{
    int fd = open(info->f_out, O_RDWR | O_CREAT, 0644);

    return (fd);
}

int compile_asm_code(const char *file)
{
    compiler_t *info = NULL;

    if (manage_errors(file) == 84)
        return (84);
    info = init_compiler(file);
    if (check_cmd_validity(info) == 84) {
        destroy_comp_struct(info);
        return (84);
    }
    info->fd_out = open_file(info);
    remove_comment_to_tab(&info->f_lines);
    if (info->fd_out != -1) {
        transcribe_header(info);
    }
    destroy_comp_struct(info);
    return (0);
}
