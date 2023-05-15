/*
** EPITECH PROJECT, 2022
** ml_put_nbr
** File description:
** ml_put_nbr
*/

#include <unistd.h>
#include "ml_str_h.h"

void ml_put_nbr(int nb)
{
    if (nb == -2147483648){
        write(1, "-2147483648", 11);
        return;
    }
    if (nb < 0) {
        write(1, &"-", 1);
        ml_put_nbr(-nb);
    } else if ((nb % 10) == nb){
        ml_putchar(nb + 48);
    } else {
        ml_put_nbr(nb / 10);
        ml_putchar((nb % 10) + 48);
    }
    return;
}
