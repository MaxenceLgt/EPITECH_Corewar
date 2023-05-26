/*
** EPITECH PROJECT, 2023
** ml_atoi
** File description:
** ml_atoi
*/

#include <sys/types.h>
#include <stdbool.h>
#include "ml_str_h.h"

int ml_atoi(const char *str)
{
    int nb = 0;

    if (!str || str[0] == '\0')
        return (0);
    if (ml_strlen(str) == 11 && ml_strncmp(str, "-2147483648", 11))
        return (-2147483648);
    if (str[0] == '-')
        return (- ml_atoi(&str[1]));
    for (size_t parse = 0; ml_char_isnum(str[parse]) && str[parse]; parse++) {
        nb *= 10;
        nb += str[parse] - 48;
    }
    return (nb);
}
