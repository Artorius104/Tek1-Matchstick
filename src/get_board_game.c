/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** print_game
*/

#include "matchstick.h"

void get_matchstick(char **tab, int len)
{
    int k = 0;
    int m = my_strlen(tab[0]);
    int o = m - 2;

    for (int i = len; i > 0; i--) {
        for (int j = 1; tab[i][j] != '*'; j++)
            tab[i][j] = '|';
        if (k >= 1) {
            for (int w = 1; w <= k; w++)
                tab[i][w] = ' ';
            for (int n = (m - 2); n > (m / 2) && n > o; n--)
                tab[i][n - 1] = ' ';
        }
        o--;
        k++;
    }
}

void get_boarder(char **tab, int len)
{
    for (int i = 0; i < (len + 2); i++) {
        if (i == 0 || i == (len + 1)) {
            for (int j = 0; j < ((len * 2) + 1); j++) {
                tab[i][j] = '*';
                tab[i][j + 1] = '\n';
            }
        }
        if (i > 0 && i < (len + 1)) {
            for (int j = 0; j < ((len * 2) + 1); j++) {
                tab[i][0] = '*';
                tab[i][j] = ' ';
                tab[i][(len * 2)] = '*';
                tab[i][j + 1] = '\n';
            }
        }
    }
}

char **get_board_game(int len)
{
    char **tab = malloc(sizeof(char *) * (len + 2));

    if (!tab)
        return NULL;
    for (int i = 0; i < (len + 2); i++) {
        tab[i] = malloc(sizeof(char) * ((len * 2) + 2));
        if (!tab[i])
            return NULL;
    }
    get_boarder(tab, len);
    get_matchstick(tab, len);

    return tab;
}