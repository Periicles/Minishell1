/*
** EPITECH PROJECT, 2023
** delivery [WSL: Ubuntu]
** File description:
** minishell
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

    #define EPITECH_ERROR 84;

    int error_check(int ac, char **av, char **env);
    int execute_builtins(char **command, char **env);
    int execute_beans(char **command, char **env);

    char *my_get_env(char **env, char *str);
    int my_cd(char **command, char **env);
    int my_exit(char **command);
    int my_setenv(char **command, char **env);

#endif /* !MINISHELL_H_ */
