/*
** EPITECH PROJECT, 2023
** delivery [WSL: Ubuntu]
** File description:
** commands
*/

#include "lib.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int my_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        write(1, "\n", 1);
    }
    return 0;
}

int execute_builtins(char **command, char **env)
{
    if (my_strcmp(command[0], "cd") == 0) {
        my_cd(command, env);
        return 0;
    }
    if (my_strcmp(command[0], "env") == 0) {
        my_env(env); return 0;
    }
    if (my_strcmp(command[0], "exit") == 0) {
        my_exit(command);
        return 0;
    }
    if (my_strcmp(command[0], "setenv") == 0) {
        my_setenv(command, env);
        return 0;
    }
    return 1;
}
