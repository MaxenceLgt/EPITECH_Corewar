/*
** EPITECH PROJECT, 2023
** commands
** File description:
** live
*/

#include "corewar_header.h"

int command_live(int reg, vm_t *vm, champ_t *node)
{
    node->is_alive = true;
    vm->nbr_live++;
    return 0;
}
