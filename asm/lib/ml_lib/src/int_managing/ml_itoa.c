/*
** EPITECH PROJECT, 2023
** ml_itoa
** File description:
** ml_itoa
*/

#include <stdlib.h>
#include "ml_str_h.h"
size_t ml_nbrlen(int nbr);

static char *set_str_zero(char **str)
{
    (*str)[0] = '0';
    (*str)[1] = '\0';
    return (0);
}

static void add_nb_to_str(char **str, char *temp)
{
    (*str)[0] = '-';
    (*str)[1] = '\0';
    ml_strcat(str, temp);
    free(temp);
}

char *ml_itoa(int nb)
{
    char *temp = NULL;
    size_t parser = 0;
    char *str = malloc(sizeof(char) * (ml_nbrlen(nb) + 1));

    if (!str)
        return (NULL);
    if (nb < 0) {
        temp = ml_itoa(-nb);
        add_nb_to_str(&str, temp);
        return (str);
    }
    if (nb == 0 || nb == -0)
        return (set_str_zero(&str));
    for (; nb != 0; parser++, nb /= 10)
        str[parser] = (nb % 10) + 48;
    str[parser] = '\0';
    ml_revstr(&str);
    return (str);
}
