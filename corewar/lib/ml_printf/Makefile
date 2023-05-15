##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	src/ml_printf.c	\
		src/display_functions/display_char_pf.c	\
		src/display_functions/display_int_pf.c	\
		src/display_functions/display_str_pf.c	\
		src/display_functions/strlen_pf.c	\
		src/func_point_display/display_char.c	\
		src/func_point_display/display_int.c	\
		src/func_point_display/display_modulo.c	\
		src/func_point_display/display_str.c


INCLUDE = include/

NAME	=	libml_printf.a

CFLAGS = $(INCLUDE:%=-I%) -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o ../$(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)

re: fclean all

.SILENT:
