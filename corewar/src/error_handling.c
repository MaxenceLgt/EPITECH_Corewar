/*
** EPITECH PROJECT, 2023
** error_handling
** File description:
** corewar
*/

#include "corewar_header.h"
#include <stdio.h>

static int check_hexa(char **av)
{
    for (int i = 0; av[2][i]; i++)
        if (CHECK_HEXA);
        else
            return 84;
    return 0;
}

static int check_nb(char *av)
{
    for (int i = 0; av[i]; i++)
        if (av[i] >= '0' && av[i] <= '9');
        else
            return 84;
    return 0;
}

int error_handling(char **av, int ac)
{
    int i;

    for (i = 0; i < ac; i++) {
        if (ml_strcmp(av[i], "-dump") == 0)
            if (check_nb(av[i + 1]) == 84) return 84;
        if (ml_strcmp(av[i], "-n") == 0)
            if (check_nb(av[i + 1]) == 84) return 84;
        if (ml_strcmp(av[i], "-a") == 0)
            if (check_nb(av[i + 1]) == 84) return 84;
    }
    return 0;
}
