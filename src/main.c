/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "lib.h"
#include "minishell.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int commands(char *buffer, char **env)
{
    char **cmd = NULL;
    cmd = my_str_to_word_array(buffer, " \n\t");
    if (cmd == NULL)
        return 0;

    if (execute_builtins(cmd, env) == 1)
        execute_beans(cmd, env);
    return 0;
}

int minishell_start(char **env)
{
    int loop = 0;
    int status = 0;
    char *buffer = NULL;
    size_t size = 0;

    while (loop == 0) {
        write (1, " $> ", 4);
        if (getline(&buffer, &size, stdin) == -1) {
            write(1, "exit\n", 5);
            buffer[size] = '\0';
            loop = 1;
        }
        if (buffer[0] != '\n' && loop == 0 &&
        (status = commands(buffer, env) == 84))
            return EPITECH_ERROR;
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    if (error_check(ac, av, env) == 84)
        return EPITECH_ERROR;

    if (minishell_start(env) == 84)
        return EPITECH_ERROR;
    return 0;
}
