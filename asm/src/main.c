/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "asm_head.h"

static void display_usage(void)
{
    write(1, "USAGE\n", 7);
    write(1, "./asm file_name[.s]\n", 21);
    write(1, "DESCRIPTION\n", 13);
    write(1, "file_name file in assembly ", 27);
    write(1, "language to be converted into ", 30);
    write(1, "file_name.cor, an executable in the Virtual Machine.\n", 53);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (ac == 2 && ml_strcmp(av[1], "-h") == 0)
        display_usage();
    else
        compile_asm_code(av[1]);
    return 0;
}
