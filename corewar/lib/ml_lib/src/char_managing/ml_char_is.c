/*
** EPITECH PROJECT, 2023
** ml_char_is
** File description:
** ml_char_is
*/

#include <stdbool.h>

bool ml_char_isalpha(const char c)
{
    if (c >= 'A' && c <= 'Z')
        return (true);
    if (c >= 'a' && c <= 'z')
        return (true);
    return (false);
}

bool ml_char_isnum(const char c)
{
    if (c >= '0' && c <= '9')
        return (true);
    return (false);
}

bool ml_char_isalphanum(const char c)
{
    if (ml_char_isnum(c))
        return (true);
    if (ml_char_isalpha(c))
        return (true);
    return (false);
}

bool ml_char_islow(const char c)
{
    if (c >= 'a' && c <= 'z')
        return (true);
    return (false);
}

bool ml_char_isup(const char c)
{
    if (c >= 'A' && c <= 'Z')
        return (true);
    return (false);
}
