/*
** EPITECH PROJECT, 2023
** corewar_header.h
** File description:
** corewar_header
*/

#ifndef COREWAR_HEADER_
    #define COREWAR_HEADER_

    // INCLUDES

    #include <stdbool.h>
    #include <sys/types.h>
    #include "ml_lib_head.h"
    #include "defines_header.h"
    #include "op.h"

    // STRUCT

    typedef struct process_struct {
        int reg[REG_NUMBER];
        int pos;
        int goal_cycle;
        bool carry;
    } process_t;

    typedef struct champs {
        char *file;
        char *name;
        size_t load_address;
        size_t prog_number;
        unsigned char *champ_content;
        bool is_alive;
        ml_list *process;
        size_t prog_size;
    } champ_t;

    typedef struct virtual_machine {
        unsigned char *vm;
        size_t nbr_live;
        size_t cycle_to_die;
        size_t cycle_delta;
        size_t nb_champ;
        ml_list *champs_data;
    } vm_t;

    // ROOT

    void change_endians(void *data, size_t size);
    void destroy_vm(vm_t *vm);

    // DOC

    int manage_help(int ac, char **av);

    // INIT

    vm_t *init_vm(int ac, char **av);
    int parse_args(vm_t *vm, int ac, char **av);
    int handle_cycles(vm_t *vm, char **av, size_t *i);
    int handle_champ(vm_t *vm, char **av, size_t *i);
    void init_file_content(vm_t *vm);

    // PROCESSING

    int add_champs_to_vm(vm_t *vm);

    // COMMANDS

    int command_live(int reg, vm_t *vm, champ_t *node);
    int command_ld(int reg, vm_t *vm, process_t *process);

#endif /* !COREWAR_HEADER_ */
