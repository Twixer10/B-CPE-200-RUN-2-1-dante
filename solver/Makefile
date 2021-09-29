##
## EPITECH PROJECT, 2020
## makefile exe
## File description:
## fct
##

SRC	=	$(wildcard *.c)

CFLAGS	=	-W -Wextra -Wall -Werror -g3

IFLAGS	=	-I include/

NAME	=	solver

all:
	gcc -o $(NAME) $(SRC) $(IFLAGS) $(CFLAGS)

clean:
	rm -f *~
	rm -f *.o

fclean:
	rm -f $(NAME)

re:	fclean all