/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int command_st(int reg, int arg, process_t *process, UNUSED vm_t *vm)
{
    if (arg == T_REG)
        process->pos = process->pc + (process->reg[reg] % IDX_MOD);
    return 0;
}
