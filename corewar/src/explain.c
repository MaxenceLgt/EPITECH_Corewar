/*
** EPITECH PROJECT, 2023
** VM
** File description:
** -h
*/

#include <unistd.h>

#include "corewar_header.h"

void explain_h(char **av)
{
    if (my_strcmp(av[1], "-h") == 0) {
        write(1, "USAGE\n", 7);
        write(1, "./corewar [-dump nbr_cycle] [[-n prog_number] ", 46);
        write(1, "[-a load_address] prog_name] ...\n", 33);
        write(1, "DESCRIPTION\n", 13);
        write(1, "-dump nbr_cycle dumps the memory after ", 39);
        write(1, "the nbr_cycle execution (if the round is not", 44);
        write(1, "already over) with the following format: 32 bytes/line", 54);
        write(1, "in hexadecimal (A0BCDEFE1DD3...)\n", 33);
        write(1, "-n prog_number sets the next number of program. ", 48);
        write(1, "By default, the first free number", 33);
        write(1, "in the parameter order\n", 23);
        write(1, "-a load_address sets the next loading", 38);
        write(1, "_address of program. When no address is", 39);
        write(1, "specified, optimize the addresses so that ", 42);
        write(1, "the processes are as far", 24);
        write(1, "away from each other as possible. ", 34);
        write(1, "The addresses are MEM_SIZE modulo.\n", 36);
    }
}
