/*
** EPITECH PROJECT, 2020
** B-CPE-200-PAR-2-1-matchstick-gilbert.badiabo
** File description:
** main.c
*/

#include "matchstick.h"

int main(int ac, char const *av[])
{
    int check = check_input(ac, av);
    char **tab = NULL;
    int res = 0;

    if (check == 84)
        return 84;
    tab = get_board_game(my_atoi(av[1]));
    if (!tab)
        return 84;
    res = start_game(my_atoi(av[1]), my_atoi(av[2]), tab);
    return res;
}