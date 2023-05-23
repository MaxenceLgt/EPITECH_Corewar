/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** handle_champ
*/

#include <stdlib.h>
#include "corewar_header.h"

int handle_champ(vm_t *vm, char **av, size_t *i)
{
    champ_t *champ = malloc(sizeof(champ_t));

    if (champ == NULL)
        return 1;
    vm->nb_champ++;
    champ->prog_number = vm->nb_champ;
    champ->load_address = NULL;
    champ->champ_content = NULL;
    return 0;
}
