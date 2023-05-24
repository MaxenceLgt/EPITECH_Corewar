/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** my_strlen
*/

#include <unistd.h>

size_t strlen_pf(char const *str)
{
    size_t i = 0;

    for (;str[i] != '\0'; i++);
    return (i);
}
