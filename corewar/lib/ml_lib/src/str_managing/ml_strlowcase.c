/*
** EPITECH PROJECT, 2022
** ml_strlowcase
** File description:
** ml_strlowcase
*/

#include "ml_str_h.h"

void ml_strlowcase(char **str)
{
    for (size_t i = 0; (*str)[i] != '\0'; i++){
        if (ml_char_isup((*str)[i]))
            (*str)[i] += 32;
    }
}
