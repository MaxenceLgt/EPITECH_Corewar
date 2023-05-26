/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int command_ldi(int *index, int reg, process_t *process, UNUSED vm_t *vm)
{
    process->pos = index[0] + index[1];
    process->reg[reg] = process->pos;
    return 0;
}
