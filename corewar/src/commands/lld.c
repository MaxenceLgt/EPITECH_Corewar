/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int command_lld(int arg, int reg, process_t *process, UNUSED vm_t *vm)
{
    process->reg[reg] = arg % IDX_MOD;
    process->carry = 1;
    return 0;
}
