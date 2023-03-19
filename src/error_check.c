/*
** EPITECH PROJECT, 2023
** delivery [WSL: Ubuntu]
** File description:
** error_check
*/

#include "lib.h"
#include "minishell.h"
#include <stddef.h>

int error_check(int ac, char **av, char **env)
{
    if (av == NULL || env == NULL)
        return EPITECH_ERROR;
    if (ac != 1)
        return EPITECH_ERROR;
    return 0;
}
