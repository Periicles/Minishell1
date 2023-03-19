##
## EPITECH PROJECT, 2023
## delivery [WSL: Ubuntu]
## File description:
## Makefile
##

CC = cc

DIR = src

CPPFLAGS = -I./include/

LDFLAGS = -L./lib -lmy

CFLAGS = -Wall -Wextra -g

SRC = $(DIR)/commands.c \
	  $(DIR)/error_check.c \
	  $(DIR)/binaries.c \
	  $(DIR)/my_exit.c \
	  $(DIR)/my_getenv.c \
	  $(DIR)/cd_builtin.c \
	  $(DIR)/my_setenv.c \
	  $(DIR)/main.c

OBJ = $(SRC:.c=.o)

NAME = mysh

RM = rm -f

all: make_libs $(NAME)

$(NAME): lib/libmy.a $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

make_libs:
	make -C lib

clean:
	make -C lib clean
	$(RM) $(OBJ)

fclean: clean
	make -C lib fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all make_libs clean fclean re
