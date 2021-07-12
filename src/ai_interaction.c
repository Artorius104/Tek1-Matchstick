/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** ai_interaction
*/

#include "matchstick.h"

int random_line(int len)
{
    int nb = rand() % len + 1;
    if (nb <= 0 || nb > len)
        nb = random_line(len);
    return nb;
}

int random_nb_matches(int nb_matches_max)
{
    int nb = rand() % nb_matches_max + 1;
    if (nb <= 0 || nb > nb_matches_max)
        nb = random_nb_matches(nb_matches_max);
    return nb;
}

void ai_remove_message(int nb_matches, int nb_line)
{
    my_putstr("AI removed ");
    my_put_nbr(nb_matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(nb_line);
    my_putchar('\n');
}

int ai_interaction(char **tab, int nb_matches_max, int len)
{
    int nb_line;
    int nb_matches;
    int verif = 0;

    srand(time(NULL));
    my_putstr("AI's turn...\n");
    while (verif == 0) {
        nb_line = random_line(len);
        nb_matches = random_nb_matches(nb_matches_max);
        verif = get_matchsticks_line_ai(tab, nb_line, nb_matches);
    }
    tab = update_board_game_ai(tab, nb_line, nb_matches);
    ai_remove_message(nb_matches, nb_line);
    for (int y = 0; y < (len + 2); y++)
        my_putstr(tab[y]);
    return 1;
}