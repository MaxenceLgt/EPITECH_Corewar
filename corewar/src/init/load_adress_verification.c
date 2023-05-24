/*
** EPITECH PROJECT, 2023
** load_adress_verification
** File description:
** load_adress_verification
*/

#include "corewar_header.h"

bool only_one_load(ml_list *lst_champ)
{
    ml_node *champ = lst_champ->head;
    size_t nb_load = 0;
    champ_t *info = NULL;

    for (; champ; champ = champ->next) {
        info = champ->data;
        if (info->load_address != 0)
            nb_load++;
        if (nb_load > 1)
            return (false);
    }
    return (true);
}

size_t get_load(ml_list *champ_lst)
{
    ml_node *champ = champ_lst->head;
    champ_t *info = NULL;

    for (; champ; champ = champ->next) {
        info = champ->data;
        if (info->load_address != 0)
            return (info->load_address);
    }
    return (0);
}
