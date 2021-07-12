/*
** EPITECH PROJECT, 2020
** tmp_matchstick
** File description:
** check_arg.c
*/

#include "matchstick.h"

int check_input(int ac, char const **av)
{
    if (ac != 3)
        return 84;
    for (int i = 1; i < 3; i++)
        if (my_str_isnum(av[i]) == 0)
            return 84;
    for (int i = 1; i < 3; i++)
        for (int j = 0; av[i][j] != '\0'; j++)
            if (av[i][j] < '0' || av[i][j] > '9')
                return 84;
    if (my_getnbr(av[1]) <= 0 || my_getnbr(av[2]) <= 0)
        return 84;
    return 0;
}