/*
** EPITECH PROJECT, 2023
** add_champs_to_vm
** File description:
** add_champs_to_vm
*/

#include "corewar_header.h"

static int set_equivalent(vm_t *vm)
{
    int offset = MEM_SIZE / vm->nb_champ;
    ml_node *temp = vm->champs_data->head;
    champ_t *champ = NULL;

    for (size_t i = 0; temp; temp = temp->next, i += offset) {
        champ = temp->data;
        for (size_t pos = 0; pos < champ->prog_size; pos++)
            vm->vm[i + pos] = champ->champ_content[pos];
    }
    return (0);
}

static bool all_adress_are_null(ml_node *node)
{
    champ_t *champ = NULL;

    for (; node; node = node->next) {
        champ = node->data;
        if (champ->load_address != 0)
            return (false);
    }
    return (true);
}

static bool invalid_size_champ(vm_t *vm)
{
    ml_node *temp = vm->champs_data->head;
    champ_t *champ = NULL;

    for (; temp; temp = temp->next){
        champ = temp->data;
        if (champ->prog_size > MEM_SIZE / vm->nb_champ) {
            ml_putstr_error(champ->name);
            write(2, ": Invalid size of champion.\n", 28);
            return (true);
        }
    }
    return (false);
}

int add_champs_to_vm(vm_t *vm)
{
    if (vm->nb_champ < 2) {
        write(2, "Not enough champions.\n", 22);
        return (84);
    }
    if (invalid_size_champ(vm))
        return (84);
    for (size_t i = 0; i < MEM_SIZE; i++)
        vm->vm[i] = 0;
    if (all_adress_are_null(vm->champs_data->head))
        return (set_equivalent(vm));
    return (set_load_adress(vm));
}
