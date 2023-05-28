/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

static int set_ld_to_reg(UNUSED vm_t *vm, process_t *process, int *params)
{
    int ind_size = process->pos + (params[0] + params[1]) % IDX_MOD;

    process->reg[params[2]] = ind_size;
    if (process->reg[params[2]] == 0)
        process->carry = 1;
    else
        process->carry = 0;
    return (0);
}

int exec_ldi(vm_t *vm, UNUSED champ_t *champ, process_t *process, int *args)
{
    int start = process->pos + 2;
    int params[3] = {0, 0, 0};
    int temp = 0;

    for (size_t i = 0; i < 2; i++) {
        if (args[i] == T_REG) {
            params[i] = process->reg[vm->vm[IS_OUT(start)] - 1];
            start++;
        } if (args[i] == T_IND) {;
            temp = process->pos + get_short_param(vm->vm, IS_OUT(start)) %
            IDX_MOD;
            params[i] = get_short_param(vm->vm, IS_OUT(temp));
            start += 2;
        } if (args[i] == T_DIR) {
            params[i] = get_short_param(vm->vm, IS_OUT(start));
            start += 2;
        }
    }
    params[2] = vm->vm[IS_OUT(start)] - 1;
    return set_ld_to_reg(vm, process, params);
}
