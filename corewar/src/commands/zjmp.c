/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int command_zjmp(int arg, process_t *process, UNUSED vm_t *vm)
{
    process->pos = arg;
    return 0;
}
