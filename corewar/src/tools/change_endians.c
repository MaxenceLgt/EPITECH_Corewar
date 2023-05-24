/*
** EPITECH PROJECT, 2023
** change_endians
** File description:
** change_endians
*/

#include <sys/types.h>

void change_endians(void *data, size_t size)
{
    unsigned char *byte = (unsigned char *)data;
    size_t i = 0;
    unsigned char temp = 0;

    for (; i < size / 2; i++) {
        temp = byte[i];
        byte[i] = byte[size - i - 1];
        byte[size - i - 1] = temp;
    }
}
