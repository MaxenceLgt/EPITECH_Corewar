/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "corewar_header.h"
#include <stdio.h>

int main(int ac, char **av)
{
    int size_vm = 2;
    int tot_vm = 6;
    int bytes = 20;
    char *arg[3] = {"live", "22", NULL};

    if (ac > 2) explain_h(av);
    if (ac == 1)
        return 84;
    if (error_handling(av, ac, size_vm, tot_vm) == 84)
        return 84;

    while (bytes - 4 >= 0)
        if ((ml_strcmp(arg[0], "0x01") == 0 || \
ml_strcmp(arg[0], "live") == 0) && arg[2] == NULL)
            com_live(&bytes, arg[1]);
    return 0;
}
