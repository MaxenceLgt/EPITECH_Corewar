/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int command_st(int *reg, process_t *process, UNUSED vm_t *vm)
{
    process->reg[reg[1]] = process->reg[0];
    return 0;
}
