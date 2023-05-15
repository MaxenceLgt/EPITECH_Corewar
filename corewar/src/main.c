/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "corewar_header.h"

int main(int ac, char **av)
{
    explain_h(av);
    if (ac < 3 || ac % 2 == 0)
        return 84;
    if (error_handling(av) == 84)
        return 84;
    return 0;
}
