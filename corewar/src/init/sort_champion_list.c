/*
** EPITECH PROJECT, 2023
** sort_list_champion
** File description:
** sort_list_champion
*/

#include "corewar_header.h"

size_t find_pos_lowest(ml_node *champ)
{
    ml_node *temp = champ;
    champ_t *info = temp->data;
    size_t number = info->prog_number;
    size_t lowest = 0;
    size_t parse = 1;

    for (temp = temp->next; temp; temp = temp->next, parse++) {
        info = temp->data;
        if (info->prog_number < number) {
            lowest = parse;
            number = info->prog_number;
        }
    }
    return (lowest);
}

static void switch_data(ml_node *champ, size_t lowest)
{
    ml_node *temp = champ;
    void *temp_data = NULL;

    for (size_t i = 0; i != lowest; temp = temp->next, i++);
    temp_data = champ->data;
    champ->data = temp->data;
    temp->data = temp_data;
}

void sort_champion_lst(ml_list *champ_lst)
{
    ml_node *champ = champ_lst->head;
    size_t pos_lowest = 0;

    for (size_t i = 0; champ->next; champ = champ->next, i++){
        pos_lowest = find_pos_lowest(champ);
        if (pos_lowest + i != i)
            switch_data(champ, pos_lowest);
    }
}
