/*
** EPITECH PROJECT, 2021
** B-CPE-200-RUN-2-1-dante-thomas.techer
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct generator_h
{
    int x;
    int y;
    int up;
    int left;
} generator_t;

void print_map(char **tab, int x, int y);
void imperfect(int x, int y);
char **init_tab(int x, int y);
char **init_maze(char **tab, int x, int y);
void break_fifprct(char **tab, int x, int y);
void al_perfect(generator_t * gen, char **tab);
void get_perfect(int x, int y);

#endif /* !GENERATOR_H_ */
