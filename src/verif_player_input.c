/*
** EPITECH PROJECT, 2020
** B-CPE-200-PAR-2-1-matchstick-gilbert.badiabo
** File description:
** verif_player_input.c
*/

#include "matchstick.h"

int verif_player_line(int line, int len)
{
    if (line > len || line == 0) {
        my_putstr("Error: this line is out of range\n");
        return 0;
    }
    if (line < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return 0;
    }
    else
        return 1;
}

int verif_player_matches(int nb_matches, int nb_matches_max)
{
    if (nb_matches > nb_matches_max) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(nb_matches_max);
        my_putstr(" matches per turn\n");
        return 0;
    }
    if (nb_matches < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return 0;
    }
    if (nb_matches == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return 0;
    }
    return 1;
}