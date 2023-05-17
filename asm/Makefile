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
		\
		src/compiler/error_handling/manage_errors.c		\
		src/compiler/error_handling/file_is_readable.c	\
		src/compiler/error_handling/header_presence.c

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
