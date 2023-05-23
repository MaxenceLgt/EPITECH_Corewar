/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "corewar_header.h"
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac > 2) explain_h(av);
    if (ac == 1)
        return 84;
    if (error_handling(av, ac) == 84)
        return 84;
    return 0;
}
