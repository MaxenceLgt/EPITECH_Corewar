/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int command_aff(int reg, UNUSED vm_t *vm, process_t *process, champ_t *champ)
{
    process->reg[reg] = champ->champ_content[0];
    return 0;
}
