/*
** EPITECH PROJECT, 2023
** coreswar
** File description:
** process_corewar
*/

#include "corewar_header.h"

static int check_vm_run(vm_t *vm)
{
    if (vm->max_cycles != 0 && vm->current_cycle == vm->max_cycles)
        return 0;
    if (vm->nb_champ <= 1) {
        return 0;
    }
    return 1;
}

int process_corewar(vm_t *vm)
{
    init_goal_cycle(vm, vm->champs_data);
    while (check_vm_run(vm)) {
        vm->current_cycle++;
        exec_prog(vm);
        check_alive_state(vm);
    }
    display_winner(vm);
    return 0;
}
