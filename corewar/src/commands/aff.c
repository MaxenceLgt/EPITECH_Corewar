/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int exec_aff(vm_t *vm, UNUSED champ_t *champ,
process_t *process, int *args)
{
    int start = process->pos + 2;
    int params[3] = {0, 0, 0};

    if (args[0] == 1) {
        params[0] = process->reg[vm->vm[IS_OUT(start)] - 1];
        ml_printf("%c\n", params[0] % 256);
    }
    return 0;
}
