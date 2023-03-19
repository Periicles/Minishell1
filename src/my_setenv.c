/*
** EPITECH PROJECT, 2023
** SHELL [WSL: Ubuntu]
** File description:
** my_setenv
*/

#include "lib.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>


int concat_env(int i, char *str, char *str2, char **command, char **env)
{
    for (int k = 0; command[2][k] != '\0'; k++) {
                str2[k] = command[2][k];
            str2[k] = '\0';
            env[i] = my_strcat(str, str2);
            return 0;
        }
    return 0;
}

int my_setenv(char **command, char **env)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * my_strlen(command[1]));
    if (str == NULL)
        return EPITECH_ERROR;
    char *str2 = malloc(sizeof(char) * my_strlen(command[2]));
    if (str2 == NULL)
        return EPITECH_ERROR;
    if (command[1] == NULL) {
        my_env(env);
        return 0;
    }
    for (i = 0; env[i] != NULL; i++) {
        for (j = 0; env[i][j] != '='; j++)
            str[j] = env[i][j];
        str[j] = '\0';
        if (my_strcmp(str, command[1]) == 0) {
            concat_env(i, str, str2, command, env);
            return 0;
        }
    }
    env[i] = my_strcat(command[1], command[2]);
    return 0;
}
