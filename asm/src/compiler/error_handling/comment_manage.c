/*
** EPITECH PROJECT, 2023
** comment_manage
** File description:
** comment_manage
*/

#include "asm_head.h"

bool comment_is_present(char *line)
{
    if (!line)
        return (false);
    for (size_t i = 0; line[i] != '\0'; i++)
        if (line[i] == COMMENT_CHAR)
            return (true);
    return (false);
}

char *delete_comment(char *line)
{
    size_t count = 0;
    char *cmd = NULL;

    for (; line[count] != COMMENT_CHAR; count++);
    cmd = ml_strndup(line, count);
    return (cmd);
}
