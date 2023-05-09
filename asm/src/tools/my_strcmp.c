/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** strcmp
*/

#include <stdbool.h>

#include "asm_header.h"

int my_strcmp(char const *s1, const char *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return true;
    for (int i = 0; s1[i] != s2[i]; i++){
        if (s1[i] != s2[i])
            return true;
    }
    return false;
}
