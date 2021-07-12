/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** matchstick
*/

#include "matchstick.h"

int game_loop(int len, int nb_matches_max, char **tab)
{
    int verif = 0;
    int count = -1;

    while (count != 0) {
        my_putstr("Your turn:\n");
        verif = player_interaction(tab, nb_matches_max, len);
        if (verif == 84)
            break;
        if (count_stick(tab, len) == 0)
            break;
        my_putchar('\n');
        verif = ai_interaction(tab, nb_matches_max, len);
        if (count_stick(tab, len) == 0)
            break;
        my_putchar('\n');
    }
    return verif;
}

int start_game(int len, int nb_matches_max, char **tab)
{
    int verif = 0;

    for (int i = 0; i < (len + 2); i++)
        my_putstr(tab[i]);
    my_putchar('\n');
    verif = game_loop(len, nb_matches_max, tab);
    return win_or_lose(verif);
}
