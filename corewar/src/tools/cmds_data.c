/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** cmds_data
*/

#include "corewar_header.h"

cmd_t cmds_data[] = {
    {1, 10, 1, exec_live},
    {2, 5, 2, exec_ld},
    {3, 5, 2, exec_st},
    {4, 10, 3, exec_add},
    {5, 10, 3, exec_sub},
    {6, 6, 3, exec_and},
    {7, 6, 3, exec_or},
    {8, 6, 3, exec_xor},
    {9, 20, 1, exec_zjmp},
    {10, 25, 3, exec_ldi},
    {11, 25, 3, exec_sti},
    {12, 800, 1, exec_fork},
    {13, 10, 2, exec_lld},
    {14, 50, 3, exec_lldi},
    {15, 1000, 1, exec_lfork},
    {16, 2, 1, exec_aff},
};
