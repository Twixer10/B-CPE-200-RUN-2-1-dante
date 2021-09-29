##
## EPITECH PROJECT, 2021
## B-CPE-200-RUN-2-1-dante-thomas.techer
## File description:
##makefile
##

all:
	make --no-print-directory -C generator
	make --no-print-directory -C solver

clean:
	make --no-print-directory -C generator clean
	make --no-print-directory -C solver clean

fclean:
	make --no-print-directory -C generator fclean
	make --no-print-directory -C solver fclean

re:
	make --no-print-directory -C generator re
	make --no-print-directory -C solver re