/*
** EPITECH PROJECT, 2023
** set_info_next_step
** File description:
** set_info_next_step
*/

#include <stdio.h>
#include "corewar_header.h"

void move_to_pc(vm_t *vm, process_t *process)
{
    process->pos = process->pc;

    for (size_t i = 0; op_tab[i].nbr_args != 0; i++) {
        if (op_tab[i].code == vm->vm[process->pos]) {
            process->goal_cycle += op_tab[i].nbr_cycles;
            break;
        }
    }
}
