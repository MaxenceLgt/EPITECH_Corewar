/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** handle_champ
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
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

static int set_champ_in_list(champ_t *champ, vm_t *vm,
UNUSED char **av, size_t *i)
{
    if (vm->champs_data == NULL) {
        vm->champs_data = ml_create_list();
        if (vm->champs_data == NULL)
            return 1;
    }
    ml_add_node_back(vm->champs_data, champ);
    (*i)++;
    return 0;
}

static int init_process(champ_t *champ, vm_t *vm, char **av, size_t *i)
{
    process_t *process = malloc(sizeof(process_t));

    if (process == NULL)
        return 1;
    process->carry = true;
    process->goal_cycle = 0;
    process->pos = champ->load_address;
    for (size_t reg_i = 0; reg_i < REG_NUMBER; reg_i++)
        process->reg[reg_i] = 0;
    champ->process = ml_create_list();
    if (champ->process == NULL)
        return 1;
    ml_add_node_back(champ->process, process);
    return set_champ_in_list(champ, vm, av, i);
}

static int handle_champ_content(champ_t *champ, vm_t *vm, char **av, size_t *i)
{
    int fd = open(av[(*i)], O_RDONLY);
    char *extension = &av[(*i)][ml_strlen(av[(*i)]) - 4];

    if (fd == -1) {
        free(champ);
        write(2, "Invalid file.\n", 15);
        return 1;
    } else if (ml_strcmp(extension, ".cor")) {
        free(champ);
        write(2, "Invalid file format.\n", 21);
        return 1;
    }
    champ->file = ml_strdup(av[(*i)]);
    if (champ->file == NULL)
        return 1;
    close(fd);
    return init_process(champ, vm, av, i);
}

int handle_champ(vm_t *vm, char **av, size_t *i)
{
    champ_t *champ = malloc(sizeof(champ_t));

    if (champ == NULL)
        return 1;
    vm->nb_champ++;
    champ->name = NULL;
    champ->prog_number = vm->nb_champ;
    champ->load_address = 0;
    champ->champ_content = NULL;
    champ->process = NULL;
    champ->is_alive = false;
    champ->prog_size = 0;
    if (!ml_strcmp(av[(*i)], "-n") || !ml_strcmp(av[(*i)], "-a"))
        handle_champ_flags(champ, vm, av, i);
    if (av[(*i)] == NULL) {
        write(2, "No file: Refer to -h.\n", 22);
        free(champ);
        return 1;
    }
    return handle_champ_content(champ, vm, av, i);
}
