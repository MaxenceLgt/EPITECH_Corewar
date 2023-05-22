/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parse_args
*/

#include <unistd.h>
#include "corewar_header.h"

static int handle_parameter(vm_t *vm, char **av, size_t *i)
{
    if (!ml_strcmp("-dump", av[*i]))
        return handle_cycles(vm, av, i);
    return handle_champ(vm, av, i);
}

int parse_args(vm_t *vm, int ac, char **av)
{
    for (size_t i = 1; (int)i < ac;) {
        if (handle_parameter(vm, av, &i)) {
            write(2, "Invalid parameter.\n", 19);
            return 84;
        }
    }
    return 0;
}
