/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-paul.ragueneau
** File description:
** cd_builtin
*/

#include "lib.h"
#include "minishell.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int valid_dir(char **command)
{
    struct stat st;
    if (stat(command[1], &st) == -1) {
        write(2, command[1], my_strlen(command[1]));
        write(2, ": No such file or directory.\n", 30);
        return 1;
    }
    if (S_ISDIR(st.st_mode) == 0) {
        write(2, command[1], my_strlen(command[1]));
        write(2, ": Not a directory.\n", 19);
        return 1;
    }
    return 0;
}

int dir_or_not_dir(char **command)
{
    if (valid_dir(command) == 1)
        return 1;
    if (access(command[1], X_OK) == -1) {
        write(2, command[1], my_strlen(command[1]));
        write(2, ": Permission denied.\n", 21);
        return 1;
    }
    if (chdir(command[1]) == -1) {
        write(2, command[1], my_strlen(command[1]));
        write(2, ": No such file or directory.\n", 29);
        return 1;
    }
    return 0;
}

int check_home_oldpwd(char **command, char **env)
{
    if (command[1] == NULL) {
        if (chdir(my_get_env(env, "HOME=")) == -1) {
            write(2, ": No home directory.\n", 21);
            return 1;
        }
        return 1;
    }
    if (command[1][0] == '-' && command[2] == NULL) {
        if (chdir(my_get_env(env, "OLDPWD=")) == -1) {
            write(2, ": No such file or directory.\n", 29);
            return 1;
        }
        return 1;
    }
    return 0;
}

int check_args(char **command, char **env)
{
    if (check_home_oldpwd(command, env) == 1)
        return 1;
    if (dir_or_not_dir(command) == 1)
        return 1;
    return 0;
}

int my_cd(char **command, char **env)
{
    if (check_args(command, env) == 1)
        return 1;
    return 0;
}
