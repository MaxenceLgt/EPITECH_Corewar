/*
** EPITECH PROJECT, 2023
** get_values.c
** File description:
** get_values.c
*/

#include "corewar_header.h"

short get_short_param(unsigned char *vm, int start)
{
    short res = 0;
    int temp = 0;
    char values[2] = "";

    for (size_t i = 0; i < 2; i++) {
        temp = start + i;
        values[i] = vm[IS_OUT(temp)];
    }
    res |= values[0];
    res <<= 8;
    res |= values[1];
    change_endians(&res, sizeof(short));
    return (res);
}

int get_int_param(unsigned char *vm, int start)
{
    short res = 0;
    int temp = 0;
    char values[4] = "";

    for (size_t i = 0; i < 2; i++) {
        temp = start + i;
        values[i] = vm[IS_OUT(temp)];
    }
    res |= values[0];
    for (size_t i = 1; i < 4; i++) {
        res <<= 8;
        res |= values[i];
    }
    change_endians(&res, sizeof(int));
    return (res);
}
