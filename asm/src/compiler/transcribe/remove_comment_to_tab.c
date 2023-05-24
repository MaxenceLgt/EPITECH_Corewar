/*
** EPITECH PROJECT, 2023
** remove_comment_to_tab
** File description:
** remove_comment_to_tab
*/

#include <stdlib.h>
#include "asm_head.h"

void remove_comment_to_tab(char ***tab)
{
    char *temp = NULL;

    for (size_t i = 2; (*tab)[i]; i++)
        if (comment_is_present((*tab)[i])) {
            temp = delete_comment((*tab)[i]);
            free((*tab)[i]);
            (*tab)[i] = ml_strdup(temp);
            free(temp);
        }
}
