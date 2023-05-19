/*
** EPITECH PROJECT, 2023
** ml_putchar
** File description:
** ml_putchar
*/

#include <unistd.h>

void ml_putchar(char const c)
{
    write(1, &c, 1);
}

void ml_putchar_error(char const c)
{
    write(2, &c, 1);
}
