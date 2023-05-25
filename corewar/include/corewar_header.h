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

    int command_live(vm_t *vm, champ_t *champ);
    int command_ld(int par, vm_t *vm, process_t *process);
    int command_zjmp(int reg, vm_t *vm);
    int command_fork(int par, vm_t *vm);
    int command_lfork(int par, vm_t *vm);
    int command_aff(int reg, vm_t *vm);
    int command_add(process_t *process, vm_t *vm);
    int command_and(int par, process_t *process, vm_t *vm);
    int command_ldi(int par, vm_t *vm);
    int command_lld(int par, process_t *process, vm_t *vm);
    int command_lldi(int par, process_t *process, vm_t *vm);
    int command_or(int par, process_t *process, vm_t *vm);
    int command_st(int par, vm_t *vm);
    int command_sti(int par, vm_t *vm);
    int command_sub(int reg, process_t *process, vm_t *vm);
    int command_xor(int par, process_t *process, vm_t *vm);

    int process_corewar(UNUSED vm_t *vm);
    void display_winner(vm_t *vm);
    // TOOLS
    int get_hexa(unsigned char buffer);

#endif /* !COREWAR_HEADER_ */
