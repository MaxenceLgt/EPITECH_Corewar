/*
** EPITECH PROJECT, 2023
** ml_atoi_b
** File description:
** ml_atoi_b
*/

#include <sys/types.h>
#include "ml_str_h.h"

u_int16_t ml_atoi_b(char *str)
{
    u_int16_t nb = 0;
    size_t parse = 0;

    if (!str || str[0] == '\0')
        return (nb);
    if (str[0] == '-')
        parse++;
    for (; ml_char_isnum(str[parse]) && str[parse]; parse++) {
        nb *= 10;
        nb += str[parse] - 48;
    }
    if (nb > 32767)
        return (0);
    if (str[0] == '-')
        nb *= -1;
    return (nb);
}
