##
## EPITECH PROJECT, 2022
## Minishell1
## File description:
## Makefile
##

SRC	= 	src/explain.c 	\
		src/error_handling.c

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
