/*
** EPITECH PROJECT, 2021
** B-CPE-200-RUN-2-1-dante-thomas.techer
** File description:
** print
*/

#include "./include/generator.h"

void print_map(char **tab, int x, int y)
{
    int i = 0;
    int j = 0;
    int np = 0;

    while (i < y) {
        j = 0;
        if (i > 0)
            printf("\n");
        while (j < x) {
            if (i == y - 1 && j == x - 1 && tab[i][j] == 'X') {
                printf("*");
                np = 1;
            }
            if (tab[i][j] == '*')
                printf("*");
            if (tab[i][j] == 'X' && np != 1)
                printf("X");
            j++;
        }
        i++;
    }
}