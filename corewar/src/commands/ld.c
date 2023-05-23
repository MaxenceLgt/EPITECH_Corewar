/*
** EPITECH PROJECT, 2023
** ld
** File description:
** coreware vm
*/

#include "corewar_header.h"

int com_ld(int *bytes, char *nb, char *player)
{
    int i;

    *bytes = *bytes - 4;
    for (i = 0; nb[i]; i++)
        if (nb[i] <= 48 || nb[i] > 57) {
            ml_printf("Incorrect command of nb\n");
            return 84;
        }
    for (i = 0; player[i]; i++)
        if (player[i] <= 48 || player[i] > 57) {
            ml_printf("Incorrect command of player\n");
            return 84;
        }
    return 0;
}
