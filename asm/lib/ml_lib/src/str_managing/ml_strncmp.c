/*
** EPITECH PROJECT, 2022
** ml_strncmp
** File description:
** ml_strncmp
*/

#include "ml_str_h.h"

int ml_strncmp(char const *s1, char const *s2, size_t n)
{
    size_t count = 1;

    if (n == 0)
        return (0);
    if (ml_strlen(s1) < n && ml_strlen(s2) < n)
        return (ml_strcmp(s1, s2));
    while (s1[count - 1] != '\0' && s2[count - 1] != '\0' &&
    s1[count - 1] == s2[count - 1] && count != n)
        count++;
    return (s1[count - 1] - s2[count - 1]);
}
