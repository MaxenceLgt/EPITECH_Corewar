/*
** EPITECH PROJECT, 2023
** corewar_header.h
** File description:
** corewar_header
*/

#ifndef COREWAR_HEADER_
    #define COREWAR_HEADER_

    // INCLUDES

    #include <sys/types.h>
    #include "ml_lib_head.h"

    // STRUCT

    typedef struct champs {
        int load_address;
        int prog_number;
        unsigned char *champ_content;
    } champ_t;

    typedef struct virtual_machine {
        unsigned char *vm;
        size_t nbr_live;
        size_t cycle_to_die;
        size_t cycle_delta;
        ml_list *champs_data;
    } vm_t;

    // DOC

    void manage_help(int ac, char **av);

    // INIT

    vm_t *init_vm(char **av);
    int parse_args(vm_t *vm, char **av);

#endif /* !COREWAR_HEADER_ */
