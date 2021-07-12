/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** print_updated_game
*/

#include "matchstick.h"

void remove_stick(char ***tab, int y, int x)
{
    if ((*tab)[y][x] == '|')
        (*tab)[y][x] = ' ';
}

char **update_board_game(char **tab, int line, int nb_matches)
{
    int y = 0;
    int x = 0;

    for (y = 0; y < line; y++);
    for (int count_matches = nb_matches; count_matches > 0; count_matches--) {
        for (x = my_strlen(tab[y]) - 2; tab[y][x] != '|'; x--);
        remove_stick(&tab, y, x);
    }
    return tab;
}