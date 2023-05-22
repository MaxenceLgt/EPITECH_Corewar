/*
** EPITECH PROJECT, 2023
** ml_lib
** File description:
** ml_str_is_num
*/

#include <stddef.h>
#include "ml_macros.h"

int ml_str_is_num(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (!IS_NUM(str[i]))
            return 0;
    }
    return 1;
}
