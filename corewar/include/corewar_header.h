/*
** EPITECH PROJECT, 2023
** corewar_header.h
** File description:
** corewar_header
*/

#ifndef COREWAR_HEADER_
    #define COREWAR_HEADER_

    // INCLUDES

    #include "ml_lib_head.h"

    // STRUCT

typedef struct virtual_machine {
    char *tmp;
} vm_t;

    // DOC

    void manage_help(int ac, char **av);

    // INIT

    vm_t *init_vm(char **av);

#endif /* !COREWAR_HEADER_ */
