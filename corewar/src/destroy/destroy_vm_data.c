/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** destroy_vm_data
*/

#include <stdlib.h>
#include "corewar_header.h"

static void clean_champs_data(vm_t *vm)
{
    return;
}

void destroy_vm_data(vm_t *vm)
{
    if (vm == NULL)
        return;
    if (vm->vm != NULL)
        free(vm->vm);
    if (vm->champs_data != NULL)
        clean_champs_data(vm);
    free(vm);
    return;
}
