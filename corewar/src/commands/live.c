/*
** EPITECH PROJECT, 2023
** commands
** File description:
** live
*/

#include "corewar_header.h"

int command_live(int reg, vm_t *vm, champ_t *champ)
{
    champ->is_alive = true;
    vm->nbr_live++;
    return 0;
}
