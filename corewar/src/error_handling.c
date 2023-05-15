/*
** EPITECH PROJECT, 2023
** error_handling
** File description:
** corewar
*/

#include "corewar_header.h"

static int check_hexa(char **av)
{
    for (int i = 0; av[2][i]; i++)
        if (CHECK_HEXA);
        else
            return 84;
    return 0;
}

int error_handling(char **av)
{
    if (ml_strcmp(av[1], "-dump") != 0) return 84;
    if (check_hexa(av) == 84) return 84;
    if (ml_strcmp(av[3], "-n") != 0) return 84;
    if (ml_strcmp(av[5], "-a") != 0) return 84;
    return 0;
}
