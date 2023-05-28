/*
** EPITECH PROJECT, 2023
** commands
** File description:
** live
*/

#include "corewar_header.h"

int exec_live(vm_t *vm, champ_t *champ, UNUSED process_t *process, UNUSED
int *args)
{
    ml_printf("The player %d(%s)is alive.\n", process->reg[0],
    champ->name);
    champ->is_alive = true;
    vm->nbr_live++;
    return 0;
}
