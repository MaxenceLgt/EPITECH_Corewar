/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int set_ld_reg_values(UNUSED vm_t *vm, process_t *process, int *params)
{
    process->reg[params[1] - 1] = params[0];

    if (process->reg[params[1] - 1] == 0)
        process->carry = true;
    else
        process->carry = false;
    return 0;
}

int exec_ld(vm_t *vm, UNUSED champ_t *champ, process_t *process, int *args)
{
    int start = process->pos + 2;
    short temp = 0;
    int params[3] = {0, 0, 0};

    for (size_t i = 0; i < 2; i++) {
        if (args[i] == 1) {
            params[i] = process->reg[vm->vm[IS_OUT(start)] - 1];
            start++;
        } if (args[i] == T_DIR) {
            params[i] = get_int_param(vm->vm, start);
            start += 4;
        } if (params[i] == T_IND) {
            temp = process->pc + get_short_param(vm->vm, start) % IDX_MOD;
            params[i] = vm->vm[IS_OUT(temp)];
            start += 2;
        }
    }
    return set_ld_reg_values(vm, process, params);
}
