/*
** EPITECH PROJECT, 2023
** ml_add_node_front
** File description:
** ml_add_node_front
*/

#include <stdlib.h>
#include "ml_list_h.h"

static ml_node *create_node_front(ml_list *list, void *data)
{
    ml_node *node = malloc(sizeof(ml_node));

    if (!list || !data || !node)
        return (NULL);
    node->next = list->head;
    node->prev = NULL;
    node->data = data;
    return (node);
}

void ml_add_node_front(ml_list *list, void *data)
{
    ml_node *node = create_node_front(list, data);

    if (!list || !data || !node)
        return;
    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->head->prev = node;
        list->head = node;
    }
    list->size += 1;
}
