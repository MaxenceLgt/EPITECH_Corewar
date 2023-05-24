/*
** EPITECH PROJECT, 2023
** presence_of_header
** File description:
** presence_of_header
*/

#include "asm_head.h"
#include <sys/types.h>
#include <stdbool.h>

static int skip_quote(char *buff, size_t *parser, char opt)
{
    size_t size_arg = 0;

    if (opt == 'n')
        (*parser) += 6;
    else if (opt == 'c')
        (*parser) += 9;
    for (; CHAR_IS(buff[(*parser)], "\t ") && buff[(*parser)] != '\0';
    (*parser)++);
    if (buff[(*parser)] != '"')
        return (84);
    (*parser)++;
    for (; buff[(*parser)] != '"' && buff[(*parser)] != '\n' &&
    buff[(*parser)] != '\0'; (*parser)++, size_arg++);
    if ((opt == 'n' && size_arg > PROG_NAME_LENGTH) ||
    (opt == 'c' && size_arg > COMMENT_LENGTH))
        return (84);
    return (0);
}

static void skip_comment(char *buff, size_t *parser)
{
    for (; buff[(*parser)] != '\n' && buff[(*parser)] != '\0'; (*parser)++);
}

static bool presence_of_comment(size_t parser, char *buff)
{
    if (skip_quote(buff, &parser, 'n') == 84 || buff[parser] != '"')
        return (false);
    for (parser++; buff[parser] != '.' && buff[parser] != '\0'; parser++) {
        if (buff[parser] == COMMENT_CHAR)
            skip_comment(buff, &parser);
        if (!CHAR_IS(buff[parser], "\n\t "))
            break;
    }
    if (buff[parser] == '\0' || ml_strncmp(&buff[parser], ".comment", 8) != 0)
        return (false);
    if (skip_quote(buff, &parser, 'c') == 84 || buff[parser] != '"')
        return (false);
    for (parser++ ; buff[parser] != '\n' && buff[parser] != '\0'; parser++)
        if (!CHAR_IS(buff[parser], " \t"))
            return (false);
    return (true);
}

bool presence_of_header(char *buff)
{
    size_t parser = 0;

    if (!buff)
        return (false);
    for (; CHAR_IS(buff[parser], "\n\t #") && buff[parser] != '\0'; parser++)
        if (buff[parser] == '#')
            skip_comment(buff, &parser);
    if (buff[parser] == '\0' || ml_strncmp(&buff[parser], ".name", 5) != 0)
        return (false);
    if (!presence_of_comment(parser, buff))
        return (false);
    return (true);
}
