/*
** EPITECH PROJECT, 2023
** get_params_type.c
** File description:
** get_params_type
*/

#include <stdio.h>
#include <stdlib.h>
#include "corewar_header.h"

static void set_pc_to_zjmp(process_t *process, unsigned char *vm)
{
    char pos_param[2] = "\0";
    int result = 0;

    for (size_t i = 1; i <= 2; i++) {
        if (process->pos + i > MEM_SIZE)
            pos_param[i - 1] = vm[(process->pos + i) - MEM_SIZE - 1];
        else
            pos_param[i - 1] = vm[process->pos + i];
    }
    result = (pos_param[0] << 8) | pos_param[1];
    process->pc += result;
}

static void set_pc(int *params, process_t *process, char function,
unsigned char *vm)
{
    int val = 0;

    if (function == 9)
        return (set_pc_to_zjmp(process, vm));
    for (size_t i = 0; i < 3; i++)
        if (params[i] != -1)
            val += params[i];
    if (val > MEM_SIZE) {
        process->pc = val - MEM_SIZE - 1;
        return;
    }
    process->pc += val + 1;
    if (!NO_CODING(vm[process->pos]))
        process->pc++;
}

static int *handle_no_coding(char function, process_t *process,
unsigned char *vm)
{
    int *params = malloc(sizeof(int) * 3);

    if (!params)
        return (NULL);
    for (size_t i = 0; i < 3; i++)
        params[i] = -1;
    if (function == 1)
        params[0] = DIR_SIZE;
    if (function == 9 || function == 12 || function == 15)
        params[0] = IND_SIZE;
    set_pc(params, process, function, vm);
    return (params);
}

static int *set_params_tab(char *test, process_t *process, char function,
unsigned char *vm)
{
    int *params = malloc(sizeof(int) * 3);

    if (!params)
        return (NULL);
    for (size_t i = 0, parser = 0; parser < 3; i += 2, parser++) {
        if (test[i] == '1' && test[i + 1] == '1')
            params[parser] = IND_SIZE;
        if (test[i] == '1' && test[i + 1] == '0')
            params[parser] = DIR_SIZE;
        if (test[i] == '0' && test[i + 1] == '1')
            params[parser] = 1;
        if (test[i] == '0' && test[i + 1] == '0')
            params[parser] = -1;
        if (((test[i] == '1' && test[i + 1] == '0') ||
        (test[i] == '1' && test[i + 1] == '1')) && IS_INDEX(function))
            params[parser] = IND_SIZE;
    }
    set_pc(params, process, function, vm);
    return (params);
}

int *get_params_type(process_t *process, unsigned char *vm)
{
    char coding_byte = 0;
    char val[] = "00000000";

    if (NO_CODING(vm[process->pos]))
        return (handle_no_coding(vm[process->pos], process, vm));
    if (process->pos + 1 <= MEM_SIZE)
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
    return (set_params_tab(val, process, vm[process->pos], vm));
}
