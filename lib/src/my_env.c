/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-paul.ragueneau
** File description:
** my_arraylen
*/

#include <stdlib.h>
#include <unistd.h>

void my_putstr(char const *str);

int my_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        write(1, "\n", 1);
    }
    return 0;
}
