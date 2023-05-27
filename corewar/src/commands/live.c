/*
** EPITECH PROJECT, 2023
** commands
** File description:
** live
*/

#include "corewar_header.h"

int command_live(vm_t *vm, champ_t *champ)
{
    ml_printf("The player %d is alive.\n", champ->prog_number);
    champ->is_alive = true;
    vm->nbr_live++;
    return 0;
}
