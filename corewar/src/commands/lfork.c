/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int exec_lfork(vm_t *vm, champ_t *champ, process_t *process, UNUSED int *args)
{
    int start = process->pos + 1;
    short temp = 0;
    int params[3] = {0, 0, 0};

    temp = process->pos + get_short_param(vm->vm, start);
    params[0] = vm->vm[IS_OUT(temp)];
    return load_new_process(vm, champ, params);
}
