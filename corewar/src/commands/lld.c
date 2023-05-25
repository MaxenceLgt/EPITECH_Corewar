/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int command_lld(UNUSED int par, process_t *process, UNUSED vm_t *vm)
{
    process->carry = 1;
    return 0;
}
