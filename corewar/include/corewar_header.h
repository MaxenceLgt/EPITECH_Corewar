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
    #include <stdio.h>
    #include "ml_lib_head.h"
    #include "defines_header.h"
    #include "op.h"

    // STRUCT

    typedef struct process_struct {
        int reg[REG_NUMBER];
        int pos;
        size_t goal_cycle;
        bool carry;
        int pc;
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
        size_t last_check;
        size_t cycle_to_die;
        size_t cycle_delta;
        size_t current_cycle;
        size_t max_cycles;
        size_t nb_champ;
        ml_list *champs_data;
    } vm_t;

    typedef struct commands {
        int id;
        int cycles;
        int nb_args;
        int (*command)(vm_t *, champ_t *, process_t *, int *);
    } cmd_t;

    // ROOT

    void change_endians(void *data, size_t size);
    void destroy_vm(vm_t *vm);
    void destroy_champ(void *data);
    short get_short_param(unsigned char *vm, int start);
    int get_int_param(unsigned char *vm, int start);
    void set_int_to_char(int num, vm_t *vm, int pos);
    void set_short_to_char(short num, vm_t *vm, int pos);

    // DOC

    int manage_help(int ac, char **av);

    // INIT

    vm_t *init_vm(int ac, char **av);
    int parse_args(vm_t *vm, int ac, char **av);
    int handle_cycles(vm_t *vm, char **av, size_t *i);
    int handle_champ(vm_t *vm, char **av, size_t *i);
    int handle_champ_flags(champ_t *champ, vm_t *vm, char **av, size_t *i);
    void init_file_content(vm_t *vm);
    int add_champs_to_vm(vm_t *vm);
    int set_load_adress(vm_t *vm);
    size_t get_load(ml_list *champ_lst);
    bool only_one_load(ml_list *lst_champ);
    void sort_champion_lst(ml_list *champ_lst);
    void load_process(champ_t *champ, size_t pos);

    // COMMANDS

    int exec_live(vm_t *vm, champ_t *champ, process_t *process, int *args);
    int exec_ld(vm_t *vm, champ_t *champ, process_t *process, int *args);
    int exec_zjmp(vm_t *vm, champ_t *champ, process_t *process, int *args);
    int exec_lfork(vm_t *vm, champ_t *champ, process_t *process, int *args);
    int exec_fork(vm_t *vm, champ_t *champ, process_t *process, int *args);
    int exec_aff(vm_t *vm, champ_t *champ, process_t *process, int *args);
    int exec_add(vm_t *vm, champ_t *champ, process_t *process, int *args);
    int exec_and(vm_t *vm, champ_t *champ, process_t *process, int *args);
    int exec_ldi(vm_t *vm, champ_t *champ, process_t *process, int *args);
    int exec_lld(vm_t *vm, champ_t *champ, process_t *process, int *args);
    int exec_lldi(vm_t *vm, champ_t *champ, process_t *process, int *args);
    int exec_or(vm_t *vm, champ_t *champ, process_t *process, int *args);
    int exec_st(vm_t *vm, champ_t *champ, process_t *process, int *args);
    int exec_sti(vm_t *vm, champ_t *champ, process_t *process, int *args);
    int exec_sub(vm_t *vm, champ_t *champ, process_t *process, int *args);
    int exec_xor(vm_t *vm, champ_t *champ, process_t *process, int *args);

    // COREWAR

    int process_corewar(UNUSED vm_t *vm);
    int check_alive_state(vm_t *vm);
    int exec_prog(UNUSED vm_t *vm);
    void display_winner(vm_t *vm);
    int *get_params_type(process_t *process, unsigned char *vm);
    void init_goal_cycle(vm_t *vm, ml_list *champ_lst);
    void move_to_pc(vm_t *vm, process_t *process);

    // TOOLS
    int get_hexa(unsigned char buffer);

    // COMMAND STRUCT

    extern cmd_t cmds_data[];

#endif /* !COREWAR_HEADER_ */
