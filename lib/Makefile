##
## EPITECH PROJECT, 2023
## delivery [WSL: Ubuntu]
## File description:
## Makefile
##

CC = gcc

DIR = src

CFLAGS = -Wall -Wextra

SRC = $(DIR)/check_char.c \
	  $(DIR)/mini_printf.c \
	  $(DIR)/my_put_nbr.c \
	  $(DIR)/my_putchar.c \
	  $(DIR)/my_putstr.c \
	  $(DIR)/my_str_to_word_array.c \
	  $(DIR)/my_strcat.c \
	  $(DIR)/my_strcmp.c \
	  $(DIR)/my_strlen.c \
	  $(DIR)/my_getnbr.c \
	  $(DIR)/my_strdup.c \
	  $(DIR)/my_env.c \
	  $(DIR)/my_strncmp.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
