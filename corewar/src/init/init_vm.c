/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** init_vm
*/

#include <stdlib.h>
#include "op.h"
#include "corewar_header.h"

vm_t *init_vm(int ac, char **av)
{
    vm_t *vm = malloc(sizeof(vm_t));

    if (vm == NULL)
        return NULL;
    vm->vm = malloc(sizeof(unsigned char) * MEM_SIZE);
    if (vm->vm == NULL)
        return NULL;
    vm->nbr_live = NBR_LIVE;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->cycle_delta = CYCLE_DELTA;
    vm->champs_data = NULL;
    if (parse_args(vm, ac, av) == 84)
        return NULL;
    if (!init_file_content(vm))
        return (NULL);
    return vm;
}
