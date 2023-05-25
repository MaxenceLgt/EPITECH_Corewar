/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "corewar_header.h"

int calcul_n_pc(int v, int pc)
{
    int r;

    r = (v % IDX_MOD) + pc;
    if (r < 0)
        return (MEM_SIZE + r) % MEM_SIZE;
    else
        return (r % MEM_SIZE);
    return -1;
}

int command_fork(UNUSED int arg, vm_t *vm, champ_t *champ, process_t *process)
{
    int n_pc;
    int v;

    v = champ->champ_content[0];
    n_pc = calcul_n_pc(v, process->pc);
    if (n_pc == -1)
        ml_printf("ERROR\n");
    return 0;
}
