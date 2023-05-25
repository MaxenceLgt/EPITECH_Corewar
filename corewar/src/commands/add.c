/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int command_add(process_t *process, UNUSED vm_t *vm)
{
    process->reg[2] = process->reg[0] + process->reg[1];
    process->carry = 1;
    return 0;
}
