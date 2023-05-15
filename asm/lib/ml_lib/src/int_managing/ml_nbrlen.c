/*
** EPITECH PROJECT, 2023
** ml_nbrlen
** File description:
** ml_nbrlen
*/

#include <unistd.h>

size_t ml_nbrlen(int nbr)
{
    size_t count = 0;

    if (nbr < 0)
        return (ml_nbrlen(-nbr) + 1);
    if (nbr == 0 || nbr == -0)
        return (1);
    while (nbr != 0){
        count++;
        nbr /= 10;
    }
    return (count);
}
