/*
** EPITECH PROJECT, 2023
** presence_of_header
** File description:
** presence_of_header
*/

#include "asm_head.h"
#include <sys/types.h>
#include <stdbool.h>

static void skip_quote(char *buff, size_t *parser, char opt)
{
    if (opt == 'n')
        (*parser) += 6;
    else if (opt == 'c')
        (*parser) += 9;
    for (; CHAR_IS(buff[(*parser)], "\t ") && buff[(*parser)] != '\0';
    (*parser)++);
    if (buff[(*parser)] != '"')
        return;
    (*parser)++;
    for (; buff[(*parser)] != '"' && buff[(*parser)] != '\n' &&
    buff[(*parser)] != '\0'; (*parser)++);
}

bool presence_of_header(char *buff)
{
    size_t parser = 0;

    if (!buff)
        return (false);
    for (; CHAR_IS(buff[parser], "\n\t ") && buff[parser] != '\0'; parser++);
    if (buff[parser] == '\0' || ml_strncmp(&buff[parser], ".name", 5) != 0)
        return (false);
    skip_quote(buff, &parser, 'n');
    if (buff[parser] != '"')
        return (false);
    parser++;
    for (; CHAR_IS(buff[parser], "\n\t ") && buff[parser] != '\0'; parser++);
    if (buff[parser] == '\0' || ml_strncmp(&buff[parser], ".comment", 8) != 0)
        return (false);
    skip_quote(buff, &parser, 'c');
    if (buff[parser] != '"')
        return (false);
    return (true);
}
