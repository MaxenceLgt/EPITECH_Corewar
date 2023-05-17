/*
** EPITECH PROJECT, 2023
** asm_header
** File description:
** asm_header
*/

#ifndef ASM_HEAD_
    #define ASM_HEAD_

    #define UNUSED __attribute__((__unused__))

    #include "ml_lib_head.h"
    #include "op.h"

    int compile_asm_code(char *file);

    /// ERROR HANDLING ///

    int manage_errors(char *file);

#endif /* !ASM_HEAD_ */
