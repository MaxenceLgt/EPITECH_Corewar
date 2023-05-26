/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** check_alive_state
*/

#include "corewar_header.h"

static void check_die_champs(ml_node *champ, vm_t *vm)
{
    champ_t *info = NULL;

    while (champ) {
        info = champ->data;
        if (!info->is_alive && champ->next) {
            champ = champ->next;
            ml_destroy_node(vm->champs_data, champ->prev, destroy_champ);
            vm->nb_champ -= 1;
            continue;
        } if (!info->is_alive && !champ->next) {
            ml_destroy_node(vm->champs_data, champ, destroy_champ);
            vm->nb_champ -= 1;
            break;
        }
        champ = champ->next;
    }
}

int check_alive_state(vm_t *vm)
{
    ml_node *champ = vm->champs_data->head;

    if (vm->nbr_live == NBR_LIVE) {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->nbr_live = 0;
    }
    if (vm->last_check + vm->cycle_to_die != vm->current_cycle)
        return (0);
    vm->last_check += vm->cycle_to_die;
    check_die_champs(champ, vm);
    return (0);
}
