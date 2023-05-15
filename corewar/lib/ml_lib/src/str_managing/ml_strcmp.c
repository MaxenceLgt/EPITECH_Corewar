/*
** EPITECH PROJECT, 2022
** ml_strcmp
** File description:
** ml_strcmp
*/

#include <unistd.h>

int ml_strcmp(char const *s1, char const *s2)
{
    size_t count = 0;

    while (s1[count] != '\0' && s2[count] != '\0' && s1[count] == s2[count])
        count++;
    return (s1[count] - s2[count]);
}
