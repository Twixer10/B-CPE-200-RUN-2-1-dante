/*
** EPITECH PROJECT, 2021
** B-CPE-200-RUN-2-1-dante-thomas.techer
** File description:
** perfect
*/

#include "./include/generator.h"

void two_wall(char **tab, int i, int j)
{
    int random = rand()%2;
    if (j - 1 >= 0 && random == 0)
        tab[i][j - 1] = '*';
    else if (i - 1 >= 0 && random == 1)
        tab[i - 1][j] = '*';
}

void one_wall(char **tab, int i, int j, generator_t *gen)
{
    if (i - 1 >= 0 && gen->up == 1 && gen->up == 0)
        tab[i - 1][j] = '*';
    if (j - 1 >= 0 && gen->up == 0 && gen->up == 1)
        tab[i][j - 1] = '*';
}

void up_left(char **tab, int i, int j, generator_t *gen)
{
    if (j - 1 >= 0 && tab[i][j - 1] == 'X')
        gen->left = 1;
    if (i - 1 >= 0 && tab[i - 1][j] == 'X')
        gen->up = 1;
}

void al_perfect(generator_t * gen, char **tab)
{
    int i = 0;
    int j;

    while (i < gen->y) {
        j = 0;
        gen->up = 0;
        gen->left = 0;
        while (j < gen->x) {
            up_left(tab, i, j, gen);
            one_wall(tab, i, j, gen);
            if (gen->up == 1 && gen->left == 1)
                two_wall(tab, i, j);
            j++;
        }
        i++;
    }
}

void get_perfect(int x, int y)
{
    char **tab;
    generator_t gen;

    gen.x = x;
    gen.y = y;
    gen.up = 0;
    gen.left = 0;
    tab = init_tab(x, y);
    if (tab == NULL)
        return ;
    tab = init_maze(tab, x, y);
    al_perfect(&gen, tab);
    print_map(tab, x, y);
}