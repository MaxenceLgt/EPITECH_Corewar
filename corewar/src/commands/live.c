/*
** EPITECH PROJECT, 2023
** commands
** File description:
** live
*/

#include "corewar_header.h"

int exec_live(vm_t *vm, champ_t *champ, process_t *process, int *args)
{
    champ->is_alive = true;
    vm->nbr_live++;
    return 0;
}
