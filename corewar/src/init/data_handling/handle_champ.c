/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** handle_champ
*/

#include <stdlib.h>
#include "corewar_header.h"

static int handle_champ_flags(champ_t *champ, vm_t *vm, char **av, size_t *i)
{
    if (av[(*i)] == NULL)
        return 0;
    if (!ml_strcmp("-n", av[(*i)]) && av[(*i) + 1] != NULL) {
        champ->prog_number = ml_atoi(av[(*i) + 1]);
        (*i) += 2;
        if (av[(*i)] == NULL)
            return 0;
        if (!ml_strcmp(av[(*i)], "-n") || !ml_strcmp(av[(*i)], "-a"))
            return handle_champ_flags(champ, vm, av, i);
    }
    if (!ml_strcmp("-a", av[(*i)]) && av[(*i) + 1] != NULL) {
        champ->load_address = ml_atoi(av[(*i) + 1]);
        (*i) += 2;
        if (av[(*i)] == NULL)
            return 0;
        if (!ml_strcmp(av[(*i)], "-n") || !ml_strcmp(av[(*i)], "-a"))
            return handle_champ_flags(champ, vm, av, i);
    }
    return 0;
}

static int handle_champ_content(champ_t *champ, vm_t *vm, char **av, size_t *i)
{
    return 0;
}

int handle_champ(vm_t *vm, char **av, size_t *i)
{
    champ_t *champ = malloc(sizeof(champ_t));

    if (champ == NULL)
        return 1;
    vm->nb_champ++;
    champ->prog_number = vm->nb_champ;
    champ->load_address = 0;
    champ->champ_content = NULL;
    champ->process = NULL;
    champ->is_alive = false;
    if (!ml_strcmp(av[(*i)], "-n") || !ml_strcmp(av[(*i)], "-a"))
        handle_champ_flags(champ, vm, av, i);
    return handle_champ_content(champ, vm, av, i);
}
