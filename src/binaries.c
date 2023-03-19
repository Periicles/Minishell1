/*
** EPITECH PROJECT, 2023
** delivery [WSL: Ubuntu]
** File description:
** binaries
*/

#include "lib.h"
#include "minishell.h"
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

char **parse_path(char **env)
{
    char *path = my_get_env(env, "PATH=");
    char **path_separated = my_str_to_word_array(path, ":");

    return path_separated;
}

char *get_good_path(char **command, char **path_separated)
{
    if (access(command[0], F_OK) == 0)
        return command[0];

    for (int i = 0; path_separated != NULL &&
    path_separated[i] != NULL; i += 1) {
        char *str = my_strcat(my_strcat(path_separated[i], "/"), command[0]);
        if (access(str, F_OK) == 0)
            return str;
    }
    write(2, command[0], my_strlen(command[0]));
    write(2, ": Command not found.\n", 21);
    return NULL;
}

int check_segfault(int status)
{
    char *signal = NULL;
    if (WIFSIGNALED(status)) {
        if (status == SIGFPE) {
            write(2, "Floating exception", 19);
        } else {
            signal = strsignal(WTERMSIG(status));
            write(2, signal, my_strlen(signal));
        }
        if (WCOREDUMP(status))
            write(2, " (core dumped)", 15);
        write(2, "\n", 1);
    }
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    if (WIFSTOPPED(status))
        return WSTOPSIG(status);
    return 0;
}

int execute_beans(char **command, char **env)
{
    int status = 0;
    char **path_separated = parse_path(env);
    char *str = get_good_path(command, path_separated);
    if (str == NULL)
        return 0;
    int child_pid = fork();

    if (child_pid != 0) {
        waitpid(child_pid, &status, WUNTRACED);
        check_segfault(status);
    } else {
        if (execve(str, command, env) == -1){
            exit(0);
        }
    }
    return 0;
}
