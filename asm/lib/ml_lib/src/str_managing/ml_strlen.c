/*
** EPITECH PROJECT, 2022
** ml_strlen
** File description:
** ml_strlen
*/

#include <unistd.h>

size_t ml_strlen(char const *str)
{
    size_t i = 0;

    if (!str)
        return (i);
    for (; str[i] != '\0'; i++);
    return (i);
}
