/*
** EPITECH PROJECT, 2023
** init_file_content
** File description:
** init_file_content
*/

#include "corewar_header.h"

int init_file_content(vm_t *vm)
{
    ml_node *temp = vm->champs_data->head;
    champ_t *node = NULL;

    for (; temp; temp = temp->next) {
        node = temp->data;
    }
}
