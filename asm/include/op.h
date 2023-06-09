/*
** EPITECH PROJECT, 2023
** op
** File description:
** op
*/

#ifndef OP_H_
    #define OP_H_

    #define MEM_SIZE (6 * 1024)
    #define IDX_MOD 512   /* modulo of the index < */

    // ARGS

    #define MAX_ARGS_NUMBER 4     /* this may not be changed 2^*IND_SIZE */
    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

    // HEADER

    #define COREWAR_EXEC_MAGIC 0xea83f3        /* why not */
    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"

    // REGS
    #define REG_NUMBER 16              /* r1 <--> rx */

    // ARGS
    typedef char args_type_t;

    // Register
    #define T_REG 1
    // Direct (ld  #1,r1  put 1 into r1)
    #define T_DIR 2
    /* Indirect always relative ( ld 1,r1 put what's in the address (1+pc)
    into r1 (4 bytes )) */
    #define T_IND 4
    // LABEL
    #define T_LAB 8

    // SIZE (in bytes)

    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE DIR_SIZE

    // HEADER

    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048

    // LIVE

    // Number of cycle before beig declared dead
    #define CYCLE_TO_DIE 1536
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40

    typedef struct op_s {
        char *mnemonique;
        char nbr_args;
        args_type_t  type[MAX_ARGS_NUMBER];
        char code;
        int nbr_cycles;
        char *comment;
    } op_t;

    typedef struct header_s {
        int magic;
        char prog_name[PROG_NAME_LENGTH + 1];
        int prog_size;
        char comment[COMMENT_LENGTH + 1];
    } header_t;

    // OP_TAB

    extern op_t op_tab[];

#endif /* OP_H_ */
