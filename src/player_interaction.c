/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** interaction_game
*/

#include "matchstick.h"

void player_removal_message(int nb_matches, int line)
{
    my_putstr("Player removed ");
    my_put_nbr(nb_matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int player_interaction(char **tab, int nb_matches_max, int len)
{
    int line = 0;
    int nb_matches = 0;

    line = get_player_line(tab, len);
    if (line == -1)
        return 84;
    nb_matches = get_player_matches(tab, line, nb_matches_max);
    if (nb_matches == -1)
        return 84;
    else if (nb_matches == -2)
        return player_interaction(tab, nb_matches_max, len);
    tab = update_board_game(tab, line, nb_matches);
    player_removal_message(nb_matches, line);
    for (int i = 0; i < (len + 2); i++)
        my_putstr(tab[i]);
    return 2;
}