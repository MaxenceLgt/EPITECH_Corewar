/*
** EPITECH PROJECT, 2023
** ASM
** File description:
** -h
*/

#include <unistd.h>

#include "asm_header.h"

void explain_h(char **av)
{
    if (my_strcmp(av[1], "-h") == 0) {
        write(2, "USAGE\n", 7);
        write(2, "./asm file_name[.s]\n", 21);
        write(2, "DESCRIPTION\n", 13);
        write(2, "file_name file in assembly ", 27);
        write(2, "language to be converted into ", 30);
        write(2, "file_name.cor, an executable in the Virtual Machine.\n", 53);
    }
}
