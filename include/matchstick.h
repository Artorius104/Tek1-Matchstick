/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myrunner-gilbert.badiabo
** File description:
** matchstick.h
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int start_game(int len, int nb_matches_max, char **tab);
int game_loop(int len, int nb_matches_max, char **tab);
int check_input(int ac, char const **av);
char **get_board_game(int len);
void get_boarder(char **tab, int len);
void get_matchstick(char **tab, int len);
int player_interaction(char **tab, int nb_matches_max, int len);
void player_removal_message(int nb_matches, int line);
int verif_player_line(int line, int len);
int verif_player_matches(int nb_matches, int nb_matches_max);
int check_removal_matchstick(char **tab, int i, int nb_matches);
int get_player_line(char **tab, int len);
int get_player_matches(char **tab, int line, int nb_matches_max);
int check_str(char *str);
char **update_board_game(char **tab, int line, int nb_matches);
void remove_stick(char ***tab, int y, int x);
int ai_interaction(char **tab, int nb_matches_max, int len);
void ai_remove_message(int nb_matches, int nb_line);
int random_nb_matches(int nb_matches_max);
int random_line(int len);
char **update_board_game_ai(char **tab, int line, int nb_matches);
void remove_stick_ai(char ***tab, int y, int x);
int get_matchsticks_line_ai(char **tab, int y, int nb_matches);
int count_stick(char **tab, int len);
int win_or_lose(int verif);

#endif