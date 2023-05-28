/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

static int manage_indirect_arg(vm_t *vm, process_t *process, int reg_idx)
{
    short val = get_short_param(vm->vm, process->pos + 2);

    vm->vm[process->pc + val % IDX_MOD] = process->reg[reg_idx];
    return (0);
}

int exec_st(vm_t *vm, UNUSED champ_t *champ, process_t *process, int *args)
{
    int pos_reg[2] = {process->pos + 2, process->pos + 3};
    int reg[2] = {vm->vm[IS_OUT(pos_reg[0])], vm->vm[IS_OUT(pos_reg[1])]};
    if (args[1] == IND_SIZE)
        return (manage_indirect_arg(vm, process, reg[0] - 1));
    process->reg[reg[1] - 1] = process->reg[reg[0] - 1];
    return 0;
}
