/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

static int set_value_sti(vm_t *vm, process_t *process, int *params)
{
    int pos = process->pos + (params[1] + params[2]) % IDX_MOD;

    if (pos > MEM_SIZE)
        pos = pos % MEM_SIZE - 1;
    set_int_to_char(process->reg[params[0]], vm, pos);
    return (0);
}

int exec_sti(vm_t *vm, UNUSED champ_t *champ, process_t *process, int *args)
{
    int start = process->pos + 2;
    int params[3] = {0, 0, 0};
    int out = IS_OUT(start);
    int temp = 0;

    params[0] = vm->vm[out] - 1; start++; out = IS_OUT(start);
    for (size_t i = 1; i < 3; i++, out = IS_OUT(start)) {
        if (args[i] == 1) {
            params[i] = process->reg[vm->vm[out] - 1];
            start++;
        } if (args[i] == T_IND) {;
            temp = process->pos + get_short_param(vm->vm, out) % IDX_MOD;
            params[i] = get_short_param(vm->vm, IS_OUT(temp));
            start += 2;
        } if (args[i] == T_DIR) {
            params[i] = get_short_param(vm->vm, out);
            start += 2;
        }
    }
    return set_value_sti(vm, process, params);
}
