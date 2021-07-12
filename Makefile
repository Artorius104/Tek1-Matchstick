##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## matchstick
##

PATH_SRC        =       src/

PATH_LIB        =       lib/my/

LIB     = -L./lib -lmy

CRITERION_FLAGS =       --coverage -lcriterion

CPPFLAGS = -I./include

CFLAGS  =       -W -Wall -Wextra -g3

CC = gcc

NAME    =       matchstick

SRC_MAIN        =       $(PATH_SRC)main.c       \

SRC             =       $(PATH_SRC)matchstick.c	\
						$(PATH_SRC)ai_interaction.c	\
						$(PATH_SRC)check_start_input.c	\
						$(PATH_SRC)get_board_game.c \
						$(PATH_SRC)get_player_arg.c \
						$(PATH_SRC)player_interaction.c \
						$(PATH_SRC)update_game_ai.c \
						$(PATH_SRC)update_game.c \
						$(PATH_SRC)verif_player_input.c \
						$(PATH_SRC)win_or_lose.c \

TEST_NAME       =       unit_tests

PATH_TESTS      =       tests/

SRC_TESTS       =       \

OBJ     =       $(SRC:.c=.o) $(SRC_MAIN:.c=.o)

all:    $(NAME)

$(NAME):    $(OBJ)
		make -C ./$(PATH_LIB)
		$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME) $(LIB)
		rm -f $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		make fclean -C $(PATH_LIB)
		rm -f $(NAME)
		rm -f $(TEST_NAME)
		rm -f *.gcda
		rm -f *.gcno

re:             fclean all

debug:
		$(CFLAGS) += -ggdb
		$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME) $(LIB)

tests_run:
		rm -f *.gcda
		rm -f *.gcno
		$(CC) -o $(TEST_NAME) $(CFLAGS) $(CPPFLAGS) $(SRC) tests/*.c $(CRITERION_FLAGS)
		./$(TEST_NAME)

.PHONY: clean fclean re all tests_run
