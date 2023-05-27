/*
** EPITECH PROJECT, 2023
** set_goal_cycles
** File description:
** set_goal_cycles
*/

#include "corewar_header.h"

static void load_goal_cycle(ml_node *process_lst, unsigned char *vm)
{
    process_t *process = process_lst->data;

    for (size_t i = 0; op_tab[i].mnemonique != 0; i++)
        if (op_tab[i].code == vm[process->pos]) {
            process->goal_cycle += op_tab[i].nbr_cycles;
            break;
        }
}

void init_goal_cycle(vm_t *vm, ml_list *champ_lst)
{
    ml_node *champ = champ_lst->head;
    champ_t *info = NULL;
    ml_node *process_lst = NULL;

    for (; champ; champ = champ->next) {
        info = champ->data;
        process_lst = info->process->head;
        for (; process_lst; process_lst = process_lst->next)
            load_goal_cycle(process_lst, vm->vm);
    }
}
