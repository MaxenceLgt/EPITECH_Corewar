/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** handle_cycles
*/

#include "corewar_header.h"

int handle_cycles(vm_t *vm, char **av, size_t *i)
{
    if (av[(*i) + 1] == NULL)
        return 1;
    if (!ml_str_is_num(av[(*i) + 1]))
        return 1;
    vm->cycle_to_die = ml_atoi(av[(*i) + 1]);
    (*i) += 2;
    return 0;
}
