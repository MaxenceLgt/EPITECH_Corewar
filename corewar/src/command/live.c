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

    ml_printf("The register %s is alive\n", player);
    return 0;
}
