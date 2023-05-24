/*
** EPITECH PROJECT, 2023
** ml_display_array
** File description:
** ml_display_array
*/

#include "ml_str_h.h"

void ml_display_str_array(const char **array)
{
    if (!array) {
        ml_putstr("\n");
        return;
    }
    for (size_t parser = 0; array[parser]; parser++) {
        ml_putstr(array[parser]);
        ml_putchar('\n');
    }
}
