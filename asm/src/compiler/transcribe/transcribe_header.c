/*
** EPITECH PROJECT, 2023
** transcribe_header
** File description:
** transcribe_header
*/

#include <stdio.h>
#include "asm_head.h"

static char *get_between_quote(char *line)
{
    size_t beg = 0;
    size_t end = 0;
    char *name = NULL;

    for (; line[beg] != '"'; beg++);
    for (end = beg + 1; line[end] != '"'; end++);
    if (end == beg + 1)
        return (NULL);
    name = ml_strndup(&line[beg + 1], end - beg - 1);
    return (name);
}

void transcribe_header(compiler_t *info)
{
    header_t header;
    char *name = get_between_quote(info->f_lines[0]);
    char *comment = get_between_quote(info->f_lines[1]);

    header.magic = COREWAR_EXEC_MAGIC;
    for (size_t i = 0; i <= PROG_NAME_LENGTH + 1; i++)
        header.prog_name[i] = '\0';
    for (size_t i = 0; i <= COMMENT_LENGTH + 1; i++)
        header.comment[i] = '\0';
    for (size_t i = 0; name && name[i] != '\0'; i++)
        header.prog_name[i] = name[i];
    for (size_t i = 0; comment && comment[i] != '\0'; i++)
        header.comment[i] = comment[i];
    header.prog_size = info->file_size;
    write(info->fd_out, &header, sizeof(header_t));
}
