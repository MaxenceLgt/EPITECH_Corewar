/*
** EPITECH PROJECT, 2023
** ml_atof
** File description:
** ml_atof
*/

#include <stdbool.h>
#include "ml_str_h.h"

static void get_int_part(double *res, size_t *parser, const char *str)
{
    for (; str[(*parser)] != '.' && ml_char_isnum((str[(*parser)])) &&
    str[(*parser)] != '\0'; (*parser)++) {
        (*res) *= (double)10;
        (*res) += (double)(str[(*parser)] - 48);
    }
    if (str[(*parser)] == '.')
        (*parser)++;
}

static void get_float_part(double *res, const char *str)
{
    size_t div = 10;

    for (size_t parser = 0; ml_char_isnum(str[parser]) && str[parser] != '\0';
    parser++) {
        (*res) += (double)(str[parser] - 48) / div;
        div *= 10;
    }
}

double ml_atof(const char *str)
{
    double res = 0;
    size_t parser = 0;

    if (!str || str[0] == '\0')
        return (0);
    if (str[0] == '-')
        return (-ml_atof(&str[1]));
    get_int_part(&res, &parser, &str[parser]);
    if (!ml_char_isnum(str[parser]))
        return (res);
    get_float_part(&res, &str[parser]);
    return (res);
}
