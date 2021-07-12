/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** win_or_lose
*/

#include "matchstick.h"

int count_stick(char **tab, int len)
{
    int count = 0;

    for (int i = 0; i < (len + 2); i++) {
        for (int j = 0; tab[i][j] != '\n'; j++) {
            if (tab[i][j] == '|')
                count++;
        }
    }
    return count;
}

int win_or_lose(int verif)
{
    if (verif == 1) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return 1;
    }
    if (verif == 2) {
        my_putstr("You lost, too bad...\n");
        return 2;
    }
    return 0;
}