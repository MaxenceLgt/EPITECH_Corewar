/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** handle_cycles
*/

#include "corewar_header.h"

int handle_cycles(vm_t *vm, char **av, size_t *i)
{
    if (av[(*i) + 1] == NULL) {
        write(2, "No dump value: Refer to -h.\n", 29);
        return 1;
    } else if (!ml_str_is_num(av[(*i) + 1])) {
        write(2, "Invalid dump value: Refer to -h.\n", 33);
        return 1;
    }
    vm->max_cycles = ml_atoi(av[(*i) + 1]);
    (*i) += 2;
    return 0;
}
