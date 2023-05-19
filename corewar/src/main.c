/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "corewar_header.h"

int main(int ac, char **av)
{
    if (ac == 1)
        return 84;
    manage_help(ac, av);
    return 0;
}
