/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int command_zjmp(int index, process_t *process, UNUSED vm_t *vm)
{
    process->pos = process->pos + index;
    return 0;
}
