/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include <stdlib.h>
#include "corewar_header.h"

static size_t load_gc(int pos, vm_t *vm)
{
    int function = vm->vm[pos];
    int gc_value = vm->current_cycle;

    if (function >= 1 && function <= 16) {
        gc_value += cmds_data[function - 1].cycles;
        return gc_value;
    }
    return 0;
}

int load_new_process(vm_t *vm, champ_t *champ, int *params)
{
    process_t *new_process = malloc(sizeof(process_t));

    if (new_process == NULL)
        return 0;
    new_process->carry = true;
    new_process->pos = params[0] % MEM_SIZE;
    new_process->pc = 0;
    new_process->goal_cycle = load_gc(new_process->pos, vm);
    for (size_t reg_i = 0; reg_i < REG_NUMBER; reg_i++)
        new_process->reg[reg_i] = 0;
    new_process->reg[0] = champ->prog_number;
    ml_add_node_back(champ->process, new_process);
    return 0;
}

int exec_fork(vm_t *vm, champ_t *champ, process_t *process, UNUSED int *args)
{
    int start = process->pos + 1;
    short temp = 0;
    int params[3] = {0, 0, 0};

    temp = process->pos + get_short_param(vm->vm, start) % IDX_MOD;
    params[0] = vm->vm[IS_OUT(temp)];
    return load_new_process(vm, champ, params);
}
