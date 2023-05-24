/*
** EPITECH PROJECT, 2023
** asm_header
** File description:
** asm_header
*/

#ifndef ASM_HEAD_
    #define ASM_HEAD_

    #include "ml_lib_head.h"
    #include "op.h"
    #include "indexes.h"
    #include "define_head.h"

    typedef struct compiler_s {
        char *f_out;
        char **f_lines;
        char **labels;
        int fd_out;
    } compiler_t;

    int compile_asm_code(const char *file);
    void change_endians(void *data, size_t size);

    /// COMPILER STRUCT ///

    compiler_t *init_compiler(const char *file);
    char **convert_file_content(char *buffer);
    void destroy_comp_struct(compiler_t *info);
    char **get_labels(char **lines);

    /// ERROR HANDLING ///

    int manage_errors(const char *file);
    bool str_num(char *str);
    bool file_is_readable(const char *file);
    bool presence_of_header(char *buff);
    int check_cmd_validity(compiler_t *info);
    bool comment_is_present(char *line);
    char *delete_comment(char *line);
    bool line_is_label(char *line);
    bool verify_cmd_and_args(char **cmd, char **labels);
    bool is_existant_label(char *cmd, char **labels);
    bool cmd_call_label(char *cmd);

    /// TRANSCRIBE ///

    void remove_comment_to_tab(char ***tab);
    int calculate_prog_size(char **prog);
    int calculate_size_cmd(char *cmd);
    void transcribe_header(compiler_t *info);
    bool is_in_index_lst(char *cmd);
    int manage_index_arg(char **args);
    bool codingbyte_is_present(char *cmd);
    int calculate_prog_size(char **prog);
    void transcribe_body(char **body, compiler_t *info);
    void transcribe_register(char *nb_str, int fd_out);
    void transcribe_direct_or_ind(char *str, compiler_t *info, size_t pos);
    void transcribe_index(char *str, compiler_t *info, size_t i);
    void transcribe_label(compiler_t *info, size_t i, char *name);
    void transcribe_direct_label(compiler_t *info, size_t pos, char *name);

#endif /* !ASM_HEAD_ */
