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

    if (manage_help(ac, av))
        return 0;
    vm = init_vm(ac, av);
    if (vm == NULL)
        return 84;
    add_champs_to_vm(vm);
    destroy_vm(vm);
    return 0;
}
