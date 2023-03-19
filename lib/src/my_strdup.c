/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-paul.ragueneau
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char *str)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (i = 0; str[i] != '\0'; i++)
        dest[i] = str[i];
    dest[my_strlen(str)] = '\0';
    return dest;
}
