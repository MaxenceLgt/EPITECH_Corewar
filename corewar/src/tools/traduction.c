/*
** EPITECH PROJECT, 2023
** traduction
** File description:
** traduction
*/

#include "corewar_header.h"

int get_hexa(unsigned char buffer)
{
    int nb = buffer;

    ml_printf("%c%c\n", "0123456789abcdef"[nb / 16],
    "0123456789abcdef"[nb % 16]);
    return 0;
}
