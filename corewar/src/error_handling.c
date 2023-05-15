/*
** EPITECH PROJECT, 2023
** error_handling
** File description:
** corewar
*/

#include "corewar_header.h"

int error_handling(char **av)
{
    if (ml_strcmp(av[1], "-dump") != 0)
        return 84;
    if (ml_strcmp(av[3], "-n") != 0)
        return 84;
    if (ml_strcmp(av[5], "-a") != 0)
        return 84;
    return 0;
}
