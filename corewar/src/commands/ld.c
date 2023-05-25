/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int command_ld(UNUSED int par, UNUSED vm_t *vm, process_t *process)
{
    process->carry = 1;
    return 0;
}
