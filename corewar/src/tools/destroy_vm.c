/*
** EPITECH PROJECT, 2023
** destroy_vm.c
** File description:
** destroy_vm
*/

#include <stdlib.h>
#include "corewar_header.h"

static void destroy_process(void *data)
{
    process_t *process = data;

    if (process)
        free(process);
}

void destroy_champ(void *data)
{
    champ_t *champ = data;

    if (!champ)
        return;
    if (champ->champ_content)
        free(champ->champ_content);
    if (champ->file)
        free(champ->file);
    if (champ->name)
        free(champ->name);
    if (champ->process)
        ml_destroy_list(champ->process, destroy_process);
    free(champ);
}

void destroy_vm(vm_t *vm)
{
    if (!vm)
        return;
    if (vm->vm)
        free(vm->vm);
    if (vm->champs_data)
        ml_destroy_list(vm->champs_data, destroy_champ);
    free(vm);
}
