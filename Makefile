##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_hunter
##

SRC     =       pushswap.c	\

CPPFLAGS =	-I ./include

OBJ     =       $(SRC:.c=.o)

NAME    =       push_swap

all:		$(NAME)

$(NAME):        $(OBJ)
		make -C ./lib/my
		gcc -o $(NAME) $(OBJ) $(CPPFLAGS) -L ./lib -lmy

clean:
		rm -f $(OBJ)

fclean:		clean
		make fclean -C ./lib/my
		rm -f $(NAME)

re:		fclean all
