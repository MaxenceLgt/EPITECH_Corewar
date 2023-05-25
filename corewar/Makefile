##
## EPITECH PROJECT, 2022
## Minishell1
## File description:
## Makefile
##

SRC	=	src/doc/help.c									\
		\
		src/tools/op.c									\
		src/tools/change_endians.c						\
		src/tools/destroy_vm.c							\
		src/tools/traduction.c 							\
		\
		src/commands/live.c								\
		src/commands/ld.c								\
		src/commands/zjmp.c								\
		src/commands/fork.c								\
		src/commands/lfork.c							\
		src/commands/aff.c								\
		src/commands/st.c								\
		src/commands/sti.c								\
		src/commands/add.c								\
		src/commands/sub.c								\
		src/commands/and.c								\
		src/commands/or.c								\
		src/commands/xor.c								\
		src/commands/ldi.c								\
		src/commands/lldi.c								\
		src/commands/lld.c								\
		\
		src/init/init_vm.c								\
		src/init/parse_args.c							\
		src/init/init_file_content.c					\
		\
		src/init/data_handling/handle_champ.c			\
		src/init/data_handling/handle_cycles.c			\
		\
		src/processing/add_champs_to_vm.c

MAIN =	src/main.c

INCLUDE =		lib/ml_headers/	\
				include/

NAME	=	corewar

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
