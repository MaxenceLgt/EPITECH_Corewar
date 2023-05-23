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

    if (ac > 2) explain_h(av);
    if (ac == 1)
        return 84;
    if (error_handling(av, ac, size_vm, tot_vm) == 84)
        return 84;
    return 0;
}
