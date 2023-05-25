/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** check_alive_state
*/

#include "corewar_header.h"

int check_alive_state(vm_t *vm)
{
    ml_node *champ = vm->champs_data->head;
    champ_t *info = NULL;

    if (vm->nbr_live == NBR_LIVE) {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->nbr_live = 0;
    }
    if (vm->last_check + CYCLE_TO_DIE != vm->current_cycle)
        return (0);
    for (; champ; champ = champ->next) {
        info = champ->data;
        if (!info->is_alive) {
            ml_destroy_node(vm->champs_data, champ, destroy_champ);
            vm->nb_champ -= 1;
        }
    }
    vm->last_check = vm->current_cycle;
    return (0);
}
