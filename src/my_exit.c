/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-paul.ragueneau
** File description:
** my_exit
*/

#include "lib.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

int my_str_isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

int my_exit(char **command)
{
    if (command[1] == NULL) {
        write(1, "exit\n", 5);
        exit(0);
    }
    if (my_str_isnum(command[1]) == 0) {
        write(2, "exit: Badly formed number.\n", 27);
        return 1;
    }
    write(1, "exit\n", 5);
    exit(my_getnbr(command[1]));
}
