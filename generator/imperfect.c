/*
** EPITECH PROJECT, 2021
** B-CPE-200-RUN-2-1-dante-thomas.techer
** File description:
** imperfect
*/

#include "./include/generator.h"

void break_fifprct(char **tab, int x, int y)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int mid = (x * y) / 2;

    while (i < mid) {
        j = rand()%x;
        k = rand()%y;
        if (tab[k][j] == 'X')
            tab[k][j] = '*';
        i++;
    }
}

char **init_maze(char **tab, int x, int y)
{
    int i = 0;
    int j = 0;

    for (; i < y; i++) {
        j = 0;
        for (; j < x; j++) {
            if (j % 2 == 0 && i % 2 == 0)
                tab[i][j] = '*';
            else if (j % 2 != 0 && i % 2 == 0)
                tab[i][j] = 'X';
            else
                tab[i][j] = 'X';
        }
        tab[i][j] = '\0';
    }
    tab[y-1][x-2] = '*';
    return (tab);
}

char **init_tab(int x, int y)
{
    int i = 0;
    char **tab;

    if ((tab = malloc(sizeof(char *) * (y + 1))) == NULL)
        return (NULL);
    while (i < y) {
        if ((tab[i] = malloc(sizeof(char) * (x + 1))) == NULL)
            return (NULL);
        i++;
    }
    tab[i] = NULL;
    return (tab);
}

void imperfect(int x, int y)
{
    char **tab;
    generator_t gen;

    gen.y = y;
    gen.x = x;
    gen.up = 0;
    gen.left = 0;
    tab = init_tab(x, y);
    if (tab == NULL)
        return ;
    tab = init_maze(tab, x, y);
    al_perfect(&gen, tab);
    break_fifprct(tab, x, y);
    print_map(tab, x, y);
}