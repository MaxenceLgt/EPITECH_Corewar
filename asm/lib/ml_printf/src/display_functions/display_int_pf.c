/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "display_pf_head.h"

int display_int_pf(int nb, size_t *count)
{
    if (nb == -2147483648){
        write(1, "-2147483648", 11);
        (*count) += 11;
        return (0);
    }
    if (nb < 0) {
        display_char_pf('-', count);
        display_int_pf(-nb, count);
    } else if ((nb % 10) == nb){
        display_char_pf(nb + 48, count);
    } else {
        display_int_pf(nb / 10, count);
        display_char_pf((nb % 10) + 48, count);
    }
    return (0);
}
