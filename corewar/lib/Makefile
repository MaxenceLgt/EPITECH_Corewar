##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME = libs

all:	$(NAME)

$(NAME):
	make -C ml_printf/
	make -C ml_lib/

clean:
	make clean -C ml_printf/
	make clean -C ml_lib/

fclean:	clean
	make fclean -C ml_printf/
	make fclean -C ml_lib/

re: fclean all

.SILENT:
