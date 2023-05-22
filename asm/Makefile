##
## EPITECH PROJECT, 2022
## Minishell1
## File description:
## Makefile
##

SRC	=	src/op.c										\
		src/compiler/compile_asm_code.c					\
		\
		src/compiler/struct_comp/convert_file_content.c	\
		src/compiler/struct_comp/init_compiler_struct.c	\
		src/compiler/struct_comp/destroy_comp_struct.c	\
		src/compiler/struct_comp/get_labels.c			\
		\
		src/compiler/error_handling/manage_errors.c		\
		src/compiler/error_handling/file_is_readable.c	\
		src/compiler/error_handling/header_presence.c	\
		src/compiler/error_handling/check_cmd_err.c		\
		src/compiler/error_handling/check_cmd_content.c	\
		src/compiler/error_handling/comment_manage.c	\
		src/compiler/error_handling/label_management.c	\
		\
		src/compiler/transcribe/transcribe_header.c		\
		src/compiler/transcribe/calculate_prog_size.c	\
		src/compiler/transcribe/remove_comment_to_tab.c	\
		src/compiler/transcribe/index_management.c		\
		src/compiler/transcribe/transcribe_body.c		\
		src/compiler/transcribe/transcribe_values.c		\
		src/compiler/transcribe/transcribe_label.c

MAIN =	src/main.c

INCLUDE =	include/	\
			lib/ml_headers/

NAME	=	asm

CFLAGS = $(INCLUDE:%=-I%) -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

OBM =	$(MAIN:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(OBM)
	make -C lib/
	gcc -o $(NAME) $(OBJ) $(OBM) -Llib/ -lml_lib -lml_printf

clean:
	make clean -C lib/
	rm -f $(OBJ) $(OBM)

fclean:	clean
	make fclean -C lib/
	rm -f $(NAME)

re: fclean all

.SILENT:

.PHONY: all clean fclean re
