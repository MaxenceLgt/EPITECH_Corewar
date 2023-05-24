/*
** EPITECH PROJECT, 2022
** ml_strcpy
** File description:
** ml_strcpy
*/

#include <unistd.h>

void ml_strcpy(char **dest, char const *src)
{
    size_t i = 0;

    for (;src[i] != '\0'; i++)
        (*dest)[i] = src[i];
    (*dest)[i] = src[i];
}
