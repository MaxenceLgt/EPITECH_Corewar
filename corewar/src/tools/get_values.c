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

    if (start > MEM_SIZE)
        start = (start % MEM_SIZE) - 1;
    res |= vm[start];
    for (size_t i = start + 1, count = 0; count < 1; i++, count++) {
        if (i > MEM_SIZE)
            i = i % MEM_SIZE - 1;
        res <<= 8;
        res |= vm[i];
    }
    return (res);
}

int get_int_param(unsigned char *vm, int start)
{
    int res = 0;

    if (start > MEM_SIZE)
        start = (start % MEM_SIZE) - 1;
    res |= vm[start];
    for (size_t i = start + 1, count = 0; count < 3; i++, count++) {
        if (i > MEM_SIZE)
            i = i % MEM_SIZE - 1;
        res <<= 8;
        res |= vm[i];
    }
    return (res);
}

void set_int_to_char(int num, vm_t *vm, int pos)
{
    int out = 0;
    int temp = 0;
    char* ptr = NULL;

    change_endians(&num, sizeof(int));
    ptr = (char*)&num;
    for (int i = 0; i < 4; i++) {
        temp = pos + i;
        out = IS_OUT(temp);
        vm->vm[out] = ptr[i];
    }
}

void set_short_to_char(short num, vm_t *vm, int pos)
{
    int out = 0;
    int temp = 0;
    char* ptr = (char*)&num;

    change_endians(&num, sizeof(short));
    ptr = (char*)&num;
    for (int i = 0; i < 2; i++) {
        temp = pos + i;
        out = IS_OUT(temp);
        vm->vm[out] = ptr[i];
    }
}
