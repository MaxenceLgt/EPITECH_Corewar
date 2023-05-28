/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** display_winner
*/

#include "corewar_header.h"

void display_winner(vm_t *vm)
{
    ml_node *node = vm->champs_data->head;
    champ_t *winner = NULL;

    if (vm->nb_champ > 1 || vm->nb_champ == 0) {
        ml_printf("Nobody won this match.\n");
        return;
    }
    winner = node->data;
    ml_printf("The player %d(%s)has won.\n", winner->prog_number,
    winner->name);
    return;
}
