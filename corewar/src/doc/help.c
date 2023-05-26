/*
** EPITECH PROJECT, 2023
** VM
** File description:
** -h
*/

#include <unistd.h>

#include "corewar_header.h"

int manage_help(int ac, char **av)
{
    if (ac == 2 && ml_strcmp(av[1], "-h") == 0) {
        ml_printf("USAGE\n");
        ml_printf("./corewar [-dump nbr_cycle] [[-n prog_number] ");
        ml_printf("[-a load_address] prog_name] ...\nDESCRIPTION\n");
        ml_printf("-dump nbr_cycle dumps the memory after ");
        ml_printf("the nbr_cycle execution (if the round is not");
        ml_printf("already over) with the following format: 32 bytes/line");
        ml_printf("in hexadecimal (A0BCDEFE1DD3...)\n");
        ml_printf("-n prog_number sets the next number of program. ");
        ml_printf("By default, the first free number");
        ml_printf("in the parameter order\n");
        ml_printf("-a load_address sets the next loading");
        ml_printf("_address of program. When no address is");
        ml_printf("specified, optimize the addresses so that ");
        ml_printf("the processes are as far");
        ml_printf("away from each other as possible. ");
        ml_printf("The addresses are MEM_SIZE modulo.\n");
        return 1;
    }
    return 0;
}
