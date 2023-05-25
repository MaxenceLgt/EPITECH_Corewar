/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** exec_prog
*/

#include "corewar_header.h"

static int exc_function(vm_t *vm, champ_t *champ, process_t *process)
{
    return 0;
}

static int handle_champ_process(vm_t *vm, champ_t *champ)
{
    ml_node *node = champ->process->head;
    process_t *current_process = NULL;

    for (;node; node = node->next) {
        current_process = node->data;
        if (vm->current_cycle == current_process->goal_cycle)
            exc_function(vm, champ, current_process);
    }
    return 0;
}

int exec_prog(UNUSED vm_t *vm)
{
    ml_node *node = vm->champs_data->head;
    champ_t *champ = NULL;

    for(; node; node = node->next) {
        champ = node->data;
        handle_champ_process(vm, champ);
    }
    return 0;
}
