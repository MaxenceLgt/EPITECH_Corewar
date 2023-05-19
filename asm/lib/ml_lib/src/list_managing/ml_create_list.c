/*
** EPITECH PROJECT, 2023
** ml_create_list
** File description:
** ml_create_list
*/

#include <stdlib.h>
#include "ml_list_h.h"

ml_list *ml_create_list(void)
{
    ml_list *list = malloc(sizeof(ml_list));

    if (!list)
        return (NULL);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return (list);
}
