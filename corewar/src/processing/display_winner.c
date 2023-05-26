/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** display_winner
*/

#include "corewar_header.h"

void display_winner(vm_t *vm)
{
    if (vm->nb_champ > 1 || vm->nb_champ == 0) {
        ml_printf("Nobody won this match.\n");
        return;
    }
    return;
}
