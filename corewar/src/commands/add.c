/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int command_add(process_t *process, UNUSED vm_t *vm, int *reg)
{
    process->reg[reg[2]] = process->reg[reg[0]] + process->reg[reg[1]];
    process->carry = 1;
    return 0;
}