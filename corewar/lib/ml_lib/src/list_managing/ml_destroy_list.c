/*
** EPITECH PROJECT, 2023
** ml_destroy_list
** File description:
** ml_destroy_list
*/

#include <stdlib.h>
#include "ml_list_h.h"

static void destroy_lst_content(ml_node *lst_node, void (*f_ptr)(void *))
{
    while (lst_node->prev){
        lst_node = lst_node->prev;
        if (f_ptr)
            f_ptr(lst_node->next->data);
        free(lst_node->next);
    }
    if (f_ptr)
        f_ptr(lst_node->data);
    free(lst_node);
}

void ml_destroy_list(ml_list *list, void (*f_ptr)(void *))
{
    ml_node *lst_node = NULL;

    if (!list)
        return;
    lst_node = list->tail;
    if (lst_node)
        destroy_lst_content(lst_node, f_ptr);
    free(list);
}
