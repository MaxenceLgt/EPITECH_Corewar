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
        write(2, "USAGE\n", 7);
        write(2, "./corewar [-dump nbr_cycle] [[-n prog_number] ", 46);
        write(2, "[-a load_address] prog_name] ...\n", 33);
        write(2, "DESCRIPTION\n", 13);
        write(2, "-dump nbr_cycle dumps the memory after ", 39);
        write(2, "the nbr_cycle execution (if the round is not", 44);
        write(2, "already over) with the following format: 32 bytes/line", 54);
        write(2, "in hexadecimal (A0BCDEFE1DD3...)\n", 33);
        write(2, "-n prog_number sets the next number of program. ", 48);
        write(2, "By default, the first free number", 33);
        write(2, "in the parameter order\n", 23);
        write(2, "-a load_address sets the next loading", 38);
        write(2, "_address of program. When no address is", 39);
        write(2, "specified, optimize the addresses so that ", 42);
        write(2, "the processes are as far", 24);
        write(2, "away from each other as possible. ", 34);
        write(2, "The addresses are MEM_SIZE modulo.\n", 36);
    }
}
