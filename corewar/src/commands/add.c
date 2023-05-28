/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int exec_add(vm_t *vm, UNUSED champ_t *champ, process_t *process,
UNUSED int *args)
{
    int args_pos[3] = {process->pos + 2, process->pos + 3, process->pos + 4};
    int reg[3] = {vm->vm[IS_OUT(args_pos[0])], vm->vm[IS_OUT(args_pos[1])],
    vm->vm[IS_OUT(args_pos[2])]};

    REGISTER[reg[2] - 1] = REGISTER[reg[0] - 1] + REGISTER[reg[1] - 1];
    if (REGISTER[reg[2] - 1] == 0)
        process->carry = 1;
    else
        process->carry = 0;
    return 0;
}
