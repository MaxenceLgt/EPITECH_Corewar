/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "corewar_header.h"

int main(int ac, char **av)
{
    vm_t *vm;

    if (ac == 1)
        return 84;
    manage_help(ac, av);
    vm = init_vm(av);
    if (vm == NULL)
        return 84;
    return 0;
}
