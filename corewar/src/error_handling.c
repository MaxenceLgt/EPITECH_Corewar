/*
** EPITECH PROJECT, 2023
** error_handling
** File description:
** corewar
*/

#include "corewar_header.h"
#include <stdio.h>

static int check_nb(char *av)
{
    for (int i = 0; av[i]; i++)
        if (av[i] >= '0' && av[i] <= '9');
        else
            return 84;
    return 0;
}

static int check_arg(char **av, int *i, int *count_no_n)
{
    if (ml_strcmp(av[*i], "-dump") == 0)
        if (check_nb(av[*i + 1]) == 84) return 84;
    if (ml_strcmp(av[*i], "-n") == 0)
        if (check_nb(av[*i + 1]) == 84) return 84;
    if (ml_strcmp(av[*i], "-a") == 0)
        if (check_nb(av[*i + 1]) == 84) return 84;
    if (ml_strcmp(av[*i], "-n") != 0)
        count_no_n++;
    return 0;
}

int init_flag_n(int size_vm, int tot_vm)
{
    int distance_vm;

    if (size_vm == 1)
        distance_vm = ((tot_vm - size_vm) / 2) + size_vm;
    else
        distance_vm = ((tot_vm - size_vm) / 2);
    return distance_vm;
}

int error_handling(char **av, int ac, int size_vm, int tot_vm)
{
    int i;
    int count_no_n = 0;

    for (i = 0; i < ac; i++)
        check_arg(av, &i, &count_no_n);
    if (count_no_n == ac)
        init_flag_n(size_vm, tot_vm);
    return 0;
}
