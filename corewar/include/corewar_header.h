/*
** EPITECH PROJECT, 2023
** corewar_header.h
** File description:
** corewar_header
*/

#ifndef COREWAR_HEADER_
    #define COREWAR_HEADER_

    #include "ml_lib_head.h"

    #define CHECK_HEXA (av[2][i] >= '0' && av[2][i] <= '9') \
|| (av[2][i] >= 65 && av[2][i] <= 70)

    void explain_h(char **av);
    int error_handling(char **av, int ac, int size_vm, int tot_vm);
    int init_flag_n(char **av, int size_vm, int tot_vm);

#endif /* !COREWAR_HEADER_ */
