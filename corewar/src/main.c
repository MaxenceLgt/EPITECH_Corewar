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
    if (add_champs_to_vm(vm) == 84){
        destroy_vm(vm);
        return (84);
    }
    sort_champion_lst(vm->champs_data);
    process_corewar(vm);
    destroy_vm(vm);
    return 0;
}
