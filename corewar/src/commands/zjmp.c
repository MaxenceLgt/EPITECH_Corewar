/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int exec_zjmp(UNUSED vm_t *vm, UNUSED champ_t *champ, process_t *process,
UNUSED int *args)
{
    if (process->carry == 0)
        process->pc = process->pos;
    return 0;
}
