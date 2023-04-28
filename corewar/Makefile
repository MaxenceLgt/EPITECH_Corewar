##
## EPITECH PROJECT, 2022
## Minishell1
## File description:
## Makefile
##

SRC	=

MAIN =	src/main.c

INCLUDE =	include/

NAME	=	corewar

CFLAGS = $(INCLUDE:%=-I%) -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

OBM =	$(MAIN:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(OBM)
	gcc -o $(NAME) $(OBJ) $(OBM)

clean:
	rm -f $(OBJ) $(OBM)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.SILENT:

.PHONY: all clean fclean re
