/*
** EPITECH PROJECT, 2023
** commands
** File description:
** live
*/

#include "corewar_header.h"

int command_live(int par, vm_t *vm, champ_t *champ)
{
    ml_printf("The player %d is alive.\n", par);
    champ->is_alive = true;
    vm->nbr_live++;
    return 0;
}
