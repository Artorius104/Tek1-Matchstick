/*
** EPITECH PROJECT, 2020
** B-CPE-200-PAR-2-1-matchstick-gilbert.badiabo
** File description:
** check_arg.c
*/

#include "matchstick.h"

int check_str(char *str)
{
    for (int i = 0; str[i] != '\n'; i++)
        if (str[i] < '0' || str[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)\n");
            return 84;
        }
    return 0;
}

int check_removal_line(char **tab, int i)
{
    int count = 0;

    for (int j = 0; tab[i][j] != '\n'; j++)
        if (tab[i][j] == '|')
            count++;
    if (count == 0) {
        my_putstr("Error: not enough matches on this line\n");
        return 0;
    }
    else
        return 1;
}

int check_removal_matchstick(char **tab, int i, int nb_matches)
{
    int count = 0;

    if (nb_matches == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return 0;
    }
    for (int j = 0; tab[i][j] != '\n'; j++)
        if (tab[i][j] == '|')
            count++;
    if (count < nb_matches) {
        my_putstr("Error: not enough matches on this line\n");
        return 0;
    }
    else
        return 1;
}

int get_player_matches(char **tab, int line, int nb_matches_max)
{
    int nb_matches = 0;
    size_t size = 100;
    char *str = malloc(sizeof(char) * size);
    int check;

    my_putstr("Matches: ");
    check = getline(&str, &size, stdin);
    if (check == -1 || check == 0) {
        my_putchar('\n');
        return -1;
    }
    nb_matches = my_atoi(str);
    if (verif_player_matches(nb_matches, nb_matches_max) == 0
    || check_removal_matchstick(tab, line, nb_matches) == 0)
        return -2;
    if (check_str(str) == 84)
        return -2;
    return nb_matches;
}

int get_player_line(char **tab, int len)
{
    int line = 0;
    size_t size = 100;
    char *str = malloc(sizeof(char) * size);
    int check;

    my_putstr("Line: ");
    check = getline(&str, &size, stdin);
    if (check == -1 || check == 0) {
        my_putchar('\n');
        return -1;
    }
    line = my_atoi(str);
    if (verif_player_line(line, len) == 0
    || check_removal_line(tab, line) == 0)
        return get_player_line(tab, len);
    if (check_str(str) == 84)
        return get_player_line(tab, len);
    return line;
}