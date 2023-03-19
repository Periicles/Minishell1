/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-paul.ragueneau
** File description:
** check_char
*/

int check_char(char *separator, char c)
{
    for (int i = 0; separator[i] != '\0'; i += 1) {
        if (separator[i] == c)
            return 1;
    }
    return 0;
}
