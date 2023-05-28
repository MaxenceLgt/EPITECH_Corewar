/*
** EPITECH PROJECT, 2023
** commands
** File description:
** live
*/

#include "corewar_header.h"

static bool id_is_champ(champ_t *champ, ml_node *process, int value)
{
    ml_node *temp = process;
    process_t *info = NULL;

    for (; temp; temp = temp->next) {
        info = temp->data;
        if (info->reg[0] == value) {
            ml_printf("The player %d(%s)is alive.\n", info->reg[0],
            champ->name);
            return (true);
        }
    }
    return (false);
}

int exec_live(vm_t *vm, champ_t *champ, UNUSED process_t *process, UNUSED
int *args)
{
    int start = process->pos + 1;
    int value = get_int_param(vm->vm, start);
    ml_node *champ_lst = vm->champs_data->head;
    champ_t *champ_node = NULL;

    for (; champ_lst; champ_lst = champ_lst->next) {
        champ_node = champ_lst->data;
        if (id_is_champ(champ_node, champ_node->process->head, value)) {
            champ_node->is_alive = true;
            vm->nbr_live++;
            break;
        }
    }
    return 0;
}
