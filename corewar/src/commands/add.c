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
    int args[3] = {process->pos + 2, process->pos + 3, process->pos + 4};
    int reg[3] = {vm->vm[IS_OUT(args[0])], vm->vm[IS_OUT(args[1])],
    vm->vm[IS_OUT(args[2])]};

    REGISTER[reg[2] - 1] = REGISTER[reg[0] - 1] + REGISTER[reg[1] - 1];
    return 0;
}
