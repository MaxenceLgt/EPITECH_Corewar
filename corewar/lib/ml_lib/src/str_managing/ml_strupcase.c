/*
** EPITECH PROJECT, 2022
** ml_strupcase
** File description:
** ml_strupcase
*/

#include "ml_str_h.h"

void ml_strupcase(char **str)
{
    for (size_t i = 0; (*str)[i] != '\0'; i++){
        if (ml_char_islow((*str)[i]))
            (*str)[i] -= 32;
    }
}
