/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** exec_prog
*/

#include <stdio.h>
#include "corewar_header.h"
#include <stdlib.h>

static int exc_function(UNUSED vm_t *vm, UNUSED champ_t *champ,
UNUSED process_t *process)
{
    int *args = get_params_type(process, vm->vm);
    int cmd = vm->vm[process->pos];

    if (cmd >= 1 && cmd <= 16)
        cmds_data[cmd - 1].command(vm, champ, process, args);
    free(args);
    return 0;
}

static int handle_champ_process(vm_t *vm, champ_t *champ)
{
    ml_node *node = champ->process->head;
    process_t *current_process = NULL;

    for (;node; node = node->next) {
        current_process = node->data;
        if (vm->current_cycle == current_process->goal_cycle) {
            exc_function(vm, champ, current_process);
        }
    }
    return 0;
}

int exec_prog(UNUSED vm_t *vm)
{
    ml_node *node = vm->champs_data->head;
    champ_t *champ = NULL;

    for (; node; node = node->next) {
        champ = node->data;
        handle_champ_process(vm, champ);
    }
    return 0;
}
