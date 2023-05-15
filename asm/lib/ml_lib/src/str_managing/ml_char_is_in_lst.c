/*
** EPITECH PROJECT, 2023
** ml_char_is_in_lst
** File description:
** ml_char_is_in_lst
*/

#include <unistd.h>
#include <stdbool.h>

bool ml_char_is_in_lst(const char c, const char *lst)
{
    for (size_t i = 0; lst[i] != '\0'; i++)
        if (lst[i] == c)
            return (true);
    return (false);
}
