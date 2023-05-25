/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int command_ld(int reg, int arg, UNUSED vm_t *vm, process_t *process)
{
    process->reg[reg] = arg;
    process->carry = 1;
    return 0;
}
