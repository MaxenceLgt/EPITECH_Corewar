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
    #include "define_head.h"

    typedef struct compiler_s {
        char *f_out;
        char **f_lines;
        char **labels;
    } compiler_t;

    int compile_asm_code(char *file);

    /// COMPILER STRUCT ///

    compiler_t *init_compiler(const char *file);
    char **convert_file_content(char *buffer);
    void destroy_comp_struct(compiler_t *info);

    /// ERROR HANDLING ///

    int manage_errors(const char *file);
    bool file_is_readable(const char *file);
    bool presence_of_header(char *buff);

#endif /* !ASM_HEAD_ */
