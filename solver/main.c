/*
** EPITECH PROJECT, 2021
** B-CPE-200-RUN-2-1-dante-thomas.techer
** File description:
** main
*/

#include "./include/solver.h"

void print_map(solver_t *sol)
{
    for (int y = 0; y != sol->y; y++) {
        for (int x = 0; x != sol->x; x++) {
            if (sol->map[y][x] == '#')
                sol->map[y][x] = '*';
        }
    }
    for (int i = 0; i != sol->y; i++) {
        if (i > 0)
            printf("\n");
        printf("%s", sol->map[i]);
    }
}

int rec_algo(solver_t *sol, int x, int y, int z)
{
    sol->map[y][x] = 'o';
    if (x == sol->x - 1 && y == sol->y - 1)
        return 1;
    if (x + 1 < sol->x && sol->map[y][x + 1] == '*')
        if (rec_algo(sol, x + 1, y, z + 1) == 1)
            return 1;
    if (y + 1 < sol->y && sol->map[y + 1][x] == '*')
        if (rec_algo(sol, x, y + 1, z + 1) == 1)
            return 1;
    if (x - 1 >= 0 && sol->map[y][x - 1] == '*')
        if (rec_algo(sol, x - 1, y, z + 1) == 1)
            return 1;
    if (y - 1 >= 0 && sol->map[y - 1][x] == '*')
        if (rec_algo(sol, x, y - 1, z + 1) == 1)
            return 1;
    sol->map[y][x] = '#';
    return -1;
}

int init_map(solver_t *sol, char *av)
{
    FILE *f;
    char *tmp = NULL;
    size_t t = 0;
    int i = 0;

    if ((f = fopen(av, "r")) == NULL)
        printf("ERORERER");
    while (getline(&tmp, &t, f) != -1) {
        sol->map[i] = strdup(tmp);
        sol->map[i][sol->x] = '\0';
        i++;
    }
    fclose(f);
    return 0;
}

int init_malloc(solver_t *sol, char **av)
{
    FILE *f;
    char *tmp = NULL;
    size_t t = 0;

    if ((f = fopen(av[1], "r")) == NULL)
        return -1;
    while (getline(&tmp, &t, f) != -1)
        sol->y++;
    sol->x = strlen(tmp) - 1;
    if ((sol->map = malloc(sizeof(char *) * sol->y)) == NULL)
        return -1;
    for (int i = 0; i != sol->y; i++)
        if ((sol->map[i] = malloc(sizeof(char) * sol->x)) == NULL)
            return -1;
    if (init_map(sol, av[1]) == -1)
        return -1;
    fclose(f);
    return 0;
}

int main(int ac, char **av)
{
    solver_t sol;

    sol.map = NULL;
    sol.x = 0;
    sol.y = 0;
    if (ac != 2)
        return 84;
    if (init_malloc(&sol, av) == -1)
        return 84;
    if (rec_algo(&sol, 0, 0, 0) == -1) {
        printf("No path found!\n");
        for (int i = 0; i != sol.y; i++)
            free(sol.map[i]);
        free(sol.map);
        return 0;
    }
    print_map(&sol);
    for (int i = 0; i != sol.y; i++)
        free(sol.map[i]);
    free(sol.map);
}