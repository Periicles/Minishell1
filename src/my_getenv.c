/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-paul.ragueneau
** File description:
** my_getenv
*/

#include "lib.h"
#include <stdlib.h>

char *my_get_env(char **env, char *str)
{
    char *path = NULL;
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(str, env[i], my_strlen(str)) == 0) {
            path = malloc(sizeof(char) * my_strlen(env[i]) + 1);
            path = env[i];
            return &path[my_strlen(str)];
        }
    }
    return NULL;
}
