/*
** EPITECH PROJECT, 2023
** live
** File description:
** coreware vm
*/

#include "corewar_header.h"

int com_live(int *bytes, char *player)
{
    *bytes = *bytes - 4;

    for (int i = 0; player[i] != '\0'; i++)
        if (player[i] <= 48 || player[i] > 57) {
            ml_printf("Incorrect command\n");
            return 84;
        }

    ml_printf("The register %s is alive\n", player);
    return 0;
}
