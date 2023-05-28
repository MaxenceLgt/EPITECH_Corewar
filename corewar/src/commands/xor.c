/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

static int manage_xor_operation(process_t *process, int *vals)
{
    process->reg[vals[2]] = vals[0] ^ vals[1];
    if (process->reg[vals[2]] == 0)
        process->carry = 1;
    else
        process->carry = 0;
    return (0);
}

int exec_xor(vm_t *vm, UNUSED champ_t *champ, process_t *process, int *args)
{
    int start = process->pos + 2;
    short temp = 0;
    int params[3] = {0, 0, 0};

    for (size_t i = 0; i < 2; i++) {
        if (args[i] == 1) {
            params[i] = process->reg[vm->vm[IS_OUT(start)] - 1];
            start++;
        } if (args[i] == DIR_SIZE) {
            params[i] = get_int_param(vm->vm, start);
            start += 4;
        } if (args[i] == IND_SIZE) {
            temp = process->pos + get_short_param(vm->vm, start) % IDX_MOD;
            params[i] = vm->vm[IS_OUT(temp)];
            start += 2;
        }
    }
    params[2] = vm->vm[IS_OUT(start)] - 1;
    return (manage_xor_operation(process, params));
}
