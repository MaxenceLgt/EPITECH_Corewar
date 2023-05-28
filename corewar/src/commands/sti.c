/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

static void set_value_sti(vm_t *vm, process_t *process, int *params)
{
    int pos = process->pos + (params[1] + params[2]) % IDX_MOD;
    int value = get_int_param(vm->vm, pos);

    process->reg[params[0]] = value;
}

int exec_sti(vm_t *vm, UNUSED champ_t *champ, process_t *process, int *args)
{
    int start = process->pos + 2;
    int params[3] = {0, 0, 0};
    int out = IS_OUT(start);

    params[0] = vm->vm[out] - 1;
    start += 1;
    out = IS_OUT(start);
    for (size_t i = 1; i < 3; i++, out = IS_OUT(start)) {
        if (args[i] == 1) {
            params[i] = process->reg[vm->vm[out] - 1];
            start++;
        } if (args[i] == IND_SIZE) {
            params[i] = get_short_param(vm->vm, out);
            start += 2;
        }
    }
    set_value_sti(vm, process, params);
    return 0;
}
