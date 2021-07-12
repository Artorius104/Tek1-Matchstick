/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** print_updated_game_ai
*/

#include "matchstick.h"

int get_matchsticks_line_ai(char **tab, int i, int nb_matches)
{
    int count = 0;

    for (int j = 0; tab[i][j] != '\n'; j++)
        if (tab[i][j] == '|')
            count++;
    if (nb_matches > count)
        return 0;
    return 1;
}

void remove_stick_ai(char ***tab, int i, int j)
{
    if ((*tab)[i][j] == '|')
        (*tab)[i][j] = ' ';
}

char **update_board_game_ai(char **tab, int line, int nb_matches)
{
    int j = 0;

    for (int count_matches = nb_matches; count_matches > 0; count_matches--) {
        for (j = my_strlen(tab[line]) - 2; tab[line][j] != '|'; j--);
        if (tab[line][j] == '|')
            remove_stick(&tab, line, j);
    }
    return tab;
}