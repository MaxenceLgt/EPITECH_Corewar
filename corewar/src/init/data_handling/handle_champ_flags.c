/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** handle_champ_flag
*/

#include "corewar_header.h"

static int handle_n_flag(champ_t *champ, vm_t *vm, char **av, size_t *i)
{
    if (av[(*i)] == NULL)
        return 0;
    if (!ml_strcmp("-n", av[(*i)]) && av[(*i) + 1] == NULL) {
        write(2, "Invalid flag value: Refer to -h.\n", 33);
        return 1;
    }
    if (!ml_strcmp("-n", av[(*i)]) && av[(*i) + 1] != NULL) {
        if (!ml_str_is_num(av[(*i) + 1])) {
            write(2, "Invalid flag value: Refer to -h.\n", 33);
            return 1;
        }
        champ->prog_number = ml_atoi(av[(*i) + 1]);
        (*i) += 2;
        if (av[(*i)] == NULL)
            return 0;
        if (!ml_strcmp(av[(*i)], "-n") || !ml_strcmp(av[(*i)], "-a"))
            return handle_champ_flags(champ, vm, av, i);
    }
    return 0;
}

static int handle_a_flag(champ_t *champ, vm_t *vm, char **av, size_t *i)
{
    if (av[(*i)] == NULL)
        return 0;
    if (!ml_strcmp("-a", av[(*i)]) && av[(*i) + 1] == NULL) {
        write(2, "Invalid flag value: Refer to -h.\n", 33);
        return 1;
    }
    if (!ml_strcmp("-a", av[(*i)]) && av[(*i) + 1] != NULL) {
        if (!ml_str_is_num(av[(*i) + 1])) {
            write(2, "Invalid flag value: Refer to -h.\n", 33);
            return 1;
        }
        champ->load_address = ml_atoi(av[(*i) + 1]);
        (*i) += 2;
        if (av[(*i)] == NULL)
            return 0;
        if (!ml_strcmp(av[(*i)], "-n") || !ml_strcmp(av[(*i)], "-a"))
            return handle_champ_flags(champ, vm, av, i);
    }
    return 0;
}

int handle_champ_flags(champ_t *champ, vm_t *vm, char **av, size_t *i)
{
    if (av[(*i)] == NULL)
        return 0;
    if (handle_n_flag(champ, vm, av, i))
        return 1;
    if (handle_a_flag(champ, vm, av, i))
        return 1;
    return 0;
}
