/*
** EPITECH PROJECT, 2023
** get_params_type.c
** File description:
** get_params_type
*/

#include <stdlib.h>
#include "corewar_header.h"

static int *handle_no_coding(char function)
{
    int *params = malloc(sizeof(int) * 3);

    if (!params)
        return (NULL);
    for (size_t i = 0; i < 3; i++)
        params[i] = -1;
    if (function == 1)
        params[0] = T_DIR;
    if (function == 9 || function == 12 || function == 15)
        params[0] = T_IND;
    return (params);
}

static int *set_params_tab(char *test)
{
    int *params = malloc(sizeof(int) * 3);

    if (!params)
        return (NULL);
    for (size_t i = 0, parser = 0; i < 3; i += 2, parser++) {
        if (test[i] == '1' && test[i + 1] == '1')
            params[parser] = T_IND;
        if (test[i] == '1' && test[i + 1] == '0')
            params[parser] = T_DIR;
        if (test[i] == '0' && test[i + 1] == '1')
            params[parser] = T_REG;
        if (test[i] == '0' && test[i + 1] == '0')
            params[parser] = -1;
    }
    return (params);
}

int *get_params_type(process_t *process, unsigned char *vm)
{
    char coding_byte = 0;
    char val[] = "00000000";

    if (NO_CODING(vm[process->pos]))
        return (handle_no_coding(vm[process->pos]));
    if (process->pos + 2 <= MEM_SIZE)
        coding_byte = vm[process->pos + 1];
    else
        coding_byte = vm[process->pos - MEM_SIZE + 1];
    coding_byte = (coding_byte & 0xF0) >> 4 | (coding_byte & 0x0F) << 4;
    coding_byte = (coding_byte & 0xCC) >> 2 | (coding_byte & 0x33) << 2;
    coding_byte = (coding_byte & 0xAA) >> 1 | (coding_byte & 0x55) << 1;
    for (size_t i = 0; i < 8; i++) {
        if (coding_byte & (1 << i))
            val[i] = '1';
        else
            val[i] = '0';
    }
    return (set_params_tab(val));
}
