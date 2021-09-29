/*
** EPITECH PROJECT, 2021
** B-CPE-200-RUN-2-1-dante-thomas.techer
** File description:
** main
*/

#include "./include/generator.h"

int	main(int ac, char **av)
{
    srand(time(NULL));
    if (ac >= 3 && ac <= 4) {
        if (atol(av[1]) != 0 && atol(av[2]) != 0) {
	        if (ac == 3)
                imperfect(atoi(av[1]), atoi(av[2]));
            else if (ac == 4 && strcmp(av[3], "perfect") == 0) {
                get_perfect(atoi(av[1]), atoi(av[2]));
            } else
                return 84;
        } else
            return 84;
    } else
        return 84;
    return 0;
}
